/*
 * AROS stub implementations of curses functions for Lynx.
 * Backed by libtermcap where possible; otherwise no-ops.
 * Also provides SocketBase opener and fork() stub.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---- curses globals ---- */
typedef unsigned long chtype;
typedef unsigned long attr_t;
typedef struct _win_st { int _cury, _curx; attr_t _attrs; short _color; } WINDOW;

static WINDOW _stdscr_s = { 0, 0, 0, 0 };
static WINDOW _curscr_s = { 0, 0, 0, 0 };
WINDOW *stdscr = &_stdscr_s;
WINDOW *curscr = &_curscr_s;

int LINES  = 24;
int COLS   = 80;
int COLORS = 8;
int COLOR_PAIRS = 64;

chtype acs_map[128];
chtype _acs_map[128];
char ttytype[128] = "unknown";

/* Use direct ANSI/VT100 escape sequences - no libtermcap needed */
#define ANSI_CLEAR       "\033[2J\033[H"
#define ANSI_ENTER_CA    "\033[?1049h"
#define ANSI_EXIT_CA     "\033[?1049l"
#define ANSI_CURSOR_VIS  "\033[?25h"

static void emit_str(const char *s)
{
    fputs(s, stdout);
    fflush(stdout);
}

/* ---- initscr / endwin ---- */
int initscr(void)
{
    emit_str(ANSI_ENTER_CA);
    emit_str(ANSI_CLEAR);
    return 0;
}

int endwin(void)
{
    emit_str(ANSI_CURSOR_VIS);
    emit_str(ANSI_EXIT_CA);
    fflush(stdout);
    return 0;
}

/* ---- input modes ---- */
int cbreak(void)  { return 0; }
int crmode(void)  { return 0; }
int noecho(void)  { return 0; }
int echo(void)    { return 0; }

/* ---- output ---- */
int refresh(void)         { fflush(stdout); return 0; }
int wrefresh(WINDOW *w)   { (void)w; fflush(stdout); return 0; }

int move(int y, int x)
{
    fprintf(stdout, "\033[%d;%dH", y + 1, x + 1);
    fflush(stdout);
    if (stdscr) { stdscr->_cury = y; stdscr->_curx = x; }
    return 0;
}

int wmove(WINDOW *w, int y, int x)
{
    if (w == stdscr || w == curscr) return move(y, x);
    if (w) { w->_cury = y; w->_curx = x; }
    return 0;
}

int waddch(WINDOW *w, chtype ch)
{
    (void)w;
    putchar((int)(ch & 0xFF));
    return 0;
}

int waddstr(WINDOW *w, const char *s)
{
    (void)w;
    if (s) fputs(s, stdout);
    return 0;
}

int waddnstr(WINDOW *w, const char *s, int n)
{
    (void)w;
    if (s) fwrite(s, 1, n, stdout);
    return 0;
}

int wattrset(WINDOW *w, int a)  { if (w) w->_attrs = a; return 0; }
int wattron(WINDOW *w, int a)   { if (w) w->_attrs |= a; return 0; }
int wattroff(WINDOW *w, int a)  { if (w) w->_attrs &= ~a; return 0; }
int wbkgdset(WINDOW *w, chtype c) { (void)w; (void)c; return 0; }
int wbkgd(WINDOW *w, chtype c)    { (void)w; (void)c; return 0; }

int clear(void)
{
    emit_str(ANSI_CLEAR);
    if (stdscr) { stdscr->_cury = 0; stdscr->_curx = 0; }
    return 0;
}

int erase(void)    { return clear(); }
int clrtoeol(void) { emit_str("\033[K"); return 0; }

int clearok(WINDOW *w, int bf)  { (void)w; (void)bf; return 0; }
int scrollok(WINDOW *w, int bf) { (void)w; (void)bf; return 0; }

int touchwin(WINDOW *w)              { (void)w; return 0; }
int touchline(WINDOW *w, int y, int n) { (void)w; (void)y; (void)n; return 0; }
int wredrawln(WINDOW *w, int y, int n) { (void)w; (void)y; (void)n; return 0; }
int wresize(WINDOW *w, int y, int x)   { (void)w; (void)y; (void)x; return 0; }
int resizeterm(int y, int x)           { LINES = y; COLS = x; return 0; }
int napms(int ms)                      { (void)ms; return 0; }

int box(WINDOW *w, chtype v, chtype h) { (void)w; (void)v; (void)h; return 0; }

int keypad(WINDOW *w, int on)  { (void)w; (void)on; return 0; }

/* ---- windows ---- */
int newpad(int y, int x) { (void)y; (void)x; return 0; }

WINDOW *newwin(int nlines, int ncols, int y, int x)
{
    (void)nlines; (void)ncols; (void)y; (void)x;
    WINDOW *w = calloc(1, sizeof(WINDOW));
    return w;
}

int delwin(WINDOW *w)
{
    if (w && w != stdscr && w != curscr) free(w);
    return 0;
}

typedef struct _screen SCREEN;
struct _screen { int dummy; };

WINDOW *newterm(char *type, FILE *out, FILE *in)
{
    (void)type; (void)out; (void)in;
    return stdscr;
}

int delscreen(SCREEN *s) { (void)s; return 0; }
int define_key(const char *s, int k) { (void)s; (void)k; return 0; }

int pnoutrefresh(WINDOW *w, int py, int px, int sy, int sx, int ey, int ex)
{
    (void)w; (void)py; (void)px; (void)sy; (void)sx; (void)ey; (void)ex;
    return 0;
}

/* ---- color ---- */
int start_color(void)   { return 0; }
int has_colors(void)    { return 0; }
int use_default_colors(void)      { return 0; }
int use_legacy_coding(int l)      { (void)l; return 0; }
int assume_default_colors(int f, int b) { (void)f; (void)b; return 0; }

static short color_pairs[256][2];
int init_pair(short pair, short fg, short bg)
{
    if (pair < 0 || pair >= 256) return -1;
    color_pairs[pair][0] = fg;
    color_pairs[pair][1] = bg;
    return 0;
}

int pair_content(short pair, short *fg, short *bg)
{
    if (pair < 0 || pair >= 256) return -1;
    if (fg) *fg = color_pairs[pair][0];
    if (bg) *bg = color_pairs[pair][1];
    return 0;
}

int wattr_get(WINDOW *w, attr_t *a, short *c, void *opts)
{
    (void)opts;
    if (a) *a = w ? w->_attrs : 0;
    if (c) *c = w ? w->_color : 0;
    return 0;
}

int wborder(WINDOW *w, chtype ls, chtype rs, chtype ts, chtype bs,
            chtype tl, chtype tr, chtype bl, chtype br)
{
    (void)w; (void)ls; (void)rs; (void)ts; (void)bs;
    (void)tl; (void)tr; (void)bl; (void)br;
    return 0;
}

int getattrs(WINDOW *w) { return w ? (int)w->_attrs : 0; }
int getbegx(WINDOW *w)  { (void)w; return 0; }
int getbegy(WINDOW *w)  { (void)w; return 0; }

WINDOW *derwin(WINDOW *orig, int nlines, int ncols, int y, int x)
{
    (void)orig; (void)nlines; (void)ncols; (void)y; (void)x;
    return newwin(nlines, ncols, y, x);
}

int doupdate(void)           { fflush(stdout); return 0; }
int wnoutrefresh(WINDOW *w)  { (void)w; return 0; }
int wclear(WINDOW *w)        { (void)w; return clear(); }
int werase(WINDOW *w)        { (void)w; return 0; }
int wclrtoeol(WINDOW *w)     { (void)w; emit_str("\033[K"); return 0; }

/* ---- fork stub ---- */
int fork(void) { return -1; }

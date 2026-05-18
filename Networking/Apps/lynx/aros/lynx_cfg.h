/* config.h - Hand-tuned for AROS (pc-x86_64) cross-compilation
 * Based on config.hin from Lynx 2.9.2
 * Do not run configure on AROS; use this file directly.
 */
#ifndef LYNX_CFG_H
#define LYNX_CFG_H 1

/* AROS identification */
#define AROS 1

/* System name */
#define SYSTEM_NAME "aros"

/* We are NOT a "real unix" system - disables fork/getpw/utmp/etc */
/* #undef REAL_UNIX_SYSTEM */
/* #undef UNIX */

/* ------------------------------------------------------------------ */
/* Standard C features                                                 */
/* ------------------------------------------------------------------ */
#define STDC_HEADERS 1
#define HAVE_LYHELP_H 1

/* Inline */
/* #undef inline */

/* ANSI noreturn */
/* #undef STDC_NORETURN */

/* ------------------------------------------------------------------ */
/* C type sizes (x86_64)                                               */
/* ------------------------------------------------------------------ */
#define SIZEOF_INT     4
#define SIZEOF_LONG    8
#define SIZEOF_OFF_T   8
#define SIZEOF_SIZE_T  8
#define SIZEOF_TIME_T  8

/* ------------------------------------------------------------------ */
/* Available standard headers                                          */
/* ------------------------------------------------------------------ */
#define HAVE_DIRENT_H 1
#define HAVE_FCNTL_H 1
#define HAVE_INTTYPES_H 1
#define HAVE_LIMITS_H 1
#define HAVE_LOCALE_H 1
#define HAVE_MEMORY_H 1
#define HAVE_STDDEF_H 1
#define HAVE_STDINT_H 1
#define HAVE_STDLIB_H 1
#define HAVE_STRING_H 1
#define HAVE_SYS_STAT_H 1
#define HAVE_SYS_TIME_H 1
#define HAVE_SYS_TYPES_H 1
#define HAVE_TIME_H 1
#define HAVE_UNISTD_H 1
/* #undef HAVE_SYS_FILIO_H */
/* #undef HAVE_SYS_NDIR_H */
/* #undef HAVE_SYS_DIR_H */
/* #undef HAVE_NDIR_H */
/* #undef HAVE_WCHAR_H */
/* #undef NEED_WCHAR_H */
/* #undef HAVE_SYSLOG_H */

/* Network headers - provided by bsdsocket.library on AROS */
#define HAVE_SYS_SOCKET_H 1
#define HAVE_NETINET_IN_H 1
#define HAVE_NETDB_H 1
#define HAVE_ARPA_INET_H 1

/* Time */
#define TIME_WITH_SYS_TIME 1

/* ------------------------------------------------------------------ */
/* Available library functions                                         */
/* ------------------------------------------------------------------ */
#define HAVE_ALLOCA 1
#define HAVE_ALLOCA_H 1
#define HAVE_BZERO 1
#define HAVE_CHMOD 1
#define HAVE_FSEEKO 1
#define HAVE_FTELLO 1
#define HAVE_GETCWD 1
#define HAVE_GETENV 1
#define HAVE_GETTIMEOFDAY 1
#define HAVE_MEMCPY 1
#define HAVE_MEMMOVE 1
#define HAVE_MKTEMP 1
#define HAVE_PUTENV 1
#define HAVE_READDIR 1
#define HAVE_REMOVE 1
#define HAVE_SETJMP 1
#define HAVE_SETLOCALE 1
#define HAVE_SIGACTION 1
#define HAVE_SIGNAL 1
#define HAVE_SNPRINTF 1
#define HAVE_STAT 1
#define HAVE_STRCASECMP 1
#define HAVE_STRFTIME 1
#define HAVE_STRLCAT 1
#define HAVE_STRLCPY 1
#define HAVE_STRNCASECMP 1
#define HAVE_STRSTR 1
#define HAVE_STRTOL 1
#define HAVE_SYMLINK 1
#define HAVE_TOUPPER 1
#define HAVE_TOLOWER 1
#define HAVE_VFPRINTF 1
#define HAVE_VSNPRINTF 1

/* Networking - bsdsocket.library provides these */
#define HAVE_GETHOSTBYNAME 1
#define HAVE_GETADDRINFO 1
#define HAVE_SOCKET 1
#define HAVE_SELECT 1
#define HAVE_SETSOCKOPT 1
#define HAVE_FCNTL 1

/* These are NOT available on AROS */
/* #undef HAVE_GETPWUID */
/* #undef HAVE_GETPWNAM */
/* #undef HAVE_GETLOGIN */
/* #undef HAVE_WAITPID */
/* #undef WAITPID_USES_UNION */
/* #undef WAIT_USES_UNION */
/* #undef HAVE_UTMP_H */
/* #undef HAVE_UTMPX_H */
/* #undef USE_SYSV_UTMP */
/* #undef UTMPX_FOR_UTMP */
/* #undef NSL_FORK */
/* #undef _WINDOWS_NSL */

/* ------------------------------------------------------------------ */
/* SSL (OpenSSL 1.1.x from contrib)                                   */
/* ------------------------------------------------------------------ */
#define USE_SSL 1
#define USE_OPENSSL_INCL 1
#define USE_X509_SUPPORT 1
/* #undef USE_GNUTLS_FUNCS */
/* #undef USE_GNUTLS_INCL */

/* ------------------------------------------------------------------ */
/* zlib                                                                */
/* ------------------------------------------------------------------ */
#define USE_ZLIB 1
/* #undef USE_BZLIB */
/* #undef USE_BROTLI */

/* ------------------------------------------------------------------ */
/* Screen / curses (AROS uses termcap via bsdsocket-independent        */
/* console — we use the built-in curses/termcap support)              */
/* ------------------------------------------------------------------ */
/* #undef NCURSES */
/* #undef NCURSES_BROKEN */
/* #undef USE_SLANG */
/* #undef XCURSES */
/* #undef PDC_DLL_BUILD */
/* #undef PDC_WIDE */
/* #undef WIDEC_CURSES */
/* #undef NEED_PTEM_H */
/* #undef TERMIO_AND_CURSES */
/* #undef TERMIO_AND_TERMIOS */

/* ------------------------------------------------------------------ */
/* I/O control method for non-blocking sockets                        */
/* ------------------------------------------------------------------ */
#define USE_FCNTL 1
/* #undef USE_IOCTL */

/* ------------------------------------------------------------------ */
/* Lynx features enabled                                               */
/* ------------------------------------------------------------------ */
#define USE_COLOR_STYLE 1
#define USE_PRETTYSRC 1
#define USE_PERSISTENT_COOKIES 1
#define USE_SESSIONS 1
#define USE_CACHEJAR 1
#define USE_CHARSET_CHOICE 1
#define USE_FILE_UPLOAD 1
#define USE_ALT_BINDINGS 1
#define USE_ADDRLIST_PAGE 1
#define USE_PROGRESSBAR 1
#define USE_READPROGRESS 1
#define USE_SCROLLBAR 1
#define USE_SOURCE_CACHE 1
#define USE_LOCALE_CHARSET 1
#define USE_JUSTIFY_ELTS 1
#define TRACK_INTERNAL_LINKS 1
#define UNDERLINE_LINKS 1

/* ------------------------------------------------------------------ */
/* Lynx features disabled (require fork/Unix/dired)                   */
/* ------------------------------------------------------------------ */
/* #undef LYNXCGI_LINKS */
/* #undef NSL_FORK */
/* #undef NO_LYNX_TRACE */
/* #undef NO_CONFIG_INFO */
/* CGI links disabled (needs fork/execve) */
/* #undef USE_EXTERNALS */
/* DIRED (directory editor) disabled */
/* #undef OK_INSTALL */
/* #undef OK_OVERRIDE */
/* #undef OK_PERMIT */

/* ------------------------------------------------------------------ */
/* Path programs - map to AROS equivalents                            */
/* ------------------------------------------------------------------ */
#define GZIP_PATH    "C:gzip"
#define TAR_PATH     "C:tar"
#define RM_PATH      "C:delete"
#define MV_PATH      "C:rename"
#define MKDIR_PATH   "C:makedir"
#define TOUCH_PATH   "C:touch"
#define UNCOMPRESS_PATH "C:gunzip"
#define ZCAT_PATH    "C:zcat"
/* #undef TELNET_PATH */
/* #undef RLOGIN_PATH */
/* #undef TN3270_PATH */
/* #undef UUDECODE_PATH */
/* #undef ZIP_PATH */
/* #undef UNZIP_PATH */
/* #undef SETFONT_PATH */

/* AROS shell - used for GOT_SYSTEM */
#define HAVE_SYSTEM 1

/* ------------------------------------------------------------------ */
/* Configuration file paths                                           */
/* ------------------------------------------------------------------ */
#define LYNX_CFG_FILE "Lynx:lynx.cfg"
#define MIME_LIBDIR   "Lynx:"
#define LYNX_CFG_PATH "Lynx:"
#define LYNX_LSS_FILE "Lynx:lynx.lss"

/* ------------------------------------------------------------------ */
/* Miscellaneous                                                       */
/* ------------------------------------------------------------------ */
#define HAVE_DIRENT_H 1
#define D_NAMLEN(d) strlen((d)->d_name)

/* lstat falls back to stat on AROS */
#ifndef HAVE_LSTAT
#define lstat stat
#endif

/* pid_t / uid_t / mode_t / off_t */
/* #undef pid_t */
/* #undef uid_t */
/* #undef mode_t */
/* #undef off_t */
/* #undef socklen_t */
/* #undef ssize_t */

/* Random */
#define lynx_rand  rand
#define lynx_srand srand

/* NLS */
/* #undef NLS_TEXTDOMAIN */

/* Groups */
/* #undef NGROUPS */

/* Color defaults */
/* #undef ENABLE_SCROLLBACK */

/* Struct dirent */
#define STRUCT_DIRENT struct dirent

#endif /* LYNX_CFG_H */

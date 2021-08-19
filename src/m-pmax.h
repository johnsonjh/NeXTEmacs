#include "m-mips.h"
#undef LIBS_MACHINE
#undef BIG_ENDIAN
#undef LIB_STANDARD
#undef START_FILES
#undef COFF
#undef TERMINFO
#define MAIL_USE_FLOCK
#define HAVE_UNION_WAIT

/* Supposedly the following will overcome a kernel bug.  */
#undef LD_SWITCH_MACHINE
#undef DATA_START
#define DATA_START 0x10000000
#define DATA_SEG_BITS 0x10000000

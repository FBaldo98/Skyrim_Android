/* Skyrim's statically linked MSVC memset / memcpy / memmove, replaced by
 * bionic's (HOST_OVERRIDES_SKYRIM in tools/lift.py). Lifted, they are
 * byte loops, emulated rep movsd/stosd and SSE block loops, and between
 * them they have about a thousand call sites. All three are cdecl and return
 * the destination; MSVC's memcpy copes with overlap like memmove does. */
#include "rt.h"

#ifdef GAME_SKYRIM
void f_F52240(CPU *c) {  /* memset(dst, c, n) */
    uint32_t d = ARG(0);
    memset(MEM + d, (int)(ARG(1) & 0xFF), ARG(2));
    RETC(d);
}
void f_F537F0(CPU *c) {  /* memcpy(dst, src, n) */
    uint32_t d = ARG(0);
    memmove(MEM + d, MEM + ARG(1), ARG(2));
    RETC(d);
}
void f_F52E30(CPU *c) {  /* memmove(dst, src, n) */
    uint32_t d = ARG(0);
    memmove(MEM + d, MEM + ARG(1), ARG(2));
    RETC(d);
}
#endif

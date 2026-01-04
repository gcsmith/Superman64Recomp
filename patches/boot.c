#include "patches.h"
#include <ultra64.h>

extern s16 D_800D60D0;
extern OSMesgQueue D_800E85C0;
extern OSMesg D_800E85DC;

void yield_self_1ms(void);

RECOMP_PATCH void func_80000FC0(u32 arg0, u8* arg1, u32 arg2) {
    OSIoMesg sp30;
    u32 sp2C;

    if ((arg2 < 0xF000U) || D_800D60D0 == 0) {
        osInvalDCache(arg1, (s32) arg2);
        osPiStartDma(&sp30, 0, 0, arg0, arg1, arg2, &D_800E85C0);
        osRecvMesg(&D_800E85C0, &D_800E85DC, 1);
        return;
    }

    sp2C = (arg2 / 5U) & ~7;
    while (arg2 >= sp2C) {
            osInvalDCache(arg1, (s32) sp2C);
            osPiStartDma(&sp30, 0, 0, arg0, arg1, sp2C, &D_800E85C0);
            osRecvMesg(&D_800E85C0, &D_800E85DC, 1);
            arg0 += sp2C;
            arg1 += sp2C;
            arg2 -= sp2C;
            D_800D60D0 = 2;
            while (D_800D60D0 == 2) {
                yield_self_1ms();
            }
    }
    if (arg2 != 0) {
        osInvalDCache(arg1, (s32) arg2);
        osPiStartDma(&sp30, 0, 0, arg0, arg1, arg2, &D_800E85C0);
        osRecvMesg(&D_800E85C0, &D_800E85DC, 1);
    }
}


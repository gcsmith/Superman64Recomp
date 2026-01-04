#include "patches.h"
#include <ultra64.h>

extern s32 D_800D6100;
extern ALSeqPlayer* D_800D6108;

void yield_self_1ms(void);

RECOMP_PATCH void alSynRemovePlayer(ALSynth* s, ALPlayer* client) {
    if (D_800D6100 != 0) {
        D_800D6100 = 0;
        alSeqpStop(D_800D6108);
        if (alSeqpGetState(D_800D6108) != 0) {
            do {
                yield_self_1ms();
            } while (alSeqpGetState(D_800D6108) != 0);
        }
    }
}


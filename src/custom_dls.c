#include "global.h"
#include "object_link_boy.h"
#include "object_link_child.h"
#include "gameplay_keep.h"

extern Gfx gLinkHumanGreatFairysSwordDL[];
extern Gfx gLinkHumanHookshotDL[];
extern Gfx gLinkHumanBowDL[];
extern Gfx gLinkHumanHerosShieldDL[];
extern Gfx gLinkHumanMirrorShieldDL[];
extern Gfx gKokiriSwordDL[];
extern Gfx gRazorSwordDL[];
extern Gfx gLinkHumanGildedSwordHandleDL[];
extern Gfx gLinkHumanGildedSwordBladeDL[];

// child fixes
Gfx gLinkChildLeftHandHoldingGreatFairysSwordDL[] = {
    gsSPDisplayList(gLinkChildLeftFistNearDL),
    gsSPBranchList(gLinkHumanGreatFairysSwordDL),
};

Gfx gLinkChildRightHandHoldingBowDL[] = {
    gsSPDisplayList(gLinkChildRightHandClosedNearDL),
    gsSPBranchList(gLinkHumanBowDL),
};

Gfx gLinkHumanRightHandHoldingHookshotDL[] = {
    gsSPDisplayList(gLinkChildRightHandClosedNearDL),
    gsSPBranchList(gLinkHumanHookshotDL),
};

// default mm works for this, but for parity sake
Gfx gLinkChildLeftHandHoldingKokiriSwordDL[] = {
    gsSPDisplayList(gLinkChildLeftFistNearDL),
    gsSPBranchList(gKokiriSwordDL),
};

Gfx gLinkChildLeftHandHoldingRazorSwordDL[] = {
    gsSPDisplayList(gLinkChildLeftFistNearDL),
    gsSPBranchList(gRazorSwordDL),
};

Gfx gLinkChildLeftHandHoldingGildedSwordDL[] = {
    gsSPDisplayList(gLinkChildLeftFistNearDL),
    gsSPDisplayList(gLinkHumanGildedSwordHandleDL),
    gsSPBranchList(gLinkHumanGildedSwordBladeDL),
};

Gfx gLinkChildRightHandHoldingHerosShieldDL[] = {
    gsSPDisplayList(gLinkChildRightHandClosedNearDL),
    gsSPBranchList(gLinkHumanHerosShieldDL),
};

Gfx gLinkChildRightHandHoldingMirrorShieldDL[] = {
    gsSPDisplayList(gLinkChildRightHandClosedNearDL),
    gsSPBranchList(gLinkHumanMirrorShieldDL),
};

// adult fixes
Gfx gLinkAdultLeftHandHoldingGreatFairysSwordDL[] = {
    gsSPDisplayList(gLinkAdultLeftHandClosedNearDL),
    gsSPBranchList(gLinkHumanGreatFairysSwordDL),
};

Gfx gLinkAdultRightHandHoldingHookshotDL[] = {
    gsSPDisplayList(gLinkAdultRightHandClosedNearDL),
    gsSPBranchList(gLinkHumanHookshotDL),
};

Gfx gLinkAdultRightHandHoldingBowDL[] = {
    gsSPDisplayList(gLinkAdultRightHandClosedNearDL),
    gsSPBranchList(gLinkHumanBowDL),
};

Gfx gLinkAdultLeftHandHoldingKokiriSwordDL[] = {
    gsSPDisplayList(gLinkAdultLeftHandClosedNearDL),
    gsSPBranchList(gKokiriSwordDL),
};

Gfx gLinkAdultLeftHandHoldingRazorSwordDL[] = {
    gsSPDisplayList(gLinkAdultLeftHandClosedNearDL),
    gsSPBranchList(gRazorSwordDL),
};

Gfx gLinkAdultLeftHandHoldingGildedSwordDL[] = {
    gsSPDisplayList(gLinkAdultLeftHandClosedNearDL),
    gsSPDisplayList(gLinkHumanGildedSwordHandleDL),
    gsSPBranchList(gLinkHumanGildedSwordBladeDL),
};

Gfx gLinkAdultRightHandHoldingHerosShieldDL[] = {
    gsSPDisplayList(gLinkAdultRightHandClosedNearDL),
    gsSPBranchList(gLinkHumanHerosShieldDL),
};

Gfx gLinkAdultRightHandHoldingMirrorShieldDL[] = {
    gsSPDisplayList(gLinkAdultRightHandClosedNearDL),
    gsSPBranchList(gLinkHumanMirrorShieldDL),
};
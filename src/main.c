#include "global.h"
#include "modding.h"
#include "recompconfig.h"

RECOMP_IMPORT("*", int recomp_printf(const char* fmt, ...));

#include "object_link_child.h"

extern Gfx* gPlayerWaistDLs[2 * PLAYER_FORM_MAX];
extern TexturePtr sPlayerMouthTextures[PLAYER_MOUTH_MAX];
extern TexturePtr sPlayerEyesTextures[PLAYER_EYES_MAX];
extern Gfx* gPlayerRightHandOpenDLs[2 * PLAYER_FORM_MAX];
extern Gfx* gPlayerRightHandClosedDLs[2 * PLAYER_FORM_MAX];
extern Gfx* gPlayerRightHandBowDLs[2 * PLAYER_FORM_MAX];
extern Gfx* gPlayerRightHandInstrumentDLs[2 * PLAYER_FORM_MAX];
extern Gfx* gPlayerRightHandHookshotDLs[2 * PLAYER_FORM_MAX];
extern Gfx* gPlayerLeftHandOpenDLs[2 * PLAYER_FORM_MAX];
extern Gfx* gPlayerLeftHandClosedDLs[2 * PLAYER_FORM_MAX];
extern Gfx* gPlayerLeftHandTwoHandSwordDLs[2 * PLAYER_FORM_MAX];
extern Gfx* gPlayerLeftHandOneHandSwordDLs[2 * PLAYER_FORM_MAX];
extern Gfx* gPlayerLeftHandBottleDLs[2 * PLAYER_FORM_MAX];
extern Gfx* sPlayerFirstPersonLeftForearmDLs[PLAYER_FORM_MAX];
extern Gfx* sPlayerFirstPersonLeftHandDLs[PLAYER_FORM_MAX];
extern Gfx* sPlayerFirstPersonRightShoulderDLs[PLAYER_FORM_MAX];
extern Gfx* sPlayerFirstPersonRightHandDLs[PLAYER_FORM_MAX];
extern Gfx* sPlayerFirstPersonRightHandHookshotDLs[PLAYER_FORM_MAX];

// gPlayerWaistDLs
// gPlayerHandHoldingShields
// gPlayerSheath12DLs
// gPlayerSheath13DLs
// gPlayerSheath14DLs
// gPlayerShields
// gPlayerSheathedSwords
// gPlayerSwordSheaths
// gPlayerLeftHandTwoHandSwordDLs
// gPlayerLeftHandOpenDLs
// gPlayerLeftHandClosedDLs
// gPlayerLeftHandOneHandSwordDLs
// D_801C018C // holding sword
// gPlayerRightHandOpenDLs
// gPlayerRightHandClosedDLs
// gPlayerRightHandBowDLs
// gPlayerRightHandInstrumentDLs
// gPlayerRightHandHookshotDLs
// gPlayerLeftHandBottleDLs
// sPlayerFirstPersonLeftForearmDLs
// sPlayerFirstPersonLeftHandDLs
// sPlayerFirstPersonRightShoulderDLs
// sPlayerFirstPersonRightHandDLs
// sPlayerFirstPersonRightHandHookshotDLs

TexturePtr sMouthTextures[PLAYER_MOUTH_MAX] = {
    gLinkChildMouthClosedTex, // PLAYER_MOUTH_CLOSED
    gLinkChildMouthHalfTex,   // PLAYER_MOUTH_HALF
    gLinkChildMouthOpenTex,   // PLAYER_MOUTH_OPEN
    gLinkChildMouthSmileTex,  // PLAYER_MOUTH_SMILE
};

TexturePtr sEyeTextures[PLAYER_EYES_MAX] = {
    gLinkChildEyesOpenTex,    // PLAYER_EYES_OPEN
    gLinkChildEyesHalfTex,    // PLAYER_EYES_HALF
    gLinkChildEyesClosedfTex, // PLAYER_EYES_CLOSED
    gLinkChildEyesLeftTex,    // PLAYER_EYES_LEFT
    gLinkChildEyesRightTex,   // PLAYER_EYES_RIGHT
    gLinkChildEyesWideTex,    // PLAYER_EYES_WIDE
    gLinkChildEyesDownTex,    // PLAYER_EYES_DOWN
    gLinkChildEyesWincingTex, // PLAYER_EYES_WINCING
};

RECOMP_HOOK("Player_Init") void on_Player_Init(Actor* thisx, PlayState* play) {
    gPlayerSkeletons[PLAYER_FORM_HUMAN] = &gLinkChildSkel;

    gPlayerWaistDLs[PLAYER_FORM_HUMAN * 2 + 0] = gLinkChildWaistNearDL;
    gPlayerWaistDLs[PLAYER_FORM_HUMAN * 2 + 1] = gLinkChildWaistFarDL;

    gPlayerRightHandOpenDLs[PLAYER_FORM_HUMAN * 2 + 0] = gLinkChildRightHandNearDL;
    gPlayerRightHandOpenDLs[PLAYER_FORM_HUMAN * 2 + 1] = gLinkChildRightHandFarDL;
    gPlayerRightHandClosedDLs[PLAYER_FORM_HUMAN * 2 + 0] = gLinkChildRightHandClosedNearDL;
    gPlayerRightHandClosedDLs[PLAYER_FORM_HUMAN * 2 + 1] = gLinkChildRightHandClosedFarDL;
    gPlayerRightHandBowDLs[PLAYER_FORM_HUMAN * 2 + 0] = gLinkChildRightHandHoldingSlingshotNearDL;
    gPlayerRightHandBowDLs[PLAYER_FORM_HUMAN * 2 + 1] = gLinkChildRightHandHoldingSlingshotFarDL;
    // gPlayerRightHandInstrumentDLs[PLAYER_FORM_HUMAN * 2 + 0] = gLinkChildRightHandHoldingFairyOcarinaNearDL;
    // gPlayerRightHandInstrumentDLs[PLAYER_FORM_HUMAN * 2 + 1] = gLinkChildRightHandHoldingFairyOcarinaFarDL;
    gPlayerRightHandInstrumentDLs[PLAYER_FORM_HUMAN * 2 + 0] = gLinkChildRightHandAndOotNearDL;
    gPlayerRightHandInstrumentDLs[PLAYER_FORM_HUMAN * 2 + 1] = gLinkChildRightHandHoldingOOTFarDL;
    gPlayerRightHandHookshotDLs[PLAYER_FORM_HUMAN * 2 + 0] = gLinkChildRightHandNearDL;
    gPlayerRightHandHookshotDLs[PLAYER_FORM_HUMAN * 2 + 1] = gLinkChildRightHandFarDL;
    
    gPlayerLeftHandOpenDLs[PLAYER_FORM_HUMAN * 2 + 0] = gLinkChildLeftHandNearDL;
    gPlayerLeftHandOpenDLs[PLAYER_FORM_HUMAN * 2 + 1] = gLinkChildLeftHandFarDL;
    gPlayerLeftHandClosedDLs[PLAYER_FORM_HUMAN * 2 + 0] = gLinkChildLeftFistNearDL;
    gPlayerLeftHandClosedDLs[PLAYER_FORM_HUMAN * 2 + 1] = gLinkChildLeftFistFarDL;
    gPlayerLeftHandTwoHandSwordDLs[PLAYER_FORM_HUMAN * 2 + 0] = gLinkChildLeftHandHoldingGreatFairysSwordDL;
    gPlayerLeftHandTwoHandSwordDLs[PLAYER_FORM_HUMAN * 2 + 1] = gLinkChildLeftHandHoldingGreatFairysSwordDL;
    gPlayerLeftHandOneHandSwordDLs[PLAYER_FORM_HUMAN * 2 + 0] = gLinkChildLeftFistAndKokiriSwordNearDL;
    gPlayerLeftHandOneHandSwordDLs[PLAYER_FORM_HUMAN * 2 + 1] = gLinkChildLeftFistAndKokiriSwordFarDL;
    gPlayerLeftHandBottleDLs[PLAYER_FORM_HUMAN * 2 + 0] = gLinkChildLeftHandUpNearDL;
    gPlayerLeftHandBottleDLs[PLAYER_FORM_HUMAN * 2 + 1] = gLinkChildLeftHandUpNearDL;

    sPlayerFirstPersonLeftForearmDLs[PLAYER_FORM_HUMAN] = gLinkChildLeftForearmNearDL;
    sPlayerFirstPersonLeftHandDLs[PLAYER_FORM_HUMAN] = gLinkChildLeftFistNearDL;
    sPlayerFirstPersonRightShoulderDLs[PLAYER_FORM_HUMAN] = gLinkChildRightShoulderNearDL;
    sPlayerFirstPersonRightHandDLs[PLAYER_FORM_HUMAN] = gLinkChildRightHandClosedNearDL;
    sPlayerFirstPersonRightHandHookshotDLs[PLAYER_FORM_HUMAN] = gLinkChildRightHandClosedNearDL;
 
    for (int i = 0; i < PLAYER_MOUTH_MAX; i++) {
        sPlayerMouthTextures[i] = sMouthTextures[i];
    }
    for (int i = 0; i < PLAYER_EYES_MAX; i++) {
        sPlayerEyesTextures[i] = sEyeTextures[i];
    }
}

void fixLinkColor(PlayState* play) {
    Player* player = GET_PLAYER(play);
    if (recomp_get_config_u32("fix_color") && player->transformation == PLAYER_FORM_HUMAN) {
        OPEN_DISPS(play->state.gfxCtx);
        gDPSetEnvColor(POLY_OPA_DISP++, 30, 105, 27, 0);
        CLOSE_DISPS(play->state.gfxCtx);
    }
}

s32 Player_OverrideLimbDrawGameplayCommon(PlayState* play, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, Actor* thisx);
void func_80125CE0(Player* player, struct_80124618* arg1, Vec3f* pos, Vec3s* rot);

RECOMP_HOOK("Player_OverrideLimbDrawGameplayDefault")
void Recolor_OverrideLimbDrawDefault(PlayState* play, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, Actor* actor) {
    Player* player = (Player*)actor;
    fixLinkColor(play);
}

RECOMP_HOOK("Player_OverrideLimbDrawGameplayFirstPerson")
void Recolor_OverrideLimbDrawFirstPerson(PlayState* play, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, Actor* actor) {
    Player* player = (Player*)actor;
    fixLinkColor(play);
}
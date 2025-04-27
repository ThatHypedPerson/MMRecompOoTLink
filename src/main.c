#include "global.h"
#include "modding.h"
#include "recompconfig.h"

RECOMP_IMPORT("*", int recomp_printf(const char* fmt, ...));

#include "object_link_child.h"
#include "object_link_boy.h"
#include "custom_dls.h"

typedef enum {
    LINK_TYPE_CHILD,
    LINK_TYPE_ADULT,
} LinkType;

extern Gfx* gPlayerWaistDLs[2 * PLAYER_FORM_MAX];
extern Gfx* gPlayerHandHoldingShields[2 * (PLAYER_SHIELD_MAX - 1)];
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
extern Gfx* D_801C018C[];
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

// note: these are flipped from oot decomp
void* sEyeTextures[][PLAYER_EYES_MAX] = {
    {
        gLinkChildEyesOpenTex,    // PLAYER_EYES_OPEN
        gLinkChildEyesHalfTex,    // PLAYER_EYES_HALF
        gLinkChildEyesClosedfTex, // PLAYER_EYES_CLOSED
        gLinkChildEyesLeftTex,    // PLAYER_EYES_LEFT
        gLinkChildEyesRightTex,   // PLAYER_EYES_RIGHT
        gLinkChildEyesWideTex,    // PLAYER_EYES_WIDE
        gLinkChildEyesDownTex,    // PLAYER_EYES_DOWN
        gLinkChildEyesWincingTex, // PLAYER_EYES_WINCING
    },
    {
        gLinkAdultEyesOpenTex,    // PLAYER_EYES_OPEN
        gLinkAdultEyesHalfTex,    // PLAYER_EYES_HALF
        gLinkAdultEyesClosedfTex, // PLAYER_EYES_CLOSED
        gLinkAdultEyesLeftTex,    // PLAYER_EYES_LEFT
        gLinkAdultEyesRightTex,   // PLAYER_EYES_RIGHT
        gLinkAdultEyesWideTex,    // PLAYER_EYES_WIDE
        gLinkAdultEyesDownTex,    // PLAYER_EYES_DOWN
        gLinkAdultEyesWincingTex, // PLAYER_EYES_WINCING
    },
};

void* sMouthTextures[][PLAYER_MOUTH_MAX] = {
    {
        gLinkChildMouthClosedTex, // PLAYER_MOUTH_CLOSED
        gLinkChildMouthHalfTex,   // PLAYER_MOUTH_HALF
        gLinkChildMouthOpenTex,   // PLAYER_MOUTH_OPEN
        gLinkChildMouthSmileTex,  // PLAYER_MOUTH_SMILE
    },
    {
        gLinkAdultMouthClosedTex, // PLAYER_MOUTH_CLOSED
        gLinkAdultMouthHalfTex,   // PLAYER_MOUTH_HALF
        gLinkAdultMouthOpenTex,   // PLAYER_MOUTH_OPEN
        gLinkAdultMouthSmileTex,  // PLAYER_MOUTH_SMILE
    },
};

// rough fix for some issue caused by replacing these for child/adult
extern u64 gLinkGoronEyesOpenTex[];
extern u64 gLinkGoronEyesHalfTex[];
extern u64 gLinkGoronEyesClosedTex[];
extern u64 gLinkGoronEyesSurprisedTex[];

TexturePtr sGoronEyesTextures[PLAYER_EYES_MAX] = {
    gLinkGoronEyesOpenTex,      // PLAYER_EYES_OPEN
    gLinkGoronEyesHalfTex,      // PLAYER_EYES_HALF
    gLinkGoronEyesClosedTex,    // PLAYER_EYES_CLOSED
    gLinkGoronEyesSurprisedTex, // PLAYER_EYES_ROLL_RIGHT
    gLinkGoronEyesSurprisedTex, // PLAYER_EYES_ROLL_LEFT
    gLinkGoronEyesSurprisedTex, // PLAYER_EYES_ROLL_UP
    gLinkGoronEyesSurprisedTex, // PLAYER_EYES_ROLL_DOWN
    gLinkGoronEyesSurprisedTex, // PLAYER_EYES_7
};

extern u64 gLinkZoraEyesOpenTex[];
extern u64 gLinkZoraEyesHalfTex[];
extern u64 gLinkZoraEyesClosedTex[];
extern u64 gLinkZoraEyesRollRightTex[];
extern u64 gLinkZoraEyesRollLeftTex[];
extern u64 gLinkZoraEyesRollUpTex[];
extern u64 gLinkZoraEyesRollDownTex[];
extern u64 object_link_zora_Tex_003800[];

TexturePtr sZoraEyesTextures[PLAYER_EYES_MAX] = {
    gLinkZoraEyesOpenTex,        // PLAYER_EYES_OPEN
    gLinkZoraEyesHalfTex,        // PLAYER_EYES_HALF
    gLinkZoraEyesClosedTex,      // PLAYER_EYES_CLOSED
    gLinkZoraEyesRollRightTex,   // PLAYER_EYES_ROLL_RIGHT
    gLinkZoraEyesRollLeftTex,    // PLAYER_EYES_ROLL_LEFT
    gLinkZoraEyesRollUpTex,      // PLAYER_EYES_ROLL_UP
    gLinkZoraEyesRollDownTex,    // PLAYER_EYES_ROLL_DOWN
    object_link_zora_Tex_003800, // PLAYER_EYES_7
};

extern u64 gLinkZoraMouthClosedTex[];
extern u64 object_link_zora_Tex_004400[];
extern u64 gLinkZoraMouthAngryTex[];
extern u64 gLinkZoraMouthHappyTex[];

TexturePtr sZoraMouthTextures[PLAYER_MOUTH_MAX] = {
    gLinkZoraMouthClosedTex,        // PLAYER_MOUTH_CLOSED
    object_link_zora_Tex_004400,    // PLAYER_MOUTH_TEETH
    gLinkZoraMouthAngryTex,         // PLAYER_MOUTH_ANGRY
    gLinkZoraMouthHappyTex,         // PLAYER_MOUTH_HAPPY
};

extern PlayerAgeProperties sPlayerAgeProperties[PLAYER_FORM_MAX];
static PlayerAgeProperties savedAgeProperties[2];

void updateLink(PlayState* play);

RECOMP_HOOK("Player_Init")
void setSavedAgeProperties(Actor* thisx, PlayState* play) {
    LinkType type = recomp_get_config_u32("link_type");
    PlayerAgeProperties adultProperties;
    
    if (savedAgeProperties[type].ceilingCheckHeight == 0) {
        switch (type) {
            case LINK_TYPE_CHILD:
                savedAgeProperties[LINK_TYPE_CHILD] = sPlayerAgeProperties[PLAYER_FORM_HUMAN];
                break;
            case LINK_TYPE_ADULT:
                adultProperties = sPlayerAgeProperties[PLAYER_FORM_ZORA];
                adultProperties.unk_28 = 44.8f;
                adultProperties.unk_3C = 15.0f;
                adultProperties.unk_44 = sPlayerAgeProperties[PLAYER_FORM_FIERCE_DEITY].unk_44;
                adultProperties.unk_4A->x = sPlayerAgeProperties[PLAYER_FORM_FIERCE_DEITY].unk_4A->x;
                adultProperties.unk_4A->y = sPlayerAgeProperties[PLAYER_FORM_FIERCE_DEITY].unk_4A->y;
                adultProperties.unk_4A->z = sPlayerAgeProperties[PLAYER_FORM_FIERCE_DEITY].unk_4A->z;
                adultProperties.unk_62->x = sPlayerAgeProperties[PLAYER_FORM_FIERCE_DEITY].unk_62->x;
                adultProperties.unk_62->y = sPlayerAgeProperties[PLAYER_FORM_FIERCE_DEITY].unk_62->y;
                adultProperties.unk_62->z = sPlayerAgeProperties[PLAYER_FORM_FIERCE_DEITY].unk_62->z;
                adultProperties.unk_7A->x = sPlayerAgeProperties[PLAYER_FORM_FIERCE_DEITY].unk_7A->x;
                adultProperties.unk_7A->y = sPlayerAgeProperties[PLAYER_FORM_FIERCE_DEITY].unk_7A->y;
                adultProperties.unk_7A->z = sPlayerAgeProperties[PLAYER_FORM_FIERCE_DEITY].unk_7A->z;
                adultProperties.voiceSfxIdOffset = SFX_VOICE_BANK_SIZE * 0;
                adultProperties.surfaceSfxIdOffset = 0x80;
                savedAgeProperties[LINK_TYPE_ADULT] = adultProperties;
                break;
        }
    }

    updateLink(play);
}

void updateLink(PlayState* play) {
    Player* player = GET_PLAYER(play);

    LinkType type = recomp_get_config_u32("link_type");

    // so much needs to be replaced...
    switch (type) {
        case LINK_TYPE_CHILD:
            gPlayerSkeletons[PLAYER_FORM_HUMAN] = &gLinkChildSkel;

            gPlayerWaistDLs[PLAYER_FORM_HUMAN * 2 + 0] = gLinkChildWaistNearDL;
            gPlayerWaistDLs[PLAYER_FORM_HUMAN * 2 + 1] = gLinkChildWaistFarDL;

            gPlayerRightHandOpenDLs[PLAYER_FORM_HUMAN * 2 + 0] = gLinkChildRightHandNearDL;
            gPlayerRightHandOpenDLs[PLAYER_FORM_HUMAN * 2 + 1] = gLinkChildRightHandFarDL;
            gPlayerRightHandClosedDLs[PLAYER_FORM_HUMAN * 2 + 0] = gLinkChildRightHandClosedNearDL;
            gPlayerRightHandClosedDLs[PLAYER_FORM_HUMAN * 2 + 1] = gLinkChildRightHandClosedFarDL;
            gPlayerRightHandBowDLs[PLAYER_FORM_HUMAN * 2 + 0] = gLinkChildRightHandHoldingBowDL;
            gPlayerRightHandBowDLs[PLAYER_FORM_HUMAN * 2 + 1] = gLinkChildRightHandHoldingBowDL;
            // gPlayerRightHandInstrumentDLs[PLAYER_FORM_HUMAN * 2 + 0] = gLinkChildRightHandHoldingFairyOcarinaNearDL;
            // gPlayerRightHandInstrumentDLs[PLAYER_FORM_HUMAN * 2 + 1] = gLinkChildRightHandHoldingFairyOcarinaFarDL;
            gPlayerRightHandInstrumentDLs[PLAYER_FORM_HUMAN * 2 + 0] = gLinkChildRightHandAndOotNearDL;
            gPlayerRightHandInstrumentDLs[PLAYER_FORM_HUMAN * 2 + 1] = gLinkChildRightHandHoldingOOTFarDL;
            gPlayerRightHandHookshotDLs[PLAYER_FORM_HUMAN * 2 + 0] = gLinkHumanRightHandHoldingHookshotDL;
            gPlayerRightHandHookshotDLs[PLAYER_FORM_HUMAN * 2 + 1] = gLinkHumanRightHandHoldingHookshotDL;
            
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

            // its easier to use the normal models for this atm
            // sPlayerFirstPersonLeftForearmDLs[PLAYER_FORM_HUMAN] = gLinkChildLeftForearmNearDL;
            // sPlayerFirstPersonLeftHandDLs[PLAYER_FORM_HUMAN] = gLinkChildLeftFistNearDL;
            // sPlayerFirstPersonRightShoulderDLs[PLAYER_FORM_HUMAN] = gLinkChildRightShoulderNearDL;
            // sPlayerFirstPersonRightHandDLs[PLAYER_FORM_HUMAN] = gLinkChildRightHandClosedNearDL;
            // sPlayerFirstPersonRightHandHookshotDLs[PLAYER_FORM_HUMAN] = gLinkChildRightHandClosedNearDL;

            gPlayerHandHoldingShields[(PLAYER_SHIELD_HEROS_SHIELD - 1) * 2 + 0] = gLinkChildRightHandHoldingHerosShieldDL;
            gPlayerHandHoldingShields[(PLAYER_SHIELD_HEROS_SHIELD - 1) * 2 + 1] = gLinkChildRightHandHoldingHerosShieldDL;
            gPlayerHandHoldingShields[(PLAYER_SHIELD_MIRROR_SHIELD - 1) * 2 + 0] = gLinkChildRightHandHoldingMirrorShieldDL;
            gPlayerHandHoldingShields[(PLAYER_SHIELD_MIRROR_SHIELD - 1) * 2 + 1] = gLinkChildRightHandHoldingMirrorShieldDL;

            D_801C018C[(EQUIP_VALUE_SWORD_KOKIRI - 1) * 2 + 0] = gLinkChildLeftHandHoldingKokiriSwordDL;
            D_801C018C[(EQUIP_VALUE_SWORD_KOKIRI - 1) * 2 + 1] = gLinkChildLeftHandHoldingKokiriSwordDL;
            D_801C018C[(EQUIP_VALUE_SWORD_RAZOR - 1) * 2 + 0] = gLinkChildLeftHandHoldingRazorSwordDL;
            D_801C018C[(EQUIP_VALUE_SWORD_RAZOR - 1) * 2 + 1] = gLinkChildLeftHandHoldingRazorSwordDL;
            D_801C018C[(EQUIP_VALUE_SWORD_GILDED - 1) * 2 + 0] = gLinkChildLeftHandHoldingGildedSwordDL;
            D_801C018C[(EQUIP_VALUE_SWORD_GILDED - 1) * 2 + 1] = gLinkChildLeftHandHoldingGildedSwordDL;

            sPlayerAgeProperties[PLAYER_FORM_HUMAN] = savedAgeProperties[LINK_TYPE_CHILD];
            player->ageProperties = &savedAgeProperties[LINK_TYPE_CHILD];
            break;
        case LINK_TYPE_ADULT:
            gPlayerSkeletons[PLAYER_FORM_HUMAN] = &gLinkAdultSkel;
            gPlayerWaistDLs[PLAYER_FORM_HUMAN * 2 + 0] = gLinkAdultWaistNearDL;
            gPlayerWaistDLs[PLAYER_FORM_HUMAN * 2 + 1] = gLinkAdultWaistFarDL;

            gPlayerRightHandOpenDLs[PLAYER_FORM_HUMAN * 2 + 0] = gLinkAdultRightHandNearDL;
            gPlayerRightHandOpenDLs[PLAYER_FORM_HUMAN * 2 + 1] = gLinkAdultRightHandFarDL;
            gPlayerRightHandClosedDLs[PLAYER_FORM_HUMAN * 2 + 0] = gLinkAdultRightHandClosedNearDL;
            gPlayerRightHandClosedDLs[PLAYER_FORM_HUMAN * 2 + 1] = gLinkAdultRightHandClosedFarDL;
            // gPlayerRightHandBowDLs[PLAYER_FORM_HUMAN * 2 + 0] = gLinkAdultRightHandHoldingBowNearDL;
            // gPlayerRightHandBowDLs[PLAYER_FORM_HUMAN * 2 + 1] = gLinkAdultRightHandHoldingBowFarDL;
            gPlayerRightHandBowDLs[PLAYER_FORM_HUMAN * 2 + 0] = gLinkAdultRightHandHoldingBowDL;
            gPlayerRightHandBowDLs[PLAYER_FORM_HUMAN * 2 + 1] = gLinkAdultRightHandHoldingBowDL;
            gPlayerRightHandInstrumentDLs[PLAYER_FORM_HUMAN * 2 + 0] = gLinkAdultRightHandHoldingOotNearDL;
            gPlayerRightHandInstrumentDLs[PLAYER_FORM_HUMAN * 2 + 1] = gLinkAdultRightHandHoldingOotFarDL;
            gPlayerRightHandHookshotDLs[PLAYER_FORM_HUMAN * 2 + 0] = gLinkAdultRightHandHoldingHookshotDL;
            gPlayerRightHandHookshotDLs[PLAYER_FORM_HUMAN * 2 + 1] = gLinkAdultRightHandHoldingHookshotDL;
            
            gPlayerLeftHandOpenDLs[PLAYER_FORM_HUMAN * 2 + 0] = gLinkAdultLeftHandNearDL;
            gPlayerLeftHandOpenDLs[PLAYER_FORM_HUMAN * 2 + 1] = gLinkAdultLeftHandFarDL;
            gPlayerLeftHandClosedDLs[PLAYER_FORM_HUMAN * 2 + 0] = gLinkAdultLeftHandClosedNearDL;
            gPlayerLeftHandClosedDLs[PLAYER_FORM_HUMAN * 2 + 1] = gLinkAdultLeftHandClosedFarDL;
            // gPlayerLeftHandTwoHandSwordDLs[PLAYER_FORM_HUMAN * 2 + 0] = gLinkAdultLeftHandHoldingBgsNearDL;
            // gPlayerLeftHandTwoHandSwordDLs[PLAYER_FORM_HUMAN * 2 + 1] = gLinkAdultLeftHandHoldingBgsFarDL;
            gPlayerLeftHandTwoHandSwordDLs[PLAYER_FORM_HUMAN * 2 + 0] = gLinkAdultLeftHandHoldingGreatFairysSwordDL;
            gPlayerLeftHandTwoHandSwordDLs[PLAYER_FORM_HUMAN * 2 + 1] = gLinkAdultLeftHandHoldingGreatFairysSwordDL;
            gPlayerLeftHandOneHandSwordDLs[PLAYER_FORM_HUMAN * 2 + 0] = gLinkAdultLeftHandHoldingMasterSwordNearDL;
            gPlayerLeftHandOneHandSwordDLs[PLAYER_FORM_HUMAN * 2 + 1] = gLinkAdultLeftHandHoldingMasterSwordFarDL;
            gPlayerLeftHandBottleDLs[PLAYER_FORM_HUMAN * 2 + 0] = gLinkAdultLeftHandOutNearDL;
            gPlayerLeftHandBottleDLs[PLAYER_FORM_HUMAN * 2 + 1] = gLinkAdultLeftHandOutNearDL;

            // its easier to use the normal models for this atm
            // sPlayerFirstPersonLeftForearmDLs[PLAYER_FORM_HUMAN] = gLinkAdultLeftArmOutNearDL; // oot uses right???
            // sPlayerFirstPersonLeftHandDLs[PLAYER_FORM_HUMAN] = gLinkAdultLeftHandClosedNearDL; // why is oot backwards
            // sPlayerFirstPersonRightShoulderDLs[PLAYER_FORM_HUMAN] = gLinkAdultRightShoulderNearDL;
            // sPlayerFirstPersonRightHandDLs[PLAYER_FORM_HUMAN] = gLinkAdultRightHandOutNearDL;
            // sPlayerFirstPersonRightHandHookshotDLs[PLAYER_FORM_HUMAN] = gLinkAdultRightHandHoldingHookshotNearDL;

            gPlayerHandHoldingShields[(PLAYER_SHIELD_HEROS_SHIELD - 1) * 2 + 0] = gLinkAdultRightHandHoldingHerosShieldDL;
            gPlayerHandHoldingShields[(PLAYER_SHIELD_HEROS_SHIELD - 1) * 2 + 1] = gLinkAdultRightHandHoldingHerosShieldDL;
            gPlayerHandHoldingShields[(PLAYER_SHIELD_MIRROR_SHIELD - 1) * 2 + 0] = gLinkAdultRightHandHoldingMirrorShieldDL;
            gPlayerHandHoldingShields[(PLAYER_SHIELD_MIRROR_SHIELD - 1) * 2 + 1] = gLinkAdultRightHandHoldingMirrorShieldDL;

            D_801C018C[(EQUIP_VALUE_SWORD_KOKIRI - 1) * 2 + 0] = gLinkAdultLeftHandHoldingKokiriSwordDL;
            D_801C018C[(EQUIP_VALUE_SWORD_KOKIRI - 1) * 2 + 1] = gLinkAdultLeftHandHoldingKokiriSwordDL;
            D_801C018C[(EQUIP_VALUE_SWORD_RAZOR - 1) * 2 + 0] = gLinkAdultLeftHandHoldingRazorSwordDL;
            D_801C018C[(EQUIP_VALUE_SWORD_RAZOR - 1) * 2 + 1] = gLinkAdultLeftHandHoldingRazorSwordDL;
            D_801C018C[(EQUIP_VALUE_SWORD_GILDED - 1) * 2 + 0] = gLinkAdultLeftHandHoldingGildedSwordDL;
            D_801C018C[(EQUIP_VALUE_SWORD_GILDED - 1) * 2 + 1] = gLinkAdultLeftHandHoldingGildedSwordDL;
            break;
    }

    switch (player->transformation) {
        case PLAYER_FORM_HUMAN:
            sPlayerAgeProperties[PLAYER_FORM_HUMAN] = savedAgeProperties[type];
            player->ageProperties = &savedAgeProperties[type];
            for (int i = 0; i < PLAYER_MOUTH_MAX; i++) {
                sPlayerMouthTextures[i] = sMouthTextures[type][i];
            }
            for (int i = 0; i < PLAYER_EYES_MAX; i++) {
                sPlayerEyesTextures[i] = sEyeTextures[type][i];
            }
            break;
        case PLAYER_FORM_ZORA:
            for (int i = 0; i < PLAYER_MOUTH_MAX; i++) {
                sPlayerMouthTextures[i] = sZoraMouthTextures[i];
            }
            for (int i = 0; i < PLAYER_EYES_MAX; i++) {
                sPlayerEyesTextures[i] = sZoraEyesTextures[i];
            }
        case PLAYER_FORM_GORON:
            for (int i = 0; i < PLAYER_EYES_MAX; i++) {
                sPlayerEyesTextures[i] = sGoronEyesTextures[i];
            }
        default:
            break;
    }
}

RECOMP_CALLBACK("*", recomp_on_play_main)
void mainUpdate(PlayState* play) {
    updateLink(play);
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

RECOMP_PATCH f32 Player_GetHeight(Player* player) {
    f32 extraHeight;

    if (player->stateFlags1 & PLAYER_STATE1_800000) {
        extraHeight = 32.0f;
    } else {
        extraHeight = 0.0f;
    }

    switch (player->transformation) {
        default:
        case PLAYER_FORM_FIERCE_DEITY:
            return extraHeight + 124.0f;

        case PLAYER_FORM_GORON:
            return extraHeight + ((player->stateFlags3 & PLAYER_STATE3_1000) ? 34.0f : 80.0f);

        case PLAYER_FORM_ZORA:
            return extraHeight + 68.0f;

        case PLAYER_FORM_DEKU:
            return extraHeight + 36.0f;

        case PLAYER_FORM_HUMAN:
            if (recomp_get_config_u32("link_type")) {
                return extraHeight + 68.0f;
            }
            return extraHeight + 44.0f;
    }
}
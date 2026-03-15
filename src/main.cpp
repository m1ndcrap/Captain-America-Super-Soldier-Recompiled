// captainamericasupersoldier - ReXGlue Recompiled Project
//
// This file is yours to edit. 'rexglue migrate' will NOT overwrite it.

#include "generated/captainamericasupersoldier_config.h"
#include "generated/captainamericasupersoldier_init.h"

#include "captainamericasupersoldier_app.h"

#include <float.h>

void MaskFPUExceptions() {
    _clearfp();
    _controlfp_s(nullptr, _MCW_EM, _MCW_EM);
}

REX_DEFINE_APP(captainamericasupersoldier, CaptainamericasupersoldierApp::Create)

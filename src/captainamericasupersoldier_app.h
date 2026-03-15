// captainamericasupersoldier - ReXGlue Recompiled Project
//
// This file is yours to edit. 'rexglue migrate' will NOT overwrite it.
// Customize your app by overriding virtual hooks from rex::ReXApp.

#pragma once

#include <rex/rex_app.h>
#include <rex/graphics/flags.h>
#include <windows.h>
#include <float.h>

inline LONG WINAPI VectoredFPExceptionHandler(PEXCEPTION_POINTERS pExceptionInfo)
{
    if (pExceptionInfo->ExceptionRecord->ExceptionCode == EXCEPTION_FLT_INEXACT_RESULT ||
        pExceptionInfo->ExceptionRecord->ExceptionCode == EXCEPTION_FLT_DENORMAL_OPERAND ||
        pExceptionInfo->ExceptionRecord->ExceptionCode == EXCEPTION_FLT_UNDERFLOW ||
        pExceptionInfo->ExceptionRecord->ExceptionCode == EXCEPTION_FLT_OVERFLOW ||
        pExceptionInfo->ExceptionRecord->ExceptionCode == EXCEPTION_FLT_DIVIDE_BY_ZERO ||
        pExceptionInfo->ExceptionRecord->ExceptionCode == EXCEPTION_FLT_INVALID_OPERATION ||
        pExceptionInfo->ExceptionRecord->ExceptionCode == EXCEPTION_FLT_STACK_CHECK)
    {
        pExceptionInfo->ContextRecord->MxCsr |= 0x8D80; // mask all SSE FP exceptions
        pExceptionInfo->ContextRecord->MxCsr &= ~0x003F; // clear pending flags
        _clearfp();
        return EXCEPTION_CONTINUE_EXECUTION;
    }
    return EXCEPTION_CONTINUE_SEARCH;
}

class CaptainamericasupersoldierApp : public rex::ReXApp
{
public:
  using rex::ReXApp::ReXApp;

  static std::unique_ptr<rex::ui::WindowedApp> Create(
      rex::ui::WindowedAppContext &ctx)
  {
    return std::unique_ptr<CaptainamericasupersoldierApp>(new CaptainamericasupersoldierApp(ctx, "captainamericasupersoldier",
                                                                                            PPCImageConfig));
  }

  void OnPreSetup(rex::RuntimeConfig& config) override
  {
      REXCVAR_SET(gpu_allow_invalid_fetch_constants, true);
      REXCVAR_SET(d3d12_submit_on_primary_buffer_end, true);
      _clearfp();
      _controlfp_s(nullptr, _MCW_EM, _MCW_EM);
      AddVectoredExceptionHandler(1, VectoredFPExceptionHandler);
  }

  // Override virtual hooks for customization:
  // void OnPostSetup() override {}
  // void OnCreateDialogs(rex::ui::ImGuiDrawer* drawer) override {}
  // void OnShutdown() override {}
  // void OnConfigurePaths(rex::PathConfig& paths) override {}
};

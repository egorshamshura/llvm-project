#include "MCTargetDesc/EmberInfo.h"
#include "Ember.h"
#include "TargetInfo/EmberTargetInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "EmberGenRegisterInfo.inc"

#define GET_INSTRINFO_MC_DESC
#include "EmberGenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "EmberGenSubtargetInfo.inc"

static MCRegisterInfo *createEmberMCRegisterInfo(const Triple &TT) {
  EMBER_DUMP_MAGENTA
  unsigned RA = (TT.getArch() == Triple::x86_64)
                    ? Ember::R0
                    : Ember::RH0;
  MCRegisterInfo *X = new MCRegisterInfo();
  InitEmberMCRegisterInfo(X, RA);
  return X;
}

static MCInstrInfo *createEmberMCInstrInfo() {
  EMBER_DUMP_MAGENTA
  MCInstrInfo *X = new MCInstrInfo();
  InitEmberMCInstrInfo(X);
  return X;
}

static MCSubtargetInfo *createEmberMCSubtargetInfo(const Triple &TT,
                                                  StringRef CPU, StringRef FS) {
  EMBER_DUMP_MAGENTA
  return createEmberMCSubtargetInfoImpl(TT, CPU, CPU, FS);
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeEmberTargetMC() {
  EMBER_DUMP_MAGENTA
  for (Target* target: {&getTheEmber32Target(), &getTheEmber64Target()}) {
    TargetRegistry::RegisterMCRegInfo(*target, createEmberMCRegisterInfo);
    TargetRegistry::RegisterMCInstrInfo(*target, createEmberMCInstrInfo);
    TargetRegistry::RegisterMCSubtargetInfo(*target, createEmberMCSubtargetInfo);
  }
  // Register the MC register info.
}

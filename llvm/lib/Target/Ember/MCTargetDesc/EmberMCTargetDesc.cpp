#include "MCTargetDesc/EmberInfo.h"
#include "Ember.h"
#include "EmberMCAsmInfo.h"
#include "TargetInfo/EmberTargetInfo.h"
#include "llvm/MC/MCDwarf.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/ErrorHandling.h"

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

static MCAsmInfo *createEmberMCAsmInfo(const MCRegisterInfo &MRI,
                                    const Triple &TT,
                                    const MCTargetOptions &Options) {
  EMBER_DUMP_MAGENTA
  MCAsmInfo *MAI = new EmberELFMCAsmInfo(TT);
  unsigned SP = MRI.getDwarfRegNum(((TT.getArch() == Triple::x86_64)
                    ? Ember::R1
                    : Ember::RH1), true);
  MCCFIInstruction Inst = MCCFIInstruction::cfiDefCfa(nullptr, SP, 0);
  MAI->addInitialFrameState(Inst);
  return MAI;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeEmberTargetMC() {
  EMBER_DUMP_MAGENTA
  for (Target* target: {&getTheEmber32Target(), &getTheEmber64Target()}) {
    TargetRegistry::RegisterMCAsmInfo(*target, createEmberMCAsmInfo);
    TargetRegistry::RegisterMCRegInfo(*target, createEmberMCRegisterInfo);
    TargetRegistry::RegisterMCInstrInfo(*target, createEmberMCInstrInfo);
    TargetRegistry::RegisterMCSubtargetInfo(*target, createEmberMCSubtargetInfo);
  }
  // Register the MC register info.
}

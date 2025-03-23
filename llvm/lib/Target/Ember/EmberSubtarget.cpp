#include "EmberSubtarget.h"
#include "Ember.h"
#include "llvm/Target/TargetMachine.h"

using namespace llvm;

#define DEBUG_TYPE "ember-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "EmberGenSubtargetInfo.inc"

EmberSubtarget::EmberSubtarget(const Triple &TT, const std::string &CPU,
  const std::string &FS, const TargetMachine &TM)
  : EmberGenSubtargetInfo(TT, CPU, /*TuneCPU=*/CPU, FS), TLInfo(TM, *this) {
  EMBER_DUMP_CYAN
}
#include "EmberSubtarget.h"
#include "Ember.h"
#include "llvm/Target/TargetMachine.h"

using namespace llvm;

#define DEBUG_TYPE "ember-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "EmberGenSubtargetInfo.inc"

EmberSubtarget::EmberSubtarget(const StringRef &CPU, const StringRef &TuneCPU,
                          const StringRef &FS, const TargetMachine &TM)
    : EmberGenSubtargetInfo(TM.getTargetTriple(), CPU, TuneCPU, FS) {
  EMBER_DUMP_CYAN
}
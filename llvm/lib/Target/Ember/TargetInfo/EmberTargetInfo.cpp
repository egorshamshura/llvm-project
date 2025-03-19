#include "TargetInfo/EmberTargetInfo.h"
#include "Ember.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

Target &llvm::getTheEmberTarget() {
EMBER_DUMP_YELLOW
static Target TheEmberTarget;
return TheEmberTarget;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeEmberTargetInfo() {
EMBER_DUMP_YELLOW
RegisterTarget<Triple::ember> X(getTheEmberTarget(), "ember",
                                "Target for LLVM course", "Ember");
}
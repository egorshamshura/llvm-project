#include "TargetInfo/EmberTargetInfo.h"
#include "Ember.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

Target &llvm::getTheEmber32Target() {
EMBER_DUMP_YELLOW
static Target TheEmber32Target;
return TheEmber32Target;
}

Target &llvm::getTheEmber64Target() {
EMBER_DUMP_YELLOW
static Target TheEmber64Target;
return TheEmber64Target;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeEmberTargetInfo() {
EMBER_DUMP_YELLOW
RegisterTarget<Triple::ember32> X(getTheEmber32Target(), "ember32",
                                "Target for LLVM course 32-bit", "Ember32");
RegisterTarget<Triple::ember64> Y(getTheEmber64Target(), "ember64",
                                "Target for LLVM course 64-bit", "Ember64");
}
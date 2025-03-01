#include "TargetInfo/SimTargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
using namespace llvm;

Target &llvm::getTheSimTarget() {
  static Target TheSimTarget;
  return TheSimTarget;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeSimTargetInfo() {
  RegisterTarget<Triple::sim> X(getTheSimTarget(), "sim", "Sim 32",
                                   "SIM");
}
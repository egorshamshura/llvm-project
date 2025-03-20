#ifndef LLVM_LIB_TARGET_EMBER_TARGETINFO_EMBERTARGETINFO_H
#define LLVM_LIB_TARGET_EMBER_TARGETINFO_EMBERTARGETINFO_H

namespace llvm {

class Target;

Target &getTheEmber32Target();
Target &getTheEmber64Target();

} // end namespace llvm

#endif // LLVM_LIB_TARGET_EMBER_TARGETINFO_EMBERTARGETINFO_H
#ifndef LLVM_LIB_TARGET_EMBER_MCTARGETDESC_EMBERMCASMINFO_H
#define LLVM_LIB_TARGET_EMBER_MCTARGETDESC_EMBERMCASMINFO_H

#include "llvm/MC/MCAsmInfoELF.h"

namespace llvm {

class Triple;

class EmberELFMCAsmInfo : public MCAsmInfoELF {
public:
  explicit EmberELFMCAsmInfo(const Triple &TheTriple);
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_EMBER_MCTARGETDESC_EMBERMCASMINFO_H
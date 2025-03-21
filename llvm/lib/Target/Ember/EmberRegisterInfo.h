#ifndef LLVM_LIB_TARGET_EMBER_EMBERREGISTERINFO_H
#define LLVM_LIB_TARGET_EMBER_EMBERREGISTERINFO_H

#define GET_REGINFO_HEADER
#include "EmberGenRegisterInfo.inc"

namespace llvm {
class Triple;

struct EmberRegisterInfo final : public EmberGenRegisterInfo {
private:
  /// Is64Bit - Is the target 64-bits.
  bool Is64Bit;
public:
  explicit EmberRegisterInfo(const Triple &TT);
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_EMBER_EMBERREGISTERINFO_H
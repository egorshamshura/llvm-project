#ifndef LLVM_LIB_TARGET_EMBER_EMBERREGISTERINFO_H
#define LLVM_LIB_TARGET_EMBER_EMBERREGISTERINFO_H

#define GET_REGINFO_HEADER
#include "EmberGenRegisterInfo.inc"

namespace llvm {
class Triple;
class TargetInstrInfo;
class EmberSubtarget;

struct EmberRegisterInfo final : public EmberGenRegisterInfo {
private:
  /// Is64Bit - Is the target 64-bits.
  bool Is64Bit;
public:
  explicit EmberRegisterInfo(const Triple &TT);


  const MCPhysReg *getCalleeSavedRegs(const MachineFunction *MF) const override;
 
  const uint32_t *getCallPreservedMask(const MachineFunction &MF,
                                       CallingConv::ID CC) const override;

  BitVector getReservedRegs(const MachineFunction &MF) const override;

  bool requiresRegisterScavenging(const MachineFunction &MF) const override;

  bool eliminateFrameIndex(MachineBasicBlock::iterator II, int SPAdj,
                           unsigned FIOperandNum,
                           RegScavenger *RS = nullptr) const override;

  Register getFrameRegister(const MachineFunction &MF) const override;
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_EMBER_EMBERREGISTERINFO_H
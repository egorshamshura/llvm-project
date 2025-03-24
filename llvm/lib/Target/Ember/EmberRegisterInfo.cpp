#include "EmberRegisterInfo.h"
#include "Ember.h"
#include "EmberFrameLowering.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

using namespace llvm;

#define GET_REGINFO_TARGET_DESC
#include "EmberGenRegisterInfo.inc"

EmberRegisterInfo::EmberRegisterInfo(const Triple &TT) : EmberGenRegisterInfo((TT.isArch64Bit() ? Ember::R0 : Ember::RH0)) {
  EMBER_DUMP_GREEN
  Is64Bit = TT.isArch64Bit();
  llvm::outs() << Is64Bit << '\n';
}

const MCPhysReg *
EmberRegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  EMBER_DUMP_GREEN
  return Is64Bit ? CSR_Ember64_SaveList : CSR_Ember32_SaveList;
}

BitVector EmberRegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  EMBER_DUMP_GREEN
  EmberFrameLowering const *TFI = getFrameLowering(MF);

  BitVector Reserved(getNumRegs());
  Reserved.set(Is64Bit ? Ember::R1 : Ember::RH1);

  if (TFI->hasFP(MF)) {
    Reserved.set(Is64Bit ? Ember::R2 : Ember::RH2);
  }
  return Reserved;
}

bool EmberRegisterInfo::requiresRegisterScavenging(const MachineFunction &MF) const {
  return false;
}

bool EmberRegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator II, int SPAdj, unsigned FIOperandNum, RegScavenger *RS) const {
  EMBER_DUMP_GREEN
  assert(SPAdj == 0 && "Unexpected non-zero SPAdj value");

  MachineInstr &MI = *II;
  MachineFunction &MF = *MI.getParent()->getParent();
  DebugLoc DL = MI.getDebugLoc();

  int FrameIndex = MI.getOperand(FIOperandNum).getIndex();
  Register FrameReg;
  int Offset = getFrameLowering(MF)
                  ->getFrameIndexReference(MF, FrameIndex, FrameReg)
                  .getFixed();
  Offset += MI.getOperand(FIOperandNum + 1).getImm();

  if (!isInt<16>(Offset)) {
    llvm_unreachable("");
  }

  MI.getOperand(FIOperandNum).ChangeToRegister(FrameReg, false, false, false);
  MI.getOperand(FIOperandNum + 1).ChangeToImmediate(Offset);
  return false;
}

Register EmberRegisterInfo::getFrameRegister(const MachineFunction &MF) const {
  EMBER_DUMP_GREEN
  const TargetFrameLowering *TFI = getFrameLowering(MF);
  return TFI->hasFP(MF) ? (Is64Bit ? Ember::R2 : Ember::RH2) : (Is64Bit ? Ember::R1 : Ember::RH1);
}

const uint32_t* EmberRegisterInfo::getCallPreservedMask(const MachineFunction &MF, CallingConv::ID CC) const {
  EMBER_DUMP_GREEN
  return Is64Bit ? CSR_Ember64_RegMask : CSR_Ember32_RegMask;
}
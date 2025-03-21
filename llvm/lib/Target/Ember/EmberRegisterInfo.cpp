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
}
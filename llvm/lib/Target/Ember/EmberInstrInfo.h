#ifndef LLVM_LIB_TARGET_EMBER_EMBERINSTRINFO_H
#define LLVM_LIB_TARGET_EMBER_EMBERINSTRINFO_H

#include "EmberRegisterInfo.h"
#include "MCTargetDesc/EmberInfo.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "EmberGenInstrInfo.inc"

namespace llvm {

class EmberSubtarget;

class EmberInstrInfo : public EmberGenInstrInfo {
public:
  EmberInstrInfo();

};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_EMBER_EMBERINSTRINFO_H
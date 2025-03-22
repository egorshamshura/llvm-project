#ifndef LLVM_LIB_TARGET_EMBER_MCTARGETDESC_EMBERMCTARGETDESC_H
#define LLVM_LIB_TARGET_EMBER_MCTARGETDESC_EMBERMCTARGETDESC_H

// Defines symbolic names for Ember registers.  This defines a mapping from
// register name to register number.
//
#define GET_REGINFO_ENUM
#include "EmberGenRegisterInfo.inc"

#define GET_INSTRINFO_ENUM
#include "EmberGenInstrInfo.inc"

#endif // LLVM_LIB_TARGET_EMBER_MCTARGETDESC_EMBERMCTARGETDESC_H
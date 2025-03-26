#ifndef LLVM_LIB_TARGET_EMBER_MCTARGETDESC_EMBERMCTARGETDESC_H
#define LLVM_LIB_TARGET_EMBER_MCTARGETDESC_EMBERMCTARGETDESC_H

namespace llvm {
class MCCodeEmitter;
class MCContext;
class MCInstrInfo;
class MCAsmBackend;
class MCObjectTargetWriter;
class MCRegisterInfo;
class MCSubtargetInfo;
class MCTargetOptions;
class Target;

MCCodeEmitter *createEmberMCCodeEmitter(const MCInstrInfo &MCII, MCContext &Ctx);
MCAsmBackend *createEmberAsmBackend(const Target &T, const MCSubtargetInfo &STI, const MCRegisterInfo &MRI, const MCTargetOptions &Options);
} // namespace llvm
 

// Defines symbolic names for Ember registers. This defines a mapping from
// register name to register number.
//
#define GET_REGINFO_ENUM
#include "EmberGenRegisterInfo.inc"

#define GET_INSTRINFO_ENUM
#include "EmberGenInstrInfo.inc"

#endif // LLVM_LIB_TARGET_EMBER_MCTARGETDESC_EMBERMCTARGETDESC_H
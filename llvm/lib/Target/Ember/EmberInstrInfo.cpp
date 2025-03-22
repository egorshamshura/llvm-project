#include "EmberInstrInfo.h"
#include "Ember.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineMemOperand.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

#define GET_INSTRINFO_CTOR_DTOR
#include "EmberGenInstrInfo.inc"

#define DEBUG_TYPE "Ember-inst-info"

EmberInstrInfo::EmberInstrInfo() : EmberGenInstrInfo() { EMBER_DUMP_GREEN }
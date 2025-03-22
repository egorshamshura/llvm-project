include "llvm/Target/Target.td"
include "EmberRegisterInfo.td"
include "EmberInstrInfo.td"

def EmberInstrInfo : InstrInfo;
def Ember : Target {
  let InstructionSet = EmberInstrInfo;
}
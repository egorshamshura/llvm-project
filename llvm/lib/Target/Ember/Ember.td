include "llvm/Target/Target.td"
include "EmberRegisterInfo.td"
include "EmberInstrInfo.td"
include "EmberCallingConv.td"

class Proc<string Name, list<SubtargetFeature> Features>
  : Processor<Name, NoItineraries, Features>;

def : Proc<"generic", []>;

def EmberInstrInfo : InstrInfo;
def Ember : Target {
  let InstructionSet = EmberInstrInfo;
}
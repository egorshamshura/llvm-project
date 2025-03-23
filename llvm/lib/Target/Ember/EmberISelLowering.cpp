#include "EmberISelLowering.h"
#include "Ember.h"
#include "EmberRegisterInfo.h"
#include "EmberSubtarget.h"
#include "llvm/CodeGen/CallingConvLower.h"
#include "llvm/CodeGen/MachineFunction.h"

#define DEBUG_TYPE "Sim-lower"

using namespace llvm;

EmberTargetLowering::EmberTargetLowering(const TargetMachine &TM,
                                    const EmberSubtarget &STI)
    : TargetLowering(TM), STI(STI) {
    EMBER_DUMP_RED
    addRegisterClass(MVT::i32, &Ember::GPR32RegClass);
    addRegisterClass(MVT::i64, &Ember::GPR64RegClass);
}

const char *EmberTargetLowering::getTargetNodeName(unsigned Opcode) const {
    EMBER_DUMP_RED
    switch (Opcode) {
    case EmberISD::CALL:
        return "EmberISD::CALL";
    case EmberISD::RET:
        return "EmberISD::RET";
    }
    return nullptr;
}
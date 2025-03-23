#ifndef LLVM_LIB_TARGET_EMBER_EMBERISELLOWERING_H
#define LLVM_LIB_TARGET_EMBER_EMBERISELLOWERING_H

#include "Ember.h"
#include "llvm/CodeGen/SelectionDAG.h"
#include "llvm/CodeGen/TargetLowering.h"

namespace llvm {

class EmberSubtarget;
class EmberTargetMachine;

namespace EmberISD {

enum NodeType : unsigned {
// Start the numbering where the builtin ops and target ops leave off.
    FIRST_NUMBER = ISD::BUILTIN_OP_END,
    RET,
    CALL,
    BR_CC,
};

} // namespace EmberISD

class EmberTargetLowering : public TargetLowering {
public:
    explicit EmberTargetLowering(const TargetMachine &TM, const EmberSubtarget &STI);

    /// This method returns the name of a target specific DAG node.
    const char *getTargetNodeName(unsigned Opcode) const override;

    EmberSubtarget const &getSubtarget() const { return STI; }

private:
    const EmberSubtarget &STI;
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_EMBER_EMBERISELLOWERING_H
#ifndef LLVM_LIB_TARGET_EMBER_MCTARGETDESC_SIMINFO_H
#define LLVM_LIB_TARGET_EMBER_MCTARGETDESC_SIMINFO_H

#include "llvm/MC/MCInstrDesc.h"

namespace llvm {

namespace EmberOp {
enum OperandType : unsigned {
  OPERAND_SIMM16 = MCOI::OPERAND_FIRST_TARGET,
};
} // namespace EmberOp

} // end namespace llvm

#endif
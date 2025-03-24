#ifndef LLVM_LIB_TARGET_Ember_Ember_H
#define LLVM_LIB_TARGET_Ember_Ember_H

#include "MCTargetDesc/EmberMCTargetDesc.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetMachine.h"

#define EMBER_DUMP(Color)                                                        \
{                                                                            \
    llvm::errs().changeColor(Color)                                            \
        << __func__ << "\n\t\t" << __FILE__ << ":" << __LINE__ << "\n";        \
    llvm::errs().changeColor(llvm::raw_ostream::WHITE);                        \
}
// #define EMBER_DUMP(Color) {}

#define EMBER_DUMP_RED EMBER_DUMP(llvm::raw_ostream::RED)
#define EMBER_DUMP_GREEN EMBER_DUMP(llvm::raw_ostream::GREEN)
#define EMBER_DUMP_YELLOW EMBER_DUMP(llvm::raw_ostream::YELLOW)
#define EMBER_DUMP_CYAN EMBER_DUMP(llvm::raw_ostream::CYAN)
#define EMBER_DUMP_MAGENTA EMBER_DUMP(llvm::raw_ostream::MAGENTA)
#define EMBER_DUMP_WHITE EMBER_DUMP(llvm::raw_ostream::WHITE)

namespace llvm {
class EmberTargetMachine;
class FunctionPass;
class EmberSubtarget;
class AsmPrinter;
class InstructionSelector;
class MCInst;
class MCOperand;
class MachineInstr;
class MachineOperand;
class PassRegistry;

FunctionPass *createEmberISelDag(EmberTargetMachine &TM, CodeGenOptLevel OptLevel);


bool lowerEmberMachineInstrToMCInst(const MachineInstr *MI, MCInst &OutMI, AsmPrinter &AP);
bool LowerEmberMachineOperandToMCOperand(const MachineOperand &MO, MCOperand &MCOp, const AsmPrinter &AP);

} // namespace llvm

#endif // LLVM_LIB_TARGET_Ember_Ember_H
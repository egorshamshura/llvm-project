//===----------------------------------------------------------------------===//
// Ember profiles and nodes
//===----------------------------------------------------------------------===//

def ember32_ret      : SDNode<"EmberISD::RET32", SDTNone,
                            [SDNPHasChain, SDNPOptInGlue, SDNPVariadic]>;

def ember64_ret      : SDNode<"EmberISD::RET64", SDTNone,
                            [SDNPHasChain, SDNPOptInGlue, SDNPVariadic]>;

//===----------------------------------------------------------------------===//
// Instruction format superclass
//===----------------------------------------------------------------------===//

include "EmberInstrFormats.td"

//===----------------------------------------------------------------------===//
// Ember Operand, Complex Patterns and Transformations Definitions.
//===----------------------------------------------------------------------===//

class SImmAsmOperand<int width> : AsmOperandClass {
  let Name = "SImm" # width;
  let RenderMethod = "addImmOperands";
  let DiagnosticType = !strconcat("Invalid", Name);
}

def simm8 : Operand<i32>, ImmLeaf<i32, [{return isInt<8>(Imm);}]> {
  let ParserMatchClass = SImmAsmOperand<8>;
  let EncoderMethod = "getSImm8OpValue";
  let DecoderMethod = "decodeSImmOperand<8>";
  let MCOperandPredicate = [{
    int32_t Imm;
    if (MCOp.evaluateAsConstantImm(Imm))
      return isInt<8>(Imm);
    return MCOp.isBareSymbolRef();
  }];
  let OperandType = "OPERAND_SIMM8";
  let OperandNamespace = "EmberOp";
}

def simm16 : Operand<i64>, ImmLeaf<i64, [{return isInt<16>(Imm);}]> {
  let ParserMatchClass = SImmAsmOperand<16>;
  let EncoderMethod = "getSImm16OpValue";
  let DecoderMethod = "decodeSImmOperand<16>";
  let MCOperandPredicate = [{
    int64_t Imm;
    if (MCOp.evaluateAsConstantImm(Imm))
      return isInt<16>(Imm);
    return MCOp.isBareSymbolRef();
  }];
  let OperandType = "OPERAND_SIMM16";
  let OperandNamespace = "EmberOp";
}


//===----------------------------------------------------------------------===//
// Ember Instructions
//===----------------------------------------------------------------------===//

let hasSideEffects = 0, mayLoad = 0, mayStore = 0, isCall = 1, isBranch = 1, isTerminator = 1, r2_imm = 0, r3_imm = 0 in
def BR32 : EmberInst32<0xBB, (outs), (ins GPR32:$r1), "BR32 $r1",
                  [(brind GPR32:$r1)]>;

let hasSideEffects = 0, mayLoad = 0, mayStore = 0, isCall = 1, isBranch = 1, isTerminator = 1, r2_imm = 0, r3_imm = 0 in
def BR64 : EmberInst64<0x00BA, (outs), (ins GPR64:$r1), "BR64 $r1",
                  [(brind GPR64:$r1)]>;

let isAsCheapAsAMove = 1, isCodeGenOnly = 1, isReMaterializable = 1, r2_imm = 0 in
def MOVLI32 : EmberInst32<0xCC, (outs GPR32:$r1), (ins simm8:$r3_imm),
                      "MOVli32 $r1 $r3_imm",
                      [(set GPR32:$r1, simm8:$r3_imm)]>;

let isAsCheapAsAMove = 1, isCodeGenOnly = 1, isReMaterializable = 1, r2_imm = 0 in
def MOVLI64 : EmberInst64<0x00CA, (outs GPR64:$r1), (ins simm16:$r3_imm),
                      "MOVli64 $r1 $r3_imm",
                      [(set GPR64:$r1, simm16:$r3_imm)]>;

let isBarrier = 1, isReturn = 1, isTerminator = 1 in
def PseudoRET32 : EmberPseudoInst32<(outs), (ins), "# PseudoRET",
                [(ember32_ret)]>,
                PseudoInstExpansion<(BR32 RH0)>;

let isBarrier = 1, isReturn = 1, isTerminator = 1 in
def PseudoRET64 : EmberPseudoInst64<(outs), (ins), "# PseudoRET",
                [(ember64_ret)]>,
                PseudoInstExpansion<(BR64 R0)>;
//===-- EmberInstrFormats.td - Ember Instruction Formats -------*- tablegen -*-===//
//
// Description Ember instruction format 32 bit:
//
//  XX XX XX XX
//        ^^ ^^ - r3_imm - third  reg or imm
//      ^       - r2_imm - second reg or imm
//     ^        - r1     - first  reg
//  ^^          - opcode - operation code
//
// Description Ember instruction format 64 bit:
//
//  00 XX XX XX XX XX XX XX
//                    ^^ ^^ - r3_imm - third  reg or imm
//                  ^       - r2_imm - second reg or imm
//            ^             - r1     - first  reg
//     ^^                   - opcode - operation code
//  ^^                      - always 00
//===----------------------------------------------------------------------===//
// Ember Instruction Format Definitions.
//
class EmberInstCommon<dag outs, dag ins, string asmstr, list<dag> pattern>: Instruction
{
  // Inst and Size: for tablegen(... -gen-emitter) and
  // tablegen(... -gen-disassembler) in CMakeLists.txt
  let Namespace = "Ember";
  let DecoderNamespace = "Ember";

  let OutOperandList = outs;
  let InOperandList  = ins;
  let AsmString   = asmstr;
  let Pattern     = pattern;

}

class EmberInst32<bits<8> op, dag outs, dag ins, string asmstr, list<dag> pattern> 
  : EmberInstCommon<outs, ins, asmstr, pattern> {
  let Size = 4;
  field bits<32> Inst;
  bits<8> Opcode = op;
  bits<8> r1     = 0;
  bits<8> r2_imm = 0;
  bits<8> r3_imm = 0;

  let Inst{31-24} = Opcode;
  let Inst{23-16} = r1;
  let Inst{15-8}  = r2_imm;
  let Inst{7-0}   = r3_imm;
}

class EmberInst64<bits<16> op, dag outs, dag ins, string asmstr, list<dag> pattern> 
  : EmberInstCommon<outs, ins, asmstr, pattern> {
  let Size = 8;
  field bits<64> Inst;

  bits<16> Opcode = op;
  bits<16> r1     = 0;
  bits<16> r2_imm = 0;
  bits<16> r3_imm = 0;

  let Inst{63-48} = Opcode;
  let Inst{47-32} = r1;
  let Inst{31-16} = r2_imm;
  let Inst{15-0}  = r3_imm;
}

// Pseudo instructions format
class EmberPseudoInst32<dag outs, dag ins, string asmstr, list<dag> pattern>
  : EmberInst32<0, outs, ins, asmstr, pattern> {
  let isPseudo = 1;
  let isCodeGenOnly = 1;
}

class EmberPseudoInst64<dag outs, dag ins, string asmstr, list<dag> pattern>
  : EmberInst64<0, outs, ins, asmstr, pattern> {
  let isPseudo = 1;
  let isCodeGenOnly = 1;
}
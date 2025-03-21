//===----------------------------------------------------------------------===//
//  Declarations that describe the Ember register files
//===----------------------------------------------------------------------===//

let Namespace = "Ember" in {
//===----------------------------------------------------------------------===//
// Registers for 32bit
//===----------------------------------------------------------------------===//
class EmberReg32<bits<5> Enc, string n> : Register<n> {
  let HWEncoding{4-0} = Enc;
}

foreach I = 0-31 in {
  def RH#I : EmberReg32<I, "rh#Ih">;
}

//===----------------------------------------------------------------------===//
// Registers for 64bit
//===----------------------------------------------------------------------===//
class EmberReg64<bits<5> Enc, string n> : Register<n> {
  let HWEncoding{4-0} = Enc;
}

foreach I = 0-31 in {
  def R#I : EmberReg64<I, "r"#I>;
}

def GPR32 : RegisterClass<"Ember", [i32], 32, (add
  RH0, RH1, RH2, RH3, RH4, RH5, RH6, RH7, RH8, RH9, RH10, RH11, RH12, RH13, RH14, RH15, 
  RH16, RH17, RH18, RH19, RH20, RH21, RH22, RH23, RH24, RH25, RH26, RH27, RH28, RH29, RH30, RH31)>;

def GPR64 : RegisterClass<"Ember", [i64], 64, (add
  R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15, 
  R16, R17, R18, R19, R20, R21, R22, R23, R24, R25, R26, R27, R28, R29, R30, R31)>;
}



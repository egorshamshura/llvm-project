//===----------------------------------------------------------------------===//
// This describes the calling conventions for Ember architecture.
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// Ember Return Value Calling Convention
//===----------------------------------------------------------------------===//
def RetCC_Ember32 : CallingConv<[
    // i32 return values
    CCIfType<[i32, i64], CCAssignToReg<[RH9, RH10, RH11, RH12]>>,

    // Integer values get stored in stack slots that are 4 bytes in
    // size and 4-byte aligned.
    CCIfType<[i64], CCAssignToStack<8, 4>>,
    CCIfType<[i32], CCAssignToStack<4, 4>>
]>;

def RetCC_Ember64 : CallingConv<[
    // i32 return values
    CCIfType<[i32, i64], CCAssignToReg<[R9, R10, R11, R12]>>,

    // Integer values get stored in stack slots that are 4 bytes in
    // size and 4-byte aligned.
    CCIfType<[i64], CCAssignToStack<8, 8>>,
    CCIfType<[i32], CCAssignToStack<8, 8>>
]>;

//===----------------------------------------------------------------------===//
// Ember Argument Calling Conventions
//===----------------------------------------------------------------------===//
def CC_Ember32 : CallingConv<[
    // Promote i8/i16 arguments to i32.
    CCIfType<[i8, i16], CCPromoteToType<i32>>,

    // The first 4 integer arguments are passed in integer registers.
    CCIfType<[i32, i64], CCAssignToReg<[RH9, RH10, RH11, RH12]>>,

    // Integer values get stored in stack slots that are 4 bytes in
    // size and 4-byte aligned.
    CCIfType<[i64], CCAssignToStack<8, 4>>,
    CCIfType<[i32], CCAssignToStack<4, 4>>
]>;

def CC_Ember64 : CallingConv<[
    // Promote i8/i16 arguments to i32.
    CCIfType<[i8, i16, i32], CCPromoteToType<i64>>,

    // The first 4 integer arguments are passed in integer registers.
    CCIfType<[i32, i64], CCAssignToReg<[R9, R10, R11, R12]>>,

    // Integer values get stored in stack slots that are 4 bytes in
    // size and 4-byte aligned.
    CCIfType<[i64], CCAssignToStack<8, 8>>,
    CCIfType<[i32], CCAssignToStack<8, 8>>
]>;

def CSR_Ember32 : CalleeSavedRegs<(add RH0, RH1, RH3, RH5, RH6, RH7, RH8)>;
def CSR_Ember64 : CalleeSavedRegs<(add R0, R1, R3, R5, R6, R7, R8)>;
add_llvm_component_group(Ember)
 
set(LLVM_TARGET_DEFINITIONS Ember.td)

tablegen(LLVM EmberGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM EmberGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM EmberGenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM EmberGenMCPseudoLowering.inc -gen-pseudo-lowering)
tablegen(LLVM EmberGenDAGISel.inc -gen-dag-isel)
tablegen(LLVM EmberGenCallingConv.inc -gen-callingconv)
tablegen(LLVM EmberGenAsmWriter.inc -gen-asm-writer)
tablegen(LLVM EmberGenMCCodeEmitter.inc -gen-emitter)
 
add_public_tablegen_target(EmberCommonTableGen)

add_llvm_target(EmberCodeGen
  EmberTargetMachine.cpp
  EmberRegisterInfo.cpp
  EmberInstrInfo.cpp
  EmberSubtarget.cpp
  EmberAsmPrinter.cpp
  EmberISelDagToDag.cpp
  EmberISelLowering.cpp
  EmberMCInstLower.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  EmberInfo
  AsmPrinter
  SelectionDAG

  ADD_TO_COMPONENT
  Ember
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)
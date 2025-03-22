add_llvm_component_group(Ember)
 
set(LLVM_TARGET_DEFINITIONS Ember.td)

tablegen(LLVM EmberGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM EmberGenInstrInfo.inc -gen-instr-info)
 
add_public_tablegen_target(EmberCommonTableGen)

add_llvm_target(EmberCodeGen
  EmberTargetMachine.cpp
  EmberRegisterInfo.cpp
  EmberInstrInfo.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  EmberInfo

  ADD_TO_COMPONENT
  Ember
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)
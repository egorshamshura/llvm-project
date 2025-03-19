add_llvm_component_group(Ember)
 
 add_llvm_target(EmberCodeGen
   EmberTargetMachine.cpp
 
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
add_llvm_component_library(LLVMEmberInfo
   EmberTargetInfo.cpp

   LINK_COMPONENTS
   MC
   Support
 
   ADD_TO_COMPONENT
   Ember
   )
add_llvm_component_library(LLVMEmberDesc
   EmberMCTargetDesc.cpp
   EmberMCAsmInfo.cpp
   EmberInstPrinter.cpp
 
   LINK_COMPONENTS
   MC
   Support
   EmberInfo
 
   ADD_TO_COMPONENT
   Ember
  )
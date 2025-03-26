#ifndef LLVM_LIB_TARGET_EMBER_EMBERTARGETMACHINE_H
#define LLVM_LIB_TARGET_EMBER_EMBERTARGETMACHINE_H

#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"
#include "EmberSubtarget.h"
#include <optional>

namespace llvm {
extern Target TheEmberTarget;

class EmberTargetMachine : public CodeGenTargetMachineImpl {
public:
    std::unique_ptr<TargetLoweringObjectFile> TLOF;
    EmberSubtarget Subtarget;

    EmberTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                StringRef FS, const TargetOptions &Options,
                std::optional<Reloc::Model> RM,
                std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                bool JIT);

    const EmberSubtarget *getSubtargetImpl(const Function &) const override {
        EMBER_DUMP_CYAN
        return &Subtarget;
    }

    // Pass Pipeline Configuration
    TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
    TargetLoweringObjectFile *getObjFileLowering() const override;
};
} // end namespace llvm

#endif // LLVM_LIB_TARGET_EMBER_EMBERTARGETMACHINE_H
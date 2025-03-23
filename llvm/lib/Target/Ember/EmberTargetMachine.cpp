#include "EmberTargetMachine.h"
#include "Ember.h"
#include "TargetInfo/EmberTargetInfo.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"
#include <optional>

using namespace llvm;

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeEmberTarget() {
// Register the target.
EMBER_DUMP_CYAN
RegisterTargetMachine<EmberTargetMachine> A(getTheEmber32Target());
RegisterTargetMachine<EmberTargetMachine> B(getTheEmber64Target());
}

EmberTargetMachine::EmberTargetMachine(const Target &T, const Triple &TT,
                                StringRef CPU, StringRef FS,
                                const TargetOptions &Options,
                                std::optional<Reloc::Model> RM,
                                std::optional<CodeModel::Model> CM,
                                CodeGenOptLevel OL, bool JIT)
    : CodeGenTargetMachineImpl(T, "e-m:e-p:32:32-i8:8:32-i16:16:32-i64:64-n32",
        TT, CPU, FS, Options, Reloc::Static,
        getEffectiveCodeModel(CM, CodeModel::Small), OL), TLOF(std::make_unique<TargetLoweringObjectFileELF>()) {
EMBER_DUMP_CYAN
    initAsmInfo();
}

namespace {
 
/// Ember Code Generator Pass Configuration Options.
class EmberPassConfig : public TargetPassConfig {
public:
    EmberPassConfig(EmberTargetMachine &TM, PassManagerBase &PM)
        : TargetPassConfig(TM, PM) {}

    bool addInstSelector() override {
        EMBER_DUMP_CYAN
        addPass(createEmberISelDag(getSimTargetMachine(), getOptLevel()));
        return false;
    }

    EmberTargetMachine &getSimTargetMachine() const {
        return getTM<EmberTargetMachine>();
    }
};

} // end anonymous namespace

TargetPassConfig *EmberTargetMachine::createPassConfig(PassManagerBase &PM) {
    EMBER_DUMP_CYAN
    return new EmberPassConfig(*this, PM);
}

TargetLoweringObjectFile *EmberTargetMachine::getObjFileLowering() const {
    EMBER_DUMP_CYAN
    return TLOF.get();
}

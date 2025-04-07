#ifndef LLVM_CLANG_LIB_BASIC_TARGETS_EMBER_H
#define LLVM_CLANG_LIB_BASIC_TARGETS_EMBER_H
#include "clang/Basic/TargetInfo.h"
#include "clang/Basic/TargetOptions.h"
#include "llvm/Support/Compiler.h"
#include "llvm/TargetParser/Triple.h"
namespace clang {
namespace targets {

class LLVM_LIBRARY_VISIBILITY Ember32TargetInfo : public TargetInfo {
public:
  Ember32TargetInfo(const llvm::Triple &Triple, const TargetOptions &Opts)
      : TargetInfo(Triple) {
    NoAsmVariants = true;
    LongLongAlign = 32;
    SuitableAlign = 32;
    DoubleAlign = LongDoubleAlign = 32;
    SizeType = UnsignedInt;
    PtrDiffType = SignedInt;
    IntPtrType = SignedInt;
    WCharType = UnsignedChar;
    WIntType = UnsignedInt;
    resetDataLayout("e-m:e-p:32:32-i8:8:32-i16:16:32-i64:64-n32");
  }

  void getTargetDefines(const LangOptions &Opts,
                        MacroBuilder &Builder) const override;

  ArrayRef<Builtin::Info> getTargetBuiltins() const override;

  BuiltinVaListKind getBuiltinVaListKind() const override {
    return TargetInfo::VoidPtrBuiltinVaList;
  }

  std::string_view getClobbers() const override { return ""; }

  ArrayRef<const char *> getGCCRegNames() const override {
    static const char *const GCCRegNames[] = {
        "rh0", "rh1", "rh2",  "rh3",  "rh4",  "rh5",  "rh6",  "rh7",
        "rh8", "rh9", "rh10", "rh11", "rh12", "rh13", "rh14", "rh15",
        "rh16", "rh17", "rh18",  "rh19",  "rh20",  "rh21",  "rh22",  "rh23",
        "rh24", "rh25", "rh26", "rh27", "rh28", "rh29", "rh30", "rh31",};
    return llvm::ArrayRef(GCCRegNames);
  }

  ArrayRef<TargetInfo::GCCRegAlias> getGCCRegAliases() const override {
    return std::nullopt;
  }

  bool validateAsmConstraint(const char *&Name,
                            TargetInfo::ConstraintInfo &Info) const override {
    return false;
  }
};

class LLVM_LIBRARY_VISIBILITY Ember64TargetInfo : public TargetInfo {
public:
  Ember64TargetInfo(const llvm::Triple &Triple, const TargetOptions &Opts)
      : TargetInfo(Triple) {
    NoAsmVariants = true;
    LongLongAlign = 32;
    SuitableAlign = 32;
    DoubleAlign = LongDoubleAlign = 32;
    SizeType = UnsignedInt;
    PtrDiffType = SignedInt;
    IntPtrType = SignedInt;
    WCharType = UnsignedChar;
    WIntType = UnsignedInt;
    resetDataLayout("e-m:e-p:32:32-i8:8:32-i16:16:32-i64:64-n32");
  }

  void getTargetDefines(const LangOptions &Opts,
                        MacroBuilder &Builder) const override;

  ArrayRef<Builtin::Info> getTargetBuiltins() const override;

  BuiltinVaListKind getBuiltinVaListKind() const override {
    return TargetInfo::VoidPtrBuiltinVaList;
  }

  std::string_view getClobbers() const override { return ""; }

  ArrayRef<const char *> getGCCRegNames() const override {
    static const char *const GCCRegNames[] = {
        "r0", "r1", "r2",  "r3",  "r4",  "r5",  "r6",  "r7",
        "r8", "r9", "r10", "r11", "r12", "rh3", "r14", "r15",
        "r16", "r17", "r18", "r19", "r20",  "r21",  "r22",  "r23",
        "r24", "r25", "r26", "r27", "r28", "r29", "r30", "r31",};
    return llvm::ArrayRef(GCCRegNames);
  }

  ArrayRef<TargetInfo::GCCRegAlias> getGCCRegAliases() const override {
    return std::nullopt;
  }

  bool validateAsmConstraint(const char *&Name,
                            TargetInfo::ConstraintInfo &Info) const override {
    return false;
  }
};
} // namespace targets
} // namespace clang
#endif // LLVM_CLANG_LIB_BASIC_TARGETS_EMBER_H
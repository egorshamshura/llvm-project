#include "Ember.h"
#include "clang/Basic/Builtins.h"
#include "clang/Basic/MacroBuilder.h"
#include "clang/Basic/TargetBuiltins.h"

using namespace clang;
using namespace clang::targets;

static constexpr Builtin::Info BuiltinInfo[] = {
  #define BUILTIN(ID, TYPE, ATTRS)                                               \
    {#ID, TYPE, ATTRS, nullptr, HeaderDesc::NO_HEADER, ALL_LANGUAGES},
  #include "clang/Basic/BuiltinsEmber.def"
};

void Ember32TargetInfo::getTargetDefines(const LangOptions &Opts,
                                    MacroBuilder &Builder) const {
  Builder.defineMacro("__ember__");
}

ArrayRef<Builtin::Info> Ember32TargetInfo::getTargetBuiltins() const {
  return llvm::ArrayRef(BuiltinInfo,
    clang::Ember::LastTSBuiltin - Builtin::FirstTSBuiltin);
}

void Ember64TargetInfo::getTargetDefines(const LangOptions &Opts,
                                    MacroBuilder &Builder) const {
  Builder.defineMacro("__ember__");
}

ArrayRef<Builtin::Info> Ember64TargetInfo::getTargetBuiltins() const {
  return llvm::ArrayRef(BuiltinInfo,
    clang::Ember::LastTSBuiltin - Builtin::FirstTSBuiltin);
}
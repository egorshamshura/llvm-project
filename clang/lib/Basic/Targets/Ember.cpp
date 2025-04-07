#include "Ember.h"
#include "clang/Basic/Builtins.h"
#include "clang/Basic/MacroBuilder.h"

using namespace clang;
using namespace clang::targets;

void Ember32TargetInfo::getTargetDefines(const LangOptions &Opts,
                                    MacroBuilder &Builder) const {
  Builder.defineMacro("__sim__");
}

ArrayRef<Builtin::Info> Ember32TargetInfo::getTargetBuiltins() const {
  return std::nullopt;
}

void Ember64TargetInfo::getTargetDefines(const LangOptions &Opts,
                                    MacroBuilder &Builder) const {
  Builder.defineMacro("__sim__");
}

ArrayRef<Builtin::Info> Ember64TargetInfo::getTargetBuiltins() const {
  return std::nullopt;
}
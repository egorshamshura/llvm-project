#ifndef LLVM_LIB_TARGET_Ember_Ember_H
#define LLVM_LIB_TARGET_Ember_Ember_H

#include "llvm/Support/raw_ostream.h"

#define EMBER_DUMP(Color)                                                        \
{                                                                            \
    llvm::errs().changeColor(Color)                                            \
        << __func__ << "\n\t\t" << __FILE__ << ":" << __LINE__ << "\n";        \
    llvm::errs().changeColor(llvm::raw_ostream::WHITE);                        \
}
// #define EMBER_DUMP(Color) {}

#define EMBER_DUMP_RED EMBER_DUMP(llvm::raw_ostream::RED)
#define EMBER_DUMP_GREEN EMBER_DUMP(llvm::raw_ostream::GREEN)
#define EMBER_DUMP_YELLOW EMBER_DUMP(llvm::raw_ostream::YELLOW)
#define EMBER_DUMP_CYAN EMBER_DUMP(llvm::raw_ostream::CYAN)
#define EMBER_DUMP_MAGENTA EMBER_DUMP(llvm::raw_ostream::MAGENTA)

#endif // LLVM_LIB_TARGET_Ember_Ember_H
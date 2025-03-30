#include "MCTargetDesc/EmberMCTargetDesc.h"
#include "Ember.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/MC/MCELFObjectWriter.h"
#include "llvm/MC/MCExpr.h"
#include "llvm/MC/MCObjectWriter.h"
#include "llvm/MC/MCValue.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

namespace {
class EmberELFObjectWriter : public MCELFObjectTargetWriter {
public:
  EmberELFObjectWriter(bool Is64Bit, uint8_t OSABI)
      : MCELFObjectTargetWriter(Is64Bit, OSABI, Is64Bit ? ELF::EM_EMBER64 : ELF::EM_EMBER32,
                                /*HasRelocationAddend*/ true) {}

  ~EmberELFObjectWriter() override = default;

protected:
  unsigned getRelocType(MCContext &Ctx, const MCValue &Target,
                        const MCFixup &Fixup, bool IsPCRel) const override;

  bool needsRelocateWithSymbol(const MCValue &Val, const MCSymbol &Sym,
                              unsigned Type) const override;
};
} // namespace

unsigned EmberELFObjectWriter::getRelocType(MCContext &Ctx, const MCValue &Target,
                                          const MCFixup &Fixup,
                                          bool IsPCRel) const {
  MCFixupKind Kind = Fixup.getKind();
  if (Kind >= FirstLiteralRelocationKind)
    return Kind - FirstLiteralRelocationKind;

  llvm_unreachable("Unimplemented fixup -> relocation");
}

bool EmberELFObjectWriter::needsRelocateWithSymbol(const MCValue &,
                                                const MCSymbol &,
                                                unsigned Type) const {
  return false;
}

std::unique_ptr<MCObjectTargetWriter>
llvm::createEmberELFObjectWriter(bool Is64Bit, uint8_t OSABI) {
  return std::make_unique<EmberELFObjectWriter>(Is64Bit, OSABI);
}
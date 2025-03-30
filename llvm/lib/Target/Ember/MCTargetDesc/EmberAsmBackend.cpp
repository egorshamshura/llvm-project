#include "MCTargetDesc/EmberMCTargetDesc.h"
#include "llvm/ADT/StringSwitch.h"
#include "llvm/MC/MCAsmBackend.h"
#include "llvm/MC/MCELFObjectWriter.h"
#include "llvm/MC/MCExpr.h"
#include "llvm/MC/MCFixupKindInfo.h"
#include "llvm/MC/MCObjectWriter.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/MCValue.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/EndianStream.h"

using namespace llvm;

namespace {
class EmberAsmBackend : public MCAsmBackend {
protected:
  const Target &TheTarget;

public:
  EmberAsmBackend(const Target &T)
      : MCAsmBackend(llvm::endianness::little), TheTarget(T) {}

  unsigned getNumFixupKinds() const override { return 0; }
};

class ELFEmber32AsmBackend : public EmberAsmBackend {
  Triple::OSType OSType;

public:
  ELFEmber32AsmBackend(const Target &T, Triple::OSType OSType)
      : EmberAsmBackend(T), OSType(OSType) {}

  void applyFixup(const MCAssembler &Asm, const MCFixup &Fixup,
                  const MCValue &Target, MutableArrayRef<char> Data,
                  uint64_t Value, bool IsResolved,
                  const MCSubtargetInfo *STI) const override {
    return;
  }

  bool writeNopData(raw_ostream &OS, uint64_t Count, const MCSubtargetInfo *STI) const override {
    // Cannot emit NOP with size not multiple of 32 bits.
    if (Count % 4 != 0)
      return false;

    uint64_t NumNops = Count / 4;
    for (uint64_t i = 0; i != NumNops; ++i)
      support::endian::write<uint32_t>(OS, 0x01000000, Endian);

    return true;
  }

  std::unique_ptr<MCObjectTargetWriter>
  createObjectTargetWriter() const override {
    uint8_t OSABI = MCELFObjectTargetWriter::getOSABI(OSType);
    return createEmberELFObjectWriter(false, OSABI);
  }
};

class ELFEmber64AsmBackend : public EmberAsmBackend {
  Triple::OSType OSType;

public:
  ELFEmber64AsmBackend(const Target &T, Triple::OSType OSType)
      : EmberAsmBackend(T), OSType(OSType) {}

  void applyFixup(const MCAssembler &Asm, const MCFixup &Fixup,
                  const MCValue &Target, MutableArrayRef<char> Data,
                  uint64_t Value, bool IsResolved,
                  const MCSubtargetInfo *STI) const override {
    return;
  }

  bool writeNopData(raw_ostream &OS, uint64_t Count, const MCSubtargetInfo *STI) const override {
    // Cannot emit NOP with size not multiple of 64 bits.
    if (Count % 8 != 0)
      return false;

    uint64_t NumNops = Count / 8;
    for (uint64_t i = 0; i != NumNops; ++i)
      support::endian::write<uint64_t>(OS, 0x0100000000000000, Endian);

    return true;
  }

  std::unique_ptr<MCObjectTargetWriter>
  createObjectTargetWriter() const override {
    uint8_t OSABI = MCELFObjectTargetWriter::getOSABI(OSType);
    return createEmberELFObjectWriter(true, OSABI);
  }
};

} // end anonymous namespace

MCAsmBackend *llvm::createEmber32AsmBackend(const Target &T,
                                        const MCSubtargetInfo &STI,
                                        const MCRegisterInfo &MRI,
                                        const MCTargetOptions &Options) {
  return new ELFEmber32AsmBackend(T, STI.getTargetTriple().getOS());
}

MCAsmBackend *llvm::createEmber64AsmBackend(const Target &T, const MCSubtargetInfo &STI, const MCRegisterInfo &MRI, const MCTargetOptions &Options) {
  return new ELFEmber64AsmBackend(T, STI.getTargetTriple().getOS());
}

/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Dialect Declarations                                                       *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace mlir {
namespace anka {

class AnkaDialect : public ::mlir::Dialect {
  explicit AnkaDialect(::mlir::MLIRContext *context);

  void initialize();
  friend class ::mlir::MLIRContext;
public:
  ~AnkaDialect() override;
  static constexpr ::llvm::StringLiteral getDialectNamespace() {
    return ::llvm::StringLiteral("anka");
  }
};
} // namespace anka
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::anka::AnkaDialect)

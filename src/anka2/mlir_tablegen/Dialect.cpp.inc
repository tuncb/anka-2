/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Dialect Definitions                                                        *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::anka::AnkaDialect)
namespace mlir {
namespace anka {

AnkaDialect::AnkaDialect(::mlir::MLIRContext *context)
    : ::mlir::Dialect(getDialectNamespace(), context, ::mlir::TypeID::get<AnkaDialect>()) {
  
  initialize();
}

AnkaDialect::~AnkaDialect() = default;

} // namespace anka
} // namespace mlir

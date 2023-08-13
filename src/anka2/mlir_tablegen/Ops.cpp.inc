/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Op Definitions                                                             *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_OP_LIST
#undef GET_OP_LIST

::mlir::anka::HelloOp
#endif  // GET_OP_LIST

#ifdef GET_OP_CLASSES
#undef GET_OP_CLASSES


//===----------------------------------------------------------------------===//
// Local Utility Method Definitions
//===----------------------------------------------------------------------===//

namespace mlir {
namespace anka {
} // namespace anka
} // namespace mlir
namespace mlir {
namespace anka {

//===----------------------------------------------------------------------===//
// ::mlir::anka::HelloOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
HelloOpGenericAdaptorBase::HelloOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const ::mlir::EmptyProperties &properties, ::mlir::RegionRange regions) : odsAttrs(attrs), odsRegions(regions) {  if (odsAttrs)
    odsOpName.emplace("anka.hello", odsAttrs.getContext());
}

std::pair<unsigned, unsigned> HelloOpGenericAdaptorBase::getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
  return {index, 1};
}

::mlir::DictionaryAttr HelloOpGenericAdaptorBase::getAttributes() {
  return odsAttrs;
}

} // namespace detail
HelloOpAdaptor::HelloOpAdaptor(HelloOp op) : HelloOpAdaptor(op->getOperands(), op->getAttrDictionary(), op.getProperties(), op->getRegions()) {}

::mlir::LogicalResult HelloOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

std::pair<unsigned, unsigned> HelloOp::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::operand_range HelloOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

std::pair<unsigned, unsigned> HelloOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::result_range HelloOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

void HelloOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState) {
}

void HelloOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes) {
  assert(resultTypes.size() == 0u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void HelloOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 0u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 0u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

::mlir::LogicalResult HelloOp::verifyInvariantsImpl() {
  return ::mlir::success();
}

::mlir::LogicalResult HelloOp::verifyInvariants() {
  return verifyInvariantsImpl();
}

} // namespace anka
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::anka::HelloOp)


#endif  // GET_OP_CLASSES


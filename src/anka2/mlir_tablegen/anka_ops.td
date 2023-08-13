#ifndef ANKA_OPS
#define ANKA_OPS

include "mlir/IR/OpBase.td"

def Anka_Dialect : Dialect {
  let name = "anka";
  let cppNamespace = "::mlir::anka";
}

class Anka_Op<string mnemonic, list<Trait> traits = []> : Op<Anka_Dialect, mnemonic, traits>;

def HelloOp : Anka_Op<"hello"> {
  let summary = "prints hello";
  let description = [{
    The "hello" builtin operation prints hello :), and produces no results.
  }];

  // // The print operation takes an input tensor to print.
  // let arguments = (ins F64Tensor:$input);

  // let assemblyFormat = "$input attr-dict `:` type($input)";
}

#endif

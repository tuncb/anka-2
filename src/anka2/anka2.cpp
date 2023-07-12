#pragma warning(disable : 4146) // unary minus operator applied to unsigned type, result still unsigned
#include <mlir/IR/MLIRContext.h>
#pragma warning(default : 4146)

#include <fmt/printf.h>

int main()
{
  fmt::print("Hello world from anka 2");

  mlir::MLIRContext context;
}

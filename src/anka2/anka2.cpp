#pragma warning(disable : 4146) // unary minus operator applied to unsigned type, result still unsigned
#include <mlir/IR/MLIRContext.h>
#pragma warning(default : 4146)

#include "mlir/Dialect/Func/Extensions/AllExtensions.h"
#include "mlir/IR/BuiltinOps.h"
#include "mlir/IR/DialectRegistry.h"
#include "mlir/IR/OwningOpRef.h"

#include <fmt/printf.h>

int runJit(mlir::ModuleOp module)
{
  // Initialize LLVM targets.
  llvm::InitializeNativeTarget();
  llvm::InitializeNativeTargetAsmPrinter();

  // Register the translation from MLIR to LLVM IR, which must happen before we
  // can JIT-compile.
  mlir::registerBuiltinDialectTranslation(*module->getContext());
  mlir::registerLLVMDialectTranslation(*module->getContext());

  // An optimization pipeline to use within the execution engine.
  auto optPipeline = mlir::makeOptimizingTransformer(
      /*optLevel=*/enableOpt ? 3 : 0, /*sizeLevel=*/0,
      /*targetMachine=*/nullptr);

  // Create an MLIR execution engine. The execution engine eagerly JIT-compiles
  // the module.
  mlir::ExecutionEngineOptions engineOptions;
  engineOptions.transformer = optPipeline;
  auto maybeEngine = mlir::ExecutionEngine::create(module, engineOptions);
  assert(maybeEngine && "failed to construct an execution engine");
  auto &engine = maybeEngine.get();

  // Invoke the JIT-compiled function.
  auto invocationResult = engine->invokePacked("main");
  if (invocationResult)
  {
    llvm::errs() << "JIT invocation failed\n";
    return -1;
  }

  return 0;
}

int loadMLIR(mlir::MLIRContext &context, mlir::OwningOpRef<mlir::ModuleOp> &module)
{
  return 0;
}

int main()
{
  fmt::print("Hello world from anka 2");

  mlir::MLIRContext context;

  mlir::DialectRegistry registry;
  mlir::func::registerAllExtensions(registry);
  mlir::MLIRContext context(registry);

  // Load our Dialect in this MLIR Context.
  context.getOrLoadDialect<mlir::toy::ToyDialect>();

  mlir::OwningOpRef<mlir::ModuleOp> module;
  if (int error = loadMLIR(context, module))
    return error;

  return runJit(*module);
}

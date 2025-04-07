let TargetPrefix = "ember" in {  // All intrinsics start with "llvm.ember.".

  def int_ember_putpixel: ClangBuiltin<"emberPutPixel">,
    Intrinsic<[], [llvm_i32_ty, llvm_i32_ty, llvm_i32_ty], [IntrNoMem, IntrHasSideEffects]>;

  def int_ember_flush: ClangBuiltin<"emberFlush">,
    Intrinsic<[], [], [IntrNoMem, IntrHasSideEffects]>;

  def int_ember_rand: ClangBuiltin<"emberRand">,
    Intrinsic<[], [llvm_ptr_ty], [IntrHasSideEffects]>;

} // TargetPrefix = "ember"
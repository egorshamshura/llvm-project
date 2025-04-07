let TargetPrefix = "ember" in {  // All intrinsics start with "llvm.ember.".

  def int_ember_putpixel:
    Intrinsic<[], [llvm_i32_ty, llvm_i32_ty, llvm_i32_ty], [IntrNoMem, IntrHasSideEffects]>;

  def int_ember_flush:
    Intrinsic<[], [], [IntrNoMem, IntrHasSideEffects]>;

} // TargetPrefix = "ember"
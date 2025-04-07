define dso_local i32 @main() {
  call void @llvm.ember.putpixel(i32 10, i32 10, i32 -2)
  call void @llvm.ember.flush()
  ret i32 12
}

declare void @llvm.ember.putpixel(i32, i32, i32)
declare void @llvm.ember.flush()
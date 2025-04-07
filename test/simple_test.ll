; ModuleID = 'test/simple_test.cpp'
source_filename = "test/simple_test.cpp"
target datalayout = "e-m:e-p:32:32-i8:8:32-i16:16:32-i64:64-n32"
target triple = "ember32"

; Function Attrs: mustprogress noinline nounwind optnone
define dso_local void @_Z3appv() #0 {
entry:
  call void @llvm.ember.putpixel(i32 5, i32 5, i32 -1)
  call void @llvm.ember.flush()
  ret void
}

; Function Attrs: nounwind
declare void @llvm.ember.putpixel(i32, i32, i32) #1

; Function Attrs: nounwind
declare void @llvm.ember.flush() #1

attributes #0 = { mustprogress noinline nounwind optnone "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" }
attributes #1 = { nounwind }

!llvm.module.flags = !{!0, !1}
!llvm.ident = !{!2}

!0 = !{i32 1, !"wchar_size", i32 1}
!1 = !{i32 7, !"frame-pointer", i32 2}
!2 = !{!"clang version 20.1.0 (git@github.com:egorshamshura/llvm-project.git 1eb9a6c624c78b638b73915bc0d5f9759c7edb90)"}

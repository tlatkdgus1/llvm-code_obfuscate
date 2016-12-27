add_llvm_library(LLVMSmartalter
	First.cpp
  )

add_dependencies(LLVMSmartalter intrinsics_gen)

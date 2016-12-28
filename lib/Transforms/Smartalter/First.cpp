#include "llvm/Pass.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/InstrTypes.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/Type.h"
#include "llvm/ADT/Statistic.h"
#include "llvm/IR/GlobalValue.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/Transforms/Utils/Cloning.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#include "llvm/CodeGen/ISDOpcodes.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Transforms/IPO.h"
#include <list>

#include "llvm/Transforms/Smartalter/First.h"
#include "llvm/IRReader/IRReader.h"
#include "llvm/Linker/Linker.h"
#include "llvm/Support/SourceMgr.h"
using namespace llvm;
namespace {
	struct First : public FunctionPass {
		static char ID; // Pass identification
		bool flag;
		First() : FunctionPass(ID) {}
		First(bool flag) : FunctionPass(ID) {this->flag = flag; First();}

		virtual bool runOnFunction(Function &F){
			errs() << "Smartalter First code obfuscation\n";
		}
	};
}

char First::ID = 0;
static RegisterPass<First> X("First", "llvm obfuscation first");

Pass *llvm::createFirst() {
	return new First();
}

Pass *llvm::createFirst(bool flag) {
	return new First(flag);
}

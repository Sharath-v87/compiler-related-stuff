#include "llvm/Analysis/LoopInfo.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Module.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
#include <map>

using namespace llvm;

namespace {
class Demo : public FunctionPass {
private:
  unsigned count;

public:
  static char ID;
  Demo() : FunctionPass(ID) { count = 0; }

 void countBB(Loop *L) {
    int BBCnt = 0;
    for (auto BB : L->getBlocks()) {
      BBCnt++;
    }
    errs() << "#BB = " << BBCnt << "\n";

    for (auto NL : *L)
      countBB(NL);
  }
bool runOnFunction(Function &F) override {
    LoopInfo &LI = getAnalysis<LoopInfoWrapperPass>().getLoopInfo();
    int loopCnt = 0;
    for (Loop *L : LI) {
      countBB(L);
    }
    return false;
  }

  void getAnalysisUsage(AnalysisUsage &AU) const override {
    AU.addRequired<LoopInfoWrapperPass>();
    AU.addPreserved<LoopInfoWrapperPass>();
    // AU.setPreservesAll();
  }
};
} // namespace
char Demo::ID = 0;
static RegisterPass<Demo> res("demo", "This is a demo Pass");
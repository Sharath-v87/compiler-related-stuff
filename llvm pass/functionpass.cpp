#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

namespace{
class Demo : public FunctionPass {
public:
    static char ID;
    Demo() : FunctionPass(ID) {}
    bool runOnFunction(Function &F) override{
        auto name = F.getName();
        errs()<<"Function name is : "<<name<<"\n";
        return false
    }
};
char Demo:: ID = 0;
static RegisterPass<demo> res("demo","just a demo hehe");
}

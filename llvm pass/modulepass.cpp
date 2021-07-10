#include "llvm/Pass.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

namespace {
class Demo : public ModulePass {
private:
    unsigned count;
public:    
    static char ID;
    Demo() : ModulePass(ID) { count = 0; }
    bool runOnModule(Module &M) override {
        for(auto &F : M.functions()){
            if(F.isDeclaration())
                continue;
            auto name = F.getName();
            errs() << "Hello from: " << name << "\n";
            count++;

        }
        errs() << "#Functions = " << count << "\n";
        return false;
    }
};
} 

char Demo::ID = 0;
static RegisterPass<Demo> res("demo", "This is a demo pass");
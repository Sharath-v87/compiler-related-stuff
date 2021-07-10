#include "llvm/Pass.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"
#include <map>

using namespace llvm;

namespace {
class Demo : public FunctionPass {
private:
    unsigned count;
    std::map <std::string, unsigned> instFreqMap;
public:    
    static char ID;
    Demo() : FunctionPass(ID) { count = 0; }
    bool runOnFunction(Module &M) override {
        // for(auto &F : M.functions()){
        //     instFreqMap = new std::map <std::string, unsigned>();
        //     if(F.isDeclaration())
        //         continue;
            auto name = F.getName();
            errs() << "Hello from: " << name << "\n";
            count++;
            for(BasicBlock &&BB : F.){
                for(Instruction &I : BB){
                    if(instFreqMap.find(I.getOpcodeName()) == instFreqMap.end())
                        instFreqMap[I.getOpcodeName()] = 1;
                    else
                        instFreqMap[I.getOpcodeName()] += 1;
                }
            } 
            for(auto i : instFreqMap){
                errs() << i.first << "-" << i.second <<"\n";
            }
        // }
        // errs() << "#Functions = " << count << "\n";
        return false;
    }
};
} 

char Demo::ID = 0;
static RegisterPass<Demo> res("demo", "This is a demo pass");
#include "llvm/Analysis/LoopInfo.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Module.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
#include <map>

using namespace llvm;

namespace{
    class ArithInt : public FunctionPass{
    private:
    unsigned count1;
    unsigned count2;
    unsigned ai; 
    public:
    static char ID;
    ArithInt() : Function(ID) {count=0;}
    bool runOnFunction (Function &F){
        for (auto &BB : F){
            for(auto &I : BB){
                if(I.getOpcode() == Instruction:Add || I.getOpcode() == Instruction:Sub || I.getOpcode() == Instruction:Mul || I.getOpcode() == Instruction:Div )
                    count1++;
                if(I.getOpcode() == Instruction:Load || I.getOpcode() == Instruction:Store )
                    count2++;
            }
            ai=count1/count2;
            errs() << "Arithmetic Intensity = " << ai << "\n";

        }
        return false;
    }
    };
}

char ArithInt:: ID=0;
static RegisterPass<ArithInt> res("arithint","this is a pass to get arithmetic intensity");
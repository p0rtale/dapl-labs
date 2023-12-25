#include <iostream>

#include <stack_machine/asm_compiler/Compiler.h>
#include <stack_machine/machine/Machine.h>


int main(int argc, char* argv[]) {
    size_t filesNum = argc - 1;
    std::vector<std::string> files(argv + 1, argv + 1 + (filesNum));    
    asm_compiler::Compiler compiler{/*filenames=*/files};

    bool ok = compiler.compile();
    if (!ok) {
        return EXIT_FAILURE;
    }

    compiler.saveMachineCode("machine_code.txt");

    stack_machine::StackMachine machine{
        /*memorySize=*/100000,
        /*input=*/std::cin,
        /*output=*/std::cout
    };

    std::ifstream fin("machine_code.txt");
    stack_machine::Word result = machine.run(fin);

    std::cout << result << "\n";

    return EXIT_SUCCESS;
}

#include <iostream>

#include <stack_machine/machine/Machine.h>
#include <stack_machine/asm_compiler/Lexer.h>
#include <stack_machine/asm_compiler/Compiler.h>

using namespace asm_compiler;
using namespace stack_machine;

int main() {
    // std::ifstream fin("test.txt");
    // Lexer lex{fin};
    // auto ok = lex.scan();

    // if (!ok) {
    //     return EXIT_FAILURE;
    // }

    // auto token = Token{TokenType::kBlank, ""};
    // do {
    //     token = lex.nextToken();
    //     std::cout << static_cast<int>(token.type) << ": " << token.value << "\n";
    // } while (!token.isEmpty());


    // Compiler compiler{std::vector<std::string>{"sum.txt"}};
    // bool ok = compiler.compile();
    // if (!ok) {
    //     std::cout << "BAN!\n";
    //     return EXIT_FAILURE;
    // }

    // compiler.saveMachineCode("machine_code.txt");

    StackMachine machine{1000, std::cin, std::cout};

    std::ifstream fin("machine_code.txt");

    machine.run(fin);

    std::cout << "\n";

    return EXIT_SUCCESS;
}

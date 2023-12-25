#include <iostream>

#include <Clipl/Preprocessor/Preprocessor.hpp>
#include <Clipl/Logger/Logger.hpp>

using namespace clipl;
using namespace preprocessor;

int main() {
    Logger::init();
    Preprocessor preproc;

    std::string cliplFilename = "main.clipl";

    auto resultString = preproc.run(cliplFilename);

    std::string outputFilename = "premain.clipl";
    std::ofstream out(outputFilename);
    out << resultString;
    out.close();

    return EXIT_SUCCESS;
}

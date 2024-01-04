#include <iostream>

#include <Clipl/Grammar/Driver/Driver.hpp>
#include <Clipl/Logger/Logger.hpp>

using namespace clipl;

int main() {
    Logger::init();

    Driver driver{/*traceParsing=*/true, /*traceScanning=*/true};
    Driver::Result result = driver.Parse("main.clipl");
    if (result == Driver::Result::kOK) {
        std::cout << "PLAY: OK\n";
    } else {
        std::cout << "PLAY: ERROR\n";
        return EXIT_FAILURE;
    }

    driver.ConvertTreeToDot("main.dot");
    std::cout << "PLAY: DOT OK\n";

    return EXIT_SUCCESS;
}

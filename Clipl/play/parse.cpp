#include <iostream>

#include <Clipl/Grammar/Driver/Driver.hpp>
#include <Clipl/Logger/Logger.hpp>

using namespace clipl;

int main() {
    Driver driver{/*traceParsing=*/true, /*traceScanning=*/true};
    Driver::Result result = driver.parse("main.clipl");
    if (result == Driver::Result::kOK) {
        std::cout << "PLAY: OK\n";
    } else {
        std::cout << "PLAY: ERROR\n";
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

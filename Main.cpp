
#include "Core.hpp"

// std
#include <cstdlib>
#include <iostream>
#include <stdexcept>

int main() {
    Engine::Core engine{};

    try {
        engine.run();
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
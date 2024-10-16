#include "wrapper.hpp"
#include <exception>
#include <chrono>

B15F* tryGetInstance(ConnectionError& error) {
    B15F* instance = nullptr;
    try {
        instance = &B15F::getInstance();
    } catch(const std::exception& except) {
        error = ConnectionError::Err;
    }
    error = ConnectionError::None;
    return instance;
}

uint8_t B15F_getRegisterPINA(B15F& self) {
    return self.getRegister(&PINA);
}

void B15F_setRegisterDDRA(B15F& self, uint8_t value) {
    try {
        self.setRegister(&DDRA, value);
    } catch(std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void B15F_setRegisterPORTA(B15F& self, uint8_t value) {
    // auto start = std::chrono::high_resolution_clock::now();

    try {
        self.setRegister(&PORTA, value);
    } catch(std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // auto end = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double, std::milli> duration = end - start;
    // std::cout << duration.count() << std::endl;
}
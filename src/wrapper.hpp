#include "b15f/b15f.h"
#include <cstdint>

enum class ConnectionError: uint8_t {
    None = 0,
    Err = 1,
};

B15F* tryGetInstance(ConnectionError& error);

uint8_t B15F_getRegisterPINA(B15F& self);

void B15F_setRegisterDDRA(B15F& self, uint8_t value);

void B15F_setRegisterPORTA(B15F& self, uint8_t value);
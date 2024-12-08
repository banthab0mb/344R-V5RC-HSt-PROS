#include "brain_logo.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "stormlib/api.hpp"
#include "robot_config.h"
#include "comp_init.h"

void compInit() {
    autonSelector.initialize();
    
    // Print logo on brain
    printLogo();

}
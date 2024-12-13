#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/rtos.hpp"
#include "stormlib/api.hpp"
#include "robot_config.h"
#include "init.h"
#include "pros/llemu.hpp"
#include "brain_logo.h"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */

// BASICALLY PRE-AUTONOMOUS

void start() {
    pros::delay(100);
    
    pros::lcd::clear();

    chassis.calibrate(); // calibrate sensors

    printLogo();

	autonSelector.initialize();
 	LEDmanager.initialize();

}
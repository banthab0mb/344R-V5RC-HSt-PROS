#include "lemlib/api.hpp" // IWYU pragma: keep
#include "stormlib/api.hpp"
#include "robot_config.h"
#include "init.h"
#include "pros/llemu.hpp"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */

// BASICALLY PRE-AUTONOMOUS

void start() {
    pros::lcd::initialize(); // initialize brain screen
    chassis.calibrate(); // calibrate sensors

	//autonSelector.initialize();
 	LEDmanager.initialize();

}
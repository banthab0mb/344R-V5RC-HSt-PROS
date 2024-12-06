#pragma once

#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/adi.hpp"
#include "pros/motors.hpp"
#include "stormlib/led.hpp"
#include "stormlib/api.hpp"

extern pros::Controller controller;

extern stormlib::aRGB strand1;
extern stormlib::aRGB strand2;

extern stormlib::selector autonSelector;
extern stormlib::aRGB_manager LEDmanager;

extern pros::MotorGroup left_motor_group;
extern pros::MotorGroup right_motor_group;

extern lemlib::Drivetrain drivetrain;

extern pros::Imu imu;

extern pros::Rotation horizontal_encoder;

extern pros::Rotation vertical_encoder;

extern lemlib::TrackingWheel horizontal_tracking_wheel;

extern lemlib::TrackingWheel vertical_tracking_wheel;

extern lemlib::OdomSensors sensors;

extern lemlib::ControllerSettings lateral_controller;
extern lemlib::ControllerSettings angular_controller;

extern lemlib::Chassis chassis;


extern pros::Motor intake;

extern pros::adi::AnalogOut clamp;

extern pros::adi::AnalogOut cornerClearer;
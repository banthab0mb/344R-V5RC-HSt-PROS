#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/abstract_motor.hpp"
#include "pros/adi.hpp"
#include "pros/motors.hpp"
#include "stormlib/led.hpp"
#include "stormlib/api.hpp"

#include "robot_config.h"

// Controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// LEDs
stormlib::aRGB strand1(4, 41);
stormlib::aRGB strand2(5, 41);

stormlib::aRGB_manager LEDmanager(&strand1, &strand2, nullptr, nullptr,
                                  nullptr, nullptr, nullptr, nullptr);

// Auton selector
stormlib::selector autonSelector(stormlib::selector::E_BLUE_RIGHT_4, "AWP",
                                 "5Ring", "Goal Rush", "Disrupt");

// left motor group
pros::MotorGroup left_motor_group({-1, 2, -3}, pros::MotorGears::blue);

// right motor group
pros::MotorGroup right_motor_group({4, -5, 6}, pros::MotorGears::blue);

// drivetrain settings
lemlib::Drivetrain drivetrain(&left_motor_group, // left motor group
                              &right_motor_group, // right motor group
                              12.6, // 12.6 inch track width
                              lemlib::Omniwheel::NEW_275, // using new 2.75" omnis
                              450, // drivetrain rpm is 450
                              2 // horizontal drift is 2 (for now)
);

// imu
pros::Imu imu(10);
// horizontal tracking wheel encoder
pros::Rotation horizontal_encoder(8);
// vertical tracking wheel encoder
pros::Rotation vertical_encoder(9);
// horizontal tracking wheel
lemlib::TrackingWheel horizontal_tracking_wheel(&horizontal_encoder, lemlib::Omniwheel::NEW_275, -5.75);
// vertical tracking wheel
lemlib::TrackingWheel vertical_tracking_wheel(&vertical_encoder, lemlib::Omniwheel::NEW_275, -2.5);

// odometry settings
lemlib::OdomSensors sensors(&vertical_tracking_wheel, // vertical tracking wheel 1, set to null
                            nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
                            &horizontal_tracking_wheel, // horizontal tracking wheel 1
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &imu // inertial sensor
);

// lateral PID controller
lemlib::ControllerSettings lateral_controller(10, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              3, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              20 // maximum acceleration (slew)
);

// angular PID controller
lemlib::ControllerSettings angular_controller(2, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              10, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in degrees
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in degrees
                                              500, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);

// create the chassis
lemlib::Chassis chassis(drivetrain, // drivetrain settings
                        lateral_controller, // lateral PID settings
                        angular_controller, // angular PID settings
                        sensors // odometry sensors
);

// Intake motor
pros::Motor intake(7, pros::MotorGears::blue);

// Pneumatics
pros::adi::AnalogOut clamp(1); // Mogo clamp

pros::adi::AnalogOut cornerClearer(2); // Corner Clearer
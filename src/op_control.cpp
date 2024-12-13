#include "lemlib/api.hpp" // IWYU pragma: keep
// #include "pros/adi.h"
#include "pros/adi.hpp"
#include "pros/misc.h"
#include "pros/misc.hpp"
#include "pros/motors.h"
#include "stormlib/api.hpp"
#include "robot_config.h"
#include "op_control.h"
#include "brain_logo.h"

    bool l1PressState;
    void l1Press() {
    l1PressState = !l1PressState;
        if (l1PressState) {
            clamp.set_value(1);
        } else {
            clamp.set_value(0);
        }
    }

    bool l2PressState;
    void l2Press() {
    l2PressState = !l2PressState;
        if (l2PressState) {
            cornerClearer.set_value(1);
        } else {
            cornerClearer.set_value(0);
        }
    }

    void opControl() {

        printLogo();
        
        strand1.rainbow(); // rainbow flows down strand
        strand2.flow(0x00FFFF,
                    0xFFFF00);     // gradient between two colors flows down strand

        LEDmanager.rainbow();

        intake.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

        // loop forever
        while (true) {

            // Intake motor control
            if(pros::E_CONTROLLER_DIGITAL_R1 && !pros::E_CONTROLLER_DIGITAL_R2) {
                intake.move_velocity(500);
            } 
            if (!pros::E_CONTROLLER_DIGITAL_R1 && pros::E_CONTROLLER_DIGITAL_R2) {
                intake.move_velocity(-500);
            }
            if (!pros::E_CONTROLLER_DIGITAL_R1 && !pros::E_CONTROLLER_DIGITAL_R2) {
                intake.brake();
            }

            // Pneumatic controls
            if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)) {
                l1Press();
            }

            if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)) {
                l2Press();
            }

            // Driving control

            // get left y and right x positions
            int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
            int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

            // move the robot
            chassis.curvature(leftY, rightX);

            // delay to save resources
            pros::delay(25);
        }
    }
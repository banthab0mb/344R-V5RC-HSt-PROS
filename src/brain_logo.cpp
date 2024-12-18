#include "lemlib/api.hpp" // IWYU pragma: keep
#include "stormlib/api.hpp"
//#include "robot_config.h"
#include "brain_logo.h"
lv_obj_t* image;

void printLogo() {
    
    // Print logo on brain
    LV_IMG_DECLARE(brainbanner_1920x960);
    image = lv_img_create(lv_scr_act());
    lv_img_set_src(image, &brainbanner_1920x960);
    lv_obj_set_size(image, 1920, 960);
    lv_obj_align(image, LV_ALIGN_CENTER, 0, 0);
    
}
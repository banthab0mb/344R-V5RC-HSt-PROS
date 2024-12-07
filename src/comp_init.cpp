#include "lemlib/api.hpp" // IWYU pragma: keep
#include "stormlib/api.hpp"
#include "robot_config.h"
#include "comp_init.h"
lv_obj_t* brainbanner;

void compInit() {
    autonSelector.initialize();
    
    // Print logo on brain
    LV_IMG_DECLARE(Image);
    brainbanner = lv_img_create(lv_scr_act());
    lv_img_set_src(brainbanner, &Image);
    lv_obj_set_size(brainbanner, 480, 272);
    lv_obj_align(brainbanner, LV_ALIGN_CENTER, 0, 0);
    
}
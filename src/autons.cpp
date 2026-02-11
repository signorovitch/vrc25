#include "main.h"

// Constants for intake speeds
const int IN_LOWER_SPD = -200;
const int IN_UPPER_SPD = -200;
const int IN_UPPER_IDLE = 60;
//jerry.io path
ASSET(/static/path.jerryio.txt)

void autonomous() {
  // Initial pose
  chassis.setPose(0, 0, 0);

  // Deploy / Start systems
  set_in_lower(IN_LOWER_SPD);
  set_in_upper(IN_UPPER_IDLE);
  set_load(false);

  chassis.setPose(0, 0, 0);
    // lookahead distance: 15 inches
    // timeout: 2000 ms
    chassis.follow(example_txt, 15, 2000);
    // follow the next path, but with the robot going backwards
    chassis.follow(example2_txt, 15, 2000, false);

  // Score
  chassis.moveToPose(27, -47, 90, 2000, {.forwards = false}, false);
  set_load(false);

  chassis.arcade(-127, 0, true); // Push?
  set_in_upper(IN_UPPER_SPD);    // -200
  pros::delay(5000);

  // Back off
  chassis.arcade(30, 0, true);
  pros::delay(500);
  chassis.arcade(-60, 0, true);
}
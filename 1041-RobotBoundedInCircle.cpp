#include "1041-RobotBoundedInCircle.h"

bool RobotBoundedInCircle::isRobotBounded(const string &instructions) {
    int angle = 0, x = 0, y = 0;
    for (auto instruction: instructions) {
        if (instruction == 'G') {
            switch (angle % 360) {
                case 0:
                    y++;
                    break;
                case 90:
                    x++;
                    break;
                case 180:
                    y--;
                    break;
                case 270:
                    x--;
                    break;
            }
        } else if (instruction == 'L') {
            angle = (angle + 90) % 360;
        } else if (instruction == 'R') {
            angle = (angle + 270) % 360;
        }
    }

    return ((x == 0 && y == 0) || angle % 360 != 0);
}

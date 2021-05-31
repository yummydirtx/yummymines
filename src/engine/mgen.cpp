/*
    Copyright 2021 Alex Frutkin
    
    This file is part of yummymines.

    yummymines is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    yummymines is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with yummymines.  If not, see <https://www.gnu.org/licenses/>.

*/

#include "mgen.h"

std::vector<std::vector<int>> genMines() {
    bool jobDone{false};
    int randX;
    int randY;
    // blank mines to begin with
    std::vector<std::vector<int>> mines{
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    };
    for (int x = 0; x < 10; x++) {
        jobDone = false;
        while (!jobDone) {
            randX = Random::get(0,9);
            randY = Random::get(0,9);
            if (mines[randX][randY] == 0) {
                mines[randX][randY] = 1;
                jobDone = true;
            }
        }
    }
    return mines;
}
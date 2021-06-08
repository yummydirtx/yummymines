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
            // Randomly generate positions
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

std::vector<std::vector<int>> genMap(std::vector<std::vector<int>> mines) {
    // Count up the bombs
    int nearbyBombs{0};
    std::vector<std::vector<int>> map{
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
        for (int y = 0; y < 10; y++) {
            nearbyBombs = 0;
            if (mines[x][y] == 1) {
                map[x][y] == -1;
                continue;
            }
            if (x > 0) {
                if (mines[x-1][y] == 1) {
                    nearbyBombs++;
                }
                if (y > 0) {
                    if (mines[x-1][y-1] == 1) {
                        nearbyBombs++;
                    }
                }
                if (y < 9) {
                    if (mines[x-1][y+1] == 1) {
                        nearbyBombs++;
                    }
                }
            }
            if (y > 0) {
                if (mines[x][y-1] == 1) {
                    nearbyBombs++;
                }
            }
            if (x < 9) {
                if (mines[x+1][y] == 1){
                    nearbyBombs++;
                }
                if (y < 9) {
                    if (mines[x+1][y+1] == 1) {
                        nearbyBombs++;
                    }
                }
                if (y > 0) {
                    if (mines[x+1][y-1] == 1) {
                        nearbyBombs++;
                    }
                }
            }
            if (y < 9) {
                if (mines[x][y+1]) {
                    nearbyBombs++;
                }
            }
            map[x][y] = nearbyBombs;
        }
    }
    return map;
}
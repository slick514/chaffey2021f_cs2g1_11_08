//
// Created by Justin Gries on 11/9/2021.
//

#ifndef CHAFFEY2021F_CS2G1_11_08_DISK_MOVER_H
#define CHAFFEY2021F_CS2G1_11_08_DISK_MOVER_H
#include <string>

class DiskMover {

public:
    DiskMover(int num_discs_to_move, int from_peg, int to_peg);
    std::string next_move();
    bool has_more_moves();
};


#endif //CHAFFEY2021F_CS2G1_11_08_DISK_MOVER_H

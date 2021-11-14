//
// Created by Justin Gries on 11/9/2021.
//

#include <iosfwd>
#include <sstream>
#include <iostream>
#include "disk_mover.h"
using namespace std;

DiskMover::DiskMover(const int &num_disks, const int &from_peg, const int &to_peg) {
    disk_number = num_disks;
    from = from_peg;
    to = to_peg;
    other = NUMBER_OF_PEGS - from - to;
    status = disk_number > 1 ? covered : can_move;
    cycle_helper(from, other);
}

bool DiskMover::has_more_moves() const{
    return !out_of_moves();
}

bool DiskMover::out_of_moves() const {
    return status == moved && ( helper == nullptr || !helper->has_more_moves());
}

string DiskMover::make_move_string() const{
    stringstream builder;
    builder << "Disk-"<<disk_number << " from peg-" << from + 1 << " to peg-" << to + 1;
    return builder.str();
}

DiskMover::~DiskMover() {
    delete helper;
}

string DiskMover::next_move(){
    string output;
    switch(status){
        case can_move: {
            output = make_move_string();
            move_disk();
            break;
        }
        case covered:{
            output = helper->next_move();
            if(!helper->has_more_moves()){
                status = can_move;
            }
            break;
        }
        case moved: {
            output = helper->next_move();
            break;
        }
        default: ;
    }
    return output;
}

void DiskMover::cycle_helper(const int &from_peg, const int &to_peg) {
    if (disk_number > 1) {
        DiskMover *allocated_memory = helper;
        helper = new DiskMover(disk_number - 1, from_peg, to_peg);
        delete allocated_memory;
    }
}

void DiskMover::move_disk() {
    status = moved;
    cycle_helper(other, to);
}

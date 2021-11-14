//
// Created by Justin Gries on 11/9/2021.
//

#ifndef CHAFFEY2021F_CS2G1_11_08_DISK_MOVER_H
#define CHAFFEY2021F_CS2G1_11_08_DISK_MOVER_H
#include <string>
#include <vector>

static const int NUMBER_OF_PEGS = 3;
const int PEG_1 = 0;
const int PEG_3 = 2;

class DiskMover {
public:
    DiskMover(const int &num_disks, const int &from_peg, const int &to_peg);
    ~DiskMover();
    std::string next_move();
    bool has_more_moves() const;
private:
    enum state{
        covered,
        can_move,
        moved
    };
    state status;
    int disk_number;
    int from;
    int to;
    int other;
    DiskMover* helper = nullptr;

    /**
     * Generates a string representing this disk's move
     * @return the string that is generated
     */
    std::string make_move_string() const;

    /**
     * Indicates if this disk-mover is out of moves
     * @return true if this disk-mover has moved and its helper is out of moves, false otherwise
     */
    bool out_of_moves() const;

    /**
     * sets the disk status to "moved" and cycles the helper iterator
     */
    void move_disk();

    /**
     * generates a new DiskMover from heap space,and releases the previously allocated memory;
     * @param from_peg The "from"-peg of the new helper iterator
     * @param to_peg The "to"-peg of the new helper iterator
     */
    void cycle_helper(const int &from_peg, const int &to_peg);
};


#endif //CHAFFEY2021F_CS2G1_11_08_DISK_MOVER_H

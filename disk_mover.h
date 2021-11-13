//
// Created by Justin Gries on 11/9/2021.
//

#ifndef CHAFFEY2021F_CS2G1_11_08_DISK_MOVER_H
#define CHAFFEY2021F_CS2G1_11_08_DISK_MOVER_H
#include <string>
#include <vector>

static const int NUMBER_OF_PEGS = 3;

class DiskMover {
public:
    DiskMover(const int &num_discs, const int &from_peg, const int &to_peg);
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
    int disc_number;
    int from;
    int to;
    int other;
    DiskMover* helper = nullptr;

    /**
     * Generates a string representing this disc's move
     * @return the string that is generated
     */
    std::string make_move_string() const;

    /**
     * Indicates if this disc-mover is out of moves
     * @return true if this disc-mover has moved and its helper is out of moves, false otherwise
     */
    bool out_of_moves() const;

    /**
     * sets the disc status to "moved" and cycles the helper iterator
     */
    void move_disc();

    /**
     * generates a new DiskMover from heap space,and releases the previously allocated memory;
     * @param from_peg The "from"-peg of the new helper iterator
     * @param to_peg The "to"-peg of the new helper iterator
     */
    void cycle_helper(const int &from_peg, const int &to_peg);
};


#endif //CHAFFEY2021F_CS2G1_11_08_DISK_MOVER_H

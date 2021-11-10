#include <iostream>
#include "disk_mover.h"

using namespace std;

/**
 * Course: Chaffey College 2021-Fall CS2
 * Prof: Dr. Tracy Kocher
 * Date: 09 Nov 2021
 * Project: 11.08
 * Coder: Justin Gries
 * Tester(s):
 *
 * Prompt:
 * Implement an iterator that produces the moves for the Towers of Hanoi puzzle described in Worked Example 11.2.
 * Provide functions has_more_moves and next_move. The next_move function should yield a string describing the next
 * move. For example, the following code prints all moves needed to move five disks from peg 1 to peg 3:
 DiskMover mover(5, 1, 3);
 while (mover.has_more_moves())
 {
    cout << mover.next_move() << endl;
 }
 Hint: A disk mover that moves a single disk from one peg to another simply has a next_move function that returns a
 string

 Move disk from peg source to target
 A disk mover with more than one disk to move must work harder. It needs another DiskMover to help it move the first
 d – 1 disks. Then next_move asks that disk mover for its next move until it is done. Then the next_move function
 issues a command to move the dth disk. Finally, it constructs another disk mover that generates the remaining moves.

 It helps to keep track of the state of the disk mover:
 •BEFORE_LARGEST: A helper mover moves the smaller pile to the other peg.
 •LARGEST: Move the largest disk from the source to the destination.
 •AFTER_LARGEST: The helper mover moves the smaller pile from the other peg to the target.
 •DONE: All moves are done.
 */
int main() {
    std::cout << "Hello, 11.08!" << std::endl;
    {
        //todo: prompt user for values
        int num_discs;
        int peg_1;
        int peg_2;
        DiskMover mover(num_discs, peg_1, peg_2);
        while (mover.has_more_moves()) {
            cout << mover.next_move() << endl;
        }
    }
    return 0;
}

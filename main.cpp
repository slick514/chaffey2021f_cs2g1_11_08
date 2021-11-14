#include <iostream>
#include <sstream>
#include "disk_mover.h"
#include "main.h"

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
 */
int main() {
    cout << "Hello, 11.08!" << endl;
    cout << "This program outputs all the moves for the 'Tower of Hanoi'-puzzle, for a given number of disks";
    cout << endl;
    int number_of_disks = get_number_of_disks_from_user();
    DiskMover mover(number_of_disks, PEG_1, PEG_3);
    cout << endl << "Here are the moves: " << endl;
    while( mover.has_more_moves())
        cout << mover.next_move() << endl;
    cout << endl << "You evaluated " << number_of_disks << " disks." << endl;
    cout << "There were " << add_commas(power_two(number_of_disks) - 1) << " moves";
    cout << endl << "Goodbye";
    return 0;
}

string add_commas(const int &integer_number) {
    string iString = to_string(integer_number);
    stringstream stream;
    stream << iString[0];
    int first_index = (int)iString.length() % 3;
    for( int i = 1; i < iString.length(); i++ ) {
        if( abs(i - first_index) % 3 == 0 )
            stream << ",";
        stream << iString[i];
    }
    return stream.str();
}

int get_number_of_disks_from_user() {
    int num_disks;
    string input;
    do {
        cout << "Please enter the number of disks to evaluate:" << endl;;
        getline(cin, input);
        cout << "You entered '" << input << "'" << endl;
        num_disks = evaluate_input(input);
    } while( num_disks < 1 );
    return num_disks;
}

int evaluate_input(const string &input) {
    int result = 0;
    int begin = -1;
    int len = 0;
    string digits;
    for( int i = 0; i < input.length(); i++ ) {
        if( isdigit(input[i])) {
            if( begin < 0 )
                begin = i;
            len++;
        } else if( len > 0 ) {
            break;
        }
    }
    if( len > 0 ) {
        digits = input.substr(begin, len);
        result = atoi(digits.c_str()); // NOLINT(cert-err34-c)
    }

    if( result < 1 ) {
        cout << "A positive number could not be extracted from the input." << endl;
        cout << "Please try again." << endl << endl;
    }
    return result;
}

long long int power_two(int power) {
    if( power == 0 )
        return 1;
    return 2 * power_two(power - 1);
}


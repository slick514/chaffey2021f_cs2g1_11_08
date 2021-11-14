//
// Created by Justin Gries on 11/13/2021.
//

#ifndef CHAFFEY2021F_CS2G1_11_08_MAIN_H
#define CHAFFEY2021F_CS2G1_11_08_MAIN_H

/**
 * Calculates to to the power of "power".
 * Could have just used a counter, but this is more fun
 * @param power
 * @return
 */
long long int power_two(int power);

/**
 * Produces an string representing an integer, with commas added at the "thousands"-place
 * @param integer_number the number to be considered
 * @return a string representing the integer, with commas added.
 */
std::string add_commas(const int &integer_number);

/**
 * Prompts the user to supply a number
 * re-prompts until a positive integer is supplied.
 * @return the input integer
 */
int get_number_of_disks_from_user();

/**
 * Pulls out the first integer value found in the supplied string
 * @param input input to be parsed
 * @return The first integer found within the string, or 0 if no integer is found;
 */
int evaluate_input(const std::string &input);

#endif //CHAFFEY2021F_CS2G1_11_08_MAIN_H

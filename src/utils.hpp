#include "timing.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
* @brief Function to check if the bases at indices i and j in the sequence form a valid pairing. A vaild pairing is the pairing of bases (A and U) and (C and G)
*
* @param i index of the first base
* @param j index of the second base
* @return 1 if (seq[i],seq[j]) is (A,U) or (U,A) or (C,G) or (G,C) i.e the bases at indices i and j in the sequence form a valid pairing
* @return 0 otherwise
*/
int isValid(int i , int j);

/**
* @brief Inititialize and allocate memory a two-dimensional matrix A of dimension n x n.
*
* @param a The pointer to the matrix A
* @param n The dimension of the matrix.
*/
void initialize(int*** a , int n);

/**
* @brief Function to find the maximum number of pairings for the RNA sequence s.
*
*/
void findOptimalPairing();

/**
* @brief Function which prints the pairs (maximum number) between the indices i and j of the RNA sequence
*
* @param i The lower bound of the indices between which the pairs (max number) have to be printed
* @param j The upper bound of the indices between which the pairs (max number) have to be printed
*/
void getPairs(int i, int j);

/**
* @brief Used to find the max number of pairings and print the pairs after scanning the RNA sequence s.
*
*/
int solve();

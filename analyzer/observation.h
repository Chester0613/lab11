
/*
 * Course: COEN 2210 - Introduction to Programming
 * Name: [Joandry A. Irizarry Roman]
 * Lab: 11 - Arrays and Structs
 * Description: Defines the Observation struct used
 *              to store county election data.
 * Due Date: [Nov/1/2026]
 */

#ifndef OBSERVATION_H
#define OBSERVATION_H

#include <string>

struct Observation {
    int id = 0;
    std::string state;
    std::string county;
    int totalVotes = 0;
    int democraticVotes = 0;
    int republicanVotes = 0;
    double democraticShare = 0.0;
    bool isEmpty = true;
};

#endif

// Copyright (c) 2022 Hertz  All rights reserved.
//
// Created by: Hertz Antonella
// Created on: Apr 6, 2022
// This program asks the user to  guess a number. It then generates a
// random number.It also checks to see if he user entered a valid number.

#include <iostream>
#include <random>
#include <string>

int main() {
    // Generates random number
    int randomNumber;
    std::random_device rseed;
    std::mt19937 rgen(rseed());  // mersenne_twister
    std::uniform_int_distribution<int> idist(0, 9);  // [0,100]
    randomNumber = idist(rgen);
    // std::cout << randomNumber << std::endl;

    // declare variables

    std::string userNumberAsString;
    int userNumberAsInt;

    // get user number
    std::cout << "Enter Guess a number between 0 and 9: ";
    std::cin >> userNumberAsString;
    std::cout << "" << std::endl;

    try {
        // convert the user number  from string to an int
        userNumberAsInt = std::stoi(userNumberAsString);
        std::cout << "" << std::endl;

        // compare the user number with the random number
        if (userNumberAsInt == randomNumber) {
            std::cout << "Your guess is correct";
        } else {
            std::cout << "Incorrect, the correct number is " \
            << randomNumber << "\n";
    }

        // checks to see if user entered a valid number
    } catch (std::invalid_argument) {
        // user did not enter an integer.
        std::cout << userNumberAsString << " is not a number\n";
        std::cout << "" << std::endl;
    }
}

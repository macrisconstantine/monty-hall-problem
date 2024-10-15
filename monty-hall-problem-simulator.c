/**
 * Constantine Macris and Rea Batsari
 * Professor Konstantinos Lentzos
 * ITC 3006: Mathematics for Computing
 * 25 March, 2022
 *
 * The Monty Hall problem is as follows: there are three doors. Behind two of
 * the doors, there is a goat (an "incorrect guess"). Behind the third door,
 * there is an expensive car (the "correct guess").
 * A contestant is allowed to select one of the three doors, so his
 * initial guess has a 1 in 3 probability of being correct.
 *
 * Before the door is opened and the contestant's first guess is shown to be
 * correct or incorrect, Monty Hall (who knows what is behind the doors),
 * reveals a goat from behind one of the two NOT-guessed doors.
 * Monty Hall now gives the contestant the choice between sticking to his
 * original guess, or switching to the only other un-revealed door.
 * Will the probability of a correct guess be affected by whether or not
 * the guess is changed?
 *
 * The following program illustrates the problem and compares the
 * probability of a correct guess via the "switch" method to the probability
 * of a correct guess using the "non-switch" method.
 *
 **/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Macro definition of number of trials/simulations
#define NUMBER_OF_TRIALS 100000

// Declarations of switch and non-switch functions
float montyHallNoSwitch();
float montyHallSwitch();


// Main function calls the functions and displays the results
int main()
{
    // Randomizes the seed used for rand function to produce different random values
    // each time the program is run
    srand(time(NULL));
    printf("\n\n\t  Monty Hall Probability Simulator\n");
    printf("_____________________________________________________\n");
    printf("The probability of winning by not switching is %.2f%%", montyHallNoSwitch()*100);
    printf("\nIf you switch, your odds increase to %.2f%%\n", montyHallSwitch()*100);
    printf("_____________________________________________________\n");
    printf("(probabilities calculated by running 100,000 trials)\n");
    return 0;
}

// Method to calculate probability of a correct guess without switching:
// Since the first guess is retained, and the first guess had a probability of
// 1 in 3, the probability of guessing correctly with this method is expected
// to be approximately 1 in 3 as well.
float montyHallNoSwitch()
{
    // Variables used to calculate the probability of a correct guess
    int correctGuesses=0;
    float probability;
    int door, guess;

    // Trial is repeated 100,000 times
    for (int i = 0; i<NUMBER_OF_TRIALS; i++)
    {
        // A random value between 1-3 is generated to represent the correct door
        door = rand()%3+1;

        // Another random value between 1-3 is generated to represent the guess
        guess = rand()%3+1;

        // If the numbers match, the tally of correct guesses is incremented
        if (door==guess) correctGuesses++;
    }
    // Probability of a correct guess is calculated from total number of
    // correct guesses divided by total number of trials
    probability = (float)correctGuesses/NUMBER_OF_TRIALS;
    return probability;
}

// Method to calculate probability of a correct guess via switching:
// Since the first guess had 1/3 odds of being correct, it follows that the
// remaining 2 doors should have a combined 2/3 odds of having the correct door.
// Because Monty Hall exposes the INCORRECT guess of those two doors, the
// 2/3rds odds of success are now contained in that ONE remaining door.
float montyHallSwitch()
{
    // Variables used to calculate the probability of a correct guess
    int correctGuesses=0;
    float probability;
    int door, guess;

    // Trial is repeated 100,000 times
    for (int i = 0; i<NUMBER_OF_TRIALS; i++)
    {
        door = rand()%3+1;
        guess = rand()%3+1;

        // In the case of a switch, the contestant is effectively exposing
        // the two un-revealed doors, which is the same as ending up with
        // a correct guess in the case that the initial guess was incorrect.
        if (door!=guess) correctGuesses++;

    }
    probability = (float)correctGuesses/NUMBER_OF_TRIALS;
    return probability;
}



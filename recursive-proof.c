#include <stdio.h>

/**
 * The following program, a modification of an exercise given in ITC2276,
 * was made to prove that the sum of an ascending sequence 
 * of all odd integers beginning from 1 and ending on the nth value 
 * is equal to n^2.
 *
 * This is accomplished by creating a sorted array of prime numbers, 
 * and plugging the nth value of the array into a recursive function 
 * that sums n with every odd number >= 1 and < n.
 */
const int odds[] = {1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31,33,35,37,39,41};
int square(int n);

/**
 * Main function that takes an input integer, indexes array, and displays square
 */
int main() {        
    int number, result;
    
    // displays prompt
    printf("Enter a positive integer: ");
    scanf("%d", &number);
    
    // indexes array of odd numbers to find nth value 
    int primeNum = odds[number-1];
    // calls recursive function
    result = square(primeNum);
    

    // displays results
    printf("\n%d^2 = %d", number, result);
    
    return 0;
}

int square(int n) {
    
    // continues recursion only until n-2 reaches zero, the first array index
    if (n >= 2){
        
        // square() function calls itself with the nearest odd number < n
        return n + square(n-2); }
    else
    
        //terminates recursion and returns sum
        return n;
}


/**
 * Following function does the same job as the recursive one. 
 * But c'mon which one is cooler. 
int squareLame(int n){
    int sum = 0;
        while(n>0){
            sum+=n;
            n=n-2;
        } 
}
*/


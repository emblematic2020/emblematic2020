#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float dollars;
    // keep prompting user for Change owed in dollars until positive integer is given
    do
    {
        dollars = get_float("Change owed: \n");
    }
    while (dollars <= 0);
    
    // convert dollars into totalcents and round to nearest int cents 
    int totalcents = round(dollars * 100);
    
    // Then keep track of the number of coins we accumulate while counting those pennies , by initialising a variable (int numCoins)
    
    int numcoins = 0;
    
    // if can subtract by quarter (25c), subtract totalCents by 25c and increase numCoins count; repeat until can't anymore
    
    while (totalcents >= 25)
    {
        numcoins = numcoins + 1;
        totalcents = totalcents - 25;
    }
    // if can subtract by dime (10c), subtract 10c; increase numCoins by1; and repeat until can't anymore 
    
    while (totalcents >= 10)
    {
        numcoins = numcoins + 1;
        totalcents = totalcents - 10;
    }
    
    // if can subtract by nickel (5c), subtract 5c; increase numCoins by1; and repeat until can't anymore
    
    while (totalcents >= 5)
    {
        numcoins = numcoins + 1;
        totalcents = totalcents - 5;
    }
    
    //if can subtract by penny (1c), subtract 1c; increase numCoins by1; and repeat until can't anymore 
    
    while (totalcents >= 1)
    {
        numcoins = numcoins + 1;
        totalcents = totalcents - 1;
    }
    
//print the numcoins used to provide change
    printf("%i\n", numcoins);
}

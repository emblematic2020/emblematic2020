#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");
    float numletters = 0, numwords = 1, numsentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Prompt count of number of letters in string(text), and store as a float "numletters". (Assume letter is any lowercase character from a to z or uppercase character from A to Z)
        if (isalpha(text[i]))
        {
            numletters++;
        }
        // Prompt count of number of words in string(text), store as a float "numwords". Assume any sequence of characters separated by spaces should count as a word
        if (isspace(text[i]))
        {
            numwords++;
        }
        // prompt count of number of sentences in string(text), store as as a float "numsentences". (assume that any occurrence of a period, exclamation point, or question mark indicates the end of a sentence.
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            numsentences++;
        }
    }
    
    // calculate Coleman-Liau index as a float and round

    int CLindex = round(0.0588 * (numletters / numwords * 100) - 0.296 * (numsentences * 100 / numwords) - 15.8);
    
    // If index number is 16 or higher, printf("Grade 16+");
    if (CLindex >= 16)
    {
        printf("Grade 16+\n");
        return 0;
    }  

    // If index number < 1, printf ("Before Grade 1")
    if (CLindex < 1)
    {
        printf("Before Grade 1\n");
        return 0;
        printf("\n");
    }
    // Otherwise print the Grade rounded to no decimal places

    else 
    {
        printf("Grade %d\n", CLindex);
    }
}

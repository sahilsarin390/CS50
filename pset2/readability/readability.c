#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    string text = get_string("Text:");
    int letterscount = 0;
    int wordscount = 1;
    int sentencecount = 0;
    
    for (int i = 0; i <= strlen(text); i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letterscount++;
        }
        else if (text[i] == ' ')
        {
            wordscount++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentencecount++;
        }
    }
    //printf("letters: %i; words: %i; sentences: %i;", letterscount, wordscount, sentencecount);
    
    float index = (0.0588 * (100 * (float) letterscount / (float) wordscount) - 0.296 * (100 * (float) sentencecount /
                   (float) wordscount) - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", (int) round(index));
    }
}
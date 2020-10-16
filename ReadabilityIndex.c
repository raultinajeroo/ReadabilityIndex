#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main(void) {
    char st[1000];
    printf("Input a string (1000 characters or less): ");
    fgets(st, 1000, stdin);

    int letters = 0, sentences = 0, words = 1;
    int n = (int)strlen(st);

    for (int i = 0; i < n; i++)
    {
        //counts the number of letters
        if (isupper(st[i]) || islower(st[i]))
        {
            letters++;
        }
        //counts the number of words
        else if (isspace(st[i]))
        {
            if (isupper(st[i + 1]) || islower(st[i + 1]) || ispunct(st[i + 1]))
            {
                words++;
            }
        }
        //counts the number of sentences, assuming that for each !/?/. there is a sentence
        else if (st[i] == '!' || st[i] == '.' || st[i] == '?')
        {
            sentences++;
        }
    }

    /* To get the index the program uses the Coleman-Liau index, an equation that is utilized to see around what grade the reader would have to be
     * in order to comprehend the reading.
     * More information about this can be found in this URL: https://en.wikipedia.org/wiki/Coleman%E2%80%93Liau_index
     */
    float index = 0.0588 * (float) letters * 100 / (float) words - .296 * (float) sentences * 100 / (float) words - 15.8;

    if (index <= 16 && index >= 1)
    {
        printf("Grade %i\n", (int) round(index));
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }

    return 0;
}

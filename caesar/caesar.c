#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void cesar(string plaintext, int key);

int main(int argc, string argv[])
{
    // promt: single commandline atg for non neg int and its = k
    if (argc != 2)
    {
        printf("need 1 command-line argument -> number to rotate text by\n");
        return 1;
    }

    // formats the input into a integer
    int key = atoi(argv[1]);

    // prompts for input
    printf("plaintext: ");

    string plaintext = get_string();
    cesar(plaintext, key);


    return 0;
}

// this function converts all the plaintext into caesar cyphertext
void cesar(string plaintext, int key)
{
    int cap_ascii = 65;
    int low_ascii = 97;
    int wrapper = 26;
    printf("cyphertext: ");

    if (plaintext != NULL)
    {
        for (int i=0, n=strlen(plaintext); i<n; i++)
        {
            if (isupper(plaintext[i]))
            {
                printf("%c", ((plaintext[i]-cap_ascii+key)%wrapper)+cap_ascii);
            }
            else if (islower(plaintext[i]))
            {
                printf("%c", ((plaintext[i]-low_ascii+ key)%wrapper)+low_ascii);
            }
            else
            {
                printf("%c", plaintext[i]); // doesn't affect non-letters
            }
        }
        printf("\n");

    }

}

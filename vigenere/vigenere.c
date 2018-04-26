#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void vigenere(string plaintext, string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./vigenere key\n");
        return 1;
    }

    string key = argv[1];
    printf("plaintext: ");
    string plaintext = get_string();
    
    vigenere(plaintext, key);
    
    printf("\n");
    return 0;
    
}

void vigenere(string plaintext, string key)
{
    //int cap_ascii = 65;
    //int low_ascii = 97;
    
    printf("cyphertext: ");
    if (plaintext != NULL)
    {
        for (int i=0, n=strlen(plaintext); i<n; i++)
        {
            if (isupper(plaintext[i]))
            {
                // make the key cyclic: (char) ((i) % strlen(key))+cap_ascii
                // outputs the cyphertext = plaintext + cyclic key
                printf("%c", (char) ( plaintext[i]+(i%strlen(key)) ));
            }
            else if (islower(plaintext[i]))
            {
                // outputs the cyphertext = plaintext + cyclic key
                printf("%c", (char) ( plaintext[i]+(i%strlen(key)) ));
            }
            else
            {
                printf("%c", plaintext[i]);
            }
        }
    }
}


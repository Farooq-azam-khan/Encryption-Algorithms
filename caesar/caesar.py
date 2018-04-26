import cs50
import sys

# this function converts all the plaintext into caesar cyphertext
def caesar(plaintext, key):
    # variables
    CAP_ASCII = 65 # capital ascii characters
    LOW_ASCII = 97 # lowercase ascii characters
    WRAPPER = 26 # there are 24 letters in english alphabet
    cyphertext = []
    for i in plaintext:
        if ord(i)>=65 and ord(i)<(65+25): # accepts uppercase
            cypher_char =  chr( ((ord(i)-CAP_ASCII+key) % WRAPPER )+ CAP_ASCII)
            cyphertext.append(cypher_char)
        elif ord(i)>=97 and ord(i)<(97+25): # accepts lowercase
            cypher_char =  chr( ((ord(i) - LOW_ASCII + key) % WRAPPER ) + LOW_ASCII )
            cyphertext.append(cypher_char)
        else:
            cyphertext.append(i)
    return cyphertext

def main():
    # arguments are passed here
    if len(sys.argv) != 2:
        print("arguments needed: key")
        exit(1)
    key = int(sys.argv[1])

    # prompts user for plaintext
    print("Plaintext: ", end=" ")
    plaintext = cs50.get_string()

    # applies the caesar cypher on it
    caesar_cypher = caesar(plaintext, key)

    # formats the cyphertext and gives to user
    for i in caesar_cypher:
        print(i, end='')
    print()
    exit(0)

if __name__ == "__main__":
    main()
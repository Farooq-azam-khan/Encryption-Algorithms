import cs50
import sys

def vigenere(plaintext, key):

    cyphertext = []

    key_length = len(key) #this is the wrapper
    plaintext_list = range(len(plaintext))

    for i,j in zip(plaintext, plaintext_list):

        # accepts uppercase
        if ord(i)>=65 and ord(i)<(65+25):
            cypher_char = chr( ord(i)+(j%key_length) )
            cyphertext.append(cypher_char)

        # accepts lowercase
        elif ord(i)>=97 and ord(i)<(97+25):
            cypher_char = chr( ord(i)+(j%key_length) )
            cyphertext.append(cypher_char)

        else:
            cyphertext.append(i)

    return cyphertext

def main():

    if len(sys.argv) != 2:
        print("argument needed: key (vigenere encryption)")
        exit(1)

    key = sys.argv[1]

    print("Plaintext: ", end=" ")
    plaintext = cs50.get_string()

    vigenere_encryption = vigenere(plaintext, key)
    print(vigenere_encryption)

    exit(0)


if __name__ == "__main__":
    main()
#include <stdio.h>
#include <ctype.h>

#define MAX_TEXT_LENGTH 100

// Function to encrypt a character using the Affine cipher
char encrypt(char c, int keyA, int keyB) {
    if (isalpha(c)) {
        // Convert the character to uppercase for encryption
        c = toupper(c);
        return (((c - 'A') * keyA + keyB) % 26) + 'A';
    }
    return c;
}

// Function to decrypt a character using the Affine cipher
char decrypt(char c, int keyA, int keyB) {
    if (isalpha(c)) {
        // Convert the character to uppercase for decryption
        c = toupper(c);
        int inverse = 0;
        // Find the multiplicative inverse of keyA
        for (int i = 0; i < 26; i++) {
            if ((keyA * i) % 26 == 1) {
                inverse = i;
                break;
            }
        }
        return ((inverse * (c - 'A' - keyB + 26)) % 26) + 'A';
    }
    return c;
}

// Function to perform Affine cipher encryption
void affineEncrypt(char* text, int keyA, int keyB) {
    int i = 0;
    while (text[i]) {
        text[i] = encrypt(text[i], keyA, keyB);
        i++;
    }
}

// Function to perform Affine cipher decryption
void affineDecrypt(char* text, int keyA, int keyB) {
    int i = 0;
    while (text[i]) {
        text[i] = decrypt(text[i], keyA, keyB);
        i++;
    }
}

int main() {
    char plaintext[MAX_TEXT_LENGTH];
    int keyA, keyB;

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter key A (must be coprime with 26): ");
    scanf("%d", &keyA);

    printf("Enter key B: ");
    scanf("%d", &keyB);

    // Encrypt the plaintext
    affineEncrypt(plaintext, keyA, keyB);
    printf("Encrypted text: %s\n", plaintext);

    // Decrypt the encrypted text
    affineDecrypt(plaintext, keyA, keyB);
    printf("Decrypted text: %s\n", plaintext);

    return 0;
}

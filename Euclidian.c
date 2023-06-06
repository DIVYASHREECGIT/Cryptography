#include <stdio.h>

int extended_euclidean_algorithm(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }

    int x1, y1;
    int gcd = extended_euclidean_algorithm(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * y1;

    return gcd;
}

int find_modular_inverse(int a, int m) {
    int x, y;
    int gcd = extended_euclidean_algorithm(a, m, &x, &y);
    if (gcd != 1) {
        printf("Inverse does not exist.\n");
        return -1; // Indicate that the inverse does not exist
    }

    int inverse = (x % m + m) % m;
    return inverse;
}

int main() {
    int a, m;
    printf("Enter a number to find inverse: ");
    scanf("%d", &a);
    printf("Enter the number whose modulus is to be found: ");
    scanf("%d", &m);

    int inverse = find_modular_inverse(a, m);
    if (inverse != -1) {
        printf("Modular inverse of %d mod %d is: %d\n", a, m, inverse);
    }

    return 0;
}

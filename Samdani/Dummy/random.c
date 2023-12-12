#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, digit;
    printf("Enter the number of digits: ");
    scanf("%d", &digit);
    printf("Enter the number of random numbers to generate: ");
    scanf("%d", &n);

    //srand(time(NULL)); // Seed the random number generator with the current time

    for (int i = 0; i < n; i++) {
        int num = 0;
        for (int j = 0; j < digit; j++) {
            num = num * 10 + (rand() % 10); // Generate a random digit and append it to the number
        }
        printf("%d\n", num);
    }

    return 0;
}






#include <stdio.h>

// Function to implement OR gate
int orGate(int a, int b) {
    return a || b;  // Using OR operation
}

int main() {
    // Iterate through all possible input combinations (0, 1) for a and b
    printf("a  b  | OR(a, b)\n");
    printf("-------------------\n");
    
    for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {
            printf(" %d  %d  |     %d\n", a, b, orGate(a, b));
        }
    }

    return 0;
}

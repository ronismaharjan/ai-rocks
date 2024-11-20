#include <stdio.h>

// Function to implement NOT gate
int notGate(int a) {
    return !a;  // Using NOT operation
}

int main() {
    // Iterate through all possible input combinations (0, 1) for a
    printf("a  | NOT(a)\n");
    printf("----------------\n");
    
    for (int a = 0; a <= 1; a++) {
        printf(" %d  |     %d\n", a, notGate(a));
    }

    return 0;
}

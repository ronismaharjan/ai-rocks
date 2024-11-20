#include <stdio.h>

// Function to find the greatest common divisor (GCD)
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to check if the problem is solvable
int isSolvable(int x, int y, int z) {
    return (z <= x && z <= y && z % gcd(x, y) == 0);
}

// Function to perform the water jug problem
void waterJugProblem(int x, int y, int z) {
    // Check if the solution is possible
    if (!isSolvable(x, y, z)) {
        printf("Solution not possible.\n");
        return;
    }

    int jug1 = 0; // Initially, Jug 1 is empty
    int jug2 = 0; // Initially, Jug 2 is empty

    printf("Steps to measure %d liters:\n", z);
    
    // While we don't have the required amount in either jug
    while (jug1 != z && jug2 != z) {
        // If Jug 1 is empty, fill it
        if (jug1 == 0) {
            jug1 = x;
            printf("Fill Jug 1 (Jug 1: %d, Jug 2: %d)\n", jug1, jug2);
        }
        // If Jug 2 is full, empty it
        else if (jug2 == y) {
            jug2 = 0;
            printf("Empty Jug 2 (Jug 1: %d, Jug 2: %d)\n", jug1, jug2);
        }
        // If Jug 1 has water, pour it into Jug 2
        else {
            int temp = jug1 + jug2;
            if (temp <= y) {
                jug2 = temp; // Jug 2 can hold all the water from Jug 1
                jug1 = 0;
            } else {
                jug1 = temp - y; // Jug 2 is full, the rest stays in Jug 1
                jug2 = y;
            }
            printf("Pour water from Jug 1 to Jug 2 (Jug 1: %d, Jug 2: %d)\n", jug1, jug2);
        }
    }
    
    printf("Measured %d liters in one of the jugs.\n", z);
}

int main() {
    int x, y, z;

    // Taking input for the capacities of jugs and the required amount of water
    printf("Enter the capacity of Jug 1: ");
    scanf("%d", &x);
    printf("Enter the capacity of Jug 2: ");
    scanf("%d", &y);
    printf("Enter the amount of water to be measured: ");
    scanf("%d", &z);

    // Solving the water jug problem
    waterJugProblem(x, y, z);

    return 0;
}

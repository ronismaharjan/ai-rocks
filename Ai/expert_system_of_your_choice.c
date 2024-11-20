#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50

// Function to call the Prolog program and pass the symptoms
void call_prolog(char* symptom) {
    char command[MAX_LEN];
    
    // Format the Prolog query based on the user's input
    snprintf(command, sizeof(command), "swipl -s diagnosis.pl -g \"assert(symptom(%s)), diagnose.\" -t halt", symptom);
    
    // Run the Prolog query and print the result
    system(command);
}

int main() {
    char symptom[MAX_LEN];
    char choice;

    // Welcome message
    printf("Welcome to the Cold/Flu Diagnosis Expert System\n");

    // Collect symptoms from the user
    printf("Do you have a cough? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        strcpy(symptom, "cough");
        call_prolog(symptom);
    }
    
    printf("Do you have a fever? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        strcpy(symptom, "fever");
        call_prolog(symptom);
    }

    printf("Do you have a runny nose? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        strcpy(symptom, "runny_nose");
        call_prolog(symptom);
    }

    printf("Do you have sore throat? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        strcpy(symptom, "sore_throat");
        call_prolog(symptom);
    }

    printf("Do you have body aches? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        strcpy(symptom, "body_aches");
        call_prolog(symptom);
    }

    printf("Do you have chills? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        strcpy(symptom, "chills");
        call_prolog(symptom);
    }

    return 0;
}

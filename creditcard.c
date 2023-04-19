#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// function to check if the given credit card number is valid or not
bool isCreditCardValid(char cardType[], char cardNumber[]) {
    // check if the card number is of the correct length
    if (strlen(cardNumber) != 16) {
        printf("Invalid card number length. Please enter a 16-digit card number.\n");
        return false;
    }

    // check if the card number matches the specified card type
    if (strcmp(cardType, "visa") == 0) {
        if (cardNumber[0] != '4') {
            printf("Invalid Visa card number.\n");
            return false;
        }
    } else if (strcmp(cardType, "mastercard") == 0) {
        if (cardNumber[0] != '5' || (cardNumber[1] < '1' || cardNumber[1] > '5')) {
            printf("Invalid Mastercard number.\n");
            return false;
        }
    } else {
        printf("Invalid card type specified.\n");
        return false;
    }

    // if all checks pass, the card number is valid
    printf("Valid card number.\n");
    return true;
}

// main function
int main() {
    char cardType[20], cardNumber[20];
    bool isValid = false;

    // prompt user for card type until a valid one is entered
    while (!isValid) {
        printf("Enter card type (visa or mastercard): ");
        scanf("%s", cardType);
        if (strcmp(cardType, "visa") != 0 && strcmp(cardType, "mastercard") != 0) {
            printf("Invalid card type specified. Please enter 'visa' or 'mastercard'.\n");
        } else {
            isValid = true;
        }
    }

    // prompt user for card number until a valid one is entered
    isValid = false;
    while (!isValid) {
        if (strcmp(cardType, "visa") == 0) {
            printf("Enter 16-digit visa card number: ");
        } else if (strcmp(cardType, "mastercard") == 0) {
            printf("Enter 16-digit mastercard number: ");
        }
        scanf("%s", cardNumber);
        isValid = isCreditCardValid(cardType, cardNumber);
    }

    return 0;
}

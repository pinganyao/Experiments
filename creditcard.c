#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char card_type[10];
    char card_num[20];
    int valid = 0;

    while (!valid) {
        // Prompt user for card type
        printf("Enter card type (visa/mastercard): ");
        scanf("%s", card_type);

        // Check card type
        if (strcmp(card_type, "visa") != 0 && strcmp(card_type, "mastercard") != 0) {
            printf("Invalid card type. Please enter 'visa' or 'mastercard'.\n");
            continue;
        }

        // Prompt user for card number
        printf("Enter credit card number: ");
        scanf("%s", card_num);

        // Check if card number is 16 digits
        if (strlen(card_num) != 16) {
            printf("Invalid card number length. Please enter 16 digits.\n");
            continue;
        }

        // Check card type
        if (strcmp(card_type, "visa") == 0) {
            if (card_num[0] != '4') {
                printf("Invalid card number for visa. Please enter a valid visa card number.\n");
                continue;
            }
        } else if (strcmp(card_type, "mastercard") == 0) {
            if (card_num[0] != '5' || (card_num[1] < '1' || card_num[1] > '5')) {
                printf("Invalid card number for mastercard. Please enter a valid mastercard number.\n");
                continue;
            }
        }

        // If all checks pass, the card number is valid
        printf("Card number is valid.\n");
        valid = 1;
    }

    return 0;
}

#include <cs50.h>
#include <stdio.h>

// Defining variables
long get_card_number(void);
bool card_valid(long number);
void card_type_check(long number);

int main(void)
{
    long card_number = get_card_number(); // Getting card number from the user

    if (card_valid(card_number)) // Checks if card number is valid
    {
        card_type_check(card_number); // Checks what card type
    }
    else
    {
        printf("INVALID\n"); // Prints invalid if card fails Luhn's test
    }
}

// A function to get a credit card number using get_long
long get_card_number(void)
{
    long number;

    do
    {
        number = get_long("Enter Your Credit Card number: ");
    }
    while (number < 0); // Ensuring only positive numbers are accepted
    return number;
}

// Luhn's test to validate credit card number
bool card_valid(long number)
{
    int sum = 0;
    int digit_count = 0;
    bool multiply = false; // Alternating between multiplying and not

    while (number > 0)
    {
        int digit = number % 10; // Getting the last card digit

        if (multiply)
        {
            int sub_sum = digit * 2;
            sum += sub_sum / 10 + sub_sum % 10; // Adding up the sub_sum digits
        }
        else
        {
            sum += digit; // Adding digits otherwise
        }

        multiply = !multiply; // Switch flag
        number /= 10;         // Removing the last digit
        digit_count++;
    }

    return (sum % 10 == 0); // Valid if sum's last digit is zero
}

// A function checking the type of the card
void card_type_check(long number)
{
    int length = 0;
    long first_digits = number;

    // A function to count the card digits and get the first two
    while (first_digits >= 100)
    {
        first_digits /= 10;
        length++;
    }
    length += 2; // Accounting for the last two digits

    // A function to determin card type based on first digits and lentgh
    if ((first_digits / 10 == 4) && (length == 13 || length == 16))
    {
        printf("VISA\n");
    }
    else if ((first_digits == 34 || first_digits == 37) && (length == 15))
    {
        printf("AMEX\n");
    }
    else if ((first_digits >= 51 && first_digits <= 55) && (length == 16))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

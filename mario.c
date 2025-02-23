#include <cs50.h>
#include <stdio.h>



// A function to get the valid pyramid height from user
int get_height(void)
{
    int height;
    do {
        height = get_int("What is the pyramid height?: "); // Using the get_int() cs50 function
    } while (height < 1 || height > 8);
    return height;
}

// A function to print out the pyramid
void print_pyramid(int height)
{
    for (int i = 1; i <= height; i++)
    {
        for (int j = 0; j < height - i; j++)
        {
            printf(" "); // Prints leading up spaces
        }
        // Prints left side of the pyramid
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        // Prints the gap between L & R
        printf("  ");
        // Prints the right side of the pyramid
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        // Prints each row on a new line
        printf("\n");
    }
}

int main()
{
    int height = get_height(); // Gets the input from user
    print_pyramid(height); // Prints out the pyramid
    return 0;
}

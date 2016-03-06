/*
 Kory Bartlett
 COEN 20L
 Lab 4
 Friday 2:15
 24 April 2015
 
 Read ASCII string of eight 0's and 1's from the keyboard into an array of characters.
 Convert the string into an array of integers 0 and 1.
 The least-significant digit is in the first element (subscript 0) of the array.
 Convert the binary array to its 2's complement.
 Print out both the original and 2's complement binary numbers.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIZE 8

void asc2Bin(char *string, int binary[SIZE]);
void PrintBin(int binary[SIZE]);
int bin2Signed(int binary[SIZE]);
void TwosComp(int binary[SIZE]);

int main()
{
    //create variables, strings, and arrays
    int s = 0;
    int bin[SIZE] = { 0 };
    char ascii[101];
    unsigned int u = 0;
    
    //gets the string of binary from the user
    printf("Enter a binary string <8 characters only>: ");
    scanf("%8s", ascii);
    
    //assigns the string of binary characters to an integer array
    asc2Bin(ascii, bin);
    
    printf("Initial binary number:\n");
    PrintBin(bin);
    printf("\n");

    printf("2's complement:\n");
    TwosComp(bin);
    PrintBin(bin);
    printf("\n");
    
    return 0;
}

void asc2Bin(char *string, int binary[SIZE])
{
    int length, i;
    
    //gets the length of the string entered
    length = strlen(string);
    //printf("string length %d\n", length);
    
    //checks to see if the string entered has 8 bits, less than 8 bits, or more than 8 bits
    if (length == 8)
    {
        //assigns the string's values to the corresponding array slots
        for (i = 7; i >= 0; i--)
        {
            //saves characters from string in reverse order
            binary[7 - i] = string[i] - 48;//makes the string values 1 or 0
        }
    }
    
    //when the string of binary input is less than 8 bits
    else if (length < 8)
    {
        for (i = length; i >= 0; i--)
        {
            binary[length - i] = string[i - 1] - 48;
        }
        
        //checks the sign of the binary input
        //fills the empty space in the integer array with corresponding sign value, either 1 or 0
        if ((string[0] - 48) == 0)
        {
            for (i = length; i < 8; i++)
            {
                binary[i] = 0;
            }
        }
        else
        {
            for (i = length; i < 8; i++)
            {
                binary[i] = 1;
            }
        }
    }
    
    else//the length of the string is greater than 8
    {
        //saves the values for the 8 most right bit characters from the string
        int end = length - 8;
        for (i = length; i >= end; i--)
        {
            binary[i] = string[i] - 48;
        }
    }
}

void PrintBin(int binary[SIZE])
{
    int i;
    for (i = SIZE - 1; i >=0; i--)
    {
        printf("%d", binary[i]);
    }
}

void TwosComp(int binary[SIZE])
{
    //flag used as a carry out/in symbolization
    int i, flag = 0;
    
    //trasnverses the number to complement each term
    for(i=0; i < SIZE; i++)
    {
        binary[i] ^= 1;
    }

    //checks the term in the least significant digit
    //if a one exists in the digit, a carry out is created and spot changed to zero
    if(binary[0]==1)
    {
        flag = 1;
        binary[0] = 0;
    }
    
    else
    {
        binary[0] = 1;
    }
    
    //continues the carry out/addition check with the remaining binary digits
    for(i=1; i < SIZE; i++)
    {
        if(flag==1)
        {
            if(binary[i] == 0)
            {
                binary[i] = 1;
                flag = 0;
            }
            
            else
            {
                binary[i] = 0;
            }
        }
    }
}


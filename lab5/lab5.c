#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIZE 8

void asc2Bin(char *string, int binary[SIZE]);
void PrintBin(int binary[SIZE]);
int AddBinary(int first[SIZE], int second[SIZE], int result[SIZE]);
int SubBinary(int first[SIZE], int second[SIZE], int result[SIZE]);

int main()
{
    int first[SIZE], second[SIZE], result[SIZE], cout;
    char ascii[101], ascii2[101];
    
    //gets the string of binary from the user
    printf("Enter the first binary string <8 characters only>: ");
    scanf("%8s", ascii);
    //assigns the string of binary characters to an integer array
    asc2Bin(ascii, first);

    //gets the string of binary from the user
    printf("Enter a second binary string <8 characters only>:  ");
    scanf("%8s", ascii2);
    //assigns the string of binary characters to an integer array
    asc2Bin(ascii2, second);
    
    printf("\n");
    
    cout = AddBinary(first, second, result);
    
    printf("The first plus the second is: ");
    PrintBin(result);
    
    printf("The carry out is: ");
    printf("%d\n", cout);
    
    printf("\n");
    
    cout = SubBinary(first, second, result);
    
    printf("The first less the second is: ");
    PrintBin(result);
    
    printf("The borrow out is: ");
    printf("%d\n", cout);
    
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
    printf("\n");
}

int AddBinary(int first[SIZE], int second[SIZE], int result[SIZE])
{
    int i;
    int flag = 0;
    
    for(i = 0; i < SIZE; i++)
    {
        if(first[i] == 1)
        {
            if(first[i] == second[i])
            {
                if(flag == 0)
                {
                    flag = 1;
                    result[i] = 0;
                }

                else
                {
                    result[i] = 1;
                }
            }
            else
            {
                if(flag == 0)
                {
                    result[i] = 1;
                    flag = 0;
                }
                else
                {
                    result[i] = 0;
                    flag = 1;
                }
            }
        }
        else
        {
            if(first[i] == second[i])
            {
                if(flag == 0)
                {
                    flag = 0;
                    result[i] = 0;
                }
                else
                {
                    result[i] = 1;
                    flag = 0;
                }
            }
            else
            {
                if(flag == 0)
                {
                    flag = 0;
                    result[i] = 1;
                }
                else
                {
                    flag = 1;
                    result[i] = 0;
                }
            }
        }
    }

    return flag;
    
}

int SubBinary(int first[SIZE], int second[SIZE], int result[SIZE])
{
    int i;
    int flag = 0;

    for(i = 0; i < SIZE; i++)
    {
        if(first[i] == 1)
        {
            if(first[i] == second[i])
            {
                if(flag == 0)
                {
                    result[i] = 0;
                }
                
                else
                {
                    result[i] = 1;
                }
            }
            else
            {
                if(flag == 0)
                {
                    result[i] = 1;
                    flag = 0;
                }
                else
                {
                    result[i] = 0;
                    flag = 0;
                }
            }
        }
        else
        {
            if(first[i] == second[i])
            {
                if(flag == 0)
                {
                    result[i] = 0;
                }
                else
                {
                    result[i] = 1;
                    flag = 1;
                }
            }
            else
            {
                if(flag == 0)
                {
                    flag = 1;
                    result[i] = 1;
                }
                else
                {
                    flag = 1;
                    result[i] = 0;
                }
            }
        }
    }

    return flag;
    
}

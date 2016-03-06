/*
Kory Bartlett
COEN 20L
Lab 3
Friday 2:15
17 April 2015

Read ASCII string of eight 0’s and 1’s from the keyboard into an array of characters.
Convert the string into an array of integers 0 and 1.
The least-significant digit is in the first element (subscript 0) of the array. 
If the original string has more than 8 characters use only the last (right-most) 8.
If it has less than 8 characters fill the most-significant bits with zero.
Convert the binary array into an unsigned decimal integer.
Convert the binary array into a signed (2’s complement) decimal integer
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIZE 8

void asc2Bin(char *string, int binary[SIZE]);
unsigned int bin2Unsigned(int binary[SIZE]);
int bin2Signed(int binary[SIZE]);

int main()
{
	//create variables, strings, and arrays
	int s = 0;
	int bin[SIZE] = { 0 };
	char ascii[101];
	unsigned int u = 0;

	//gets the string of binary from the user
	printf("Enter a binary string <8 characters only>:\n");
	scanf("%8s", ascii);

	//assigns the string of binary characters to an integer array
	asc2Bin(ascii, bin);

	//gets the unsigned and signed value of the binary
	u = bin2Unsigned(bin);
	printf("Unsigend value: %d\n", u);
	printf("Sigend value: ");
	s = bin2Signed(bin);
	printf("%d\n", s);

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

unsigned int bin2Unsigned(int binary[SIZE])
{
	unsigned int sum = 0;
	int i;

	//creates the value of the unsigned binary input
	for (i = 0; i < 8; i++)
	{
		sum += (binary[i] * pow(2, i));//does the power of two multiplication
	}

	return sum;
}

int bin2Signed(int binary[SIZE])
{
	//flag used as a carry out/in symbolization
	int i, flag = 0;
	int sum = 0;

	//checks if the binary number is positive or negative
	//if binary positive, repeat same step as finding unsigned value 
	if (binary[7] == 0)
	{
		for (i = 0; i < 7; i++)
		{
			sum += binary[i] * pow(2, i);
		}
	}

	else//negative number calculation
	{
		//generates sum of the first 7-bits
		for (i = 0; i < 7; i++)
		{
			sum += binary[i] * pow(2, i);
		}
		//adds the negative product of the final eigthth bit to the previously aquired sum to get the correct negative number
		sum += -1 * pow(2, i);
	}

	return sum;
}


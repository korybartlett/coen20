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
    int s = 0;
    int bin[SIZE] = {0};
    char ascii[16];
    unsigned int u = 0;
    printf("Enter ASCII string of 8-bits\n");
    scanf("%8s", ascii);

    asc2Bin(ascii, bin);
    
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
    
    length = strlen(string);
    printf("string length %d ", length);
    if(length == 8)
    {
        for(i = 7; i >= 0; i--)
        {
            binary[7-i] = string[i] - 48;
        }
    }
    else if(length < 8)
    {
        for(i = length; i >= 0; i--)
        {
            binary[length - i] = string[i-1] - 48;
        }

        //positive
        if((string[0] - 48) == 0)
        {
            for(i = length; i < 8; i++)
            {
                binary[i] = 0;
            }
        }
        else
        {
            for(i = length; i < 8; i++)
            {
                binary[i] = 1;
            }
        }
    }
    
    else//length>8
    {
        int end = length - 8;
        for(i = length; i >= end ; i--)
        {
            binary[i] = string[i] - 48;
        }
    }
}

unsigned int bin2Unsigned(int binary[SIZE])
{
    unsigned int sum = 0;
    int i;
    
    for (i = 0; i < 8; i++)
    {
        sum += (binary[i] * pow(2,i));
    }
    
    return sum;
}

int bin2Signed(int binary[SIZE])
{
    int i, flag = 0;
    int sum = 0;
    
    if (binary[7] == 0)
    {
        for (i=0; i < 7; i++)
        {
            sum += binary[i] * pow(2,i);
        }
    }
    
    else
    {
	printf("-");
        for(i=0; i < 8; i++)
        {
            binary[i] ^= 1;
        }

	if(binary[0]==1)
	{
		flag = 1;
		binary[0] = 0;
	}
	else
	{
		binary[0] = 1;
	}

        for(i=1; i < 8; i++)
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

        for (i=0; i < 8; i++)
        {
            sum += binary[i] * pow(2,i);
        }
        
    }
    return sum;
}


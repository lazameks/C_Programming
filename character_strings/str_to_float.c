#include <stdio.h>
#include <stdbool.h>

/*
 * strToFloat - Converts a string representation of a float to a float value.
 * @string: The string to be converted.
 *
 * Return: The float value represented by the string.
 *
 * Description: Processes optional negative signs and handles decimal points.
 * Converts the integer and fractional parts separately and stops processing
 * at invalid characters or multiple decimal points.
 */
float strToFloat(const char string[])
{
	int i = 0, intValue;
	float result = 0.0, fraction = 0.1;
        bool isNegative = false, decimal = false;

        while (string[i] == '-')
        {
                if (isNegative)
                        isNegative = false;
                else
                        isNegative = true;
                ++i;
        }


        while ( (string[i] >= '0' && string[i] <= '9') || string[i] == '.' )
        {
		if (string[i] == '.')
		{
			if (decimal)
			{
				printf("Invalid decimal placement");
				break;
			}
			else
			{
				++i;
				decimal = true;
				continue;
			}
		}
		if ( ! decimal )
		{
                	intValue = string[i] - '0';
                	result = result * 10 + intValue;
                	++i;
		}
		else
		{
			intValue = string[i] - '0';
                        result = result + intValue * fraction;
			fraction *= 0.1;
                        ++i;
		}
        }
        if (isNegative)
                result = -result;

        return result;
}
/*
int main (void)
{
	float strToFloat (const char string[]);

	printf ("245.435 to float is %g\n", strToFloat("245.435") );
	printf ("-100.002 + 25.3 tp float is %g\n", strToFloat("-100.002") + 25.3 );
	printf ("---5.666 to float is %g\n", strToFloat("---5.666") );

	return 0;
}
*/

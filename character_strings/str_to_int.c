#include <stdio.h>
#include <stdbool.h>

/*
 * strToInt - Converts a string representation of an integer to an int.
 * @string: The string to be converted.
 *
 * Return: The integer value represented by the string.
 *
 * Description: Handles optional negative signs at the start and iterates
 * through numeric characters to compute the integer value. Stops processing
 * when non-numeric characters are encountered.
 */
int strToInt (const char string[])
{
	int i = 0, intValue, result = 0;
	bool isNegative = false;

	while (string[i] == '-')
	{
		if (isNegative)
			isNegative = false;
		else
			isNegative = true;
		++i;
	}


	while ( string[i] >= '0' && string[i] <= '9' )
	{
		intValue = string[i] - '0';
		result = result * 10 + intValue;
		++i;
	}
	if (isNegative)
		result = -result;

	return result;
}

int main (void)
{
	int strToInt (const char string[]);

	printf ("\"-245\" to integer is %i\n", strToInt("-245"));
	printf ("\"100\" to intrger is %i\n", strToInt("100") + 25);
	printf ("\"--345\" to integer is %i\n", strToInt("--345"));

	return 0;
}

#include <stdio.h>

/**
 * findString - Searches for the first occurrence of `String` within `mainString`.
 *
 * @mainString: The string to be searched.
 * @string: The substring to look for.
 *
 * Return: The starting index of `searchString` in `mainString` if found. 
 * -1 if `searchString` is not found.
 */
int findString(const char mainString[], const char string[])
{
	int i, j = 0, index;

	while ( mainString[j] != '\0')
	{
		if (string[0] == mainString[j])
		{
			index = j, i = 0;

			while(string[i] == mainString[j + i] && string[i] != '\0')
				++i;

			if (string[i] == '\0')
				return (index);
		}
		++j;
	}

	return (-1);
}

/*int main(void)
{
	int index;
	index = findString ("a chatterbox", "hatw");

	printf("the index of your search is %i\n", index);

	return (0);
}
*/

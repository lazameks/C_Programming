#include <stdio.h>

/**
 * removeString - Removes a specified number of characters from a string starting at a given index.
 * @string: The string to modify.
 * @startIndex: The starting index for removal.
 * @numofChar: The number of characters to remove.
 *
 * The function shifts characters left and adjusts the null terminator.
 */
void removeString ( char string[], int startIndex, int numofChar )
{
	int i;

	for (i = startIndex; string[i + numofChar] != '\0'; ++i)
		string[i] = string[i + numofChar];
	string[i] = '\0';
}


/*
int main (void)
{
	char text[] = "the wrong son";
	printf("text before removing string is; %s\n", text);

	removeString( text, 4, 6);

	printf("text after removing string is; %s\n", text);

	return (0);
}
*/

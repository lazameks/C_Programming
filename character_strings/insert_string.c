#include <stdio.h>

/*
 * insertString - Inserts a string into another at a specified position.
 * @sourceString: The original string where insertion will occur.
 * @insertedString: The string to be inserted.
 * @position: The position in the original string to insert the new string.
 *
 * Description: This function validates the position, shifts the characters
 * in sourceString to create space, and inserts the insertedString at the
 * specified position.
 */

void insertString(char sourceString[], char insertedString[], int position)
{
	int i, j, sourceStringLen = 0, insertedStringLen = 0;

	for ( i = 0; sourceString[i] != '\0'; ++i )
		++sourceStringLen;

	for ( i = 0; insertedString[i] != '\0'; ++i )
		++insertedStringLen;

	if (position < 0 || position > sourceStringLen)
        {
                printf("Error: Invalid position.\n");
                return;
        }

	for ( j = sourceStringLen; j >= position; --j )
		sourceString[ j + insertedStringLen ] = sourceString[ j ];

	for ( i = 0; i < insertedStringLen; ++i)
	       sourceString[position + i] = insertedString[i];

	sourceString[sourceStringLen + insertedStringLen] = '\0';
}

/*
int main (void)
{
	char text[30] = "A tree make a forest";
	printf("string before insertion is \"%s\"\n\n", text);

	insertString (text, "cannot ", 7);
	printf("string after insertion is \"%s\"\n", text);

	return (0);
}
*/

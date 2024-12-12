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

/**
 * removeString - Removes a specified number of characters from a string starting at a given index. * @string: The string to modify.
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
 * insertString - Inserts a string into another at a specified position.
 * @sourceString: The original string where insertion will occur.
 * @insertedString: The string to be inserted.
 * @position: The position in the original string to insert the new string.
 *
 * Description: This function validates the position, shifts the characters
 * in sourceString to create space, and inserts the insertedString at the
 * specified position.
 */
void insertString(char sourceString[], const char insertedString[], int position)
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
 * replaceString - Replaces the first occurrence of a substring with another.
 * @source: The source string where the replacement occurs.
 * @s1: The substring to be replaced.
 * @s2: The substring to replace with.
 *
 * Description: Finds the first occurrence of s1 in source, removes it, 
 * and inserts s2 at the same position.
 */
void replaceString (char source[], const char s1[], const char s2[])
{
	int s1Index, s1Len = 0, i;

	int findString(const char mainString[], const char string[]);
	void removeString ( char string[], int startIndex, int numofChar );
	void insertString(char sourceString[], const char insertedString[], int position);

	s1Index = findString ( source, s1 );

	if (s1Index == -1)
	{
		printf("Number to replace not found in the source string\n");
		return;
	}
	else
	{
		for (i = 0; s1[i] != '\0'; ++i)
			++s1Len;

		removeString( source, s1Index, s1Len );
	}

	insertString ( source, s2, s1Index );
}


/*
int main (void)
{
	char myName[25] = "Anibuali Emeka lazarus";

	printf("My name before first replacement is \"%s\"\n\n", myName);

	replaceString( myName, "Emeka", "Lazarus");
	printf("My name after first replacement is \"%s\"\n\n", myName);

	replaceString( myName, "lazarus", "Emeka");
	printf("My name after first replacement is \"%s\"\n\n", myName);

	return (0);
}
*/

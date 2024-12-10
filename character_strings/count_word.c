#include <stdio.h>
#include <stdbool.h>

/**
 * alphabetic - Function to check a character for alphabetic
 * @c: character to checked 
 *
 * Return: bool
 */
bool alphabetic (const char c)
{
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
                return true;
        else
                return false;
}

/**
 * numeric - function to check if a character is a number or not.
 *
 * @c: character to be checked
 *
 * Return: bool
 */
bool numeric (const char c )
{
	if ( (c >= '0' && c <= '9') || c  == ',' || c == '.')
		return true;
	else
		return false;
}

/**
 * readLine - function to read a line of character only
 * @buffer: strings of character to be read
 */
void readLine (char buffer[])
{
        int i = 0;
        char character;

        do
        {
                character = getchar();
                buffer[i] = character;
                ++i;
        }
        while (character != '\n');

        buffer[i - 1] = '\0';
}

/**
 * countWords - The function processes a string and counts the number of words.
 * It treats any sequence of characters separated by whitespace as a word,
 * and has been enhanced to: Count words containing apostrophes (e.g., "don't")
 * as a single word.
 * Treat sequences of numbers, including positive and negative numbers
 * with embedded commas and periods (e.g., "1,000", "-12.5"), as a single word.
 * @string: strings to be processed
 *
 * Return: wordCount as the number word counted
 */
int countWords (const char string[])
{
        int i, wordCount = 0;
        bool lookingForWord = true, alphabetic( const char c ), numeric (const char c );

        for (i = 0; string[i] != '\0'; ++i)
        {
                if ( (alphabetic (string[i])) || ( string[i] == '\'' && i > 0 && 
					alphabetic (string[i - 1]) && alphabetic (string[i + 1])) )
                {
                        if (lookingForWord)
                        {

                                ++wordCount;
                                lookingForWord = false;
                        }
                }
		else if (numeric (string[i]))
		{
			if (lookingForWord)
			{
				++wordCount;
				lookingForWord = false;
			}
		}
                else
                        lookingForWord = true;
        }

        return (wordCount);
}


/**
 * main - Enter the program
 *
 * Retrun: 0
 */
int main (void)
{
        char text[81];
        int totalWords = 0;
        int countWords (const char string[]);
        void readLine (char buffer[]);
        bool endOfText = false;

        printf ("Type in your text.\n");
        printf ("When you are don press 'Return' or 'Enter'. \n\n");

        while ( ! endOfText )
        {
                readLine (text);

                if ( text[0] == '\0')
                        endOfText = true;
                else
                        totalWords += countWords (text);
        }

        printf ("\nThere are %i words in the above text.\n", totalWords);

        return (0);
}

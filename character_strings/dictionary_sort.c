#include <stdio.h>
#include <stdbool.h>

struct entry
{
	char word[15];
	char definition[50];
};
/*
 * alphabetOrder - Compares two strings to check if they are in alphabetical order.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 *
 * Return: true if s1 comes before s2 alphabetically, false otherwise.
 *
 * Description: Compares characters of two strings sequentially until a 
 * mismatch is found or the end of one string is reached.
 */
bool alphabetOrder (const char s1[], const char s2[])
{
        int i = 0;
	bool inOrder;

        while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
                ++i;

        if (s1[i] < s2[i])
                inOrder = true;
        else
		inOrder = false;

        return (inOrder);
}
/*
 * dictionarySort - Sorts an array of dictionary entries in alphabetical order.
 * @dictionary: The array of dictionary entries to be sorted.
 * @size: The number of entries in the dictionary.
 *
 * Description: Uses a bubble sort algorithm and the alphabetOrder function 
 * to arrange the entries alphabetically by their 'word' field.
 */
void dictionarySort (struct entry dictionary[], int size)
{
	int i, j;
	struct entry temp;

	for ( i = 0; i < size - 1; ++i)
		for ( j = i + 1; j < size; ++j )
		{
			if ( ! alphabetOrder( dictionary[i].word, dictionary[j].word) )
			{
				temp = dictionary[i];
				dictionary[i] = dictionary[j];
				dictionary[j] = temp;
			}

		}
}
/**
 * main - Enter the program
 *
 * return (0)
 */
/*
int main (void)
{
	int i;
	struct entry dictionary[20] =
	{
		{ "Phonic",	"about the nature of sound."		},
		{ "Fervor",	"ardor or intensity of feeling"		},
		{ "Posse",	"a force of men."			},
		{ "Endue",	"to endow with some quality."		},
		{ "Vista",	"a view."				},
		{ "Votary",	"consecrated by a vow or promise."	},
		{ "Artful",	"characterized by craft or cunning."	},
		{ "Lucid",	"mentally sound."			},
		{ "Unison",	"a condition of perfect agreement."	},
		{ "Altar",	"where sacrifices may be offered"	},
		{ "Germane",	"relevant."				},
		{ "Probe",	"to search through and through."	},
		{ "What",	"to make more keen or eager."		},
		{ "Matrix",	"that which contains and gives shape."	},
		{ "Canine",	"characteristic of a dog."		}
	};

	printf("word	Definition\n");
	printf("-----	-------------------------------\n");

	for (i = 0; i < 15; ++i)
		printf("%s	%s\n", dictionary[i].word, dictionary[i].definition);

	dictionarySort ( dictionary, 15 );

	printf("\n\nbelow is the dictionary after sorting them in ascending order...\n\n");
	printf("\nword    Definition\n");
        printf("-----   -------------------------------\n");

        for (i = 0; i < 15; ++i)
                printf("%s      %s\n", dictionary[i].word, dictionary[i].definition);

	return (0);
}
*/

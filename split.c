#include "main.h"
#include <stdlib.h>

int lengthOfNextWord(char *string);
int countWords(char *string);
int isQuote(char c);


/**
 * split - splits a string delimited by ' '
 * @string: string pointer
 *
 * Return: an array of malloc'd strings
*/
char **split(char *string)
{
	int number_of_words = countWords(string);
	char *word;
	char **words, **s;
	int word_len = 0;

	word = NULL;
	words = s = NULL;


	if (number_of_words == 0)
		return (NULL);

	/* Allocate space for words and null pointer*/
	words = malloc(sizeof(char *) * (number_of_words + 1));
	s = words;

	if (words == NULL)
		return (NULL);


	while (*string && *string != '#')
	{
		if (*string != ' ')
		{
			/* Allocate enough space the word and a null byte*/
			word_len = lengthOfNextWord(string);
			word = malloc(sizeof(char) * (word_len + 1));

			if (!word)
				return (NULL);

			/*
			 * If current character is a quote, copy only characters
			 * inside of the quotes
			 */
			if (isQuote(*string))
			{
				_strncpy(word, (string + 1), word_len);
				/* Add 2 to jump to account for the two quotes */
				word_len += 2;
			}
			else
				_strncpy(word, string, word_len);

			string += word_len;
			*s = word;
			s++;
		}

		string++;
	}
	words[number_of_words] = NULL;
	return (words);
}

/**
 * lengthOfNextWord - gets the length of the next word in a string
 * @string: string pointer
 *
 * Return: length of the next word in the string pointer
*/
int lengthOfNextWord(char *string)
{
	int i = 0;

	/* Handle words in double quotes e.g "hello world" */
	if (isQuote(*string))
	{
		/*
		 * The reason for adding 1 is to start counting after the
		 * quote
		 * Count until the closing quote is reached
		 */
		while (*(string + i + 1) && !isQuote(*(string + i + 1)))
			i++;
	}
	else
	{
		/* Count until a blank space is reached */
		while (*(string + i) && *(string + i) != ' ')
			i++;
	}


	return (i);
}

/**
 * countWords - returns the total number of words in the string
 * @string: string pointer
 *
 * Return: the number of words in the string pointer
*/
int countWords(char *string)
{
	int words = 0;
	int inWord = 0;
	int inQuotes = 0;

	while (*string && *string != '#')
	{
		/* Character is the first character in a word */
		if (*string != ' ' && inWord == 0)
		{
			if (isQuote(*string))
				inQuotes = 1;

			words++;
			inWord = 1;
		}
		/* Character is a blank space outside of quotes*/
		else if (*string == ' ' && !inQuotes)
		{
			inWord = 0;
		}
		/* Character is a closing quote */
		else if (isQuote(*string) && inQuotes)
		{
			/* set inWord to false & inQuote to false*/
			inWord = 0;
			inQuotes = 0;
		}

		string++;
	}

	return (words);
}

/**
 * isQuote - checks if a character is a quote
 * @c: character
 *
 * Return: 1 if quote otherwise zero
*/
int isQuote(char c)
{
	if (c == '\'' || c == '"')
		return (1);

	return (0);
}

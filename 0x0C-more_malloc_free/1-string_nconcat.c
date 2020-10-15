#include "holberton.h"
#include <stdlib.h>

/**
 * *string_nconcat - concatenates two strings
 * @s1: the first string
 * @s2: the second string
 * @n: the first n bytes
 * Return: a pointer to the allocated memory
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *p;
	unsigned int t1, t2, i, j;

	if (s1 == NULL)
		t1 = 0;
	else
	{
		for (t1 = 0; s1[t1]; ++t1)
			;
	}

	if (s2 == NULL)
		t2 = 0;
	else
	{
		for (t2 = 0; s2[t2]; ++t2)
			;
	}

	if (t2 > n)
		t2 = n;

	p = malloc((t1 + t2 + 1) * sizeof(char));
	if (p == NULL || n <= 0)
		return (NULL);

	for (i = 0; i < t1; i++)
		p[i] = s1[i];

	for (i = 0; i < t2; i++)
		p[t1 + i] = s2[i];

	p[t1 + t2] = '\0';

	return (p);
}

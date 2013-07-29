/* char.c */

/* This file contains functions for converting character formats */

#include "elvis.h"

#ifdef FEATURE_WCHAR

static void *buf;
static size_t size;

/* Convert a string of 8-bit chars to wchar_t */
wchar_t *toCHAR(s)
	char *s;
{
	size_t len;
	size_t need;
	size_t i;

	/* NULL needs no conversion */
	if (!s)
		return NULL;

	/* make sure the buffer is big enough */
	len = strlen(s);
	need = (len + 1) * sizeof(CHAR);
	if (need > size)
	{
		buf = realloc(buf, need);
		size = need;
	}

	/* Copy chars.  Note that latin-1 maps to first 256 Unicode chars */
	i = 0;
	do
	{
		((CHAR *)buf)[i] = ((unsigned char *)s)[i];
	} while (s[i++]);

	/* Return the buffer */
	return (CHAR *)buf;
}

/* Convert a wchar_t string to 8-bit chars */
char *tochar8(s)
	CHAR *s;
{
	size_t len;
	size_t need;
	size_t i;

	/* NULL needs no conversion */
	if (!s)
		return NULL;

	/* make sure the buffer is big enough */
	len = CHARlen(s);
	need = len + 1;
	if (need > size)
	{
		buf = realloc(buf, need);
		size = need;
	}

	/* Copy chars.  Note that latin-1 maps to first 256 Unicode chars */
	i = 0;
	do
	{
		if (s[i] < 256)
			((char *)buf)[i] = s[i];
		else
			((char *)buf)[i] = '?';
	} while (s[i++]);

	/* Return the buffer */
	return (char *)buf;
}
#endif /* FEATURE_WCHAR */

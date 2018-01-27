#include "StringLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Exception.h"

int startsWithString(const char* a, const char* b)
{
	checkIfNULL(a, "At parameter 0 in StartWithString()", EXCEPTION_THROW);
	checkIfNULL(b, "At parameter 1 in StartWithString()", EXCEPTION_THROW);
	if (strncmp(a, b, strlen(b)) == 0) return 1;
	return 0;
}

int indexOfChar(const char* a, char e)
{
	checkIfNULL(a, "At parameter 0 in IndexOFChar()", EXCEPTION_THROW);
	return strchr(a, e) - a;
}


char* sub(const char* a, int start, int end)
{
	checkIfNULL(a, "At parameter 0 in Substring()", EXCEPTION_THROW);
	
	if (start > end)
	{
		int tmp = start;
		start = end;
		end = tmp;
	}
	if (start < 0 || start > length(a))
	{
		throwIndexOutOfBoundsException(start, "Start out of range in SUB()", 0);
	}
	if (end < 0 || end > length(a))
	{
		throwIndexOutOfBoundsException(end, "End out of range in SUB()", 0);
	}

	char* result = (char*)malloc((end - start + 1) * sizeof(char));
	checkIfNULL(result,"Malloc Returned Null in SUB()", EXCEPTION_THROW);
	int counter = 0;
	int i = start;
	for (; i < end; i++)
	{
		result[counter] = a[i];
		counter++;
	}
	result[counter] = 0;
	return result;
}

char charAtIndex(const char* a, int index)
{
	checkIfNULL(a,"At parameter 0 in Char At Index()", EXCEPTION_THROW);
	if (index < 0 || index > length(a))
	{
		throwIndexOutOfBoundsException(index, "At parameter in Char At Index()", 0);
	}
	return a[index];
}


int endsWithString(const char* a, const char* b)
{
	checkIfNULL(a, "At parameter 0 in Ends With String()", EXCEPTION_THROW);
	checkIfNULL(b, "At parameter 1 in Ends With String()", EXCEPTION_THROW);

	int i = length(a) - 1;
	int lb = length(b) - 1;
	int counter = 0;
	for (; i >= 0; i--)
	{
		if (a[i] != b[lb - counter])
		{
			return 0;
		}
		counter++;
	}
	return 1;
}
int indexOfCharAfterIndex(const char* a, char e, int offset)
{

	checkIfNULL(a, "At parameter 0 in IndexOfCharAfterIndex()", EXCEPTION_THROW);

	int len = length(a);
	if (offset < 0 || offset > len)
	{
		throwIndexOutOfBoundsException(offset, "At parameter in Offset out of range()", 0);
	}
	int i = offset;
	for (; i < len; i++)
	{
		if (a[i] == e)
		{
			return i;
		}
	}
	return -1;
}
int length(const char* a)
{
	checkIfNULL(a,"At parameter 0 in Length()", EXCEPTION_THROW);

	return strlen(a) + 1;
}

char* trim(char* a)
{
	checkIfNULL(a, "At parameter 0 in Trim()", EXCEPTION_THROW);

	char* result = (char*)malloc(length(a) * sizeof(char));
	checkIfNULL(result, "Malloc Returned Null in Trim()", EXCEPTION_THROW);

	int i = 0;
	int len = length(a) - 1;
	int foundEndOfBeginningSpace = 0;
	int counter = 0;
	for (; i < len; i++)
	{
		if ((a[i] == '\n' || a[i] == '\t' || a[i] == ' ') && foundEndOfBeginningSpace == 0)
		{
			continue;
		}
		else
		{
			result[counter++] = a[i];
			foundEndOfBeginningSpace = 1;
		}
	}
	result[i] = 0;

	int j = strlen(result) - 1;
	for (; j >= 0; j--)
	{
		if (result[j] == '\n' || result[j] == '\t' || result[j] == ' ')
		{
			result[j] = 0;
		}
		else
		{
			break;
		}
	}

	return result;
}





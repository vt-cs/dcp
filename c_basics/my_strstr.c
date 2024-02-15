#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool mystrstr (char *haystack, char *needle)
{
    if (haystack == NULL || needle == NULL)
    {
        return false;
    }
    else
    {
        int needle_index=0;
        for (int haystack_index=0; haystack_index<strlen(haystack); ++haystack_index)
	{
            if (needle_index == strlen(needle)-1)
	    {
                return true;
	    }
	    else if (haystack[haystack_index] == needle[needle_index])
	    {
                ++needle_index;
		continue;
	    }
            else
	    {
                needle_index=0;
	    }
	}
	return false;
    }
}

int main (int argc, char **argv)
{
    char *tmp1 = "this is vivek tripathi";
    char *tmp2 = "vivek";
    char *tmp3 = "tripathi";
    char *tmp4 = "is";
    char *tmp5 = "this is vivek no match";

    printf ("%d\n", mystrstr(tmp1, tmp2));
    printf ("%d\n", mystrstr(tmp1, tmp3));
    printf ("%d\n", mystrstr(tmp1, tmp4));
    printf ("%d\n", mystrstr(tmp1, tmp5));

    return 0;
}

#include <stdio.h>

// 1 = if substr is present
// 0 - else
// main = vivek
// sub - vek = 1
// sub - abc = 0
int check_substr(char *main_str, char *substr)
{
    int mlen = main_str;
    int in_progress = 0;
    for (int i=0; i<strlen(main_str); ++i)
    {
        if (in_progress == 0)
	{
            int j = 0;

	}
	if (j == strlen(substr)-1)
	{
              return 1;
	}
	if (main_str[i] == substr[j] && j<strlen(substr))
	{
            in_progress = 1;
	    ++j;
	}
	else
	{
            in_progress = 0;
	}
    }
    return 0;

}

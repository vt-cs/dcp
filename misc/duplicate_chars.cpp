/*
 * Program: print all duplicate characters present in the input string
 */

#include <iostream>

int main (int argc, char **argv)
{
    std::string input;
    std::cin >> input;

    int charmap[26] = {0};
    for (long unsigned int i=0; i<input.size(); ++i)
    {
        if (charmap[input[i]-'a'] == 0)
	{
            charmap[input[i]-'a'] = 1;
	}
	else
	{
            std::cout << input[i];
	}
    }
    std::cout << std::endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>


int main (int argc, char **argv)
{
    std::vector<int> input_arr;
    std::vector<std::vector<int>> result;

    input_arr.push_back (2);
    input_arr.push_back (4);
    input_arr.push_back (5);
    input_arr.push_back (6);
    input_arr.push_back (11);
    input_arr.push_back (12);
    input_arr.push_back (13);
    input_arr.push_back (21);
    input_arr.push_back (24);

    int flag = 1;
    int set_start;

    std::sort (input_arr.begin(), input_arr.end());

    for (long unsigned int i=0; i<input_arr.size(); ++i)
    {
        if (flag == 1)
	{
            set_start = input_arr[i];
	    flag = 0;
	}
	if (i==input_arr.size()-1 || input_arr[i]+1 != input_arr[i+1])
	{
            std::vector<int> tmp;
	    if (set_start != input_arr[i])
	    {
                tmp.push_back (set_start);
		tmp.push_back (input_arr[i]);
		std::cout << "set: " << set_start << ", " << input_arr[i] << std::endl;
	    }
	    else
	    {
                tmp.push_back (input_arr[i]);
		std::cout << "set: " << input_arr[i] << std::endl;
	    }
	    result.push_back (tmp);
            flag = 1;
	}
    }

    return 0;
}

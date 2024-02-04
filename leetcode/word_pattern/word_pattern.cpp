#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    bool wordPattern(std::string pattern, std::string s)
    {
        std::unordered_map<char, std::string> c_map;
        std::unordered_map<std::string, char> s_map;

        std::vector<std::string> word_collection;
        
        long unsigned int word_len = 0;
        std::string word;
        for (long unsigned int i=0; i<s.size(); ++i)
        {
            if (s[i] != ' ')
            {
                word.push_back(s[i]);
                continue;
            }
            else
            {
                word_collection.push_back(word);
                std::cout << word << std::endl;

                word.clear();
                ++word_len;
            }
        }
        word_collection.push_back(word);
        std::cout << word << std::endl;
        word.clear();
	++word_len;

        if (word_len != pattern.size())
        {
            return false;
        }
	std::cout << "word len is equal to pattern size" << std::endl;
	return true;
    }
};

int main (int argc, char **argv)
{
    Solution solution;

    // inputs
    std::string pattern = "abba";
    std::string s = "dog cat cat dog";

    solution.wordPattern(pattern, s);

    return 0;
}

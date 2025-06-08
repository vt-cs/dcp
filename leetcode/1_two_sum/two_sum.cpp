/*
1. Two Sum
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]

Constraints:
2 <= nums.length <= 10^4
-10^9 <= nums[i] <= 10^9
-10^9 <= target <= 10^9
Only one valid answer exists.
 
Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
*/

#include <iostream>

#include <vector>
#include <unordered_map>

#include <algorithm>


void testcase_1(std::vector<int> &nums, int &target, std::vector<int> &expected_result);
void testcase_2(std::vector<int> &nums, int &target, std::vector<int> &expected_result);
class solution;

class solution
{
    public:
        std::vector<int> two_sum(std::vector<int> &nums, int target)
	{
            std::vector<int> result;
            std::unordered_map<int, int> hash;
	    for(unsigned int i=0; i<nums.size(); ++i)
	    {
                if (hash.find(target-nums[i]) != hash.end())
		{
		    result.push_back(hash[target-nums[i]]);
		    result.push_back(i);
		    return result;
		}
		else
		{
                    hash[nums[i]] = i;
		}
	    }
	    return result;
	}
};

int main(int argc, char **argv)
{
    int target;
    std::vector<int> nums;
    std::vector<int> expected_result;
    std::vector<int> obtained_result;

    solution ref_obj;

    testcase_1(nums, target, expected_result);

    obtained_result = ref_obj.two_sum(nums, target);

    std::sort(expected_result.begin(), expected_result.end());
    std::sort(obtained_result.begin(), obtained_result.end());
    if (expected_result == obtained_result)
    {
        std::cout << "testcase 1: pass" << std::endl;
    }
    else
    {
        std::cout << "testcase 1: fail" << std::endl;
    }
    
    testcase_2(nums, target, expected_result);

    obtained_result = ref_obj.two_sum(nums, target);

    std::sort(expected_result.begin(), expected_result.end());
    std::sort(obtained_result.begin(), obtained_result.end());
    if (expected_result == obtained_result)
    {
        std::cout << "testcase 2: pass" << std::endl;
    }
    else
    {
        std::cout << "testcase 2: fail" << std::endl;
    }


    return 0;
}

void testcase_1(std::vector<int> &nums, int &target, std::vector<int> &expected_result)
{
    nums.clear();
    expected_result.clear();

    target = 9;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);

    expected_result.push_back(0);
    expected_result.push_back(1);
}

void testcase_2(std::vector<int> &nums, int &target, std::vector<int> &expected_result)
{
    nums.clear();
    expected_result.clear();

    target = 6;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(4);

    expected_result.push_back(1);
    expected_result.push_back(2);
}

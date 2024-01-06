/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1.
To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored.
nums2 has a length of n.
*/

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        while (n > 0)
        {
            if (m>0 && nums1[m-1] >= nums2[n-1])
            {
                nums1[m+n-1] = nums1[m-1];
                --m;
            }
            else
            {
                nums1[m+n-1] = nums2[n-1];
                --n;
            }
        }
    }
};

int main (int argc, char **argv)
{
    Solution solution;

    // inputs
    vector<int> nums1 = {1,2,3,0,0,0};
    int m = 3;
    vector<int> nums2 = {2,5,6};
    int n = 3;

    // expected output
    vector<int> expected_nums = {1,2,2,3,5,6};

    // call the implementation
    solution.merge(nums1, m, nums2, n);

    // check for expected output and actual output
    for (int i=0; i<m+n; ++i)
    {
        assert (nums1[i] == expected_nums[i]);
    }
    cout << "pass\n";

    return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>
#include <climits>


// !-----------    Count One`s   ------------!

/*
Given a sorted binary array, efficiently count the total number of 1's in it.

Input: [0, 0, 0, 0, 1, 1, 1]
Output: 3

Input: [0, 0, 1, 1, 1, 1, 1]
Output: 5
*/
class Solution_1
{
public:
    int countOnes(std::vector<int> const &nums)
    {
        int count = 0;

        for (auto& element : nums)
        {
            if (element == 1)
            {
                ++count;
            }
        }

        return count;
    }
};






// !-----------    Negative Count Matrix    ------------!

/*
Given an `M × N` row-wise and column-wise sorted integer matrix, find the total number of negative numbers in it in linear time.

Input:

[
	[-7, -3, -1, 3, 5],
	[-3, -2,  2, 4, 6],
	[-1,  1,  3, 5, 8],
	[ 3,  4,  7, 8, 9]
]

Output: 6
*/
class Solution_2
{
public:
    int negativeCount(std::vector<std::vector<int>> const &mat)
    {
        int count = 0;

        for (int i = 0; i != mat.size(); ++i)
        {
            for (int j = 0; j != mat[0].size(); ++j)
            {
                if (mat[i][j] < 0)
                {
                    ++count;
                }
            }
        }

        return count;
    }
};








// !------------    Sort Array Single Swap     -----------!
/*
Given an integer array where all its elements are sorted in increasing order except two swapped elements, in-place sort it in linear time. Assume there are no duplicates in the array.

Input : [3, 8, 6, 7, 5, 9] or [3, 5, 6, 9, 8, 7] or [3, 5, 7, 6, 8, 9]
Output: [3, 5, 6, 7, 8, 9]
*/

class Solution_3
{
public:
    void sortArray(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
    }
};









// !-----------     Largest Subarray     ----------!

/*
Given a binary array containing 0’s and 1’s, find the largest contiguous subarray with equal numbers of 0’s and 1’s.

Input : [0, 0, 1, 0, 1, 0, 0]
Output: [0, 1, 0, 1] or [1, 0, 1, 0]

Input : [0, 0, 0, 0]
Output: []

Note: Since an input can contain several largest subarrays with equal numbers of 0’s and 1’s, the code should return any one of them.
*/
class Solution_4
{
public:
    std::vector<int> findLargestSubarray(std::vector<int> const &nums)
    {
        std::unordered_map <int, int> map;
        map[0] = -1;

        int sum = 0;
        int len = 0;
        int count = 0;
        int start = -1;

        for (int i = 0; i != nums.size(); ++i)
        {
            count += (nums[i] == 0) ? -1 : 1;

            if (map.find(count) != map.end())
            {
                if (i - map[count] > len)
                {
                    len = i - map[count];
                    start = map[count] + 1;
                }
            }else
            {
                map[count] = i;
            }
        }

        if (start != -1)
        {
            return std::vector<int> (nums.begin() + start, nums.begin() + start + len);
        }
        return {};
    }
};










// !-----------     Rotated Palindrome    ------------!

/*
Given a string, check if it is a rotated palindrome or not.

Input: "CBAABCD"
Output: true
Explanation: "CBAABCD" is a rotation of the palindrome "ABCDCBA"

Input: "BAABCC"
Output: true
Explanation: "BAABCC" is a rotation of the palindrome "ABCCBA"

Input: "DCABC"
Output: false
*/
class Solution_5
{
public:
    bool isPalindrome(std::string s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    bool isRotatedPalindrome(std::string s)
    {
        std::string doubled = s + s;
        int len = s.length();
        for (int i = 0; i < len; i++) {
            if (isPalindrome(doubled.substr(i, len))) {
                return true;
            }
        }
        return false;
    }

};






// !------------    Maximum Continuous Sequence    -------------!

/*
Given a binary array, find the index of 0 to be replaced with 1 to get the maximum length sequence of continuous ones. The solution should return the index of first occurence of 0, when multiple continuous sequence of maximum length is possible.

Input : [0, 0, 1, 0, 1, 1, 1, 0, 1, 1]
Output: 7
Explanation: Replace index 7 to get the continuous sequence of length 6 containing all 1’s.

Input : [0, 1, 1, 0, 0]
Output: 0
Explanation: Replace index 0 or 3 to get the continuous sequence of length 3 containing all 1’s. The solution should return the first occurence.

Input : [1, 1]
Output: -1
Explanation: Invalid Input (all 1’s)
*/
class Solution_6
{
public:
    int findIndexofZero(std::vector<int> const &nums)
    {
        std::map<int, int> map;
        int count = 0;
        int maxCount = 0;
        int n = nums.size();

        if (nums[0] == 1 && nums[1] == 1 && n == 2)
        {
            return -1;
        }
        else if (nums[0] == 0 && nums[1] == 0 && n == 2)
        {
            return 0;
        }

        for (int i = 0; i < nums.size() ; i++) {
            if (nums[i] == 1) {
                count++;
            } else {
                if (count > 0) {
                    map[count] = i;
                    maxCount = std::max(maxCount, count);
                    count = 0;
                }
            }
        }
        if (count > 0) {
            map[count] = nums.size() - count;
            maxCount = std::max(maxCount, count);
        }

        return map[maxCount];
    }

};
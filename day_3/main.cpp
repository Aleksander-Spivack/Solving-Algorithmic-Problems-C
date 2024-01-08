#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <climits>



// !---------     Maximum Sum Subarray    ---------!

/*
Given an integer array, find the maximum sum among all its subarrays.

Input : [-2, 1, -3, 4, -1, 2, 1, -5, 4]
Output: 6
Explanation: The maximum sum subarray is [4, -1, 2, 1]

Input : [-7, -3, -2, -4]
Output: -2
Explanation: The maximum sum subarray is [-2]

Input : [-2, 2, -1, 2, 1, 6, -10, 6, 4, -8]
Output: 10
Explanation: The maximum sum subarray is [2, -1, 2, 1, 6] or [6, 4] or [2, -1, 2, 1, 6, -10, 6, 4]

*/
class Solution_1
{
public:
    int findMaxSubarraySum(std::vector<int> const &nums)
    {
        int sum = nums[0];
        int maxSum = nums[0];

        for (int i = 1; i != nums.size(); ++i)
        {
            sum = std::max(nums[i], sum + nums[i]);
            maxSum = std::max(maxSum, sum);
        }
        return maxSum;
    }
};






// !------------      Move Zeroes to End     ------------!

/*
Given an integer array, in-place move all zeros present in it to the end. The solution should maintain the relative order of items in the array and should not use constant space.

Input : [6, 0, 8, 2, 3, 0, 4, 0, 1]
Output: [6, 8, 2, 3, 4, 1, 0, 0, 0]
*/
class Solution_2
{
public:
    void rearrange(std::vector<int> &nums)
    {
        int left = 0;

        for (int i = 0; i != nums.size(); ++i)
        {
            if (nums[i] != 0)
            {
                std::swap(nums[i], nums[left]);
                ++left;
            }
        }
    }
};





// !-----------     Sorted Merge Arrays    ------------!

/*
Given two integer arrays, each of which is sorted in increasing order, merge them into a single array in increasing order, and return it.

Input: X = [1, 3, 5, 7], Y = [2, 4, 6]
Output: [1, 2, 3, 4, 5, 6, 7]
*/
class Solution_3
{
public:
    std::vector<int> merge(std::vector<int> const &X, std::vector<int> const &Y)
    {
        std::vector <int> vector;

        for (auto& elem : X)
        {
            vector.push_back(elem);
        }

        for (auto& elem : Y)
        {
            vector.push_back(elem);
        }

        std::sort(vector.begin(), vector.end());
        return vector;
    }
};






// !------------    Sorted Merge Arrays II    -------------!

/*
Given two sorted integer arrays, merge them into a single array in decreasing order, and return it. In other words, merge two sorted arrays from their end.

Input : X = [1, 3, 5], Y = [2, 6, 7, 10]
Output: [10, 7, 6, 5, 3, 2, 1]
*/
class Solution_4
{
public:
    std::vector<int> merge(std::vector<int> const &X, std::vector<int> const &Y)
    {
        std::vector <int> vector;

        for (auto& elem : X)
        {
            vector.push_back(elem);
        }

        for (auto& elem : Y)
        {
            vector.push_back(elem);
        }

        std::sort(vector.begin(), vector.end());
        std::reverse(vector.begin(), vector.end());
        return vector;
    }
};





// !------------    Check Anagram   -----------!

/*
Given two strings, determine whether they are anagrams.

Any word that exactly reproduces the letters in another order is an anagram. In other words, X and Y are anagrams if by rearranging the letters of X, we can get Y using all the original letters of X exactly once.

Input: X = "silent", Y = "listen"
Output: true

Input: X = "incest", Y = "insect"
Output: true
*/
class Solution_5
{
public:
    bool isAnagram(std::string X, std::string Y)
    {
        std::sort(X.begin(), X.end());
        std::sort(Y.begin(), Y.end());

        return X == Y;
    }
};






// !----------    Maximum Product Pair    -----------!

/*
Given an integer array, find a pair with the maximum product in it.

Each input can have multiple solutions. The output should match with either one of them.

Input : [-10, -3, 5, 6, -2]
Output: (-10, -3) or (-3, -10) or (5, 6) or (6, 5)

Input : [-4, 3, 2, 7, -5]
Output: (3, 7) or (7, 3)

If no pair exists, the solution should return the pair (-1, -1).

Input : [1]
Output: (-1, -1)
*/
class Solution_6
{
public:
    std::pair<int,int> findPair(std::vector<int> const &nums)
    {
        int max1 = INT_MIN, max2 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;

        if (nums.size() == 1 || nums.empty())
        {
            return {-1, -1};
        }

        for (auto& num : nums)
        {
            if (num > max1)
            {
                max2 = max1;
                max1 = num;
            }else if (num > max2)
            {
                max2 = num;
            }

            if (num < min1)
            {
                min2 = min1;
                min1 = num;
            }else if (num < min2)
            {
                min2 = num;
            }
        }

        if (max1 * max2 > min1 * min2)
        {
            return {max1, max2};
        }
        else
        {
            return  {min1, min2};
        }
    }
};








//  !----------    Majority Element    -----------!

/*
Given an integer array of size `n`, return the element which appears more than `n/2` times. Assume that the input always contain the majority element.

Input : [2, 8, 7, 2, 2, 5, 2, 3, 1, 2, 2]
Output: 2

Input : [1, 3, 1, 1]
Output: 1
*/
class Solution_7
{
public:
    int findMajorityElement(std::vector<int> &nums)
    {
        int element = nums[0];
        int count = 1;

        for (size_t i = 1; i != nums.size(); ++i)
        {
            if (element == nums[i])
            {
                ++count;
            }else
            {
                --count;

                if (count == 0)
                {
                    element = nums[i];
                    ++count;
                }
            }

        }
        return element;
    }
};






// !----------    Search Sorted Array    -----------!

/*
Given a sorted integer array and a target, determine if the target exists in the array in logarithmic time. If target exists in the array, the procedure should return the index of it.

Input: nums[] = [2, 3, 5, 7, 9], target = 7
Output: 3
Explanation: Element found at 4th (index 3) position

• If there are duplicate elements in the array, the procedure may return any index whose element is equal to the target.

Input: nums[] = [1, 2, 3, 4, 4, 5, 6, 7], target = 4
Output: 3 (or 4)
Explanation: Element found at the 4th (index 3) or 5th (index 4) position.

• If the target is not located, the procedure should return -1.

Input: nums[] = [1, 4, 5, 8, 9], target = 2
Output: -1
*/
class Solution_8
{
public:
    int findIndex(std::vector<int> const &nums, int target)
    {
        for (int i = 0; i != nums.size(); ++i)
        {
            if (nums[i] == target)
            {
                return i;
            }
        }
        return -1;
    }
};





// !------------    First and Last Occurrence   ------------!

/*
Given a sorted integer array, find the index of a given number's first and last occurrence.

Input: nums[] = [2, 5, 5, 5, 6, 6, 8, 9, 9, 9], target = 5
Output: (1, 3)
Explanation: The first and last occurrence of element 5 is located at index 1 and 3, respectively.

• If the target is not present in the array, the solution should return the pair (-1, -1).

Input: nums[] = [2, 5, 5, 5, 6, 6, 8, 9, 9, 9], target = 4
Output: (-1, -1)
*/
class Solution_9
{
public:
    std::pair<int,int> findPair(std::vector<int> const &nums, int target)
    {
        int first = -1;
        int last = -1;

        for (int i = 0; i != nums.size(); ++i)
        {
            if (nums[i] == target)
            {
                ++last;

                if (last == 0)
                {
                    first = i;
                    last = first;
                }
            }

        }

        return {first, last};
    }
};

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>



// !--------     Derive Strings    --------!

/*
Check if a given string can be derived from another string by circularly rotating it. The rotation can be in a clockwise or anti-clockwise rotation.

Input: X = "ABCD", Y = "DABC"
Output: true
Explanation: "DABC" can be derived from "ABCD" by right-rotating it by 1 unit
*/
class Solution_1
{
public:
    bool check(std::string X, std::string Y)
    {
        // [ A B C D ]   .  [ D A B C ]
        int first_it = 0;
        int second_it = 0;

        std::sort(Y.begin(), Y.end());
        std::sort(X.begin(), X.end());

        while (first_it != Y.size())
        {
            if (Y[first_it] == X[second_it])
            {
                ++second_it;
            }

            ++first_it;

            if (second_it == first_it && first_it == Y.size() && second_it == X.size())
            {
                return true;
            }
        }

        return false;
    }
};




// !----------    Rotate Matrix    ---------!

/*

Given an `N × N` integer matrix, rotate the matrix by 90 degrees in a clockwise direction. The transformation should be done in-place and in quadratic time.

Input:

[
	[1,  2,  3,  4],
	[5,  6,  7,  8],
	[9,  10, 11, 12],
	[13, 14, 15, 16],
]

Output:

[
	[13, 9,  5, 1],
	[14, 10, 6, 2],
	[15, 11, 7, 3],
	[16, 12, 8, 4]
]

*/
class Solution_2
{
public:
    void rotateMatrix(std::vector<std::vector<int>> &mat)
    {
        if (mat.empty())
        {
            return;
        }

        int n = mat.size();

        for (int i = 0; i < n / 2; ++i)
        {
            int first = i;
            int end = n - i - 1;

            for (int j = first; j < end; ++j)
            {
                int offset = j - first;
                int top = mat[first][j];

                mat[first][j] = mat[end - offset][first];

                mat[end - offset][first] = mat[end][end - offset];

                mat[end][end - offset] = mat[j][end];

                mat[j][end] = top;
            }
        }

    }

};







// !----------- Maximum Length Subarray --------!

/*

Given an integer array, find the maximum length contiguous subarray having a given sum.

Input : nums[] = [5, 6, -5, 5, 3, 5, 3, -2, 0], target = 8
Output: [-5, 5, 3, 5]
Explanation: The subarrays with sum 8 are [[-5, 5, 3, 5], [3, 5], [5, 3]]. The longest subarray is [-5, 5, 3, 5] having length 4.

Note: Since an input can contain several maximum length subarrays with given sum, the solution should return any one of the maximum length subarray.

*/
class Solution_3
{
public:
    std::vector<int> findMaxLenSubarray(std::vector<int> const &nums, int target) {
        std::unordered_map<int, int> map;
        std::vector<int> maxSubarray;
        int len = 0;
        int sum = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];

            if (sum == target)
            {
                len = i + 1;
                maxSubarray = std::vector<int>(nums.begin(), nums.begin() + len);
            }
            else if (map.find(sum - target) != map.end())
            {
                if (i - map[sum - target] > len)
                {
                    len = i - map[sum - target];
                    maxSubarray = std::vector<int>(nums.begin() + map[sum - target] + 1, nums.begin() + i + 1);
                }
            }

            if (map.find(sum) == map.end()) {
                map[sum] = i;
            }
        }

        return maxSubarray;
    }
};







// !---------    Rotate Matrix II    ----------!

/*
Given an `N × N` integer matrix, rotate the matrix by 180 degrees in a clockwise direction. The transformation should be done in-place and in quadratic time.

Input:

[
	[1,  2,  3,  4],
	[5,  6,  7,  8],
	[9,  10, 11, 12],
	[13, 14, 15, 16],
]

Output:

[
	[16, 15, 14, 13],
	[12, 11, 10, 9],
	[8, 7, 6, 5],
	[4, 3, 2, 1]
]
*/
class Solution_4
{
public:
    void rotateMatrixII(std::vector<std::vector<int>> &mat)
    {
        if (mat.empty())
        {
            return;
        }

        int n = mat.size();

        for (int i = 0; i < n / 2; ++i)
        {
            int first = i;
            int end = n - i - 1;

            for (int j = first; j < end; ++j)
            {
                int offset = j - first;
                int top = mat[first][j];

                mat[first][j] = mat[end - offset][first];

                mat[end - offset][first] = mat[end][end - offset];

                mat[end][end - offset] = mat[j][end];

                mat[j][end] = top;
            }
        }

        for (int i = 0; i < n / 2; ++i)
        {
            int first = i;
            int end = n - i - 1;

            for (int j = first; j < end; ++j)
            {
                int offset = j - first;
                int top = mat[first][j];

                mat[first][j] = mat[end - offset][first];

                mat[end - offset][first] = mat[end][end - offset];

                mat[end][end - offset] = mat[j][end];

                mat[j][end] = top;
            }
        }

    }

};
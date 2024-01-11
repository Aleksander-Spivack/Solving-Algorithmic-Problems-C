#include <iostream>
#include <vector>
#include <unordered_set>
#include <climits>
#include <algorithm>
#include <valarray>
#include <set>






// !---------   Spiral Matrix   ---------!

/*
Given an `M × N` integer matrix, return its elements in spiral order.

Input:

[
	[ 1   2   3   4  5],
	[16  17  18  19  6],
	[15  24  25  20  7],
	[14  23  22  21  8],
	[13  12  11  10  9]
]

Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25]
*/
class Solution_1
{
public:
    std::vector<int> spiralTraversal(std::vector<std::vector<int>> const &mat)
    {
        std::vector<int> nums;

        if (mat.size() == 0) {
            return nums;
        }

        int top = 0, bottom = mat.size() - 1;
        int left = 0, right = mat[0].size() - 1;

        while (1)
        {
            if (left > right) {
                break;
            }

            for (int i = left; i <= right; i++) {
                nums.push_back(mat[top][i]);
            }
            top++;

            if (top > bottom) {
                break;
            }

            for (int i = top; i <= bottom; i++) {
                nums.push_back(mat[i][right]);
            }
            right--;

            if (left > right) {
                break;
            }

            for (int i = right; i >= left; i--) {
                nums.push_back(mat[bottom][i]);
            }
            bottom--;

            if (top > bottom) {
                break;
            }

            for (int i = bottom; i >= top; i--) {
                nums.push_back(mat[i][left]);
            }
            left++;
        }
    }
};










// !-------------  Sort Array   ---------------!

/*
Given an integer array, in-place sort it without using any inbuilt functions.

Input : [6, 3, 4, 8, 2, 9]
Output: [2, 3, 4, 6, 8, 9]

Input : [9, -3, 5, -2, -8, -6]
Output: [-8, -6, -3, -2, 5, 9]
*/
class Solution_2
{
public:
    void sort(std::vector<int> &nums)
    {
        int n = nums.size() - 1;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n - i; ++j)
            {
                if (nums[j] > nums[j+1])
                {
                    std::swap(nums[j], nums[j+1]);
                }
            }
        }
    }
};










// !------------   Floor and Ceil   -------------!

/*
Given a sorted integer array, find the floor and ceiling of a given number in it. For a given number x, floor(x) is the largest integer in the array less than or equal to x, and ceil(x) is the smallest integer in the array greater than or equal to x.

The solution should return the (floor, ceil) pair. If the floor or ceil doesn't exist, consider it to be -1.

Input: nums[] = [1, 4, 6, 8, 9], x = 2
Output: (1, 4)
Explanation: The floor is 1 and ceil is 4

Input: nums[] = [1, 4, 6, 8, 9], x = 6
Output: (6, 6)
Explanation: The floor is 6 and ceil is 6

Input: nums[] = [-2, 0, 1, 3], x = 4
Output: (3, -1)
Explanation: The floor is 3 and ceil doesn't exist
*/
class Solution_3
{
public:
    std::pair<int,int> findFloorAndCeil(std::vector<int> const &nums, int x)
    {
        int floor = -1;
        int ceil = -1;

        int low = 0;
        int high = nums.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] == x)
            {
                floor = nums[mid];
                ceil = nums[mid];
                break;
            }
            else if (nums[mid] < x)
            {
                floor = nums[mid];
                low = mid + 1;
            }
            else
            {
                ceil = nums[mid];
                high = mid - 1;
            }
        }

        return {floor, ceil};
    }
};










// !-----------   2 Diff   -------------!

/*
Given an unsorted integer array, find all pairs with a given difference `k` in it using constant space.

Input : nums = [1, 5, 2, 2, 2, 5, 5, 4], k = 3
Output: {(2, 5), (1, 4)}

Note:

• The solution should return the pair in sorted order. For instance, among pairs (5, 2) and (2, 5), only pair (2, 5) appeared in the output.

• Since the input can contain multiple pairs with a given difference, the solution should return a set containing all the distinct pairs. For instance, the pair (2, 5) appeared only once in the output.
*/
class Solution_4
{
public:
    std::set<std::pair<int,int>> findPairs(std::vector<int> const &nums, int k)
    {
        std::set<std::pair<int,int>> pairs;
        std::vector<int> vector = nums;

        int n = nums.size();
        std::sort(vector.begin(), vector.end());

        int start = 0;
        int last = 0;

        while (start < n && last < n)
        {
            if (start != last && vector[last] - vector[start] == k && k <= 0)
            {
                pairs.insert(std::make_pair(vector[last], vector[start]));
                ++start;
                ++last;
            }
            else if (start != last && vector[last] - vector[start] == k && k >= 0)
            {
                pairs.insert(std::make_pair(vector[start], vector[last]));
                ++start;
                ++last;
            }
            else if (vector[last] - vector[start] < k)
            {
                ++last;
            }
            else
            {
                ++start;
            }
        }

        return pairs;
    }
};


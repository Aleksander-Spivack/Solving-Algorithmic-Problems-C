#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>






// !-----------   Shift Matrix  -----------!

/*
Given an `M × N` integer matrix, shift all its elements by `1` in spiral order.

Input:

[
	[ 1,  2,  3,  4, 5],
	[16, 17, 18, 19, 6],
	[15, 24, 25, 20, 7],
	[14, 23, 22, 21, 8],
	[13, 12, 11, 10, 9]
]

Output:

[
	[25,  1,  2,  3, 4],
	[15, 16, 17, 18, 5],
	[14, 23, 24, 19, 6],
	[13, 22, 21, 20, 7],
	[12, 11, 10,  9, 8]
]
*/
class Solution_1
{
public:
    void shiftMatrix(std::vector<std::vector<int>> &mat)
    {
        if (mat.size() == 0) {
            return;
        }

        int top = 0, bottom = mat.size() - 1;
        int left = 0, right = mat[0].size() - 1;
        int prev = mat[0][0];

        while (true)
        {
            if (left > right) {
                break;
            }

            for (int i = left; i <= right; i++) {
                std::swap(mat[top][i], prev);
            }
            top++;


            if (top > bottom) {
                break;
            }

            for (int i = top; i <= bottom; i++) {
                std::swap(mat[i][right], prev);
            }
            right--;


            if (left > right) {
                break;
            }

            for (int i = right; i >= left; i--) {
                std::swap(mat[bottom][i], prev);
            }
            bottom--;


            if (top > bottom) {
                break;
            }

            for (int i = bottom; i >= top; i--) {
                std::swap(mat[i][left], prev);
            }

            left++;
        }

        mat[0][0] = prev;
    }
};










// !--------------  Maximum Sum Subarray II   --------------!

/*
Given an integer array, find a contiguous subarray within it that has the maximum sum.

Input : [-2, 1, -3, 4, -1, 2, 1, -5, 4]
Output: [4, -1, 2, 1]

Input : [-7, -3, -2, -4]
Output: [-2]

In case multiple subarrays exists with the largest sum, the solution can return any one of them.

Input : [-2, 2, -1, 2, 1, 6, -10, 6, 4, -8]
Output: [2, -1, 2, 1, 6] or [6, 4] or [2, -1, 2, 1, 6, -10, 6, 4]
*/
class Solution_2
{
public:
    std::vector<int> findMaxSumSubarray(std::vector<int> const &nums)
    {
        int maxSum = nums[0];
        int sum = nums[0];
        int start = 0;
        int last = 0;
        int currStart = 0;

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > sum + nums[i])
            {
                sum = nums[i];
                currStart = i;
            }
            else {
                sum += nums[i];
            }

            if (sum > maxSum)
            {
                maxSum = sum;
                start = currStart;
                last = i;
            }
        }
        return std::vector<int>(nums.begin() + start, nums.begin() + last + 1);
    }
};







// !-------------     Search Circular Array -------------!

/*
Given a circularly sorted integer array, search a target element in it. If the target exists in the array, the procedure should return the index of it. If the target is not located, the procedure should return -1. You may assume there are no duplicates in the array, and the rotation is in the anti-clockwise direction.

Input: nums[] = [8, 9, 10, 2, 5, 6], target = 10
Output: 2
Explanation: Element found at 3rd (index 2) position.

Input: nums[] = [9, 10, 2, 5, 6, 8], target = 5
Output: 3
Explanation: Element found at 4th (index 3) position.

Input: nums[] = [8, 9, 1, 4, 5], target = 2
Output: -1
Explanation: Target not found
*/
class Solution_3
{
public:
    int findIndex(std::vector<int> const &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }

            if (nums[left] <= nums[mid])
            {
                if (nums[left] <= target && target < nums[mid])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else{
                if (nums[mid] < target && target <= nums[right])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }

        }
        return -1;
    }
};










// !----------- Count Occurrences  ------------!

/*
Given a sorted integer array containing duplicates, return the count of occurrences of a given number.

Input: nums[] = [2, 5, 5, 5, 6, 6, 8, 9, 9, 9], target = 5
Output: 3
Explanation: Target 5 occurs 3 times

Input: nums[] = [2, 5, 5, 5, 6, 6, 8, 9, 9, 9], target = 6
Output: 2
Explanation: Target 6 occurs 2 times

Input: nums[] = [5, 4, 3, 2, 1], target = 6
Output: 0
Explanation: Target 6 occurs 0 times
*/
class Solution_4
{
public:
    int countOccurrences(std::vector<int> const &nums, int target)
    {
        int count = 0;

        for (auto &num : nums)
        {
            if (num == target)
            {
                ++count;
            }
        }
        return count;
    }
};






// !------------   Smallest Missing Number   ------------!

/*
Given a sorted array of non-negative distinct integers, find the smallest missing non-negative element in it.

Input: [0, 1, 2, 6, 9, 11, 15]
Output: 3

Input: [1, 2, 3, 4, 6, 9, 11, 15]
Output: 0

Input: [0, 1, 2, 3, 4, 5, 6]
Output: 7
*/
class Solution_5
{
public:
    int findSmallestMissingNumber(std::vector<int> const &nums)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == mid)
            {
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }

        return left;
    }
};






int main ()
{
    std::vector <int> data {8, -7, -3, 5, 6, -2, 3, -4, 2};
    findMaxSumSubarray(data);
    return 0;

}
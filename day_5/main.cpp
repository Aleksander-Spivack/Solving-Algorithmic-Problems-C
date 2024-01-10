#include <iostream>
#include <vector>
#include <algorithm>






// !------------    Dutch Nation Flag Problem    -----------!

/*
Given an array containing only 0’s, 1’s, and 2’s, in-place sort it in linear time and using constant space.

Input : [0, 1, 2, 2, 1, 0, 0, 2, 0, 1, 1, 0]
Output: [0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2]
*/
class Solution_1
{
public:
    void sortArray(std::vector<int> &nums)
    {
        int iter = 0;
        int last = nums.size() - 1;
        int first = 0;

        while (iter <= last)
        {
            if (nums[iter] == 0)
            {
                std::swap(nums[iter], nums[first]);
                ++iter;
                ++first;
            }
            else if (nums[iter] == 2)
            {
                std::swap(nums[iter], nums[last]);
                --last;
            }
            else
            {
                ++iter;
            }
        }
    }
};








// !------------     Merge Arrays     --------------!

/*
Given two sorted integer arrays, `X[]` and `Y[]` of size `m` and `n` each, in-place merge elements of `X[]` with elements of array `Y[]` by maintaining the sorted order, i.e., fill `X[]` with the first `m` smallest elements and fill `Y[]` with remaining elements.

Input :

X[] = [1, 4, 7, 8, 10]
Y[] = [2, 3, 9]

Output:

X[] = [1, 2, 3, 4, 7]
Y[] = [8, 9, 10]

*/
class Solution_2
{
public:
    void merge(std::vector<int> &X, std::vector<int> &Y)
    {
        int n = Y.size();

        for (int i = 0; i != X.size(); ++i)
        {
            if (X[i] > Y[0])
            {
                std::swap(X[i], Y[0]);
                int first = Y[0];

                int k = 1;
                for (k; k != Y.size() && Y[k] < first; ++k)
                {
                    Y[k - 1] = Y[k];
                }

                Y[k - 1] = first;
            }
        }
    }
};









// !-----------   Merge Arrays II    -----------!

/*
Given two sorted integer arrays `X[]` and `Y[]` of size `m` and `n` each where `m >= n` and `X[]` has exactly `n` vacant cells, merge elements of `Y[]` in their correct position in array `X[]`, i.e., merge `(X, Y)` by keeping the sorted order.

Input : Two arrays X[] and Y[] where vacant cells in X[] is represented by 0.

X[] = [0, 2, 0, 3, 0, 5, 6, 0, 0]
Y[] = [1, 8, 9, 10, 15]

Output: X[] = [1, 2, 3, 5, 6, 8, 9, 10, 15]
*/
class Solution_3
{
public:
    void merge(std::vector<int> &X, std::vector<int> &Y)
    {
        int next = 0;

        for (int i = 0; i != X.size(); ++i)
        {
            if (X[i] == 0)
            {
                std::swap(X[i], Y[next]);
                ++next;
            }
        }

        std::sort(X.begin(), X.end());
    }
};









// !------------   Rearrange Array    -------------!

/*
Given an integer array, in-place rearrange it such that every second element becomes greater than its left and right elements.

• Assume that no duplicate elements are present in the input array.
• The solution should perform single traveral of the array.
• In case the multiple rearrangement exists, the solution can return any one of them.

Input : [1, 2, 3, 4, 5, 6, 7]
Output: [1, 3, 2, 5, 4, 7, 6] or [1, 5, 2, 6, 3, 7, 4], or any other valid combination..

Input : [6, 9, 2, 5, 1, 4]
Output: [6, 9, 2, 5, 1, 4] or [1, 5, 2, 6, 4, 9], or any other valid combination..
*/
class Solution_4
{
public:
    void rearrange(std::vector<int> &nums)
    {
        for (int i = 1; i < nums.size(); i += 2)
        {
            if (nums[i - 1] > nums[i])
            {
                std::swap(nums[i - 1], nums[i]);
            }

            if (i + 1 < nums.size() && nums[i + 1] > nums[i])
            {
                std::swap(nums[i + 1], nums[i]);
            }
        }
    }

};










// !------------   Rearrange Array II  -------------!

/*
Given an integer array, in-place rearrange it such that it contains positive and negative numbers at alternate positions. Assume that all values in the array are non-zero.

• In case the multiple rearrangement exists, the solution can return any one of them.

Input : [9, -3, 5, -2, -8, -6, 1, 3]
Output: [9, -3, 5, -2, 1, -8, 3, -6] or [5, -2, 9, -6, 1, -8, 3, -3] or any other valid combination..

• If the array contains more positive or negative elements, the solution should move them to the end of the array.

Input : [9, -3, 5, -2, -8, -6]
Output: [5, -2, 9, -6, -3, -8] or [-2, 5, -6, 9, -3, -8] or any other valid combination..

Input : [5, 4, 6, -1, 3]
Output: [5, -1, 4, 6, 3] or [-1, 5, 4, 6, 3] or any other valid combination..
*/
class Solution_5
{
public:
    void rearrange(std::vector<int> &nums)
    {
        int next = 0;
        int countNeg = 0;
        int countPos = 0;

        for (int i = 0; i != nums.size(); ++i)
        {
            if (nums[i] < 0)
            {
                std::swap(nums[i], nums[next]);
                ++next;
                ++countNeg;
            }
            else
            {
                ++countPos;
            }
        }

        if (countNeg == nums.size() || countPos == nums.size())
        {
            return;
        }

        const int n = countNeg;
        const int p = countPos;

        if (p >= n)
        {
            for (int i = 0; i < nums.size(); i += 2)
            {
                if (nums[i] < 0)
                {
                    std::swap(nums[countNeg], nums[i]);
                    ++countNeg;
                }

            }
        }
        else {
            std::reverse(nums.begin(), nums.end());

            for (int i = 0; i < nums.size() && n > p; i += 2) {
                if (nums[i] > 0) {
                    std::swap(nums[countPos], nums[i]);
                    ++countPos;
                }


            }
        }
    }
};










// !--------------    Rearrange Array IV    --------------!

/*
Given an array of positive and negative integers, in-place segregate them in linear time and constant space. The output should contain all negative numbers, followed by all positive numbers.

Input : [9, -3, 5, -2, -8, -6, 1, 3]
Output: [-3, -2, -8, -6, 9, 5, 1, 3] or [-3, -2, -8, -6, 9, 5, 1, 3] or any other valid combination.

Input : [-4, -2, -7, -9]
Output: [-4, -2, -7, -9] or any other valid combination.

Input : [2, 4, 3, 1, 5]
Output: [2, 4, 3, 1, 5] or any other valid combination.
*/
class Solution_6
{
public:
    void rearrange(std::vector<int> &nums)
    {
        int next = 0;

        for (int i = 0; i != nums.size(); ++i)
        {
            if (nums[i] < 0)
            {
                std::swap(nums[i], nums[next]);
                ++next;
            }
        }
    }
};

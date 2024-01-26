#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>






// !---------------   Inversion Count II ---------------!

/*
Given an integer array, count the total number of triplets, which leads to an inversion. If (i < j < k) and (nums[i] > nums[j] > nums[k]), then the triplet (i, j, k) has formed an inversion in array `nums`.

Input : [1, 9, 6, 4, 5]
Output: 2
Explanation: There are two inversions of size three in the array: (9, 6, 4) and (9, 6, 5).

Input : [9, 4, 3, 5, 1]
Output: 5
Explanation: There are five inversions of size three in the array: (9, 4, 3), (9, 4, 1), (9, 3, 1), (4, 3, 1), and (9, 5, 1).
*/
class Solution_1
{
public:
    int findInversionCount(std::vector<int> const &nums)
    {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n - 2; ++i)
        {
            for (int j = i + 1; j < n - 1; ++j)
            {
                for (int k = j + 1; k < n; ++k)
                {
                    if (nums[i] > nums[j] && nums[j] > nums[k])
                    {
                        ++count;
                    }
                }
            }
        }
        return count;
    }
};








// !-----------------   Turn off Hth Bit    -------------------!

/*
Given an integer n and a positive number k, turn off k'th bit in n.

Input: n = 20, k = 3
Output: 16
Explanation:

20 in binary is 00010100
16 in binary is 00010000

Input: n = -20, k = 3
Output: -24
Explanation:

-20 in binary is 1111111111101100
-24 in binary is 1111111111101000
*/
class Solution_2
{
public:
    int turnOffKthBit(int n, int k)
    {
        int mask = ~(1 << (k - 1));
        return n & mask;
    }
};






// !------------------   Turn on Hth Bit   ------------------!

/*
Given an integer n and a positive number k, turn on k'th bit in n.

Input: n = 20, k = 4
Output: 28
Explanation:

20 in binary is 00010100
28 in binary is 00011100


Input: n = -24, k = 3
Output: -20
Explanation:

-24 in binary is 1111111111101000
-20 in binary is 1111111111101100
*/
class Solution_3
{
public:
    int turnOnKthBit(int n, int k)
    {
        int mask = 1 << (k - 1);
        return n | mask;
    }
};






// !-------------------  Is Kth Bit Set  --------------------!

/*
Given an integer n and a positive number k, check if k'th bit is set or not.

Input: n = 20, k = 3
Output: true
Explanation: 20 in binary is 00010100

Input: n = 16, k = 3
Output: false
Explanation: 16 in binary is 00010000
*/
class Solution_4
{
public:
    bool isKthBitSet(int n, int k)
    {
        int mask = 1 << (k - 1);
        return (n & mask) != 0;
    }
};








// !-----------------   Toggle Kth Bit  ----------------!

/*
Given an integer n and a positive number k, toggle k'th bit of n.

Input: n = 20, k = 3
Output: 16
Explanation: 20 in binary is 00010100 and 16 in binary is 00010000

Input: n = 16, k = 3
Output: 20
*/
class Solution_5
{
public:
    int toggleKthBit(int n, int k)
    {
        int mask = 1 << (k - 1);
        return n ^ mask;
    }
};



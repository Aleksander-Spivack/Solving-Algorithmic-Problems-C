#include <iostream>
#include <vector>
#include <climits>







// !-------------  Maximum Continuous Sequence II   --------------!

/*
Given a binary array and a positive integer `k`, return the indices of the maximum sequence of continuous 1’s that can be formed by replacing at most `k` zeroes by ones.

• The solution should return a pair of the starting and the ending index of the maximum sequence.
• For invalid inputs, the solution should return pair (-1, -1).
• In case multiple sequence of continuous 1’s of maximum length exists, the solution can return any one of them.

Input : nums[] = [1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0], k = 0
Output: (6, 9)
Explanation: The longest sequence of continuous 1’s is formed by index 6 to 9.

Input : nums[] = [1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0], k = 1
Output: (3, 9)
Explanation: The longest sequence of continuous 1’s is formed by index 3 to 9 on replacing zero at index 5.

Input : nums[] = [1, 1, 1, 1, 1], k = 1
Output: (0, 4)

Input : nums[] = [1, 0, 1, 1, 0, 0, 1, 1, 0, 1], k = 1
Output: (0, 3) or (6, 9)

Input : nums[] = [], k = 1
Output: (-1, -1)
*/
class Solution_1
{
public:
    std::pair<int,int> findLongestSequence(std::vector<int> const &nums, int k)
    {
        int maxLen = 0;
        int left = 0;
        int right = 0;
        int count = 0;

        std::pair<int, int> result {-1, -1};

        while (right < nums.size())
        {
            if (nums[right] == 0)
            {
                ++count;
            }

            while (count > k)
            {
                if (nums[left] == 0)
                {
                    --count;
                }
                ++left;
            }

            if (right - left + 1 > maxLen)
            {
                maxLen = right -  left + 1;
                result = std::make_pair(left, right);
            }

            ++right;
        }
        return result;
    }

};








// !-------------   Interleaving String II   ---------------!

/*

Given three strings, check if the third string is interleaving the first and second strings. In other words, check if third string is formed from all characters of the first and second string, and the order of characters is preserved.

Input: X = "AB", Y = "CD", S = "ACDB"
Output: true

Input: X = "ABC", Y = "DEF", S = "ADEBCF"
Output: true

Input: X = "ABC", Y = "ACD", S = "ACDABC"
Output: true

Input: X = "ABC", Y = "DE", S = "ACBCD"
Output: false
*/
class Solution_2
{
public:
    bool isInterleaving(std::string X, std::string Y, std::string S)
    {
        int n = X.size();
        int m = Y.size();

        if (m + n != S.length())
        {
            return false;
        }

        std::vector<bool> dp (n + 1, false);

        dp[0] = true;

        for (int i = 1; i <= m; ++i)
        {
            dp[i] = (Y[i - 1] == S[i - 1] && dp[i - 1]);
        }

        for (int i = 1; i <= n; ++i)
        {
            dp[0] = (X[i - 1] == S[i - 1] && dp[0]);

            for (int j = 1; j <= m; ++j)
            {
                dp[j] = (X[i - 1] == S[i + j - 1] && dp[j]) || (Y[j - 1] == S[i + j - 1] && dp[j - 1]);
            }
        }

        return dp[m];
    }
};







// !-------------  Minimum Absolute Difference  ------------!

/*
Given an integer array `nums` and two integers `x` and `y` present in it, find the minimum absolute difference between indices of `x` and `y` in a single traversal of the array.

Input : nums[] = [1, 3, 5, 4, 8, 2, 4, 3, 6, 5], x = 3, y = 2
Output: 2
Explanation: Element 3 is present at index 1 and 7, and element 2 is present at index 5. Their minimum absolute difference is min(abs(1-5), abs(7-5)) = 2

Input : nums[] = [1, 3, 5, 4, 8, 2, 4, 3, 6, 5], x = 2, y = 5
Output: 3
Explanation: Element 2 is present at index 5, and element 5 is present at index 2 and 9. Their minimum absolute difference is min(abs(5-2), abs(5-9)) = 3

Input : nums[] = [], x = 0, y = 1
Output: 0
*/
class Solution_3
{
public:
    int findDifference(std::vector<int> const &nums, int x, int y)
    {
        int indexX = -1;
        int indexY = -1;
        int minDiff = INT_MAX;

        if (nums.size() < 2 )
        {
            return 0;
        }

        if (x == y)
        {
            return 0;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == x)
            {
                if (indexY != -1)
                {
                    minDiff = std::min(minDiff, i - indexY);
                }
                indexX = i;
            }
            else if (nums[i] == y)
            {
                if (indexX != -1)
                {
                    minDiff = std::min(minDiff, i - indexX);
                }
                indexY = i;
            }
        }
        return minDiff;
    }
};








// !-------------- Counting Sort Array --------------!

/*
Given a collection of `n` items, each of which has a non-negative integer key whose maximum value is at most `k`, effectively sort it using the counting sort algorithm.

Input : nums[] = [4, 2, 10, 10, 1, 4, 2, 1, 10], k = 10
Output: [1, 1, 2, 2, 4, 4, 10, 10, 10]
*/
class Solution_4
{
public:
    void sort(std::vector<int> &nums, int k)
    {
        std::vector<int> count (k + 1, 0);

        for (int num : nums)
        {
            ++count[num];
        }

        int index = 0;
        for (int i = 0; i <= k; ++i)
        {
            for (int j = 0; j < count[i]; ++j)
            {
                nums[index++] = i;
            }
        }
    }

};









// !--------------   RLE  -------------!

/*
Run–length encoding (RLE) is a simple form of lossless data compression that runs on sequences with the same value occurring many consecutive times. It encodes the sequence to store only a single value and its count.

Input: "WWWWWWWWWWWWBWWWWWWWWWWWWBBBWWWWWWWWWWWWWWWWWWWWWWWWBWWWWWWWWWWWWWW"
Output: "12W1B12W3B24W1B14W"
Explanation: String can be interpreted as a sequence of twelve W’s, one B, twelve W’s, three B’s, and so on..
*/
class Solution_5
{
public:
    std::string encode(std::string s)
    {
        std::string result = "";

        int count = 1;

        for (int i = 1; i <= s.size(); ++i)
        {
            if ( i == s.size() || s[i] != s[i - 1])
            {
                result += std::to_string(count) + s[i - 1];
                count = 1;
            }
            else
            {
                ++count;
            }
        }
        return result;
    }
};







// !---------------    ----------------!


int main() {

    return 0;
}

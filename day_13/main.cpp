#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>







// !--------------   Missing Number II   --------------!

/*
Given an integer array of size `n` and containing elements between 1 and `n+1` with one element missing, find the missing number using constant space.

Input: [3, 2, 4, 6, 1]
Output: 5

Input: [3, 2, 4, 5, 6]
Output: 1

Input: [3, 2, 4, 5, 1]
Output: 6

Assume valid input.
*/
class Solution_1
{
public:
    int findMissingNumber(std::vector<int> const &nums)
    {
        int n = nums.size() + 1;
        int missing = 0;

        for (int i = 1; i <= n; ++i)
        {
            missing ^= i;
        }

        for (int num : nums)
        {
            missing ^= num;
        }

        return missing;
    }

};







// !-------------------   Excel Sheet Column Name   --------------------!

/*
Given a positive number, convert the number to the corresponding Excel column name.

Input: 1
Output: "A"

Input: 27
Output: "AA"

Input: 1001
Output: "ALM"

Note: Excel supports upto 2^14 columns, i.e. 16,384 columns.
*/
class Solution_2
{
public:
    std::string getColumnName(int n)
    {
        std::string result = "";
        while (n > 0)
        {
            int remain = (n - 1) % 26;
            result = char('A' + remain) + result;
            n = (n - 1) / 26;
        }

        return result;
    }
};






// !----------------   Rearrange Array III  ------------------!

/*
Given an unsorted integer array `A` of size `n`, whose elements lie in the range 0 to `n-1`, in-place rearrange the array such that `A[A[i]]` is set to `i` for every array element `A[i]`. Do this in linear time and without using any extra constant space.

Input : [1, 3, 4, 2, 0]
Output: [4, 0, 3, 1, 2]
Explanation:

A[0] = 1, A[1] becomes 0
A[1] = 3, A[3] becomes 1
A[2] = 4, A[4] becomes 2
A[3] = 2, A[2] becomes 3
A[4] = 0, A[0] becomes 4
*/
class Solution_3
{
public:
    void rearrange(std::vector<int> &A)
    {
        int n = A.size();

        for (int i = 0; i != n; ++i)
        {
            A[A[i] % n] += i * n;
        }

        for (int i = 0; i != n; ++i)
        {
            A[i] = A[i] / n;
        }
    }
};







// !-----------------   Repeated Subsequence   -------------------!

/*
Given a string, check if a repeated subsequence is present in it or not. The repeated subsequence should have a length of 2 or more.

Input: "XYBAXB"
Output: true
Explanation: String "XYBAXB" has XB(XBXB) as a repeated subsequence

Input: "XBXAXB"
Output: true
Explanation: String "XBXAXB" has XX(XXX) as a repeated subsequence

Input: "XYBYAXBY"
Output: true
Explanation: String "XYBYAXBY" has XB(XBXB), XY(XYXY), YY(YYY), YB(YBYB), and YBY(YBYBY) as repeated subsequences.

Input: "ABCA"
Output: false
Explanation: String "ABCA" doesn’t have any repeated subsequence
*/
class Solution_4
{
public:
    bool hasRepeatedSubsequence(std::string str)
    {
        std::unordered_set <std::string> set;

        for (int i = 1; i != str.size(); ++i)
        {
            for (int j = 0; j + i < str.size(); ++j)
            {
                std::string sub = str.substr(j, i);

                if (set.count(sub))
                {
                    return true;
                }
                set.insert(sub);
            }
        }
        return false;
    }
};





int main() {
    
    return 0;
}

#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <algorithm>




// !---------------  Equilibrium Index  ----------------!

/*
Given an integer array, return all equilibrium index in it. For an array `A[0..n-1]`, index `i` is an equilibrium index if the sum of elements of subarray `A[0…i-1]` is equal to the sum of elements of subarray `A[i+1…n-1]`.

Input : [0, -3, 5, -4, -2, 3, 1, 0]
Output: {0, 3, 7}
Explanation: For each index `i` in the output, A[0] + A[1] + … + A[i-1] = A[i+1] + A[i+2] + … + A[n-1]

Input : [-7, 3, 7, -3, 1]
Output: {4}
Explanation: `n-1` is an equilibrium index if A[0] + A[1] + … + A[n-2] sums to 0.

Input : [1, 2, -4, 2]
Output: {0}
Explanation: 0 is an equilibrium index if A[1] + A[2] + … + A[n-1] sums to 0.
*/
class Solution_1
{
public:
    std::unordered_set<int> findEquilibriumIndex(std::vector<int> const &nums)
    {
        std::unordered_set<int> indices;

        int n = nums.size();
        if (n < 1)
        {
            return indices;
        }


        std::vector<int> prefix (n, 0);
        std::vector<int> suffix (n, 0);

        prefix[0] = nums[0];
        suffix[n - 1] = nums[n - 1];

        for (int i = 1, j = n - 2; i != n; ++i, --j)
        {
            prefix[i] = prefix[i - 1] + nums[i];
            suffix[j] = suffix[j + 1] + nums[j];
        }

        for (int i = 0; i < n; ++i)
        {
            if (prefix[i] == suffix[i])
            {
                indices.insert(i);
            }
        }

        return  indices;
    }
};











// !--------------- Rotation Count  ---------------!

/*
Given a circularly sorted array of distinct integers, find the total number of times the array is rotated. You may assume that the rotation is in anti-clockwise direction.

Input: [8, 9, 10, 2, 5, 6]
Output: 3

Input: [2, 5, 6, 8, 9, 10]
Output: 0

*/
class Solution_2
{
public:
    int findRotationCount(std::vector<int> const &nums)
    {
        int low = 0;
        int high = nums.size() - 1;
        int n  = nums.size();

        while (low <= high)
        {
            if (nums[low] <= nums[high])
            {
                return low;
            }

            int mid = low + (high - low) / 2;
            int next = (mid + 1) % n;
            int prev = (mid + n - 1) % n;

            if (nums[mid] <= nums[next] && nums[mid] <= nums[prev])
            {
                return mid;
            }
            else if (nums[mid] <= nums[high])
            {
                high = mid - 1;
            }
            else if (nums[mid] >= nums[low])
            {
                low = mid + 1;
            }
        }
        return -1;
    }

};






// !-----------------   2 Diff  ----------------!

/*
Given an unsorted integer array, find all pairs with a given difference `k` in it using constant space.

Input : nums = [1, 5, 2, 2, 2, 5, 5, 4], k = 3
Output: {(2, 5), (1, 4)}

Note:

• The solution should return the pair in sorted order. For instance, among pairs (5, 2) and (2, 5), only pair (2, 5) appeared in the output.

• Since the input can contain multiple pairs with a given difference, the solution should return a set containing all the distinct pairs. For instance, the pair (2, 5) appeared only once in the output.
*/
class Solution_3
{
public:
    std::set<std::pair<int, int>> findPairs(std::vector<int> const &nums, int k)
    {
        std::set<std::pair<int, int>> pairs;
        std::unordered_set<int> seen;


        for (int i = 0; i != nums.size(); ++i)
        {
            if (seen.find(nums[i] - k) != seen.end())
            {
                pairs.insert(std::make_pair(nums[i] - k, nums[i]));
            }

            if (seen.find(nums[i] + k) != seen.end())
            {
                pairs.insert(std::make_pair(nums[i], nums[i] + k));
            }

            seen.insert(nums[i]);
        }

        return pairs;
    }
};










// !-----------------  Buy and Sell Stock III  ----------------!

/*
Given a list containing future price predictions of two different stocks for the next n–days, find the maximum profit earned by selling the stocks with a constraint that the second stock can be sold, only if no transaction happened on the previous day for any of the stock.

Assume that the given prices are relative to the buying price. Each day, we can either sell a single share of the first stock or a single share of the second stock or sell nothing.

Input: X = [5, 3, 4, 6, 3], Y = [8, 4, 3, 5, 10]

Day	 Price(X)  Price(Y)
1		5		 8
2		3		 4
3		4		 3
4		6		 5
5		3		 10

Output: 25

Explanation:

Day 1: Sell stock Y at a price of 8
Day 2: Sell stock X at a price of 3
Day 3: Sell stock X at a price of 4
Day 4: Don't sell anything
Day 5: Sell stock Y at a price of 10
*/
class Solution_4
{
public:
    int findMaximumProfit(std::vector<int> const &X, std::vector<int> const &Y)
    {
        int n = X.size();

        if (n == 0)
        {
            return 0;
        }

        int prevX = 0;
        int prev = std::max(X[0], Y[0]);

        for ( int i = 1; i < n; ++i )
        {
            int curr = std::max(X[i] + prev, Y[i] + prevX);
            prevX = prev;
            prev = curr;
        }

        return prev;

    }
};







// !------------------  Palindrome String  ------------------!

/*
Given a string, check if it is a palindrome. A palindromic string is a string that remains the same with its characters reversed.

Input : "ABCBA"
Output: true

Input : "ABCA"
Output: false
*/
class Solution_5
{
public:
    bool isPalindrome(std::string s)
    {
        int left = 0;
        int right = s.size() - 1;

        while (left < right)
        {
            if (s[left] != s[right])
            {
                return false;
            }

            ++left;
            --right;
        }
        return true;
    }
};








// !---------------   Remove Adjacent Duplicates    ---------------!

/*
Given a string, remove adjacent duplicates characters from it. In other words, remove all consecutive same characters except one.

Input : "AABBBCDDD"
Output: "ABCD"
*/
class Solution_6
{
public:
    void removeAdjacentDuplicates(std::string &s)
    {
        int n = s.size();
        int j = 0;

        for (int i = 0; i != n; ++i)
        {
            if (i < n && s[i] == s[i + 1])
            {
                continue;
            }

            s[j] = s[i];
            ++j;
        }
        s.resize(j);
    }

};










// !-----------------



int main() {

    return 0;
}

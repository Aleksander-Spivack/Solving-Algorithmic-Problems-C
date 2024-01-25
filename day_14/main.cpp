#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>
#include <unordered_map>






// !----------------   Combinations II   ---------------!

/*
Find all combinations of positive integers in increasing order that sum to a given positive number `N`.

Input : N = 3
Output: {[1, 1, 1], [1, 2], [3]}

Input : N = 4
Output: {[1, 1, 1, 1], [1, 1, 2], [1, 3], [2, 2], [4]}

Input : N = 5
Output: {[1, 1, 1, 1, 1], [1, 1, 1, 2], [1, 1, 3], [1, 2, 2], [1, 4], [2, 3], [5]}
*/
class Solution_1
{
private:
    void findCombinationsHelper(int n, int start, std::vector<int>& cur_comb, std::set<std::vector<int>>& combinations)
    {
        if (n == 0)
        {
            combinations.insert(cur_comb);
            return;
        }

        for (int i = start; i <= n; ++i)
        {
            cur_comb.push_back(i);
            findCombinationsHelper(n - i, i, cur_comb, combinations);
            cur_comb.pop_back();
        }
    }

public:
    std::set<std::vector<int>> findCombinations(int n)
    {
        std::set<std::vector<int>> combinations;
        std::vector<int> cur_comb;

        findCombinationsHelper(n, 1, cur_comb, combinations);

        return combinations;
    }
};









// !----------------   Toeplitz Matrix   -----------------!

/*
Given an `M × N` integer matrix, check if it is a Toeplitz matrix or not. A Toeplitz matrix or diagonal-constant matrix is a matrix with each descending diagonal from left to right is constant.

Any `M × N` matrix `mat` is a Toeplitz matrix if mat(i, j) = mat(i+1, j+1) = mat(i+2, j+2), and so on… Here, mat(i, j) denotes the element mat[i][j] in the matrix.

Input:

[
	[3, 7, 0, 9, 8],
	[5, 3, 7, 0, 9],
	[6, 5, 3, 7, 0],
	[4, 6, 5, 3, 7]
]

Output: true

Input:

[
	[3, 7, 0, 9, 8],
	[5, 3, 7, 0, 9],
	[6, 5, 3, 7, 0],
	[4, 5, 5, 3, 7]
]

Output: false
*/
class Solution_2
{
public:
    bool checkToeplitz(std::vector<std::vector<int>> const &mat)
    {
        if (mat.size() == 0)
        {
            return true;
        }

        int m = mat.size() - 1;
        int n = mat[0].size() - 1;

        for (int i = 0; i != m; ++i)
        {
            for (int j = 0; j != n; ++j)
            {
                if (mat[i][j] != mat[i + 1][j + 1])
                {
                    return false;
                }
            }
        }
        return true;
    }
};










// !----------------   Maximum Sum Number   -----------------!

/*
Given an integer array between 0 and 9, generate a pair using all the array digits that has the maximum sum. The difference in the number of digits of the two numbers should be ± 1.

Input : [4, 6, 2, 7, 9, 8]
Output: (974, 862)

Input : [9, 2, 5, 6, 0, 4]
Output: (952, 640)

The solution can return pair in any order. If a pair cannot be formed, the solution should return the pair (0, 0).
*/
class Solution_3
{
public:
    std::pair<int,int> constructMaxSumNumber(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end(), std::greater<int>());

        int n = nums.size();
        int num1 = 0, num2 = 0;

        for ( int i = 0; i < n; ++i )
        {
            if (i % 2 == 0)
            {
                num1= num1 * 10 + nums[i];
            }
            else
            {
                num2 = num2 * 10 + nums[i];
            }
        }

        if (n % 2 == 1)
        {
            num2 = num2 * 10 + nums[n - 1];
        }
        return  std::make_pair(num1, num2);
    }
};







// !-----------------  Repeating Element Index  ----------------!

/*
Given an integer array, find the minimum index of a repeating element in linear time and doing just a single traversal of the array.

Input : [5, 6, 3, 4, 3, 6, 4]
Output: 1
Explanation: The minimum index of the repeating element is 1

Input : [1, 2, 3, 4, 5, 6]
Output: -1
Explanation: Input doesn't contain any repeating element
*/
class Solution_4
{
public:
    int findMinIndex(std::vector<int> const &nums)
    {
        std::unordered_map<int, int> map;

        int minIndex = nums.size();

        for (int i = 0; i < nums.size(); ++i)
        {
            if (map.find(nums[i]) != map.end())
            {
                minIndex = std::min(minIndex, map[nums[i]]);
            }
            map[nums[i]] = i;
        }

        return (minIndex == nums.size()) ? -1 : minIndex;
    }
};

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>



//  !-----   TWO SUM -----!

/*
Given an unsorted integer array, find a pair with the given sum in it.

• Each input can have multiple solutions. The output should match with either one of them.

Input : nums[] = [8, 7, 2, 5, 3, 1], target = 10
Output: (8, 2) or (7, 3)

• The solution can return pair in any order. If no pair with the given sum exists, the solution should return the pair (-1, -1).

Input : nums[] = [5, 2, 6, 8, 1, 9], target = 12
Output: (-1, -1)
*/
class Solution_1
{
public:
    std::pair<int,int> findPair(std::vector<int> const &nums, int target)
    {
        std::unordered_map <int, int> map;

        for (int i = 0; i != nums.size(); ++i)
        {
            if (map.find(target - nums[i]) != map.end())
            {
                return {nums[map[target - nums[i]]], nums[i]};
            }

            map[nums[i]] = i;
        }
        return {-1, -1};
    }
};



// !------      SUM ZERO I     -------!

/*
Given an integer array, check if it contains a contiguous subarray having zero-sum.

Input : [3, 4, -7, 3, 1, 3, 1, -4, -2, -2]
Output: true
Explanation: The subarrays with zero-sum are

[3, 4, -7]
[4, -7, 3]
[-7, 3, 1, 3]
[3, 1, -4]
[3, 1, 3, 1, -4, -2, -2]
[3, 4, -7, 3, 1, 3, 1, -4, -2, -2]

Input : [4, -7, 1, -2, -1]
Output: false
Explanation: The subarray with zero-sum doesn't exist.
*/
class Solution_2
{
public:
    bool hasZeroSumSubarray(std::vector<int> const &nums)
    {
        std::unordered_set <int> set;
        int sum = 0;

        set.insert(0);

        for (int i = 0; i != nums.size(); ++i)
        {
            sum += nums[i];

            if (set.find(sum) != set.end())
            {
                return true;
            }

            set.insert(sum);
        }
        return false;
    }
};




// !--------    SORT BINARY ARRAY    -------!

/*
Given a binary array, in-place sort it in linear time and constant space. The output should contain all zeroes, followed by all ones.

Input : [1, 0, 1, 0, 1, 0, 0, 1]
Output: [0, 0, 0, 0, 1, 1, 1, 1]

Input : [1, 1]
Output: [1, 1]
*/
class Solution
{
public:
    void sortArray(std::vector<int> &nums)
    {
        int left = nums.size() - 1;

        for (int i = nums.size() - 1; i >= 0; --i)
        {
            if (nums[i] == 1)
            {
                std::swap(nums[left], nums[i]);
                --left;
            }
        }
    }
};




// !-------    SUM ZERO II    -------!

/*
Given an integer array, find all contiguous subarrays with zero-sum.

Input : [4, 2, -3, -1, 0, 4]
Output: {[-3, -1, 0, 4], [0]}

Input : [3, 4, -7, 3, 1, 3, 1, -4, -2, -2]
Output: {[3, 4, -7], [4, -7, 3], [-7, 3, 1, 3], [3, 1, -4], [3, 1, 3, 1, -4, -2, -2], [3, 4, -7, 3, 1, 3, 1, -4, -2, -2]}

Input : [0, 0]
Output: {[0], [0, 0]}

Input : [1, 2, 3]
Output: {}

Note: Since an input can have multiple subarrays with zero-sum, the solution should return a set containing all the distinct subarrays.
*/

class Solution_3
{
public:
    std::set<std::vector<int>> getAllZeroSumSubarrays(std::vector<int> const &nums)
    {
        std::set<std::vector<int>> subarrays;
        std::unordered_map<int, std::vector<int>> map;

        map[0].push_back(0);

        int sum = 0;
        auto iter = 0;

        for (auto &element: nums) {
            sum += element;
            ++iter;

            if (map.find(sum) != map.end()) {
                for (auto &index: map[sum]) {
                    std::vector<int> _temp(nums.begin() + index, nums.begin() + iter);
                    subarrays.insert(_temp);
                }
            }

            map[sum].push_back(iter);
        }

        return subarrays;
    }
};


#include <iostream>
#include <vector>
#include <unordered_map>
#include <tuple>
#include <algorithm>
#include <random>






// !---------------  Frequency Map   ---------------!

/*
Given an unsorted integer array whose elements lie in the range 0 to `n-1` where `n` is the array size, calculate the frequency of all array elements in linear time and using constant space.

Input : [2, 3, 1, 3, 1, 1]
Output: {1: 3, 2: 1, 3: 2}

Explanation:

Element 1 appears thrice.
Element 2 appears once.
Element 3 appears twice.
*/
class Solution_1
{
public:
    std::unordered_map<int, int> findFrequency(std::vector<int> &nums)
    {
        std::unordered_map<int, int> freq;

        for (int num :nums)
        {
            ++freq[num];
        }

        return freq;
    }

};









// !---------------  Frequency Map II   ---------------!

/*
Given a sorted array containing duplicates, efficiently find each element's frequency without traversing the whole array.

Input: [2, 2, 2, 4, 4, 4, 5, 5, 6, 8, 8, 9]
Output: {2: 3, 4: 3, 5: 2, 6: 1, 8: 2, 9: 1}

Explanation:

2 and 4 occurs thrice
5 and 8 occurs twice
6 and 9 occurs once
*/
class Solution_2
{
public:
    std::unordered_map<int, int> findFrequency(std::vector<int> const &nums)
    {
        std::unordered_map <int, int> freq;

        for (int i = 0; i != nums.size(); ++i)
        {
            int count = 1;

            while (i < nums.size() - 1 && nums[i] == nums[i + 1])
            {
                ++count;
                ++i;
            }
            freq[nums[i]] = count;
        }

        return freq;
    }
};









// !---------------  Shuffle Array   ----------------!

/*
Given an array of distinct integers `nums`, in-place shuffle it according to order specified by another array `pos`. For every index `i` in `nums`, the solution should update `nums[pos[i]] = nums[i]`.

Input:

nums[] = [1, 2, 3, 4, 5]
 pos[] = [3, 2, 4, 1, 0]

Output: [5, 4, 2, 1, 3]
*/
class Solution_3
{
public:
    void shuffle(std::vector<int> &nums, std::vector<int> &pos)
    {
        int n = nums.size();
        int temp[n];

        for (int i = 0; i != n; ++i)
        {
            temp[pos[i]] = nums[i];
        }

        for (int i = 0; i != n; ++i)
        {
            nums[i] = temp[i];
        }
    }
};









// !---------------  Shuffle Array II   ----------------!

/*
Given two integer arrays, reorder elements of the first array by the order of elements defined by the second array.

The elements that are not present in the second array but present in the first array should be appended at the end in sorted order. The second array can contain some extra elements which are not part of the first array.

Input:

nums[] = [5, 8, 9, 3, 5, 7, 1, 3, 4, 9, 3, 5, 1, 8, 4]
 pos[] = [3, 5, 7, 2]

Output : [3, 3, 3, 5, 5, 5, 7, 1, 1, 4, 4, 8, 8, 9, 9]

*/
class Solution_4
{
public:
    void shuffle(std::vector<int> &nums, std::vector<int> &pos) {
        std::unordered_map <int, int> map;

        for (int i = 0; i < pos.size(); ++i)
        {
            map[pos[i]] = i;
        }

        auto comp = [&](int a, int b){
            if (map.find(a) != map.end() && map.find(b) != map.end())
            {
                return map[a] < map[b];
            }
            else if (map.find(a) != map.end())
            {
                return true;
            }
            else if (map.find(b) != map.end())
            {
                return false;
            }
            else{
                return a < b;
            }
        };

        std::sort(nums.begin(), nums.end(), comp);
    }
};












// !-------------   Shuffle Array III   ---------------!

/*
Given an array of distinct integer, in-place shuffle the array. The solution should produce an unbiased permutation, i.e., every permutation is equally likely.

Input: [1, 2, 3, 4, 5]
Output: [5, 4, 2, 1, 3] or [4, 1, 5, 3, 2] or any other unbiased permutation.
*/
class Solution_5
{
public:
    void shuffle(std::vector<int> &nums)
    {
        for (int i = nums.size() - 1; i > 0; --i)
        {
            int j = std::rand() % (i + 1);

            std::swap(nums[i], nums[j]);
        }
    }
};








// !-------------  Duplicates in Range K  -------------!

/*
Given an integer array and a positive number `k`, check whether the array contains any duplicate elements within the range `k`. If `k` is more than the array’s size, the solution should check for duplicates in the complete array.

Input: nums[] = [5, 6, 8, 2, 4, 6, 9], k = 4
Output: true
Explanation: Element 6 repeats at distance 4 which is <= k

Input: nums[] = [5, 6, 8, 2, 4, 6, 9], k = 2
Output: false
Explanation: Element 6 repeats at distance 4 which is > k

Input: nums[] = [1, 2, 3, 2, 1], k = 7
Output: true
Explanation: Element 1 and 2 repeats at distance 4 and 2, respectively which are both <= k
*/
class Solution_6
{
public:
    bool hasDuplicate(std::vector<int> const &nums, int k)
    {
        std::unordered_map <int, int> map;

        for (int i = 0; i != nums.size(); ++i)
        {
            if (map.find(nums[i]) != map.end())
            {
                if (i - map[nums[i]] <= k)
                    return true;
            }

            map[nums[i]] = i;
        }
        return false;
    }
};








// !-------------- Replace Array Element   -------------!

/*
Given an integer array, in-place replace each element with the product of every other element without using the division operator.

Input : [1, 2, 3, 4, 5]
Output: [120, 60, 40, 30, 24]

Input : [5, 3, 4, 2, 6, 8]
Output: [1152, 1920, 1440, 2880, 960, 720]
*/
class Solution_7
{
public:
    void rearrange(std::vector<int> &nums)
    {
        int n = nums.size();

        if (n == 0)
        {
            return;
        }

        std::vector <int> leftProd(n);
        std::vector <int> rightProd(n);

        leftProd[0] = 1;
        for (int i = 1; i < n; ++i)
        {
            leftProd[i] = nums[i - 1] * leftProd[i - 1];
        }

        rightProd[n - 1] = 1;
        for (int i = n - 2; i >= 0; --i)
        {
            rightProd[i] = nums[i + 1] * rightProd[i + 1];
        }

        for (int i = 0; i != n; ++i)
        {
            nums[i] = leftProd[i] * rightProd[i];
        }
    }
};











// !----------------   Maximum Difference Pair  --------------!

/*
Given an integer array, find the maximum difference between two elements in it such that the smaller element appears before the larger element. If no such pair exists, return any negative number.

Input : [2, 7, 9, 5, 1, 3, 5]
Output: 7
Explanation: The pair with the maximum difference is (2, 9).

Input : [5, 4, 3, 2, 1]
Output: -1 (or any other negative number)
Explanation: No pair with the maximum difference exists.
*/
class Solution_8
{
public:
    int findMaxDiff(std::vector<int> &nums)
    {
        int min = INT_MIN;

        if (nums.size() == 0)
        {
            return min;
        }

        int max = nums[nums.size() - 1];

        for (int i = nums.size() - 2; i >= 0; --i)
        {
            if (nums[i] >= max)
            {
                max = nums[i];
            }
            else
            {
                min = std::max(min, max - nums[i]);
            }
        }

        return min;
    }

};











int main() {
    std::vector<int> nums1 = {2, 7, 9, 5, 1, 3, 5};
    std::vector<int> nums2 = {5, 3, 4, 2, 6, 8};

    findMaxDiff(nums1);


    return 0;
}

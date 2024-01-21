#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <stack>
#include <unordered_map>






// !-----------------    Interleaving String   --------------------!

/*
Find all interleavings of given strings that can be formed from all the characters of the first and second string where the order of characters is preserved.

Input: X = "ABC", Y = "ACB"
Output: {"ACBABC", "AABCBC", "ACABCB", "ABCACB", "AACBBC", "ABACCB", "ACABBC", "ABACBC", "AACBCB", "AABCCB"}

Input: X = "", Y = ""
Output: {}
*/
class Solution_1
{
private:
    void helper (const std::string &X, const std::string &Y, std::unordered_set<std::string> &str, std::string  res)
    {
        if (!X.length() && !Y.length())
        {
            str.insert(res);
            return;
        }

        if (X.length())
        {
            helper(X.substr(1), Y, str, res + X[0]);
        }

        if (Y.length())
        {
            helper(X, Y.substr(1), str, res + Y[0]);
        }

    }

public:
    std::unordered_set<std::string> findInterleavings(std::string X, std::string Y)
    {
        std::unordered_set <std::string> str;

        if (!X.length() && !Y.length()) {
            return str;
        }

        helper(X, Y, str, "");

        return str;
    }
};






// !----------------   Longest Common prefix    -------------------!

/*
Given a set of strings, find their longest common prefix (LCP).

Input: ["technique", "technician", "technology", "technical"]
Output: "techn"

Input: ["techie delight", "tech", "techie", "technology", "technical"]
Output: "tech"
*/
class Solution_2
{
public:
    std::string findLCP(std::vector<std::string> const &words)
    {
        if (words.empty())
        {
            return  "";
        }

        int minLen = words[0].size();
        for (const std::string &word : words)
        {
            minLen = std::min(minLen, (int)word.size());
        }

        std::string prefix;
        for (int i = 0; i < minLen; ++i)
        {
            char ch = words[0][i];

            for (const auto &word : words)
            {
                if (word[i] != ch)
                {
                    return prefix;
                }
            }

            prefix += ch;
        }

        return prefix;
    }

};








// !----------------    Balanced Expression   ---------------!

/*
Given a string containing opening and closing braces, determine if it represents a balanced expression or not.

Input: "{[{}{}]}[()]"
Output: true

Input: "{{}{}}"
Output: true

Input: "[]{}()"
Output: true

Input: "{()}[)"
Output: false

Input: "{(})"
Output: false
*/
class Solution_3
{
public:
    bool isBalanced(std::string s)
    {
        std::stack<char> stack;

        for (char bracket : s)
        {
            if (bracket == '(' || bracket == '{' || bracket == '[')
            {
                stack.push(bracket);
            }
            else
            {
                if (stack.empty())
                {
                    return false;
                }

                char last = stack.top();
                stack.pop();

                if ((bracket == ')' && last != '(') || (bracket == '}' && last != '{') || (bracket == ']' && last != '['))
                {
                    return false;
                }
            }
        }

        return stack.empty();
    }
};











// !----------------- Maximum Occurring Word   -----------------!

/*
Given a set of strings with duplicates present, return the maximum occurring word in it. If two words have the same count, return any one of them.

Input: [code, coder, coding, codable, codec, codecs, coded, codeless, codecs, codependence, codex, codify, codependents, codes, code, coder, codesign, codec, codeveloper, codrive, codec, codecs, codiscovered]

Output: codec or codecs
*/
class Solution_4
{
public:
    std::string lexicographicSort(std::vector<std::string> const &words)
    {
        std::unordered_map <std::string, int> freq;

        for (auto &word : words)
        {
            ++freq[word];
        }

        std::string maxWord;
        int maxCount = 0;

        for (const auto &elem : freq)
        {
            if (elem.second > maxCount)
            {
                maxCount = elem.second;
                maxWord = elem.first;
            }
        }

        return maxWord;
    }


};






// !--------------------   N Digit Numbers VII   -------------------!

class Solution_5
{
private:
    void generateOnes (int n, std::string cur, std::unordered_set<std::string> &result)
    {
        if (cur.size() == n)
        {
            result.insert(cur);
            return;
        }

        if (cur.empty() || cur[cur.size() - 1] == '0')
        {
            generateOnes(n, cur + '0', result);
            generateOnes(n, cur + '1', result);
        }
        else
        {
            generateOnes(n, cur + '0', result);
        }

    }

public:
    std::unordered_set<std::string> findNDigitNumbers(int n)
    {
        std::unordered_set<std::string> result;
        generateOnes(n, "", result);
        return result;
    }
};







// !--------------- Missing Number ---------------!

/*
Given an array of `n-1` distinct integers in the range of 1 to `n`, find the missing number in it in linear time.

Input: [1, 2, 3, 4, 5, 7, 8, 9, 10]
Output: 6
Explanation: All elements are in the range 1 to 10. The missing number is 6.

Input: [1, 2, 3, 4]
Output: 5

Assume valid input.
*/
class Solution_6
{
public:
    int findMissingNumber(std::vector<int> const &nums)
    {
        int n = nums.size();
        int m = n + 1;

        int total = m * (m + 1) / 2;

        int sum = 0;
        for (int i = 0; i != n; ++i)
        {
            sum += nums[i];
        }

        return total - sum;
    }
};




int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

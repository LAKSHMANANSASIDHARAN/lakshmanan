/* Decode the Message
You are given the strings key and message, which represent a cipher key and a secret message, respectively. The steps to decode message are as follows:
Use the first appearance of all 26 lowercase English letters in key as the order of the substitution table.
Align the substitution table with the regular English alphabet.
Each letter in message is then substituted using the table.
Spaces ' ' are transformed to themselves.
For example, given key = "happy boy" (actual key would have at least one instance of each letter in the alphabet), we have the partial substitution table of ('h' -> 'a', 'a' -> 'b', 'p' -> 'c', 'y' -> 'd', 'b' -> 'e', 'o' -> 'f').
Return the decoded message.
Example 1:
Input: key = "the quick brown fox jumps over the lazy dog", message = "vkbs bs t suepuv"
Output: "this is a secret"
Explanation: The diagram above shows the substitution table.
It is obtained by taking the first appearance of each letter in "the quick brown fox jumps over the lazy dog".
Example 2:
Input: key = "eljuxhpwnyrdgtqkviszcfmabo", message = "zwx hnfx lqantp mnoeius ycgk vcnjrdb"
Output: "the five boxing wizards jump quickly"
Explanation: The diagram above shows the substitution table.
It is obtained by taking the first appearance of each letter in "eljuxhpwnyrdgtqkviszcfmabo".*/
class Solution {
public:
    string decodeMessage(string key, string message) {
        vector<pair<char, int>> ans(26, make_pair(' ', -1));

        int count = 0;
        for (int i = 0; i < key.size(); i++) {
            if (key[i] != ' ' && ans[key[i] - 'a'].second == -1) {
                ans[key[i] - 'a'] = {key[i], count++};
            }
        }

        for (int i = 0; i < message.size(); i++) {
            char temp = message[i];
            if (message[i] != ' ') {
                char temp2 = 'a' + (ans[temp - 'a'].second);
                message[i] = temp2;
            }
        }

        return message;
    }
};
/*Permutations
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:
Input: nums = [1]
Output: [[1]]
 Constraints:
1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.*/
class Solution {
public:
    void permutations(vector<int>& nums, vector<vector<int>>& ans, int i,
                      int n) {
        if (i == n) {
            ans.push_back(nums);
            return;
        }
        for (int j = i; j < n; j++) {
            swap(nums[i], nums[j]);
            permutations(nums, ans, i + 1, n);
            swap(nums[i], nums[j]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int i = 0;
        int n = nums.size();
        permutations(nums, ans, 0, n);
        return ans;
    }
};
/*Subsets
Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.
Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:
Input: nums = [0]
Output: [[],[0]]
Constraints:
1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.*/
class Solution {
public:
    void subset(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp,
                int i, int n) {
        if (i >= n) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        subset(nums, ans, temp, i + 1, n);
        temp.pop_back();
        subset(nums, ans, temp, i + 1, n);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        int i = 0;
        int n = nums.size();
        subset(nums, ans, temp, 0, n);
        return ans;
    }
};

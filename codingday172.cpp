/*491. Non-decreasing Subsequences
Given an integer array nums, return all the different possible non-decreasing subsequences of the given array with at least two elements. You may return the answer in any order.
Example 1:
Input: nums = [4,6,7,7]
Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
Example 2:
Input: nums = [4,4,3,2,1]
Output: [[4,4]]*/
class Solution {
    void res(vector<vector<int>>& ans,
             vector<int>& temp,
             vector<int>& nums,
             int i,
             set<vector<int>>& check)           
    {
        if (i == nums.size()) return;

       
        if (temp.empty() || nums[i] >= temp.back()) {
            temp.push_back(nums[i]);
            if (temp.size() > 1 && !check.count(temp)) { 
                ans.push_back(temp);
                check.insert(temp);
            }
            res(ans, temp, nums, i + 1, check);
            temp.pop_back();
        }

       
        res(ans, temp, nums, i + 1, check);
    }

public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        set<vector<int>> check;                 
        res(ans, temp, nums, 0, check);
        return ans;
    }
};

/*77. Combinations
Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
You may return the answer in any order.
Example 1:
Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
Example 2:
Input: n = 1, k = 1
Output: [[1]]
Explanation: There is 1 choose 1 = 1 total combination.*/
class Solution {
  void  combination(int i,vector<vector<int>>&ans,vector<int>&temp,int n,int k){
        if(temp.size()==k){
            ans.push_back(temp);
            return ;
        } 
        if(i>n){
            return ;
        }
        temp.push_back(i);
        combination(i+1,ans,temp,n,k);
        temp.pop_back();
        combination(i+1,ans,temp,n,k);
    }
public:
    vector<vector<int>> combine(int n, int k) {
       vector<vector<int>>ans;
       vector<int>temp;
       combination(1,ans,temp,n,k);
       return ans; 
    }
};
/*90. Subsets II
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.
Example 1:
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:
Input: nums = [0]
Output: [[],[0]]*/
class Solution {
    void subset(vector<vector<int>>& ans, vector<int>& temp, vector<int>& nums, int i) {
      ans.push_back(temp); 
        for (int j = i; j < nums.size(); j++) {
            if (j > i && nums[j] == nums[j - 1]) continue; 
            temp.push_back(nums[j]); 
            subset(ans, temp, nums, j + 1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        subset(ans, temp, nums, 0);
        return ans;
    }
};

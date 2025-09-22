/*2597. The Number of Beautiful Subsets
You are given an array nums of positive integers and a positive integer k.
A subset of nums is beautiful if it does not contain two integers with an absolute difference equal to k.
Return the number of non-empty beautiful subsets of the array nums.
A subset of nums is an array that can be obtained by deleting some (possibly none) elements from nums. Two subsets are different if and only if the chosen indices to delete are different.
Example 1:
Input: nums = [2,4,6], k = 2
Output: 4
Explanation: The beautiful subsets of the array nums are: [2], [4], [6], [2, 6].
It can be proved that there are only 4 beautiful subsets in the array [2,4,6].
Example 2:
Input: nums = [1], k = 1
Output: 1
Explanation: The beautiful subset of the array nums is [1].
It can be proved that there is only 1 beautiful subset in the array [1].*/
class Solution {
    bool check(vector<int>& temp, int k) {
        for (int i = 0; i < (int)temp.size(); i++) {
            for (int j = i + 1; j < (int)temp.size(); j++) {
                if (abs(temp[i] - temp[j]) == k) return false;
            }
        }
        return true;
    }
    void res(vector<int>& nums, int k,vector<int>&temp,int& count,int i){
       if (i == nums.size()) {
            if (!temp.empty() && check(temp, k))
                count++;
            return;
        }
          temp.push_back(nums[i]);
        res(nums,k,temp,count,i+1);
        temp.pop_back();
        res(nums,k,temp,count,i+1);
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
       vector<int>temp;
       int count=0;
       res(nums,k,temp,count,0);
       return count; 
    }
};

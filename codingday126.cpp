/*Set Mismatch
You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.
You are given an integer array nums representing the data status of this set after the error.
Find the number that occurs twice and the number that is missing and return them in the form of an array.
Example 1:
Input: nums = [1,2,2,4]
Output: [2,3]
Example 2:
Input: nums = [1,1]
Output: [1,2]
 */
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i = 1; i <= nums.size(); ++i) mp[i]++;
        for(int x : nums) mp[x]++;
        int dup = 0, miss = 0;
        for(auto &p : mp){
            if(p.second == 3) dup = p.first;
            else if(p.second == 1) miss = p.first;
        }
        return {dup, miss};
    }
};

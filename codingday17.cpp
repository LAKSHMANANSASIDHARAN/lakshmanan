/*Count Number of Bad Pairs
You are given a 0-indexed integer array nums. A pair of indices (i, j) is a bad pair if i < j and j - i != nums[j] - nums[i].
Return the total number of bad pairs in nums.
Example 1:
Input: nums = [4,1,3,3]
Output: 5
Explanation: The pair (0, 1) is a bad pair since 1 - 0 != 1 - 4.
The pair (0, 2) is a bad pair since 2 - 0 != 3 - 4, 2 != -1.
The pair (0, 3) is a bad pair since 3 - 0 != 3 - 4, 3 != -1.
The pair (1, 2) is a bad pair since 2 - 1 != 3 - 1, 1 != 2.
The pair (2, 3) is a bad pair since 3 - 2 != 3 - 3, 1 != 0.
There are a total of 5 bad pairs, so we return 5.
Example 2:
Input: nums = [1,2,3,4,5]
Output: 0
Explanation: There are no bad pairs.
USING HASHMAP*/
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<long long, long long> mpp;
      // insert the all diff between i and nums[i] in map 
      // if it comes ones then it value is 1 
        for (int i = 0; i < nums.size(); i++) {
            long long key = nums[i] - i;
            if (mpp.find(key) == mpp.end()) {
                mpp[key] = 0;
            }
            mpp[key]++;
        }

        int i = 0;
        long long count = 0;
      // set size of nums array-1
      
        int size = nums.size() - 1;
        while (i < nums.size() - 1) {
            long long key = nums[i] - i;
            if (mpp[key] == 1) { // if key comes only ones then add the total size
                count += size;
            } else { // take only vaild pairs with the key 
                count += size - (mpp[key] - 1);
                mpp[key]--;
            }
            size--;  // decrement the size at each time
            i++;
        }
        return count;
    }
};

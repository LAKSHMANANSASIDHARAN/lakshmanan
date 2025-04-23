/*First Missing Positive
Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.
You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.
Example 1:
Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
Example 2:
Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
Example 3:
Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.
 */
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       int i=0;
       while(i<nums.size()){
        if(nums[i]==i+1 or nums[i]<=0 or nums[i]>nums.size()){
         i++;
         }
        else{
          if(nums[nums[i] - 1] == nums[i]){
              i++;
            } 
            else{
            swap(nums[i], nums[nums[i] - 1]);
            }
            }
       }
    i=0;
    while(i<nums.size()){
        if(nums[i]!=i+1){
            break;
        }
        i++;
    }
    return i+1;
    }
};

/*Sort Colors
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.
Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:
Input: nums = [2,0,1]
Output: [0,1,2]
 */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count_zero=0,count_one=0,count_two=0;
        for(auto it:nums){
               if(it==0){
                count_zero++;
               }
               else if(it==1){
                count_one++;
               }
               else{
                count_two++;
               }
        }
        for(int i=0;i<nums.size();i++){
            if(count_zero!=0){
                nums[i]=0;
                count_zero--;
            }
            else if(count_one!=0){
              nums[i]=1;
              count_one--;
            }
            else{
                nums[i]=2;
                count_two--;
            }
        }
        
    }
};

/*Ways to Make a Fair Array
You are given an integer array nums. You can choose exactly one index (0-indexed) and remove the element. Notice that the index of the elements may change after the removal.
For example, if nums = [6,1,7,4,1]:
Choosing to remove index 1 results in nums = [6,7,4,1].
Choosing to remove index 2 results in nums = [6,1,4,1].
Choosing to remove index 4 results in nums = [6,1,7,4].
An array is fair if the sum of the odd-indexed values equals the sum of the even-indexed values.
Return the number of indices that you could choose such that after the removal, nums is fair.
Example 1:
Input: nums = [2,1,6,4]
Output: 1
Explanation:
Remove index 0: [1,6,4] -> Even sum: 1 + 4 = 5. Odd sum: 6. Not fair.
Remove index 1: [2,6,4] -> Even sum: 2 + 4 = 6. Odd sum: 6. Fair.
Remove index 2: [2,1,4] -> Even sum: 2 + 4 = 6. Odd sum: 1. Not fair.
Remove index 3: [2,1,6] -> Even sum: 2 + 6 = 8. Odd sum: 1. Not fair.
There is 1 index that you can remove to make nums fair.
Example 2:
Input: nums = [1,1,1]
Output: 3
Explanation: You can remove any index and the remaining array is fair.
Example 3:
Input: nums = [1,2,3]
Output: 0
Explanation: You cannot make a fair array after removing any index.*/
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        if(nums.size()==1){
            return 1;
        }
        vector<int> even;
        vector<int> odd;
        int i = 0, x = 0, y = 0;
        while (i < nums.size()) {
            if (i % 2 == 0) {
                x += nums[i];
                even.push_back(x);
            } else {
                y += nums[i];
                odd.push_back(y);
            }
            i++;
        }
        if(even.empty() or odd.empty()){
    return 0;
     }
        int evensum = 0, oddsum = 0, ans = 0, temp1, temp2;
        i = 0;
        int E = 0, O = 0;

        while (i < nums.size()) {
            if (i % 2 == 0) {

                temp1 = even[even.size() - 1] - even[E] + oddsum;
                temp2 = odd[odd.size() - 1] - oddsum + evensum;
                evensum = even[E];
                E++;
            } else {
                temp2 = odd[odd.size() - 1] - odd[O] + evensum;
                temp1 = even[even.size() - 1] - evensum + oddsum;

                oddsum = odd[O];
                O++;
            }
            if (temp1 == temp2) {
                ans++;
            }
            i++;
        }
        return ans;
    }
};

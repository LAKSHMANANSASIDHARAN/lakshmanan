/*228. Summary Ranges
You are given a sorted unique integer array nums.
A range [a,b] is the set of all integers from a to b (inclusive).
Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.
Each range [a,b] in the list should be output as:
"a->b" if a != b
"a" if a == b
 Example 1:
Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"
Example 2:
Input: nums = [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: The ranges are:
[0,0] --> "0"
[2,4] --> "2->4"
[6,6] --> "6"
[8,9] --> "8->9"*/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.empty()) return ans;   // handle empty input

        int i = 0, j = 1;
        string temp;

        while (j < nums.size()) {
            if (nums[j] - 1 == nums[j - 1]) {
                j++;
            } else {
                temp += to_string(nums[i]);
                if (j - 1 != i) {
                    temp += "->";
                    temp += to_string(nums[j - 1]);
                }
                ans.push_back(temp);
                temp = "";
                i = j;
                j++;
            }
        }

        
        temp += to_string(nums[i]);
        if (j - 1 != i) {
            temp += "->";
            temp += to_string(nums[j - 1]);
        }
        ans.push_back(temp);

        return ans;
    }
};

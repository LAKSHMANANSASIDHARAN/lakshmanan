/*Long Pressed Name
Your friend is typing his name into a keyboard. Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.
You examine the typed characters of the keyboard. Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.
Example 1:
Input: name = "alex", typed = "aaleex"
Output: true
Explanation: 'a' and 'e' in 'alex' were long pressed.
Example 2:
Input: name = "saeed", typed = "ssaaedd"
Output: false
Explanation: 'e' must have been pressed twice, but it was not in the typed output.*/
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        while (j < typed.size()) {
            if (i < name.size() && name[i] == typed[j]) {
                i++;
                j++;
            } else if (j > 0 && typed[j] == typed[j - 1]) {
                j++;
            } else {
                return false;
            }
        }
        return i == name.size();
    }
};
/* Ant on the Boundary
An ant is on a boundary. It sometimes goes left and sometimes right.
You are given an array of non-zero integers nums. The ant starts reading nums from the first element of it to its end. At each step, it moves according to the value of the current element:
If nums[i] < 0, it moves left by -nums[i] units.
If nums[i] > 0, it moves right by nums[i] units.
Return the number of times the ant returns to the boundary.
Notes:
There is an infinite space on both sides of the boundary.
We check whether the ant is on the boundary only after it has moved |nums[i]| units. In other words, if the ant crosses the boundary during its movement, it does not count.
Example 1:
Input: nums = [2,3,-5]
Output: 1
Explanation: After the first step, the ant is 2 steps to the right of the boundary.
After the second step, the ant is 5 steps to the right of the boundary.
After the third step, the ant is on the boundary.
So the answer is 1.
Example 2:
Input: nums = [3,2,-3,-4]
Output: 0
Explanation: After the first step, the ant is 3 steps to the right of the boundary.
After the second step, the ant is 5 steps to the right of the boundary.
After the third step, the ant is 2 steps to the right of the boundary.
After the fourth step, the ant is 2 steps to the left of the boundary.
The ant never returned to the boundary, so the answer is 0.*/
class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int i=0;
        int sum=0;
        int ans=0;
        while(i<nums.size()){
            sum+=nums[i];
            if(sum==0) ans++;
            i++;
        }
        return ans;
    }
};
/*Points That Intersect With Cars
You are given a 0-indexed 2D integer array nums representing the coordinates of the cars parking on a number line. For any index i, nums[i] = [starti, endi] where starti is the starting point of the ith car and endi is the ending point of the ith car.
Return the number of integer points on the line that are covered with any part of a car.
Example 1:
Input: nums = [[3,6],[1,5],[4,7]]
Output: 7
Explanation: All the points from 1 to 7 intersect at least one car, therefore the answer would be 7.
Example 2:
Input: nums = [[1,3],[5,8]]
Output: 7
Explanation: Points intersecting at least one car are 1, 2, 3, 5, 6, 7, 8. There are a total of 7 points, therefore the answer would be 7.*/
class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int>line(102,0);
        for(int i=0;i<nums.size();i++){
            line[nums[i][0]]+=1;
            line[nums[i][1]+1]-=1;
        }
        for(int i=1;i<line.size();i++){
            line[i]=line[i]+line[i-1];
        }
        int i=0;
        int sum=0;
        while(i<line.size()){
            if(line[i]>=1){
                sum++;
            }
            i++;
        }
        return sum;
    }
};

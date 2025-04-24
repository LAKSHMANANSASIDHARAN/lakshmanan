/*Count Complete Subarrays in an Array
You are given an array nums consisting of positive integers.
We call a subarray of an array complete if the following condition is satisfied:
The number of distinct elements in the subarray is equal to the number of distinct elements in the whole array.
Return the number of complete subarrays.
A subarray is a contiguous non-empty part of an array.
Example 1:
Input: nums = [1,3,1,2,2]
Output: 4
Explanation: The complete subarrays are the following: [1,3,1,2], [1,3,1,2,2], [3,1,2] and [3,1,2,2].
Example 2:
Input: nums = [5,5,5,5]
Output: 10
Explanation: The array consists only of the integer 5, so any subarray is complete. The number of subarrays that we can choose is 10.*/
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
       unordered_map<int,int>temp,check;
       for(int i:nums){
        check[i]++;
       }
       int i=0,j=0,count=0;
       while(j<nums.size()){
          temp[nums[j]]++;
        while(i<=j&&check.size()==temp.size()){
              count+=nums.size()-j;
              temp[nums[i]]--;
              if(temp[nums[i]]==0){
                temp.erase(nums[i]);
              }
              i++;
        }
      
        j++;
       }
       return count;



    }
};
/*aseball Game
You are keeping the scores for a baseball game with strange rules. At the beginning of the game, you start with an empty record.
You are given a list of strings operations, where operations[i] is the ith operation you must apply to the record and is one of the following:
An integer x.
Record a new score of x.
'+'.
Record a new score that is the sum of the previous two scores.
'D'.
Record a new score that is the double of the previous score.
'C'.
Invalidate the previous score, removing it from the record.
Return the sum of all the scores on the record after applying all the operations.
The test cases are generated such that the answer and all intermediate calculations fit in a 32-bit integer and that all operations are valid.
Example 1:
Input: ops = ["5","2","C","D","+"]
Output: 30
Explanation:
"5" - Add 5 to the record, record is now [5].
"2" - Add 2 to the record, record is now [5, 2].
"C" - Invalidate and remove the previous score, record is now [5].
"D" - Add 2 * 5 = 10 to the record, record is now [5, 10].
"+" - Add 5 + 10 = 15 to the record, record is now [5, 10, 15].
The total sum is 5 + 10 + 15 = 30.
Example 2:
Input: ops = ["5","-2","4","C","D","9","+","+"]
Output: 27
Explanation:
"5" - Add 5 to the record, record is now [5].
"-2" - Add -2 to the record, record is now [5, -2].
"4" - Add 4 to the record, record is now [5, -2, 4].
"C" - Invalidate and remove the previous score, record is now [5, -2].
"D" - Add 2 * -2 = -4 to the record, record is now [5, -2, -4].
"9" - Add 9 to the record, record is now [5, -2, -4, 9].
"+" - Add -4 + 9 = 5 to the record, record is now [5, -2, -4, 9, 5].
"+" - Add 9 + 5 = 14 to the record, record is now [5, -2, -4, 9, 5, 14].
The total sum is 5 + -2 + -4 + 9 + 5 + 14 = 27.
Example 3:
Input: ops = ["1","C"]
Output: 0
Explanation:
"1" - Add 1 to the record, record is now [1].
"C" - Invalidate and remove the previous score, record is now [].
Since the record is empty, the total sum is 0.*/
class Solution {
public:
    int calPoints(vector<string>& s) {
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(!st.empty()&&s[i]=="C"){
                st.pop();
            }
           else if(!st.empty()&&s[i]=="D"){
                int temp=2*st.top();
                st.push(temp);
            }
            else if(st.size()>=2&&s[i]=="+"){
                int sum=st.top();
                int temp2=st.top();
                st.pop();
                sum+=st.top();
                st.push(temp2);
                st.push(sum);
            }
            else{
                int interger=stoi(s[i]);
                st.push(interger);
            }
        }
        int res=0;
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        return res;
    }
};
/*Count Binary Substrings
Given a binary string s, return the number of non-empty substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.
Substrings that occur multiple times are counted the number of times they occur.
Example 1:
Input: s = "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
Notice that some of these substrings repeat and are counted the number of times they occur.
Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.
Example 2:
Input: s = "10101"
Output: 4
Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.*/
class Solution {
public:
    int countBinarySubstrings(string s) {
         vector<int>arr;
         int i=1;
         int count=1;
        while(i<s.size()){
            if(s[i]==s[i-1]){
                count++;
            }
            else{
                arr.push_back(count);
                count=1;
            }
            i++;
        }
          arr.push_back(count);
        int res=0;
        for(int i=0;i<arr.size()-1;i++){
            res+=min(arr[i],arr[i+1]);
        }
        return res;
    }
};

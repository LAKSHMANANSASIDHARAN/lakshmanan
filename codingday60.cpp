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
/*Reverse Words in a String
Given an input string s, reverse the order of the words.
A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
Return a string of the words in reverse order concatenated by a single space.
Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.
Example 1:
Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:
Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:
Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.*/
class Solution {
public:
    string reverseWords(string s) {
      stack<string>st;
      int i=0;
    string temp="";
       while(i<s.size()){
        if(s[i]==' '){
            if(!temp.empty()){
            st.push(temp);
            temp="";
            }
          
        }else{
        temp+=s[i];
    
        }
        i++;
       } 
    if (!temp.empty()) {
            st.push(temp);
        }
        string ans="";
        while(!st.empty()){
            if(ans==""){
                ans+=st.top();
                st.pop();
            }
            else{
                ans+=" ";
                ans+=st.top();
                st.pop();
            }
        }
        return ans;
    }
};

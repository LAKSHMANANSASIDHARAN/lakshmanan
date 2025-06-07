/*Uncommon Words from Two Sentences
A sentence is a string of single-space separated words where each word consists only of lowercase letters.
A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.
Given two sentences s1 and s2, return a list of all the uncommon words. You may return the answer in any order.
Example 1:
Input: s1 = "this apple is sweet", s2 = "this apple is sour"
Output: ["sweet","sour"]
Explanation:
The word "sweet" appears only in s1, while the word "sour" appears only in s2.
Example 2:
Input: s1 = "apple apple", s2 = "banana"
Output: ["banana"]
 */
class Solution {
    void process(unordered_map<string,int>&mp,string s){
      int i=0;
      string temp="";
      while(i<s.size()){
        if(s[i]==' '){
            mp[temp]++;
            temp="";
        }
        else{
            temp+=s[i];
        }
        i++;
      }
       mp[temp]++;
    }
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int>mp;
        process(mp,s1);
        process(mp,s2);
        vector<string>ans;
        for(auto i:mp){
            if(i.second==1){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};
/*Minimum Length of String After Operations
You are given a string s.
You can perform the following process on s any number of times:
Choose an index i in the string such that there is at least one character to the left of index i that is equal to s[i], and at least one character to the right that is also equal to s[i].
Delete the closest occurrence of s[i] located to the left of i.
Delete the closest occurrence of s[i] located to the right of i.
Return the minimum length of the final string s that you can achieve.
Example 1:
Input: s = "abaacbcbb"
Output: 5
Explanation:
We do the following operations:
Choose index 2, then remove the characters at indices 0 and 3. The resulting string is s = "bacbcbb".
Choose index 3, then remove the characters at indices 0 and 5. The resulting string is s = "acbcb".
Example 2:
Input: s = "aa"Output: 2
Explanation:
We cannot perform any operations, so we return the length of the original string.*/
class Solution {
public:
    int minimumLength(string s) {
     unordered_map<char,int>map;
        int len=0;
        for(int i=0;i<s.size();i++){
            map[s[i]]++;
        }
        for(auto i:map){
            if(i.second>2){
                int temp=i.second;
               while(temp>2){
                   temp-=2;
               }
               len+=temp;
            }
            else{
                len+=i.second;
            }
        }
        if(len==0) return s.size();
        return len;
    }
};
/*Number of Pairs of Strings With Concatenation Equal to Target
Given an array of digit strings nums and a digit string target, return the number of pairs of indices (i, j) (where i != j) such that the concatenation of nums[i] + nums[j] equals target.
Example 1:
Input: nums = ["777","7","77","77"], target = "7777"
Output: 4
Explanation: Valid pairs are:
- (0, 1): "777" + "7"
- (1, 0): "7" + "777"
- (2, 3): "77" + "77"
- (3, 2): "77" + "77"
Example 2:
Input: nums = ["123","4","12","34"], target = "1234"
Output: 2
Explanation: Valid pairs are:
- (0, 1): "123" + "4"
- (2, 3): "12" + "34"
Example 3:
Input: nums = ["1","1","1"], target = "11"
Output: 6
Explanation: Valid pairs are:
- (0, 1): "1" + "1"
- (1, 0): "1" + "1"
- (0, 2): "1" + "1"
- (2, 0): "1" + "1"
- (1, 2): "1" + "1"
- (2, 1): "1" + "1"
 */
class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
       int count=0;
       for(int i=0;i<nums.size();i++){
        for(int j=0;j<nums.size();j++){
            if(i==j){
                continue;
            }
            else {
                string temp=nums[i];
                temp+=nums[j];
                if(temp==target){
                    count++;
                }
            }
        }
       }
       return count; 
    }
};

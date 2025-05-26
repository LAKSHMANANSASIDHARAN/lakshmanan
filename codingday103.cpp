/* Longest Palindrome by Concatenating Two Letter Words
You are given an array of strings words. Each element of words consists of two lowercase English letters.
Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.
Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.
A palindrome is a string that reads the same forward and backward.
Example 1:
Input: words = ["lc","cl","gg"]
Output: 6
Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
Note that "clgglc" is another longest palindrome that can be created.
Example 2:
Input: words = ["ab","ty","yt","lc","cl","ab"]
Output: 8
Explanation: One longest palindrome is "ty" + "lc" + "cl" + "yt" = "tylcclyt", of length 8.
Note that "lcyttycl" is another longest palindrome that can be created.
Example 3:
Input: words = ["cc","ll","xx"]
Output: 2
Explanation: One longest palindrome is "cc", of length 2.
Note that "ll" is another longest palindrome that can be created, and so is "xx".*/
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
      int count=0,maxi=0;
      unordered_map<string,int>mp;
      unordered_set<string>st;
      for(auto i:words){
        mp[i]++;
      }
     bool centerUsed = false;
for(auto &[f,s]:mp){
    string temp = f;
    reverse(temp.begin(), temp.end());
    if(st.find(f) != st.end()) continue;

    if(f == temp){
        if(s % 2 == 0){
            count += s * 2;
        } else {
            count += (s - 1) * 2;
            if(!centerUsed){
                count += 2;
                centerUsed = true;
            }
        }
        st.insert(f);
    } else {
        if(mp.find(temp) != mp.end()){
            count += min(mp[f], mp[temp]) * 4;
        }
        st.insert(f);
        st.insert(temp);
    }
}

     
      return count; 
    }
};

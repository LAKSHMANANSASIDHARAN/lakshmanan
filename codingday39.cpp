/*Check if the Sentence Is Pangram
A pangram is a sentence where every letter of the English alphabet appears at least once.
Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.
Example 1:
Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
Output: true
Explanation: sentence contains at least one of every letter of the English alphabet.
Example 2:
Input: sentence = "leetcode"
Output: false*/
class Solution {
public:
struct compare
{
    bool operator()(pair<char,int>a,pair<char,int>b){
           return a.second<b.second;
    }
};

public:
    bool checkIfPangram(string sentence) {
       vector<pair<char,int>>ans(26,{' ',0});
    for(auto it:sentence){
        if(ans[it-'a'].second==0){
            ans[it - 'a'] = {it, 1};
            }   
            else{
                ans[it - 'a'].second++;   
            }
         }
    sort(ans.begin(),ans.end(),compare());
    if(ans[0].second!=0){
        return true;
    }
    return false;
    }
};

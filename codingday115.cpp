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

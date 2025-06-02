/*Permutation in String
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
In other words, return true if one of s1's permutations is the substring of s2.
Example 1:
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:
Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 */
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>hash(26,0) ,hash2(26,0);
        string temp="",temp2="";
        if(s1.size()>s2.size()) return false;
        temp=s1;
        temp2=s2;
        for(auto i:temp){
            hash[i-'a']++;
        }
        int i=0;
        for(i=0;i<temp.size();i++){
            hash2[temp2[i]-'a']++;
        }
        if(hash==hash2)return true;
        int l=0;
        while (i<temp2.size()){   
            hash2[temp2[l]-'a']--;
            hash2[temp2[i]-'a']++;
            if(hash==hash2){
                return true;
            }
            l++;
            i++;
        }
        return false;
    }
};

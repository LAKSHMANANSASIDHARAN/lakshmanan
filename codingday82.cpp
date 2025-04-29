/* Repeated DNA Sequences
The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.
For example, "ACGAATTCCG" is a DNA sequence.
When studying DNA, it is useful to identify repeated sequences within the DNA.
Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.
Example 1:
Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]
Example 2:
Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]*/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>res;
        int i=0,j=0;
        unordered_map<string,int>mp;
        string temp="";
        for(j=0;j<10;j++){
             temp+=s[j];
        }
        mp[temp]++;
        while(j<s.size()){
            temp.erase(temp.begin());
            temp+=s[j];
            mp[temp]++;
            j++;
        }
       
        for(auto &[f,s]:mp){
            if(s>1){
                res.push_back(f);
            }
        }
        return res;
    }
};

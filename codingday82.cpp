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
/*Two Out of Three
Given three integer arrays nums1, nums2, and nums3, return a distinct array containing all the values that are present in at least two out of the three arrays. You may return the values in any order.
Example 1:
Input: nums1 = [1,1,3,2], nums2 = [2,3], nums3 = [3]
Output: [3,2]
Explanation: The values that are present in at least two arrays are:
- 3, in all three arrays.
- 2, in nums1 and nums2.
Example 2:
Input: nums1 = [3,1], nums2 = [2,3], nums3 = [1,2]
Output: [2,3,1]
Explanation: The values that are present in at least two arrays are:
- 2, in nums2 and nums3.
- 3, in nums1 and nums2.
- 1, in nums1 and nums3.
Example 3:
Input: nums1 = [1,2,2], nums2 = [4,3,3], nums3 = [5]
Output: []
Explanation: No value is present in at least two arrays.*/
class Solution {
    void process (unordered_map<int,int>&mp,unordered_set<int>st){
        for(auto it:st){
            mp[it]++;
        }
    }
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
     unordered_map<int,int>mp;
     unordered_set<int>one,two,three;
     for(auto it:nums1){
        one.insert(it);
     } 
     for(auto it:nums2){
         two.insert(it);
     }  
     for(auto it:nums3){
         three.insert(it);
     }
     process(mp,one);
     process(mp,two);
     process(mp,three);
     vector<int>ans;
     for(auto &[f,s]:mp){
        if(s>=2){
            ans.push_back(f);
        }
     }
     return ans;
    }
};

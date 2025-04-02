/*Intersection of Two Arrays II
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.
Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
       vector<int>ans;
       unordered_map<int,int>mp;
       for(auto it:nums1){
        mp[it]++;
       }
       int i=0;
       while(i<nums2.size()){
        if(mp.find(nums2[i])!=mp.end() and mp[nums2[i]]!=0){
                ans.push_back(nums2[i]);
                mp[nums2[i]]--;
        }
        i++;
       }
        return ans;
    }
};
/*Reverse Vowels of a String
Given a string s, reverse only all the vowels in the string and return it.
The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.
Example 1:
Input: s = "IceCreAm"
Output: "AceCreIm"
Explanation:
The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".
Example 2:
Input: s = "leetcode"
Output: "leotcede"*/
class Solution {
    bool check(char& letter) {
        if (letter == 'a' or letter == 'e' or letter == 'i' or letter == 'o' or
            letter == 'u' or letter == 'A' or letter == 'E' or letter == 'I' or
            letter == 'O' or letter == 'U') {
            return true;
        }
        return false;
    }

public:
    string reverseVowels(string s) {
        int l = 0, r = s.size() - 1;
        while (l<r) {
           if(check(s[l]) && check(s[r])){
            swap(s[l],s[r]);
            l++;r--;
           }
           else if(check(s[l]) && !check(s[r])){
            r--;
           }
           else if(!check(s[l]) && check(s[r])){
               l++;
           }
           else{
            l++;r--;
           }

        }
        return s;
    }
};

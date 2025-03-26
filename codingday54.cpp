/*Find All Anagrams in a String
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
Example 1:
Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:
Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) return {}; 
        
        vector<int> phash(26, 0), shash(26, 0), ans;
        
        for (int i = 0; i < p.size(); i++) {
            phash[p[i] - 'a']++;
            shash[s[i] - 'a']++;
        }
        
        int i = 0, j = p.size();
        if (phash == shash) ans.push_back(i);
        
        while (j < s.size()) {
            shash[s[i] - 'a']--;
            shash[s[j] - 'a']++;
            i++; j++;
            if (phash == shash) ans.push_back(i);
        }
        
        return ans;
    }
};
/* Minimum Consecutive Cards to Pick Up
You are given an integer array cards where cards[i] represents the value of the ith card. A pair of cards are matching if the cards have the same value.
Return the minimum number of consecutive cards you have to pick up to have a pair of matching cards among the picked cards. If it is impossible to have matching cards, return -1.
Example 1:
Input: cards = [3,4,2,3,4,7]
Output: 4
Explanation: We can pick up the cards [3,4,2,3] which contain a matching pair of cards with value 3. Note that picking up the cards [4,2,3,4] is also optimal.
Example 2:
Input: cards = [1,0,5,3]
Output: -1
Explanation: There is no way to pick up a set of consecutive cards that contain a pair of matching cards.*/
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int>mpp;
        int count=0,res=INT_MAX;
        int i=0,j=0,n=cards.size();
        while(j<n){
           mpp[cards[j]]++;
           while(mpp[cards[j]]>=2){
            res=min(res,j-i+1);
            mpp[cards[i]]--;
            i++;
            count++;
           }
           j++;
        }
        if(count==0){
            return -1;
        }
        return res;
    }
};

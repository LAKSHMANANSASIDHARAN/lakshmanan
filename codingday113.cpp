/* Shuffle String
You are given a string s and an integer array indices of the same length. The string s will be shuffled such that the character at the ith position moves to indices[i] in the shuffled string.
Return the shuffled string.
Example 1:
Input: s = "codeleet", indices = [4,5,6,7,0,2,1,3]
Output: "leetcode"
Explanation: As shown, "codeleet" becomes "leetcode" after shuffling.
Example 2:
Input: s = "abc", indices = [0,1,2]
Output: "abc"
Explanation: After shuffling, each character remains in its position.
 */
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
       string res="";
       vector<pair<int,char>>temp;
       int i=0;
       while(i<indices.size()){
        temp.push_back({indices[i],s[i]});
        i++;
       }
       sort(temp.begin(),temp.end());
       for(auto i:temp){
        res+=i.second;
       }

        return res;
    }
};
/* Count Items Matching a Rule
You are given an array items, where each items[i] = [typei, colori, namei] describes the type, color, and name of the ith item. You are also given a rule represented by two strings, ruleKey and ruleValue.
The ith item is said to match the rule if one of the following is true:
ruleKey == "type" and ruleValue == typei.
ruleKey == "color" and ruleValue == colori.
ruleKey == "name" and ruleValue == namei.
Return the number of items that match the given rule.
Example 1:
Input: items = [["phone","blue","pixel"],["computer","silver","lenovo"],["phone","gold","iphone"]], ruleKey = "color", ruleValue = "silver"
Output: 1
Explanation: There is only one item matching the given rule, which is ["computer","silver","lenovo"].
Example 2:
Input: items = [["phone","blue","pixel"],["computer","silver","phone"],["phone","gold","iphone"]], ruleKey = "type", ruleValue = "phone"
Output: 2
Explanation: There are only two items matching the given rule, which are ["phone","blue","pixel"] and ["phone","gold","iphone"]. Note that the item ["computer","silver","phone"] does not match.*/
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        unordered_map<string, int> type, color, name;
        for (auto i : items) {
            type[i[0]]++;
            color[i[1]]++;
            name[i[2]]++;
        }
        if (ruleKey == "type") return type[ruleValue];
        else if (ruleKey == "color") return color[ruleValue];
        else return name[ruleValue];
    }
};
/*Sort Vowels in a String
Given a 0-indexed string s, permute s to get a new string t such that:
All consonants remain in their original places. More formally, if there is an index i with 0 <= i < s.length such that s[i] is a consonant, then t[i] = s[i].
The vowels must be sorted in the nondecreasing order of their ASCII values. More formally, for pairs of indices i, j with 0 <= i < j < s.length such that s[i] and s[j] are vowels, then t[i] must not have a higher ASCII value than t[j].
Return the resulting string.
The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in lowercase or uppercase. Consonants comprise all letters that are not vowels.
Example 1:
Input: s = "lEetcOde"
Output: "lEOtcede"
Explanation: 'E', 'O', and 'e' are the vowels in s; 'l', 't', 'c', and 'd' are all consonants. The vowels are sorted according to their ASCII values, and the consonants remain in the same places.
Example 2:
Input: s = "lYmpH"
Output: "lYmpH"
Explanation: There are no vowels in s (all characters in s are consonants), so we return "lYmpH".*/
class Solution {
    bool isVowel(char ch) {
        return string("aeiouAEIOU").find(ch) != string::npos;
    }
public:
    string sortVowels(string s) {
        vector<char> vowels;
        for (char c : s) {
            if (isVowel(c)) vowels.push_back(c);
        }
        sort(vowels.begin(), vowels.end());
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) {
                s[i] = vowels[j];
                j++;
            }
        }
        return s;
    }
};

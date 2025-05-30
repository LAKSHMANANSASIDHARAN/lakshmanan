/*Longest Nice Substring
A string s is nice if, for every letter of the alphabet that s contains, it appears both in uppercase and lowercase. For example, "abABB" is nice because 'A' and 'a' appear, and 'B' and 'b' appear. However, "abA" is not because 'b' appears, but 'B' does not.
Given a string s, return the longest substring of s that is nice. If there are multiple, return the substring of the earliest occurrence. If there are none, return an empty string.
Example 1:
Input: s = "YazaAay"
Output: "aAa"
Explanation: "aAa" is a nice string because 'A/a' is the only letter of the alphabet in s, and both 'A' and 'a' appear.
"aAa" is the longest nice substring.
Example 2:
Input: s = "Bb"
Output: "Bb"
Explanation: "Bb" is a nice string because both 'B' and 'b' appear. The whole string is a substring.
Example 3:
Input: s = "c"
Output: ""
Explanation: There are no nice substrings.*/
class Solution {
public:
    static bool check(string a, string b) {
        return a.size() < b.size();
    }

    void longestsubstring(string s, vector<string>& temp) {
        unordered_map<char, bool> mp;
        for (char c : s) {
            mp[c] = false;
        }

        
        for (char c : s) {
            if (islower(c) && mp.find(toupper(c)) != mp.end()) {
                mp[c] = true;
                mp[toupper(c)] = true;
            }
            else if (isupper(c) && mp.find(tolower(c)) != mp.end()) {
                mp[c] = true;
                mp[tolower(c)] = true;
            }
        }

        for (int i = 0; i < s.size(); i++) {
            if (!mp[s[i]]) {
                string subone = s.substr(0, i);
                string subtwo = s.substr(i + 1);
                if (!subone.empty()) longestsubstring(subone, temp);
                if (!subtwo.empty()) longestsubstring(subtwo, temp);
                return;
            }
        }

        temp.push_back(s);
    }

    string longestNiceSubstring(string s) {
        vector<string> temp;
        longestsubstring(s, temp);
        if (temp.empty()) return "";
        int size=0;
        string res="";
        for(auto i:temp){
            if(i.size()>size){
              res=i;
              size=i.size();
            }
        }
        return res; 
    }
};

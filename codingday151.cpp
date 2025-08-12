/*1002. Find Common Characters
Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.

 

Example 1:

Input: words = ["bella","label","roller"]
Output: ["e","l","l"]
Example 2:

Input: words = ["cool","lock","cook"]
Output: ["c","o"]
 */
class Solution {
    bool check(vector<vector<int>>& temp, char c, int n) {
        for (auto& arr : temp) {
            if (arr[c - 'a'] < n) return false;
        }
        return true;
    }

    void insert(vector<string>& ans, char c, int n) {
        string s = "";
        s += c;
        while (n--) {
            ans.push_back(s);
        }
    }

    void doit(vector<vector<int>>& temp, char c, int n) {
        for (auto& arr : temp) {
            arr[c - 'a'] -= n; 
        }
    }

public:
    vector<string> commonChars(vector<string>& words) {
        vector<vector<int>> temp;
        for (auto& s : words) {
            vector<int> arr(26, 0);
            for (auto ch : s) {
                arr[ch - 'a']++;
            }
            temp.push_back(arr);
        }

        string s = words[0];
        vector<string> ans;
        int i = 0;
        while (i < s.size()) {
           
            int count = INT_MAX;
            for (auto& arr : temp) {
                count = min(count, arr[s[i] - 'a']);
            }

            if (count > 0) {
                if (check(temp, s[i], count)) {
                    insert(ans, s[i], count);
                    doit(temp, s[i], count);
                }
            }
            i++;
        }
        return ans;
    }
};

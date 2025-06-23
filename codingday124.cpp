/* Keyboard Row
Given an array of strings words, return the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below.
Note that the strings are case-insensitive, both lowercased and uppercased of the same letter are treated as if they are at the same row.
In the American keyboard:
the first row consists of the characters "qwertyuiop",
the second row consists of the characters "asdfghjkl", and
the third row consists of the characters "zxcvbnm".
Example 1:
Input: words = ["Hello","Alaska","Dad","Peace"]
Output: ["Alaska","Dad"]
Explanation:
Both "a" and "A" are in the 2nd row of the American keyboard due to case insensitivity.
Example 2:
Input: words = ["omk"]
Output: []
Example 3:
Input: words = ["adsdf","sfd"]
Output: ["adsdf","sfd"]
 */
class Solution {
    void insert(unordered_set<char>&st,string s){
        for(auto i:s){
            st.insert(i);
        }
    }
    bool check(unordered_set<char>&st,string s){
        for(auto i:s){
            if(st.find(tolower(i)) == st.end()){
                return false;
            }
        }
        return true;
    }
public:
    vector<string> findWords(vector<string>& words) {
        string first = "qwertyuiop", second = "asdfghjkl", third = "zxcvbnm";
        unordered_set<char> f, s, t;
        insert(f, first);
        insert(s, second);
        insert(t, third);
        vector<string> ans;
        for(auto it : words){
            char ch = tolower(it[0]);
            if(f.find(ch) != f.end()){
                if(check(f, it)){
                    ans.push_back(it);
                }
            }
            else if(s.find(ch) != s.end()){
                if(check(s, it)){
                    ans.push_back(it);
                }
            }
            else{
                if(check(t, it)){
                    ans.push_back(it);
                }
            }
        }
        return ans;
    }
};

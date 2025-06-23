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
/*Distribute Candies
Alice has n candies, where the ith candy is of type candyType[i]. Alice noticed that she started to gain weight, so she visited a doctor.
The doctor advised Alice to only eat n / 2 of the candies she has (n is always even). Alice likes her candies very much, and she wants to eat the maximum number of different types of candies while still following the doctor's advice.
Given the integer array candyType of length n, return the maximum number of different types of candies she can eat if she only eats n / 2 of them.
Example 1:
Input: candyType = [1,1,2,2,3,3]
Output: 3
Explanation: Alice can only eat 6 / 2 = 3 candies. Since there are only 3 types, she can eat one of each type.
Example 2:
Input: candyType = [1,1,2,3]
Output: 2
Explanation: Alice can only eat 4 / 2 = 2 candies. Whether she eats types [1,2], [1,3], or [2,3], she still can only eat 2 different types.
Example 3:
Input: candyType = [6,6,6,6]
Output: 1
Explanation: Alice can only eat 4 / 2 = 2 candies. Even though she can eat 2 candies, she only has 1 type.*/
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
      unordered_set<int>st(candyType.begin(),candyType.end());
      int count=0;
      int i=0;
      while(count<candyType.size()/2 && i<st.size()){
        count++;
        i++;
       // cout<<count;
      }
      return count;
        
    }
};

/*357. Count Numbers with Unique Digits
Given an integer n, return the count of all numbers with unique digits, x, where 0 <= x < 10n.
Example 1:
Input: n = 2
Output: 91
Explanation: The answer should be the total numbers in the range of 0 ≤ x < 100, excluding 11,22,33,44,55,66,77,88,99
Example 2:
Input: n = 0
Output: 1
 */
class Solution {
    void res(int& limit,int& count,string& s,vector<int>&hash){
        if(!s.empty()) {
            int val = stoi(s);
            if(val >= limit) return;
            count++;
        }
        for(int i=0;i<=9;i++){
            if(i==0 && s.empty()) continue;
            s += to_string(i);
            if(hash[s.back()-'0']!=0){
                s.pop_back();
                continue;
            }
            hash[s.back()-'0']++;
            res(limit,count,s,hash);
            hash[s.back()-'0']--;
            s.pop_back();
        }
    }
public:
    int countNumbersWithUniqueDigits(int n){
        int limit = static_cast<int>(pow(10, n) + 0.5);
        int count = 0;
        string s;
        vector<int> hash(10,0);
        res(limit,count,s,hash);
        return count+1;
    }
};

/*Number of Smooth Descent Periods of a Stock
You are given an integer array prices representing the daily price history of a stock, where prices[i] is the stock price on the ith day.
A smooth descent period of a stock consists of one or more contiguous days such that the price on each day is lower than the price on the preceding day by exactly 1. The first day of the period is exempted from this rule.
Return the number of smooth descent periods.
Example 1:
Input: prices = [3,2,1,4]
Output: 7
Explanation: There are 7 smooth descent periods:
[3], [2], [1], [4], [3,2], [2,1], and [3,2,1]
Note that a period with one day is a smooth descent period by the definition.
Example 2:
Input: prices = [8,6,7,7]
Output: 4
Explanation: There are 4 smooth descent periods: [8], [6], [7], and [7]
Note that [8,6] is not a smooth descent period as 8 - 6 ≠ 1.
Example 3:
Input: prices = [1]
Output: 1
Explanation: There is 1 smooth descent period: [1]*/
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long count=0,res=prices.size();
        int j=0;
        while(j<prices.size()-1){
            if(prices[j]-prices[j+1]==1){
                count++;
                res+=count;
            
            }
            else {
              count=0;
            }
            j++;

        }
        return res;
    }
};
/* Merge Strings Alternately
You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.
Return the merged string.
Example 1:
Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
Example 2:
Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s
Example 3:
Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q 
merged: a p b q c   d
 */
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res="";
        int i=0,j=0;
        while (i < word1.size() || j < word2.size()) {
            if (i < word1.size()) res += word1[i++];
            if (j < word2.size()) res += word2[j++];
        }
        return res;
    }
};

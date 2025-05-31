/* Grumpy Bookstore Owner
There is a bookstore owner that has a store open for n minutes. You are given an integer array customers of length n where customers[i] is the number of the customers that enter the store at the start of the ith minute and all those customers leave after the end of that minute.
During certain minutes, the bookstore owner is grumpy. You are given a binary array grumpy where grumpy[i] is 1 if the bookstore owner is grumpy during the ith minute, and is 0 otherwise.
When the bookstore owner is grumpy, the customers entering during that minute are not satisfied. Otherwise, they are satisfied.
The bookstore owner knows a secret technique to remain not grumpy for minutes consecutive minutes, but this technique can only be used once.
Return the maximum number of customers that can be satisfied throughout the day.
Example 1:
Input: customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], minutes = 3
Output: 16
Explanation:
The bookstore owner keeps themselves not grumpy for the last 3 minutes.
The maximum number of customers that can be satisfied = 1 + 1 + 1 + 1 + 7 + 5 = 16.
Example 2:
Input: customers = [1], grumpy = [0], minutes = 1
Output: 1*/
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int gmax = INT_MIN, maxi = INT_MIN, temp = 0;
        int l = 0, r = 0, start = -1, end = -1;
        
        while (r < grumpy.size()) {
            if (grumpy[r] == 1) temp += customers[r];
            if (r - l + 1 > minutes) {
                if (grumpy[l] == 1) temp -= customers[l];
                l++;
            }
            if (r - l + 1 == minutes) {
                if (gmax <= temp) {
                    start = l;
                    end = r;
                    gmax = temp;
                }
            }
            r++;
        }

        int total = 0;
        for (int i = 0; i < customers.size(); i++) {
            if (grumpy[i] == 0 || (i >= start && i <= end)) {
                total += customers[i];
            }
        }

        return total;
    }
};

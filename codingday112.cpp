/*Convert Date to Binary
You are given a string date representing a Gregorian calendar date in the yyyy-mm-dd format.
date can be written in its binary representation obtained by converting year, month, and day to their binary representations without any leading zeroes and writing them down in year-month-day format.
Return the binary representation of date.
Example 1:
Input: date = "2080-02-29"
Output: "100000100000-10-11101"
Explanation:
100000100000, 10, and 11101 are the binary representations of 2080, 02, and 29 respectively.
Example 2:
Input: date = "1900-01-01"
Output: "11101101100-1-1"
Explanation:
11101101100, 1, and 1 are the binary representations of 1900, 1, and 1 respectively.*/
class Solution {
    int process(string s) {
        int num = 0;
        int i = 0;
        while (i < s.size()) {
            num = num * 10 + (s[i] - '0');
            i++;
        }
        return num;
    }

    string process_two(int num) {
        if (num == 0) return "0";
        string temp = "";
        while (num) {
            temp += to_string(num % 2);
            num /= 2;
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }

public:
    string convertDateToBinary(string date) {
        vector<int> temp;
        vector<string> con;
        string s = "";
        for (int i = 0; i < date.size(); i++) {
            if (date[i] == '-') {
                temp.push_back(process(s));
                s = "";
            } else {
                s += date[i];
            }
        }
        temp.push_back(process(s));
        for (auto i : temp) {
            con.push_back(process_two(i));
        }
        string res = "";
        res += con[0];
        res += '-';
        res += con[1];
        res += '-';
        res += con[2];
        return res;
    }
};

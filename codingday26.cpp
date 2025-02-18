 /*Partition Labels
You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part. For example, the string "ababcc" can be partitioned into ["abab", "cc"], but partitions such as ["aba", "bcc"] or ["ab", "ab", "cc"] are invalid.
Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.
Return a list of integers representing the size of these parts.
Example 1:
Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
Example 2:
Input: s = "eccbbbbdec"
Output: [10]*/
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, vector<int>> mpp;
        for (int i = 0; i < s.size(); i++) {
            mpp[s[i]].push_back(i);
        }
        vector<pair<int, int>> temp;
        for (auto it : mpp) {
            int n = it.second.size() - 1;
            int first = it.second[0];
            int second = it.second[n];
            temp.push_back({first, second});
        }
        sort(temp.begin(), temp.end());
        int i = 1;
        int x = temp[0].first;
        int y = temp[0].second;

        vector<int> ans;
        while (i < temp.size()) {
            if (temp[i].first > y) {
                ans.push_back(y - x + 1);
                x = temp[i].first;
                y = temp[i].second;
            } else {
                y = max(y, temp[i].second);
            }
            i++;
        }
        ans.push_back(y - x + 1);
        return ans;
    }
};

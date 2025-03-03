/*Sort the People
You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.
For each index i, names[i] and heights[i] denote the name and height of the ith person.
Return names sorted in descending order by the people's heights.
Example 1:
Input: names = ["Mary","John","Emma"], heights = [180,165,170]
Output: ["Mary","Emma","John"]
Explanation: Mary is the tallest, followed by Emma and John.
Example 2:
Input: names = ["Alice","Bob","Bob"], heights = [155,185,150]
Output: ["Bob","Alice","Bob"]
Explanation: The first Bob is the tallest, followed by Alice and the second Bob.*/
class Solution {
public:
    struct compare {
        bool operator()(pair<string, int>& a, pair<string, int>& b) {
            return a.second > b.second;
        }
    };

public:
    vector<string> sortPeople(vector<string>& names, vector<int>& height) {
        vector<pair<string, int>> temp;
        for (int i = 0; i < names.size(); i++) {
            temp.push_back({names[i], height[i]});
        }
        sort(temp.begin(), temp.end(), compare());
        vector<string> ans;
        for (auto it : temp) {
            ans.push_back(it.first);
        }
        return ans;
    }
};

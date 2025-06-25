/*Minimum Index Sum of Two Lists
Given two arrays of strings list1 and list2, find the common strings with the least index sum.
A common string is a string that appeared in both list1 and list2.
A common string with the least index sum is a common string such that if it appeared at list1[i] and list2[j] then i + j should be the minimum value among all the other common strings.
Return all the common strings with the least index sum. Return the answer in any order.
Example 1:
Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"]
Output: ["Shogun"]
Explanation: The only common string is "Shogun".
Example 2:
Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["KFC","Shogun","Burger King"]
Output: ["Shogun"]
Explanation: The common string with the least index sum is "Shogun" with index sum = (0 + 1) = 1.
Example 3:
Input: list1 = ["happy","sad","good"], list2 = ["sad","happy","good"]
Output: ["sad","happy"]
Explanation: There are three common strings:
"happy" with index sum = (0 + 1) = 1.
"sad" with index sum = (1 + 0) = 1.
"good" with index sum = (2 + 2) = 4.
The strings with the least index sum are "sad" and "happy".*/
class Solution {
    static bool compare(pair<string, int> a, pair<string, int> b) {
        return a.second < b.second;
    }
    void process(unordered_map<string, vector<int>>& mp, vector<string> list) {
        for (int i = 0; i < list.size(); i++) {
            mp[list[i]].push_back(i);
        }
    }
    int addition(vector<int> ind) {
        int sum = 0;
        if (ind.size() == 1) {
            return -1;
        }
        for (auto i : ind) {
            sum += i;
        }
        return sum;
    }

public:
    vector<string> findRestaurant(vector<string>& list1,
                                  vector<string>& list2) {
        unordered_map<string, vector<int>> mp;
        process(mp, list1);
        process(mp, list2);
        vector<pair<string, int>> temp;
        for (auto i : mp) {
            int sum = addition(i.second);
            temp.push_back({i.first, sum});
        }
        sort(temp.begin(), temp.end(), compare);
        vector<string> ans;
        int i = 0;
        for (i = 0; i < temp.size(); i++) {
            if (temp[i].second != -1) {
                break;
            }
        } 
        if(i>=temp.size()){
            return {};
        }
        ans.push_back(temp[i].first);
        i++;
        while (i < temp.size()) {
            if (temp[i].second == temp[i - 1].second) {
                ans.push_back(temp[i].first);
                i++;
            } else
                break;
        }
        return ans;
    }
};

/*Top K Frequent Words
Given an array of strings words and an integer k, return the k most frequent strings.
Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.
Example 1:
Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:
Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
Output: ["the","is","sunny","day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.
 */
class Solution {
    static bool compare(pair<string,int>a,pair<string,int>b){
       if(a.second==b.second) return a.first<b.first;
         return a.second>b.second ;
    }
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
       unordered_map<string,int>mp;
       for(auto i:words){
        mp[i]++;
       } 
       vector<pair<string,int>>temp;
       for(auto &[f,s]:mp){
    temp.push_back({f,s});
        
       }
       sort(temp.begin(),temp.end(),compare);
       vector<string>ans;
       int i=0;
       while(i<k) {
        ans.push_back(temp[i].first);
        i++;
        }
       return ans;
    }
};

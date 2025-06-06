/*Subdomain Visit Count
A website domain "discuss.leetcode.com" consists of various subdomains. At the top level, we have "com", at the next level, we have "leetcode.com" and at the lowest level, "discuss.leetcode.com". When we visit a domain like "discuss.leetcode.com", we will also visit the parent domains "leetcode.com" and "com" implicitly.
A count-paired domain is a domain that has one of the two formats "rep d1.d2.d3" or "rep d1.d2" where rep is the number of visits to the domain and d1.d2.d3 is the domain itself.
For example, "9001 discuss.leetcode.com" is a count-paired domain that indicates that discuss.leetcode.com was visited 9001 times.
Given an array of count-paired domains cpdomains, return an array of the count-paired domains of each subdomain in the input. You may return the answer in any order.
Example 1:
Input: cpdomains = ["9001 discuss.leetcode.com"]
Output: ["9001 leetcode.com","9001 discuss.leetcode.com","9001 com"]
Explanation: We only have one website domain: "discuss.leetcode.com".
As discussed above, the subdomain "leetcode.com" and "com" will also be visited. So they will all be visited 9001 times.
Example 2:
Input: cpdomains = ["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]
Output: ["901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5 org","1 intel.mail.com","951 com"]
Explanation: We will visit "google.mail.com" 900 times, "yahoo.com" 50 times, "intel.mail.com" once and "wiki.org" 5 times.
For the subdomains, we will visit "mail.com" 900 + 1 = 901 times, "com" 900 + 50 + 1 = 951 times, and "org" 5 times.
 */
class Solution {
    void process(unordered_map<string,int>& hash,string s,int count){
        string temp="";
        for(int i=s.size()-1;i>=0;i--){
             if(s[i]==' '){
                break;
             }
             else if(s[i]=='.'){
                string temp_2=temp;
               reverse(temp_2.begin(),temp_2.end());
                hash[temp_2]+=count;
             }
            
                temp+=s[i];
             
        }
         reverse(temp.begin(),temp.end());
          hash[temp]+=count;
    }
    public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int>hash;
        vector<string>ans;
        vector<int>count;
        int i=0;
        for(auto i:cpdomains){
            string s=i;
            int j=0;
            string t="";
            while(j<i.size()){
            if(s[j]==' '){
                int num=atoi(t.c_str());
                count.push_back(num);
                break;
            }
            t+=s[j];
            j++;
            }
        }
        for(int i=0;i<cpdomains.size();i++){
            process(hash,cpdomains[i],count[i]);
        }
        for(auto i:hash){
            string temp="";
            temp+=to_string(i.second);
            temp+=' ';
            temp+=i.first;
            ans.push_back(temp);
        }
        return ans;
  }
};
/*Minimum Number of Changes to Make Binary String Beautiful
You are given a 0-indexed binary string s having an even length.
A string is beautiful if it's possible to partition it into one or more substrings such that:
Each substring has an even length.
Each substring contains only 1's or only 0's.
You can change any character in s to 0 or 1.
Return the minimum number of changes required to make the string s beautiful.
Example 1:
Input: s = "1001"
Output: 2
Explanation: We change s[1] to 1 and s[3] to 0 to get string "1100".
It can be seen that the string "1100" is beautiful because we can partition it into "11|00".
It can be proven that 2 is the minimum number of changes needed to make the string beautiful.
Example 2:
Input: s = "10"
Output: 1
Explanation: We change s[1] to 1 to get string "11".
It can be seen that the string "11" is beautiful because we can partition it into "11".
It can be proven that 1 is the minimum number of changes needed to make the string beautiful.
Example 3:
Input: s = "0000"
Output: 0
Explanation: We don't need to make any changes as the string "0000" is beautiful already.
 */
class Solution {
public:
    int minChanges(string s) {
        int i=0,j=1;
        int count=0;
        while(j<s.size()){
            if(s[j]!=s[i]){
                count++;
            }
            i+=2;
            j+=2;
        }
        return count;
    }
};

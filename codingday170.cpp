/*93. Restore IP Addresses
A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.
For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.
Example 1:
Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]
Example 2:
Input: s = "0000"
Output: ["0.0.0.0"]
Example 3:
Input: s = "101023"
Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]*/
class Solution {
public:
bool check(string ip) {
    stringstream ss(ip);
    string part;
    int count = 0;
    while (getline(ss, part, '.')) {
        count++;
        if (part.empty()) return false;
        for (char c : part) {
            if (!isdigit(c)) return false;
        }
        if (part.size() > 1 && part[0] == '0') return false;
        if(part.size()>3) return false;
        int num = stoi(part);
        if (num < 0 || num > 255) return false;
    }
    return (count == 4);
}
void res(vector<string>&ans, string &s,string a, string &temp,int count,int j){
  if(j==s.size()){
    return ;
  }
  if( count>=3  ){
    if(check(temp)){
    ans.push_back(temp);
    }
    return ;
  }
  for(int i=1;i<=3;i++){
    a+=s[j];
    a+='.';
    temp=a;
    if(j+1 < s.size()) temp += s.substr(j+1);
    res(ans,s,a,temp,count+1,j+1);
    j++;
    a.pop_back();
  }
}
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
string a,temp;
res(ans,s,a,temp,0,0);
return ans;
    }
};

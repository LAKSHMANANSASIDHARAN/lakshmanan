/*Number of Substrings Containing All Three Characters
Given a string s consisting only of characters a, b and c.
Return the number of substrings containing at least one occurrence of all these characters a, b and c.
Example 1:
Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
Example 2:
Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
Example 3:
Input: s = "abc"
Output: 1*/
#include <iostream>
using namespace std;
bool checking(string s, int i,int j){
    bool a=false, b=false, c=false;
    for(int start=i;start<=j;start++){
        if(s[start]=='a') a=true;
        else if(s[start]=='b') b=true;
        else if(s[start]=='c') c=true;
        if(a && b && c) return true;
    }
    return false;
}

int main() {
    string s="acbbcac";
    int i=0, j=2, count=0, k=1;
    while(j<s.size()){
        bool temp=checking(s,i,j);
        if(temp && (j-i)+1 == 3){
            count += 1 + (s.size() - 1 - j);
            i++; 
            cout << "running 1" << " : " << k << ":" << count << endl;
        }
        else if(temp && j == s.size() - 1){
            count++;
            i++;
            cout << "running 2" << " : " << k << ":" << count << endl;
        }
        else if(temp && j < s.size() - 1){
            count += 1 + (s.size() - 1 - j);
            i++;
            cout << "running 3" << " : " << k << ":" << count << endl;
        }
        else{
            if(j == s.size() - 1) {
            if(temp){count++;} j++;} 
            else{ 
            j++;
            }
            cout << "running 4" << " : " << k << ":" << count << endl;
        }
        k++;
    }
    cout << count;
}

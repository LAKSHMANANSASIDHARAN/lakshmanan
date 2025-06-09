/*Zigzag Conversion
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:
string convert(string s, int numRows);
Example 1:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:
Input: s = "A", numRows = 1
Output: "A"*/
class Solution {
public:
    string convert(string s, int numRows) {
       int i=0;
  int count=1;
  vector<pair<int,char>>temp;
  if(numRows==1) return s;
  while(i<s.size()){
    if(i<s.size()&&count==1){
      while(i<s.size()&&count<=numRows){
        temp.push_back({count,s[i]});
        i++;
        count++;
      }
      count=numRows-1;
    }
    else{
       while(i<s.size()&&count>1){
         temp.push_back({count,s[i]});
        i++;
        count--;
       }
      }
  }

  string res="";
 int c=1;
 while(c<=numRows){
    for(auto i:temp){
        if(i.first==c){
        res+=i.second;
        }
    }
    c++;
 }
  return res;

    }
};

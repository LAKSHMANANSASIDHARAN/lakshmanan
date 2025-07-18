/*Decode XORed Array
There is a hidden integer array arr that consists of n non-negative integers.
It was encoded into another integer array encoded of length n - 1, such that encoded[i] = arr[i] XOR arr[i + 1]. For example, if arr = [1,0,2,1], then encoded = [1,2,3].
You are given the encoded array. You are also given an integer first, that is the first element of arr, i.e. arr[0].
Return the original array arr. It can be proved that the answer exists and is unique.
Example 1:
Input: encoded = [1,2,3], first = 1
Output: [1,0,2,1]
Explanation: If arr = [1,0,2,1], then first = 1 and encoded = [1 XOR 0, 0 XOR 2, 2 XOR 1] = [1,2,3]
Example 2:
Input: encoded = [6,2,7,3], first = 4
Output: [4,2,0,7,4]*/
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int>arr;
        arr.push_back(first);
        for(int i=0;i<encoded.size();i++){
        arr.push_back(encoded[i] ^ arr[i]);
        }
        return arr;
    }
};
/* Find Indices of Stable Mountains
There are n mountains in a row, and each mountain has a height. You are given an integer array height where height[i] represents the height of mountain i, and an integer threshold.
A mountain is called stable if the mountain just before it (if it exists) has a height strictly greater than threshold. Note that mountain 0 is not stable.
Return an array containing the indices of all stable mountains in any order.
Example 1:
Input: height = [1,2,3,4,5], threshold = 2
Output: [3,4]
Explanation:
Mountain 3 is stable because height[2] == 3 is greater than threshold == 2.
Mountain 4 is stable because height[3] == 4 is greater than threshold == 2.
Example 2:
Input: height = [10,1,10,1,10], threshold = 3
Output: [1,3]
Example 3:
Input: height = [10,1,10,1,10], threshold = 10
Output: []*/
class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
        vector<int>ans;
        for(int i=1;i<height.size();i++){
            if(height[i-1]>threshold){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
/*Truncate Sentence
A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each of the words consists of only uppercase and lowercase English letters (no punctuation).
For example, "Hello World", "HELLO", and "hello world hello world" are all sentences.
You are given a sentence s​​​​​​ and an integer k​​​​​​. You want to truncate s​​​​​​ such that it contains only the first k​​​​​​ words. Return s​​​​​​ after truncating it.
Example 1:
Input: s = "Hello how are you Contestant", k = 4
Output: "Hello how are you"
Explanation:
The words in s are ["Hello", "how" "are", "you", "Contestant"].
The first 4 words are ["Hello", "how", "are", "you"].
Hence, you should return "Hello how are you".
Example 2:
Input: s = "What is the solution to this problem", k = 4
Output: "What is the solution"
Explanation:
The words in s are ["What", "is" "the", "solution", "to", "this", "problem"].
The first 4 words are ["What", "is", "the", "solution"].
Hence, you should return "What is the solution".
Example 3:
Input: s = "chopper is not a tanuki", k = 5
Output: "chopper is not a tanuki"*/
class Solution {
public:
    string truncateSentence(string s, int k) {
      vector<string>temp;
      string temp2="";
      int i;
        int count=1;
        for(i=0;i<s.size();i++){
            if(temp.size()==k){
                break;
            }
        if(s[i]==' '){
            temp.push_back(temp2);
            temp2="";
        }
        else{
            temp2+=s[i];
        }
    }
    if(i==s.size()){
  temp.push_back(temp2);
    }
    string ans="";
    for(auto i : temp){
        if(ans.empty()){
            ans+=i;
        }
        else {
            ans+=' ';
            ans+=i;
        }
        
    }
    return ans;
    }
};

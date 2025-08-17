/*670. Maximum Swap
You are given an integer num. You can swap two digits at most once to get the maximum valued number.
Return the maximum valued number you can get.
Example 1:
Input: num = 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
Example 2:
Input: num = 9973
Output: 9973
Explanation: No swap.*/
class Solution {
public:
    int maximumSwap(int num) {
        string n=to_string(num);
        stack<int>st;
        vector<int>ind;
        for(int i=n.size()-1;i>=0;i--){
             while(!st.empty() && n[st.top()]<n[i]){
                st.pop();
             }
             if(st.empty()) {
                ind.push_back(i);
                st.push(i);
             }
             else{
                 ind.push_back(st.top());
                 
             }
            
        }
        reverse(ind.begin(),ind.end());
   
       int i=0;
       while(i<n.size()){
        if(ind[i]!=i && n[ind[i]]!=n[i]) {
            swap(n[i],n[ind[i]]);
            break;
        }
        i++;
       }
       num=stoi(n);
       return num;
    }
};

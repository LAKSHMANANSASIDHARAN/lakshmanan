/*Take Gifts From the Richest Pile
You are given an integer array gifts denoting the number of gifts in various piles. Every second, you do the following:
Choose the pile with the maximum number of gifts.
If there is more than one pile with the maximum number of gifts, choose any.
Reduce the number of gifts in the pile to the floor of the square root of the original number of gifts in the pile.
Return the number of gifts remaining after k seconds.
Example 1:
Input: gifts = [25,64,9,4,100], k = 4
Output: 29
Explanation: 
The gifts are taken in the following way:
- In the first second, the last pile is chosen and 10 gifts are left behind.
- Then the second pile is chosen and 8 gifts are left behind.
- After that the first pile is chosen and 5 gifts are left behind.
- Finally, the last pile is chosen again and 3 gifts are left behind.
The final remaining gifts are [5,8,9,4,3], so the total number of gifts remaining is 29.
Example 2:
Input: gifts = [1,1,1,1], k = 4
Output: 4
Explanation: 
In this case, regardless which pile you choose, you have to leave behind 1 gift in each pile. 
That is, you can't take any pile with you. 
So, the total gifts remaining are 4.*/
class Solution {
public:
   long long pickGifts(vector<int>& gifts, int k) {
   priority_queue<long long> pq(gifts.begin(), gifts.end());
    long long ans=0;
    while(k--){
        long long temp=floor(sqrt(pq.top()));
        pq.push(temp);
        pq.pop();
        }
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
    return ans;
    }
};

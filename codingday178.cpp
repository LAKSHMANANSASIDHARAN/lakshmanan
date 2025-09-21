/*147. Insertion Sort List
Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.
The steps of the insertion sort algorithm:
Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
It repeats until no input elements remain.
The following is a graphical example of the insertion sort algorithm. The partially sorted list (black) initially contains only the first element in the list. One element (red) is removed from the input data and inserted in-place into the sorted list with each iteration.
Example 1:
Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        vector<int>temp;
        ListNode*temphead=head;
        while(temphead){
            temp.push_back(temphead->val);
            temphead=temphead->next;
        }
        sort(temp.begin(),temp.end());
        temphead=head;
        for(auto i:temp) {
            temphead->val=i;
            temphead=temphead->next;
        }
        delete temphead;
        return head;
    }
};
/*164. Maximum Gap
Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.
You must write an algorithm that runs in linear time and uses linear extra space.
Example 1:
Input: nums = [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
Example 2:
Input: nums = [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.*/
class Solution {
public:
    int maximumGap(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int maxi=INT_MIN;
       if(nums.size()<2) return 0;
       for(int i=0;i<nums.size()-1;i++){
        maxi=max(maxi,nums[i+1]-nums[i]);
       } 
       return maxi;
    }
};

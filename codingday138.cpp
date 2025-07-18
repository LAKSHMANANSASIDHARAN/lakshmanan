/*2236. Root Equals Sum of Children
You are given the root of a binary tree that consists of exactly 3 nodes: the root, its left child, and its right child.
Return true if the value of the root is equal to the sum of the values of its two children, or false otherwise.
Example 1:
Input: root = [10,4,6]
Output: true
Explanation: The values of the root, its left child, and its right child are 10, 4, and 6, respectively.
10 is equal to 4 + 6, so we return true.
Example 2:
Input: root = [5,3,1]
Output: false
Explanation: The values of the root, its left child, and its right child are 5, 3, and 1, respectively.
5 is not equal to 3 + 1, so we return false.*/
class Solution {
public:
    bool checkTree(TreeNode* root) {
        if(root->val==root->left->val+root->right->val) return true;
        return false;
    }
};
/*1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree
Given two binary trees original and cloned and given a reference to a node target in the original tree.
The cloned tree is a copy of the original tree.
Return a reference to the same node in the cloned tree.
Note that you are not allowed to change any of the two trees or the target node and the answer must be a reference to a node in the cloned tree.
Example 1:
Input: tree = [7,4,3,null,null,6,19], target = 3
Output: 3
Explanation: In all examples the original and cloned trees are shown. The target node is a green node from the original tree. The answer is the yellow node from the cloned tree.
Example 2:
Input: tree = [7], target =  7
Output: 7
Example 3:
Input: tree = [8,null,6,null,5,null,4,null,3,null,2,null,1], target = 4*/
class Solution {
    TreeNode* ans(TreeNode* cloned, TreeNode* target) {
        if (!cloned) return nullptr;
        if (cloned->val == target->val) return cloned;
        TreeNode* left = ans(cloned->left, target);
        if (left) return left;
        return ans(cloned->right, target);
    }

public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return ans(cloned, target);
    }
};

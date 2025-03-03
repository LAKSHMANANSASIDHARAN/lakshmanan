/*Sort the People
You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.
For each index i, names[i] and heights[i] denote the name and height of the ith person.
Return names sorted in descending order by the people's heights.
Example 1:
Input: names = ["Mary","John","Emma"], heights = [180,165,170]
Output: ["Mary","Emma","John"]
Explanation: Mary is the tallest, followed by Emma and John.
Example 2:
Input: names = ["Alice","Bob","Bob"], heights = [155,185,150]
Output: ["Bob","Alice","Bob"]
Explanation: The first Bob is the tallest, followed by Alice and the second Bob.*/
class Solution {
public:
    struct compare {
        bool operator()(pair<string, int>& a, pair<string, int>& b) {
            return a.second > b.second;
        }
    };

public:
    vector<string> sortPeople(vector<string>& names, vector<int>& height) {
        vector<pair<string, int>> temp;
        for (int i = 0; i < names.size(); i++) {
            temp.push_back({names[i], height[i]});
        }
        sort(temp.begin(), temp.end(), compare());
        vector<string> ans;
        for (auto it : temp) {
            ans.push_back(it.first);
        }
        return ans;
    }
};
/*Create Binary Tree From Descriptions
You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,
If isLefti == 1, then childi is the left child of parenti.
If isLefti == 0, then childi is the right child of parenti.
Construct the binary tree described by descriptions and return its root.
The test cases will be generated such that the binary tree is valid.
Example 1:
Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
Output: [50,20,80,15,17,19]
Explanation: The root node is the node with value 50 since it has no parent.
The resulting binary tree is shown in the diagram.
Example 2:
Input: descriptions = [[1,2,1],[2,3,0],[3,4,1]]
Output: [1,2,null,null,3,4]
Explanation: The root node is the node with value 1 since it has no parent.
The resulting binary tree is shown in the diagram.*/
class Solution {
public:
    TreeNode* constructleft(unordered_map<int, TreeNode*>& mpp, TreeNode* node, TreeNode* left) {
        node->left = left;
        mpp[node->val] = node;
        mpp[left->val] = left;
        return node;
    }

    TreeNode* constructright(unordered_map<int, TreeNode*>& mpp, TreeNode* node, TreeNode* right) {
        node->right = right;
        mpp[node->val] = node;
        mpp[right->val] = right;
        return node;
    }

    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mpp;
        unordered_map<int, int> childMap;

        for (int i = 0; i < descriptions.size(); i++) {
            int parentVal = descriptions[i][0];
            int childVal = descriptions[i][1];
            int isRight = descriptions[i][2];

            TreeNode* parent;
            TreeNode* child;

            if (mpp.find(parentVal) != mpp.end()) {
                parent = mpp[parentVal];
            } else {
                parent = new TreeNode(parentVal);
                mpp[parentVal] = parent;
            }

            if (mpp.find(childVal) != mpp.end()) {
                child = mpp[childVal];
            } else {
                child = new TreeNode(childVal);
                mpp[childVal] = child;
            }

            if (isRight == 1) {
                constructleft(mpp, parent, child);
            } else {
                constructright(mpp, parent, child);
            }

            childMap[childVal] = 1;  
        }

        TreeNode* root = nullptr;
        for (auto it : mpp) {
            if (childMap.find(it.first) == childMap.end()) {
                root = it.second;
                break;
            }
        }

        return root;
    }
};

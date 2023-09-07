// https://leetcode.com/problems/same-tree/submissions/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base case: If both nodes are NULL, they are considered the same.
        if (p == NULL && q == NULL) {
            return true;
        }
        
        // If one of the nodes is NULL or their values are different, they are not the same.
        if (p == NULL || q == NULL || p->val != q->val) {
            return false;
        }
        
        // Recursively check the left and right subtrees.
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

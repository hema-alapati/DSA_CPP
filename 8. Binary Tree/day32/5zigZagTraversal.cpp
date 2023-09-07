// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/submissions/
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;
        if(root==NULL){
            return result;
        }

        queue<TreeNode *>nodesQueue;
        nodesQueue.push(root);
        bool leftToRight=true;

        while(!nodesQueue.empty()){
            int size=nodesQueue.size();
            vector<int>row(size);
            for(int i=0;i<size;i++){
                TreeNode *node=nodesQueue.front();
                nodesQueue.pop();

                //finding position to push
                int index=(leftToRight)?i:size-i-1;
                // int index;
                // if(leftToRight){
                //     index=i;
                // }else index=size-1-i;

                row[index]=node->val;
                if(node->left){
                    nodesQueue.push(node->left);
                }
                if(node->right){
                    nodesQueue.push(node->right);
                }
            }
            //after this level, change position to push variable
            leftToRight=!leftToRight;
            result.push_back(row);
        }
        return result;
    }
};
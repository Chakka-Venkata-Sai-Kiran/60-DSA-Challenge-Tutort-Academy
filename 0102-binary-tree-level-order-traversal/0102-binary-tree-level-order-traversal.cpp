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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        queue<TreeNode*> pq;
        pq.push(root);
        while(!pq.empty()){
            vector<int> temp;
            int n = pq.size();
            for(int i = 0; i < n; i++){
                root = pq.front();
                pq.pop();
                if(root -> left)
                    pq.push(root -> left);
                if(root -> right)
                    pq.push(root -> right);
                temp.push_back(root -> val);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
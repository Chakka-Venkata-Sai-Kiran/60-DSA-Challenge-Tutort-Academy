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
    int myfun(TreeNode *root){
        if(!root)   return 1;
        
        int lt = myfun(root -> left), rt = myfun(root -> right);
        if(lt == 0 || rt == 0 || abs(lt - rt) > 1)
            return 0;
        
        return max(lt, rt) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        return myfun(root) >= 1;
    }
};
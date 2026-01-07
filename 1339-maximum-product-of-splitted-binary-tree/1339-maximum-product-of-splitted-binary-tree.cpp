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

    long long MOD = 1e9 + 7;
    int dfs(TreeNode* root){
        if(!root) return 0;

        root->val += dfs(root->left) + dfs(root->right);
        return root->val;
    }
public:
    int maxProduct(TreeNode* root) {
        long long sum = dfs(root);

        queue<TreeNode*> q;
        q.push(root);

        long long ans = 0;
        while(!q.empty()){
            auto x = q.front();
            q.pop();

            if(!x) continue;
            ans = max(ans, (sum - x->val) * x->val);

            if(x->left)q.push(x->left);
            if(x->right)q.push(x->right);

        }
        return ans % MOD;
    }
};
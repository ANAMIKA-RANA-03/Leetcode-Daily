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
    int maxLevelSum(TreeNode* root) {
        int maxi = root->val;
        int ans = 1;
        queue<TreeNode*> q;
        q.push(root);
        int k = 0;
        while(!q.empty()){
            int n = q.size();
            int sum = 0;
            for(int i = 0 ; i < n; i++){
                auto f = q.front();
                q.pop();
                sum += f->val;
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);

            }
            k++;
            if(maxi < sum){
                maxi = sum;
                ans = k;
            }
            

        }
        return ans;
    }
};
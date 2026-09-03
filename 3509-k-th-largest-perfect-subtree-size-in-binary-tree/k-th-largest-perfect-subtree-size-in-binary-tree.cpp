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

    pair<bool, int> dfs(TreeNode* root, vector<int>& ans) {
        
        if (root == NULL) {
            return {true, 0};
        }

        pair<bool, int> left = dfs(root->left, ans);
        pair<bool, int> right = dfs(root->right, ans);

        if (left.first && right.first && left.second == right.second) {
            
            int size = left.second + right.second + 1;
            
            ans.push_back(size);
            
            return {true, size};
        }

        return {false, 0};
    }

    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        
        vector<int> ans;

        dfs(root, ans);

        sort(ans.begin(), ans.end(),greater<int>());

        if (ans.size() < k)
            return -1;

        return ans[k - 1];
    }
};
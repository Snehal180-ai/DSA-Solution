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
    map<int, int> mp;

    int sum(TreeNode* root) {
        if (root == NULL)
            return 0;

        int leftSum = sum(root->left);
        int rightSum = sum(root->right);

        int sum = root->val + leftSum + rightSum;

        mp[sum]++;

        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        sum(root);

        vector<int> ans;
        int maxCount = 0;

        for (auto p : mp) {
            if (p.second > maxCount) {
                maxCount = p.second;
                ans.clear();
                ans.push_back(p.first);
            }
            else if (p.second == maxCount) {
                ans.push_back(p.first);
            }
        }

        return ans;
    }
};
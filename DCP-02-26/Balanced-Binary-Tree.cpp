1class Solution {
2public:
3    bool balanced = true;
4
5    int dfs(TreeNode* node) {
6        if (node == nullptr)
7            return 0;
8
9        int l = dfs(node->left);
10        int r = dfs(node->right);
11
12        if (abs(l - r) > 1)
13            balanced = false;
14
15        return max(l, r) + 1;
16    }
17
18    bool isBalanced(TreeNode* root) {
19        dfs(root);
20        return balanced;
21    }
22};
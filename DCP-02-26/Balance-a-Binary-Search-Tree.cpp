1class Solution {
2public:
3    TreeNode* balanceBST(TreeNode* root) {
4        // Create a vector to store the inorder traversal of the BST
5        vector<int> inorder;
6        inorderTraversal(root, inorder);
7
8        int size = inorder.size();
9
10        // Construct and return the balanced BST
11        return createBalancedBST(inorder, 0, size - 1);
12    }
13
14private:
15    void inorderTraversal(TreeNode* root, vector<int>& inorder) {
16        // Perform an inorder traversal to store the elements in sorted order
17        if (root == nullptr) return;
18        inorderTraversal(root->left, inorder);
19        inorder.push_back(root->val);
20        inorderTraversal(root->right, inorder);
21    }
22
23    TreeNode* createBalancedBST(const vector<int>& inorder, int start,
24                                int end) {
25        // Base case: if the start index is greater than the end index, return
26        // nullptr
27        if (start > end) return nullptr;
28
29        // Find the middle element of the current range
30        int mid = start + (end - start) / 2;
31
32        // Recursively construct the left and right subtrees
33        TreeNode* leftSubtree = createBalancedBST(inorder, start, mid - 1);
34        TreeNode* rightSubtree = createBalancedBST(inorder, mid + 1, end);
35
36        // Create a new node with the middle element and attach the subtrees
37        return new TreeNode(inorder[mid], leftSubtree, rightSubtree);
38    }
39};
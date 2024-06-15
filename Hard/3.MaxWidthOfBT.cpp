// number of nodes in a level between any 2 nodes = width
//do level order traversal
//Index the tree links, find difference b/w rightmost and leftmost nodes

int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;
    long long ans = 0;
    queue<pair<TreeNode*,long long>> q;
    q.push({root,0});

    while (!q.empty()) {
        int n = q.size();
        long long start = q.front().second;
        long long end = q.back().second;

        for (int i = 0; i < n; i++) { //it runs for a level
            auto p = q.front();
            q.pop();
            // note we are doing -start because we don't need previous value    
            TreeNode* curr = p.first;
            long long index = p.second - start;
            
            // 1 based indexing
            if (curr->left) q.push({curr->left,2 * index + 1});
            if (curr->right) q.push({curr->right,2 * index + 2});
        }
        ans = max(ans, end - start + 1);
    }
    return (int)ans;
}
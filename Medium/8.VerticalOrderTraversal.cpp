// (vertical,level) coordinates of a node

Approach:
- We can perform a level order traversal of the binary tree while keeping track of the horizontal distance (hd) of each node from the root.
- For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively.
- We can use a queue to perform the level order traversal. The queue will store pairs of (hd, node), where hd represents the horizontal distance and node represents the current node being processed.
- During the traversal, we maintain an unordered_map to store the nodes at each horizontal distance. The key in the map is the horizontal distance (hd), and the value is a vector of pairs representing the level and value of the nodes at that horizontal distance.
- After the traversal, we iterate over the keys in the map in ascending order and sort the nodes within each horizontal distance based on their levels. We then extract the values and add them to the result vector.
- Finally, we return the result vector containing the vertical order traversal.


vector<int> verticalTraversal(TreeNode* root) {
    if(!root)
        return {};
    
    unordered_map<int, unordered_map<int, vector<int>>> Nodes;
    queue<pair<TreeNode*, pair<int,int>>> q; // contains: node, {distance, level}
    vector<int> ans;

    q.push({root, {0,0}});

    while (!q.empty()) {
        pair<TreeNode*, pair<int, int>> temp = q.front();
        q.pop();

        TreeNode* front = temp.first;
        int horizontalDistance = temp.second.first;
        int level = temp.second.second;

        Nodes[horizontalDistance][level].push_back(front->val);

        if(front->left)
            q.push({front->left, {horizontalDistance-1, level+1}});
        if(front->right)
            q.push({front->right, {horizontalDistance+1, level+1}});
    }

    for(auto i :Nodes) {
        for(auto j : i.second) {
            for(auto k: j.second) 
                ans.push_back(k);
        }
    }
    
    return ans;
}
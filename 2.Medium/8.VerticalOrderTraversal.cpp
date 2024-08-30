/* (vertical,level) coordinates of a node. O(n) tc and sc

Approach:
- We can perform a level order traversal of the binary tree while keeping track of the horizontal distance (hd) of each node from the root.

- For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively.

- We can use a queue to perform the level order traversal. The queue will store pairs of (hd, node), where hd represents the horizontal distance and node represents the current node being processed.

- During the traversal, we maintain an unordered_map to store the nodes at each horizontal distance. The key in the map is the horizontal distance (hd), and the value is a vector of pairs representing the level and value of the nodes at that horizontal distance.

- After the traversal, we iterate over the keys in the map in ascending order and sort the nodes within each horizontal distance based on their levels. We then extract the values and add them to the result vector.

- Finally, we return the result vector containing the vertical order traversal.

*/

vector<vector<int>> verticalTraversal(TreeNode* root) {
    if (!root) return {};

    
    map<int, vector<pair<int, int>>> mp; //hd, list of (level of node, value of node)

    int mini = 0, maxi = 0;

    queue<pair<int, TreeNode*>> q; //horizontal distance, node
    q.push({0, root});

    int lvl = 0;

    while (!q.empty()) {

        int n = q.size();
        for (int i = 0; i < n; i++) {

            auto p = q.front(); q.pop();
            int hd = p.first; // Vertical Level
            TreeNode* curr = p.second; // The node to process

            if (curr->left) {
                mini = min(mini, hd - 1);
                q.push({hd - 1, curr->left});
            }

            if (curr->right) {
                maxi = max(maxi, hd + 1);
                q.push({hd + 1, curr->right});
            }

            mp[hd].push_back({lvl, curr->val});
        }
        
        lvl++;
    }

    vector<vector<int>> ans;
    for (int i = mini; i <= maxi; i++) {
        sort(mp[i].begin(), mp[i].end());
        vector<int> temp;
        for (auto it : mp[i])
            temp.push_back(it.second);
        ans.push_back(temp);
    }

    return ans;
}


------------------------

vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> nodes; //mS taken as 2 nodes at same level and vertical may have same value. a set wouldve stored only 1 value
    queue<pair<TreeNode*, pair<int,int>>> todo;
    todo.push({root,{0,0}});
    while(!todo.empty()){
        auto p = todo.front();
        todo.pop();
        TreeNode* node = p.first;
        int x = p.second.first;
        int y = p.second.second;
        nodes[x][y].insert(node->val);
        if(node->left){
            todo.push({node->left,{x-1,y+1}});
        }
        if(node->right){
            todo.push({node->right,{x+1,y+1}});
        }
    }

    vector<vector<int>> ans;
    for(auto p : nodes){
        vector<int> col;
        for(auto q : p.second){
            col.insert(col.end(),q.second.begin(),q.second.end());
        }
        ans.push_back(col);
    }

    return ans;

    }
// derive parent pointers: First, traverse the binary tree to build a map of each node to its parent node using BFS. This map will help us later to backtrack from the target node to its ancestors.

// move upward/leftward/rightward by 1 step till dist = k . Next, perform a BFS from the target node to find all nodes at a distance k from it. While doing this, we also mark visited nodes to avoid revisiting the same nodes.

 vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    vector<int> ans;
    map<TreeNode*, TreeNode*> parent;
    
    //mark parents : 1st bfs    
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            auto current = q.front();
            q.pop();

            if (current->left) {
                parent[current->left] = current;
                q.push(current->left);
            }

            if (current->right) {
                parent[current->right] = current;
                q.push(current->right);
            }
        }
    }

    map<TreeNode*, int> visited;
    q.push(target);
    while (k-- && !q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            auto current = q.front();
            q.pop();

            visited[current] = 1;

            //moving leftwards
            if (current->left && !visited[current->left]) {
                q.push(current->left);
            }
            //moving rightwards
            if (current->right && !visited[current->right]) {
                q.push(current->right);
            }
            //moving upwards
            if (parent[current] && !visited[parent[current]]) { //parent of curr node exists and isnt visited
                q.push(parent[current]);
            }
        }
    }

    while (!q.empty()) {
        ans.push_back(q.front()->val);
        q.pop();
    }
    return ans;
}

//Min time taken to burn a BT from a node(can be a leaf too)

//BFS , parent map required, visited map required

/*

in 1 second, all nodes connected to a given node get burned. That is its left child, right child, and parent.
Note: The tree contains unique values.

Example 1:
Input:
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10

Target Node = 8
Output: 7
Explanation: If the leaf with the value 8 is set on fire:
After 1 sec: 5 is set on fire.
After 2 sec: 2, 7 are set to fire.
After 3 sec: 4, 1 are set to fire.
After 4 sec: 3 is set to fire.
After 5 sec: 6 is set to fire.
After 6 sec: 9 is set to fire.
After 7 sec: 10 is set to fire.
It takes 7s to burn the complete tree.
*/

int findMaxDistance(map<TreeNode*,TreeNode*> &mpp,TreeNode* startnode){
    queue<TreeNode*> q;
    q.push(startnode);
    map<TreeNode*,int> vis;  // visited map
    vis[startnode] = 1;
    int maxi = 0;
    while(q.empty()){
        int size = q.size();
        int flag = 0;
        for (int i = 0; i < size; ++i)
        {
            auto node = q.front();
            q.pop();
            if(node->left && !vis[node->left]){ //if node->left exists and it hasnt been visited
                flag = 1; // " This node has been burned"
                vis[node->left]=1;  // node->left has been visited 
                q.push(node->left); // for next iteration
            }
            if(node->right && !vis[node->right]){ 
                flag = 1;
                vis[node->right]=1;   
                q.push(node->right); 
            }
            if(mpp[node] && !vis[node]){ // traversing parent
                flag = 1;
                vis[mpp[node]] = 1;
                q.push(mpp[node]);
            }
        }
        if(flag) maxi++; 
    }
    return maxi;
}

// does parent mapping and returns the node where the target lies(start node's val is passed,not address)
TreeNode* bfsToMapParents(TreeNode* root, map<TreeNode*,TreeNode*>&mpp, int start){
    queue<TreeNode*> q;
    q.push(root);
    while(q.empty()){
        TreeNode* current = q.front();
        q.pop();
        if(current->val == start) res = current;
        if(current->left){
            mpp[current->left] = current; // current is the parent of curr->left
            q.push(current->left);
        }
        if(current->right){
            mpp[current->right] = current;
            q.push(current->right);
        }
    }
    return res; // res is the node corresponding to int val of start
}

int timeToBurnTree(TreeNode* root, int start){
    map<TreeNode*,TreeNode*> mpp;
    TreeNode* startnode = bfsToMapParents(root,mpp,start);
    int maxi = findMaxDistance(mpp, startnode);
    return maxi;
}
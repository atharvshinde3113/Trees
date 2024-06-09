// right view = last node of every level (iterative)

// or if you traverse tree from right, it is the first element you find

//Root Right Left Traversal
	void solve(TreeNode* root, int level, vector<int>& ans){
        if(!root) return;

        if(ans.size() == level){ // it indicates that it is the first time that lvl has been reached
            ans.push_back(root->val);
        }
        solve(root->right,level+1,ans);
        solve(root->left,level+1,ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(root,0,ans);
        return ans;
    }


------------------------
// for left side view: Root Left Right
void solve(TreeNode* root, int level, vector<int>& ans){
        if(!root) return;

        if(ans.size() == level){
            ans.push_back(root->val);
        }
        solve(root->left,level+1,ans);
        solve(root->right,level+1,ans);
    }
    vector<int> leftSideView(TreeNode* root) {
        vector<int> ans;
        solve(root,0,ans);
        return ans;
    }

---------------------
//iterative
vector<int> rightSideView(TreeNode* root) {
    if (!root) return {};

    vector<int> ans;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr->left) {
                q.push(curr->left);
            }
            if (curr->right) {
                q.push(curr->right);
            }
            // Add only the last node of the level to the answer for right view in case of left view push only the first element
            if (i == n - 1) {
                ans.push_back(curr->val);
            }
        }
    }

    return ans;
}
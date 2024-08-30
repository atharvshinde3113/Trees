// 									Representation
int numberOfNodes(int N) {
    if(N <= 1) {
        return 1;
    }
    return pow(2, N - 1);
}

//2^(n-1) nodes exist in a BT at nth level
struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
	Node(int val){
		data = val;
		left = right = null;
	} 
};

int main(){
	Node* root = new Node(5);
	root->left = new Node(6);
	root->right = new Node(7);
	root->left->left = new Node(8);
	/*
				5
			6		7
		8
	*/	

}
--------------------------------------------------
/*				Traversals :: Root = Print data, left/right = make recursive calls 

TC = o(n) we visit each node once
Auxiliary SC = o(n) -> at worse a degenerate tree -> all nodes in a line like LL
					   recursion call stack
*/

//1. Preorder : Root Left Right
void preorder(Node* node){
	if(node = null){
		return;
	}
	print(node->data);
	preorder(node->left);
	preorder(node->right);
}

//2. Inorder: Left Root Right 
void inorder(Node* node){
	if(!node){
		return;
	}
	inorder(node->left);
	print(node->data);
	inorder(node->right);
}

//3. Post Order: Left Right Root
void postorder(Node* node){
	if(!node){
		return;
	}
	postorder(node->left);
	postorder(node->right);
	print(node->data);
}
------------------------------------------------------
//LC Code:
	void preorder(TreeNode* node, vector<int> &ans){
        if(!node){
            return;
        }
        ans.push_back(node->val);
        preorder(node->left,ans);
        preorder(node->right,ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root,ans);
        return ans;
    }
--------------------------------------------------

/*							BFS : Level Order Traversal
left to right level by level
-We start by pushing the root node into the queue.
- Then, while the queue is not empty, we process each level by taking the size of the queue and iterating over the nodes at that level.
- For each node, we add its value to the current level's vector and push its left and right child nodes into the queue if they exist.
- After processing each level, we add the level's vector to the result vector.
*/
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root) {
        return ans;
    }
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        vector<int> level; //Stores the current level.
        int n = q.size(); // the previous level is now processed by the below for loop 


        // this is done as for checking for the next level i.e children of nodes in curr level
        // check for each of them n times (no. of nodes in current level)


        for (int i = 0; i < n; i++) {
            TreeNode* curr = q.front();
            q.pop();
            level.push_back(curr->val);
            //store the current node. its children will be stored in the next.(for that push in queue)

            //out the next level in queue if it exists
            if (curr->left) {
                q.push(curr->left); // store the next level in q. it will be processed in the next while and for loop iteration
            }
            if (curr->right) {
                q.push(curr->right);
            }
        }
        ans.push_back(level);
    }

    return ans;
}

//o(n) visiting each node once.
//o(n) at worst case q will have all ele in it. o(n) of level and ans not considered.
 
--------------------------------------------------
/*
TreeNode:

This is an instance of the TreeNode structure.

When you declare a variable as TreeNode node;, you are creating a single instance of TreeNode on the stack.

You can access its members directly using the dot operator (node.val, node.left, node.right).


TreeNode*:

This is a pointer to a TreeNode instance.

When you declare a variable as TreeNode* nodePtr;, you are creating a pointer that can point to a TreeNode instance, which is typically allocated on the heap using new TreeNode.

You access the members of the TreeNode it points to using the arrow operator (nodePtr->val, nodePtr->left, nodePtr->right).
*/
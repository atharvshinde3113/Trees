/* O(ht of tree) O(1)

Basically, the deletion can be divided into two stages:

1. Search for a node to remove.
2. If the node is found, delete the node.

Approach:
three possible cases:
1. The node to be deleted is a leaf node (no children): remove the node from the tree and return NULL as the new root.

2. The node to be deleted has only one child (left or right child):return the non-NULL child of the node to be deleted as the new root. 

3. The node to be deleted has both left and right children:we find the maximum value node in the left subtree of the node to be deleted (the rightmost node of the left subtree), copy its value to the node to be deleted, and then recursively delete the maximum value node in the left subtree.
*/

TreeNode* deleteNode(TreeNode* root, int key) {
        if( !root ) return NULL;
        if( root->val < key ) root->right = deleteNode(root->right, key);
        else if( root->val > key ) root->left = deleteNode(root->left, key);
        else{
            if( !root->right && !root->left ) return NULL; //node to be deleted is a leaf node
            else if( !root->right ) return root->left; //Node to be deleted has only one child
            else if( !root->left ) return root->right;//Node to be deleted has only one child

            else{//Node to be deleted has both right and left children
                TreeNode* temp = root->right;
                while( temp->left ) temp = temp->left;
                temp->left = root->left;
                return root->right;
            }
        }
        return root;
   
    }
#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};
//search
struct node* search(struct node *root, int key){
    if (root==NULL){
        return NULL;
    }
    if (root->key == key){
        return root;
    }
    else if (root->key < key){
        return search (root->right,key);
    }
    else{
        return search(root->left,key);
    }
    
}
// return the pointer to the minimum value of a tree

struct node * findmin(struct node* root){
    while(root->left){
        root = root->left;
    }
    return root;
}
// Inorder traversal
void traverseInOrder(struct node *root) {
    if (root == NULL) {
        return;
    }
    traverseInOrder(root->left );
    cout <<root->key <<" ";
    traverseInOrder(root->right);

}

// Insert a node
struct node *insertNode(struct node *node, int key) {
    if (node == NULL){
        struct node *node = (struct node*)malloc(sizeof(node)) ;
        node->key = key;
        node->left = NULL; 
        node->right =NULL;
        return node;

    }
    else if (key <= node->key) {
         node -> left = insertNode(node->left , key);
    }
    else {
         node -> right = insertNode(node->right,key);
        
    }
    return node;

}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    if (root == NULL ){return root;}
    else if (key < root->key) { root->left = deleteNode(root->left , key);}
    else if (key > root->key) {root->right = deleteNode(root->right , key);}
    else{
    //case1 leaf node
        if (root->left == NULL && root->right==NULL){
        delete root;
        root=NULL;
        return root;
        

    }
    // case2.1 only right child
    else if (root-> left  == NULL ) {
        struct node * temp = root ;
        root = root->right;
        delete(temp);
        return root;
    }

    //case2.2 only left child
    else if (root->right == NULL) {
        struct node * temp = root ;
        root = root->left;
        delete(temp);
        return root;
    }

    else{
        struct node * temp = findmin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right,temp->key);
    }
    }

 return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  traverseInOrder(root);
  

}

#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int k1, k2;
    Node* left;
    Node* middle;
    Node* right;
    Node(int a, int b) : k1(a), k2(b), left(nullptr), middle(nullptr), right(nullptr) {}
};

bool search(Node* root, int key) {
    if (!root) return false;
    if (key == root->k1 || key == root->k2) return true;
    if (key < root->k1) return search(root->left, key);
    else if (key < root->k2) return search(root->middle, key);
    else return search(root->right, key);
}

Node* insert(Node* root, int key) {
    if (!root)
        return new Node(key, INT_MAX);
    if (root->k2 == INT_MAX) {
        if (key < root->k1) {
            root->k2 = root->k1;
            root->k1 = key;
        } else {
            root->k2 = key;
        }
        return root;
    }
    if (key < root->k1)
        root->left = insert(root->left, key);
    else if (key < root->k2)
        root->middle = insert(root->middle, key);
    else
        root->right = insert(root->right, key);
    return root;
}

void printTree(Node* root, int depth = 0) {
    if (!root) return;
    for (int i = 0; i < depth; ++i) cout << "  ";
    cout << "[" << root->k1;
    if (root->k2 != INT_MAX) cout << "," << root->k2;
    cout << "]\n";
    printTree(root->left, depth+1);
    printTree(root->middle, depth+1);
    printTree(root->right, depth+1);
}

int main() {
    Node* root = nullptr;
    int n;
    cout<<"Enter number of Keys to be inserted in Tree:";
    cin>>n;
    int keys[n];
    cout<<"Enter elements of tree to be inserted:";
    for(int i=0;i<n;i++){cin>>keys[i];}
    for (int k : keys)
        root = insert(root, k);
    cout << "Tree structure:\n";
    printTree(root);

    int searchKey;
    cout<<"Enter key to be searched:";
    cin>>searchKey;
    cout << "Search for " << searchKey << ": ";
    cout << (search(root, searchKey) ? "Found" : "Not found") << endl;
    return 0;
}

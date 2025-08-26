#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

// Definition of a binary tree node
struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int k) : key(k), left(nullptr), right(nullptr) {}
};

// Function to randomly generate a binary tree with 'n' nodes
TreeNode* generateRandomTree(int n) {
    if (n <= 0) return nullptr;

    // Generate a random key for the current node
    int key = rand() % 100 + 1;  // Random key between 1 and 100
    TreeNode* node = new TreeNode(key);

    // Generate random sizes for the left and right subtrees
    int nl = rand() % n;  // Random number of nodes in the left subtree
    int nr = n - 1 - nl;  // Remaining nodes for the right subtree

    // Recursively build the left and right subtrees
    node->left = generateRandomTree(nl);
    node->right = generateRandomTree(nr);

    return node;
}

// Recursive function to calculate the alternating sum of the path from root to leaf
void calculateAlternatingSum(TreeNode* node, int currentSum, bool isPositive) {
    if (!node) return;

    // Add the current node's key to the alternating sum
    currentSum += (isPositive ? node->key : -node->key);

    // If it's a leaf node, print the alternating sum
    if (!node->left && !node->right) {
        cout << "Alternating sum for leaf " << node->key << ": " << currentSum << endl;
    }

    // Recur for left and right children
    calculateAlternatingSum(node->left, currentSum, !isPositive);
    calculateAlternatingSum(node->right, currentSum, !isPositive);
}

int main() {
    // Seed for random number generation
    srand(time(0));

    int n;
    cout << "Enter the number of nodes in the binary tree: ";
    cin >> n;

    // Generate a random binary tree with 'n' nodes
    TreeNode* root = generateRandomTree(n);

    // Calculate and print the alternating sum for all leaf nodes
    calculateAlternatingSum(root, 0, true);

    return 0;
}

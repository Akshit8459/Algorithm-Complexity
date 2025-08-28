#include<iostream>
#include <random>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(){
        data=0;
        left=nullptr;
        right=nullptr;
    }
    Node(int x){
        data=x;
        left=nullptr;
        right=nullptr;
    }
    Node(int x,Node* l){
        data=x;
        left=l;
        right=nullptr;
    }
    Node(int x,Node* l,Node* r){
        data=x;
        left=l;
        right=r;
    }
};

int randInt(int a, int b) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dis(a, b);
    return dis(gen);
}

Node* buildRandomTree(int n){
    if (n == 0) return nullptr;
    int key = randInt(1, 100);
    if (n == 1) return new Node(key);

    int nl = randInt(0, n-1);
    int nr = n - 1 - nl;
    Node* left = buildRandomTree(nl);
    Node* right = buildRandomTree(nr);
    Node* root = new Node(key);
    root->left = left;
    root->right = right;
    return root;
}

void printAltSum(Node* node, int altsum=0,int depth=0){
    if(!node)return;
    int curSum=(depth%2==0)?(altsum+ node->data):(altsum-node->data);
    if(!node->left && !node->right) cout<<"Leaf Node:"<<node->data<<"  Alt Sum :"<<curSum<<endl;
    printAltSum(node->left,curSum,depth+1);
    printAltSum(node->right,curSum,depth+1);
}


void printTreeLevelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int sz = q.size(); // Number of nodes at current level
        for (int i = 0; i < sz; ++i) {
            Node* curr = q.front();
            q.pop();
            cout << curr->data << " ";
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        cout << endl; // Newline after each level
    }
}


int main(){
    int n;
    cout<<"Enter Number of nodes to be created:";
    cin>>n;

    Node* tree=buildRandomTree(n);

    cout<<endl<<"Level Order Traversal of Tree:"<<endl;
    printTreeLevelOrder(tree);

    cout<<endl<<"Alternating Sum for each leaf node :"<<endl;
    printAltSum(tree);
    return 0;
    
}
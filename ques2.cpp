#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void updateWithMaxOfNextK(Node* head, int k) {
    if (!head || k <= 0) return;

    // First, determine the size of the list
    Node* temp = head;
    int size = 1;
    while (temp->next != head) {
        temp = temp->next;
        ++size;
    }

    // Step 1: Collect all nodes in a vector for easy access
    vector<Node*> nodes;
    temp = head;
    for (int i = 0; i < size; ++i) {
        nodes.push_back(temp);
        temp = temp->next;
    }

    // Step 2: For each node, find the max of next k nodes and update
    vector<int> updatedData(size);
    for (int i = 0; i < size; ++i) {
        int maxVal = nodes[(i + 1) % size]->data;
        for (int j = 1; j <= k; ++j) {
            int index = (i + j) % size;
            maxVal = max(maxVal, nodes[index]->data);
        }
        updatedData[i] = maxVal;
    }

    // Step 3: Update the original list
    for (int i = 0; i < size; ++i) {
        nodes[i]->data = updatedData[i];
    }
}


// Create a circular linked list from a vector
Node* createCircularList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    Node* head = new Node(values[0]);
    Node* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new Node(values[i]);
        current = current->next;
    }
    current->next = head; // make it circular
    return head;
}

// Print a circular list (limited to number of nodes to avoid infinite loop)
void printCircularList(Node* head, int count) {
    Node* temp = head;
    for (int i = 0; i < count; ++i) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


int main() {
    int n;
    cout<<"Enter number of elements in linked list:"<<endl;
    cin>>n;
    cout<<"Enter elements:";
    vector<int> values(n,0);
    for(int i=0;i<n;i++){
        cin>>values[i];
    }
    cout<<"Enter value of K:"<<endl;
    int k ;
    cin>>k;

    Node* head = createCircularList(values);

    cout << "Original list:\n";
    printCircularList(head, values.size());

    updateWithMaxOfNextK(head, k);

    cout << "Updated list (each node replaced with max of next " << k << " nodes):\n";
    printCircularList(head, values.size());

    return 0;
}

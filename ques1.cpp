#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int digit;
    Node* next;
    Node(int d) : digit(d), next(nullptr) {}
};


Node* stringToList(const string& number) {
    Node* head = nullptr;
    for (int i = number.size() - 1; i >= 0; --i) {
        if (isdigit(number[i])) {
            Node* newNode = new Node(number[i] - '0');
            newNode->next = head;
            head = newNode;
        }
    }
    return head;
}


Node* addLists(Node* l1, Node* l2) {
    Node* dummy = new Node(0);
    Node* current = dummy;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) {
            sum += l1->digit;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->digit;
            l2 = l2->next;
        }

        carry = sum / 10;
        current->next = new Node(sum % 10);
        current = current->next;
    }

    return dummy->next;
}


Node* multiplyLists(Node* l1, Node* l2) {
    if (!l1 || !l2) return nullptr;

    // To store the result digits as a list of 0s first
    int len1 = 0, len2 = 0;
    for (Node* t = l1; t; t = t->next) len1++;
    for (Node* t = l2; t; t = t->next) len2++;

    vector<int> result(len1 + len2, 0);

    Node* p1 = l1;
    int i = 0;

    while (p1) {
        int carry = 0;
        Node* p2 = l2;
        int j = 0;
        while (p2) {
            int prod = p1->digit * p2->digit + result[i + j] + carry;
            result[i + j] = prod % 10;
            carry = prod / 10;
            p2 = p2->next;
            ++j;
        }
        if (carry > 0) {
            result[i + j] += carry;
        }
        p1 = p1->next;
        ++i;
    }

    // Remove trailing zeros
    while (result.size() > 1 && result.back() == 0) result.pop_back();

    // Convert vector to linked list
    Node* head = nullptr;
    for (int k = result.size() - 1; k >= 0; --k) {
        Node* newNode = new Node(result[k]);
        newNode->next = head;
        head = newNode;
    }

    return head;
}


void printList(Node* head) {
    if (!head) {
        cout << "0";
        return;
    }
    printList(head->next);  // Recursive reverse print
    cout << head->digit;
}


int main() {
    string num1 ;
    string num2 ;
    cout<<"Enter first large number:"<<endl;
    cin>>num1;
    cout<<"Enter second large number"<<endl;
    cin>>num2;

    Node* l1 = stringToList(num1);
    Node* l2 = stringToList(num2);

    cout << "Number 1: ";
    printList(l1);
    cout << "\nNumber 2: ";
    printList(l2);

    Node* sum = addLists(l1, l2);
    cout << "\n\nSum:      ";
    printList(sum);

    Node* product = multiplyLists(l1, l2);
    cout << "\n\nProduct:  ";
    printList(product);

    cout << endl;
    return 0;
}

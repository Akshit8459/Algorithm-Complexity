#include <iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(){data=0;next=nullptr;}
        Node(int x){
            data=x;
            next=nullptr;
        }
        Node(int x,Node* ptr){
            data=x;
            next=ptr;
        }
};

void printList(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

Node* createList(){
    string x;
    cout<<"Enter a large Number:"<<endl;
    cin>>x;
    Node* start=new Node();
    Node* head=start;
    for(int i=x.size()-1;i>=0;i--){
        Node* temp=new Node();
        temp->data=(x[i]-'0');
        head->next=temp;
        head=head->next;
    }

    return start;

}

Node* adder(Node* a,Node* b){
    Node* start=new Node();
    Node* head=start;
    int rem=0;
    bool started=false;
    while(a || b || rem){
        int sum=rem;
        if(a) {sum+=a->data;a=a->next;}
        if(b) {sum+=b->data;b=b->next;}
        if(!started && sum==0) continue;
        if(sum!=0) started=true;
        head->next=new Node(sum%10);
        head=head->next;
        rem=sum/10;
    }

    return start->next;
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
            int prod = p1->data * p2->data + result[i + j] + carry;
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


int main(){
    Node* listA=createList();
    printList(listA);

    Node* listB=createList();
    printList(listB);

    cout<<"Sum of the above two number in the same format:";
    Node* addedList=adder(listA,listB);
    printList(addedList);
    
    cout<<endl<<"Product of the above two number is:";
    Node* prodList=multiplyLists(listA,listB);
    printList(prodList);

    return 0;
}
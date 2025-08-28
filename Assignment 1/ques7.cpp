#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// A struct to hold the value along with the array index and element index
struct Element {
    int value;
    int arrIndex;
    int elemIndex;

    Element(int v, int a, int e) : value(v), arrIndex(a), elemIndex(e) {}
};

// Comparator for the min-heap (priority queue)
struct compare {
    bool operator()(const Element& a, const Element& b) {
        return a.value > b.value; // min heap
    }
};

vector<int> merger(vector<vector<int>>& arrays){
    priority_queue<Element, vector<Element>, compare> minHeap;
    int k=arrays.size();
    for(int i=0;i<k;i++){
        if(!arrays[i].empty()) minHeap.emplace(arrays[i][0],i,0);
    }

    vector<int> merged;
    
    while(!minHeap.empty()){
        Element curr=minHeap.top();
        minHeap.pop();
        merged.push_back(curr.value);

        int nextElement=curr.elemIndex+1;
        if(nextElement<arrays[curr.arrIndex].size()){
            minHeap.emplace(arrays[curr.arrIndex][nextElement],curr.arrIndex,nextElement);
        }
    }
    return merged;
}

int main(){
    int n;
    cout<<"Enter no. of sorted arrays:";
    cin>>n;
    vector<vector<int>> arrays;
    for(int i=0;i<n;i++){
        cout<<"Enter no elements of array "<<i+1<<" :";
        int x;
        cin>>x;
        vector<int> temp;
        for(int i=0;i<x;i++){
            int z;
            cin>>z;
            temp.push_back(z);
        }
        arrays.push_back(temp);
    }


    cout<<"Arrays before merging"<<endl;
    for(auto it:arrays){
        for(auto ele:it){
            cout<<ele<<" ";
        }
        cout<<endl;
    }

    cout<<"Array after merging:"<<endl;
    vector<int> output=merger(arrays);

    for(auto it:output){
        cout<<it<<" ";
    }

    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

void printSubset(vector<int> arr){
    for(auto it:arr){
        cout<<it<<" ";
    }
    cout<<endl;
}

void generateSubsets(int n,int k,int start,vector<int> arr){
    if(k==0){
        printSubset(arr);
        return;
    }
    for(int i=start;i<=n;i++){
        arr.push_back(i);
        generateSubsets(n,k-1,i+1,arr);
        arr.pop_back();
    }

}


int main(){
    int n,k;
    cout<<"Enter n:";
    cin>>n;
    cout<<endl<<"Enter value of k";
    cin>>k;
    cout<<endl;
    vector<int> arr;
    generateSubsets(n,k,1,arr);
    return 0;
}
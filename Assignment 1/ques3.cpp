#include <iostream>
#include<vector>
using namespace std;

void greyCode(int n,string &code,vector<string> &arr){
    if(n==0){
        arr.push_back(code);
        return;
    }
    code.push_back('0');
    greyCode(n-1,code,arr);

    code.pop_back();
    code.push_back('1');
    greyCode(n-1,code,arr);
    code.pop_back();
}

int main(){
    string code;
    int n;
    cout<<"Enter number of bits:";
    cin>>n;
    vector<string> arr;
    greyCode(n,code,arr);
    int size=arr.size();
    for(int i=0;i<size/2;i++){
        cout<<arr[i]<<", ";
    }
    for(int i=size-1;i>=size/2;i--){
        cout<<arr[i]<<", ";
    }

    return 0;
}
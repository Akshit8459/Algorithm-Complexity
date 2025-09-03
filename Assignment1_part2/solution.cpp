#include<iostream>
#include<vector>
#include <climits>
#include <algorithm>
using namespace std;
int findmin(vector<int> persons){
    int n=persons.size();
    int total=0;
    while(n>3){
        int a=persons[0]+2*persons[1]+persons[n-1];
        int b=2*persons[0]+persons[n-2]+persons[n-1];
        total+=min(a,b);
        n-=2;
    }
    if(n==3)total+=persons[0]+persons[1]+persons[2];
    else if(n==2)total+=persons[1];
    else if(n==1) total+=persons[0];
    return total;
}
int main(){
    int n;
    cout<<"Enter no. of persons:";
    cin>>n;
    vector<int> persons(n);
    cout<<"Enter pace of persons:";
    for(int i=0;i<n;i++) cin>>persons[i];
    sort(persons.begin(),persons.end());
    int ans=findmin(persons);
    cout<<"Time Required: "<<ans<<" mins"<<endl;
    return 0;
}
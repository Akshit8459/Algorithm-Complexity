#include<iostream>
#include<vector>
using namespace std;

void printboard(vector<vector<int>> board){
    for(auto it:board){
        for(auto box:it){
            cout<<box<<" ";
        }
        cout<<endl;
    }
}

bool isSafe(vector<vector<int>> &board,int row,int col){
    int n=board.size();
    int i,j;
    for(int i=0;i<8;i++){
        if(board[i][col]==1){
            return false;
        }
    }

    // Check upper diagonal on left side
    for (i = row-1, j = col-1; i >= 0 && 
         j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on left side
    for (i = row-1, j = col+1; j < n && 
         i >= 0; i--, j++){
             if (board[i][j])return false;
         }
    return true;
}

bool placeQueens(vector<vector<int>> &board,int row){
    int n=board.size();
    if(n==row){
        return true;
    }
    for(int i=0;i<n;i++){
        if(isSafe(board,row,i)){
            board[row][i]=1;
            if(placeQueens(board,row+1)){
                return true;
            }
            board[row][i]=0;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> board(8,vector<int>(8,0));
    cout<<"After Placing Queens"<<endl;
    placeQueens(board,0);
    printboard(board);
    return 0;
}
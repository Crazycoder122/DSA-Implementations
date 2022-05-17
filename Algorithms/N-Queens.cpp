#include<bits/stdc++.h>

using namespace std;

unsigned long long int countSol = 0;

void printBoard(vector<vector<int>>a){
    cout<<"\n\n*************************** The Board is: ***************************\n";
    for(int i = 0;i<a.size();i++){
        for(int j = 0;j<a.size();j++)
            cout<<a[i][j];
        cout<<endl;
    }
}


bool isValidPos(vector<vector<int>>board,int row,int col){
    int i,j;
    
    // Left Upper Diagonal
    for(i = row - 1,j = col-1;j>=0 && i>=0;j--,i--){
        if(board[i][j] == 1)
            return false;
    }

    // Right Upper Diagonal
    for(i=row-1,j=col+1;j<board.size() && i >=0;i--,j++){
        if(board[i][j] == 1)
            return false;
    }

    // Straight Up
    for(i = row-1;i>=0;i--){
        if(board[i][col] == 1)
            return false;
    }

    return true;
}

void nQueen(vector<vector<int>>a,int currentRow = 0){
    // If all the Rows have been done and there is a possible solution existing,we just print it and return
    if(currentRow == a.size()){
        countSol++;
        printBoard(a);
        return;
    }


    for(int i=0;i<a.size();i++){

        // If its not a Valid position, then we skip the iteration
        if(!isValidPos(a,currentRow,i)){
            continue;
        }

        // Placing the Queen
        a[currentRow][i] = 1;

        // Searching for Solutions for the previous placement of the Queen
         nQueen(a,currentRow + 1);

        // Backtracking Step
        a[currentRow][i] = 0;
    }
}


int main(){
    int n;
    vector<int>temp;

    cin>>n;

    // Creating a (n x n) matrix filled with zeroes
    vector<vector<int>> board;
    for(int i = 0;i<n;i++){
        temp.clear();
        for(int j = 0;j<n;j++)
        {
            temp.push_back(0);
        }

        board.push_back(temp);
    }


    nQueen(board);
    cout<<"\n\nThere Exists "<<countSol<<" solutions for "<<n<<"-Queens Problem";

    
    return 0;

}
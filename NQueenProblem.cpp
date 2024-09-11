#include<iostream>
#include<vector>
using namespace std; 
void printBoard( const vector<vector<char>> &board){
    int n=board.size(); 
    for (int i=0; i<n;i++){
      for(int j=0; j<n; j++){
       cout<< board[i][j]<<" "; 
      }
      cout<<endl;
  }  
  cout<< "------------------------------------\n";
}
bool isSafe(vector<vector<char>>&board,int row ,int col){
  int n =board.size(); 
  //Horizontal safety 
   for (int j=0;j<n; j++){
     if (board[row][j]=='Q'){
        return false; 
     }
   }
   //vertical safety 
   for (int i=0; i<row;i++){
       if (board[i][col]=='Q'){
        return false; 
       }
   }
//left Diagonal safety 
for (int i=row,j=col;i>=0 && j>=0; i--,j--){
   if(board[i][j]=='Q'){
    return false; 
   }
 }
 // diagonal right safety 
 for (int i=row, j=col; i>=0 && j<n; i--,j++){
    if (board[i][j]=='Q'){
      return false; 
    }
 }
 return true; 
}
int  nQueen(vector<vector<char>> &board,int row){
  // base case : if all queens are placed 
     int n =board.size(); 
     if (row==n){
     printBoard(board); 
     return 1; 
}
// is safe return a boolean value which has been fed here if 
int count =0;
for (int j =0; j<n; j++){
 if (isSafe(board,row,j)){
      board[row][j]='Q'; // try placing queen in each column 
      count+=nQueen(board,row+1);// recurs to do the next work 
      board[row][j]='.'; // back track 
      }
   }
   return count; // no of possible solution at each level ; 
}
int main( ){
vector<vector<char>>board; 
int n=8;
for (int i=0; i<n;i++){
     vector<char>newRow;
      for(int j=0; j<n; j++){
         newRow.push_back('.');
      }
  board.push_back(newRow); 
}
// above logic can be written as too
//vector<vector<char>> board(n, vector<char>(n, '.'));
int count =nQueen(board,0);// started from the first row =0;
cout<<"The no of possible solutions are: "<<count; 
return 0; 
}
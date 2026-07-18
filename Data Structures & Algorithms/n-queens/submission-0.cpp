class Solution {
public:
    bool isSafe(int row,int col,vector<string> &board,int n){
        int dupr = row;
        int dupc = col; 
        while(row>=0 && col >=0){
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        row = dupr;
        col = dupc;
        while(col>=0){
            if(board[row][col] == 'Q') return false;
            col--;
        }
        row = dupr;
        col = dupc;
        while(col>=0 && row<n){
            if(board[row][col] == 'Q') return false;
            col--;
            row++;
        }
        return true;

    }
    void helper(int col,vector<string> &board,vector<vector<string>>& ans,int n){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row = 0 ; row<n ; row++){
            if(isSafe(row,col,board,n)){
                board[row][col] = 'Q';
                helper(col+1,board,ans,n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        helper(0,board,ans,n);
        return ans;
    }
};

class Solution {
   public:
    bool helper(int i, int j, int idx, vector<vector<char>>& board, string word,
                vector<vector<int>>& vis) {
        if (board[i][j] != word[idx]) return false;

        if (idx == word.size() - 1) return true;
        vis[i][j] = 1;
        int dr[] = {-1, 1, 0, 0};  // Up, Down, Left, Right
        int dc[] = {0, 0, -1, 1};
        for (int k = 0; k < 4; k++) {
            int newRow = i + dr[k];
            int newCol = j + dc[k];
            if (newRow >= 0 && newRow < board.size() && newCol >= 0 && newCol < board[0].size() &&
                !vis[newRow][newCol]) {
                if (helper(newRow, newCol, idx + 1, board, word, vis)) return true;
            }
        }

        vis[i][j] = 0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (helper(i, j, 0, board, word, vis)) return true;
                }
            }
        }
        return false;
    }
};

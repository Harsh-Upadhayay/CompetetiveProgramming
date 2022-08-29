class Solution {
    
    void dfs (vector<vector<char>> &board, int i, int j, int border = false) {
        
        int n = board.size(),
            m = board[0].size();
        if(i >= n || i < 0 || j >= m || j < 0 || board[i][j] != 'O')
            return;
        
        board[i][j] = (border ? '.' : 'X');
        dfs(board, i, j + 1, border);
        dfs(board, i, j - 1, border);
        dfs(board, i + 1, j, border);
        dfs(board, i - 1, j, border);
        
    }
    
public:
    void solve(vector<vector<char>>& board) {
         int n = board.size(),
             m = board[0].size();
        
        for(int i = 0; i < n; i++)
            dfs (board, i, 0    , true),
            dfs (board, i, m - 1, true);
        
        for(int j = 0; j < m; j++)
            dfs (board, 0    , j, true),
            dfs (board, n - 1, j, true);
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                dfs(board, i, j);
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(board[i][j] == '.')
                    board[i][j] = 'O';
    }
};
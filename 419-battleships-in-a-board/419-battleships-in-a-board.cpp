class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int count = 0, n = board.size(), m = board[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'X') {
                    count += 1;
                    int _i = i, _j = j;
                    while(_i < n && board[_i][j] == 'X') board[_i][j] = '.', _i++;
                    board[i][j] = 'X';
                    while(_j < m && board[i][_j] == 'X') board[i][_j] = '.', _j++;
                }       
            }
        }
        return count;
    }
};
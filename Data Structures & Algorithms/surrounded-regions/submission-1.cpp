class Solution {
    int row, col;
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};

    int safe(int x, int y){
        return min(x,y) >= 0 and x < row and y < col;
    }

    vector<vector<int>> pos(int x, int y, vector<vector<char>>& board){
        vector<vector<int>> ans;
        for(int i = 0; i < 4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(safe(nx,ny) and board[nx][ny] == 'O') ans.push_back({nx,ny});
        }
        return ans;
    }

    void dfs(int x, int y, vector<vector<char>>& board){
        board[x][y] = 'P';
        vector<vector<int>> safes = pos(x,y, board);
        for(auto v: safes)  dfs(v[0],v[1],board);
    }

public:
    void solve(vector<vector<char>>& board) {
        row = board.size(), col = board[0].size();
        for(int i = 0; i < row; i++){
            if(board[i][0] == 'O')  dfs(i,0,board);
            if(board[i][col-1] == 'O')  dfs(i,col-1,board);
        }

        for(int j = 0; j < col; j++){
            if(board[0][j] == 'O')  dfs(0,j,board);
            if(board[row-1][j] == 'O')  dfs(row-1,j,board);
        }

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == 'O')  board[i][j] = 'X';
                if(board[i][j] == 'P')  board[i][j] = 'O';
            }
        }
    }
};

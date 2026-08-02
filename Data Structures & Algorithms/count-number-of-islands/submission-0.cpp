class Solution {
    int row,col;
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
public:
    int safe(int x, int y){
        return min(x,y) >= 0 and x < row and y < col;
    }

    void dfs(int x, int y, vector<vector<int>>& vis, vector<vector<char>>& grid){
        vis[x][y] = 1;

        for(int i = 0; i < 4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(safe(nx,ny) and !vis[nx][ny] and grid[nx][ny] == '1') dfs(nx,ny,vis,grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        row = grid.size(), col = grid[0].size();

        vector<vector<int>> vis(row, vector<int>(col, 0));

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1' and !vis[i][j]) {
                    dfs(i,j,vis,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};

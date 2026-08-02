class Solution {
    int row,col;
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
public:
    int safe(int x, int y){
        return min(x,y) >= 0 and x < row and y < col;
    }

    int dfs(int x, int y, vector<vector<int>>& vis, vector<vector<int>>& grid){
        vis[x][y] = 1;
        int size = 1;

        for(int i = 0; i < 4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(safe(nx,ny) and !vis[nx][ny] and grid[nx][ny]) size += dfs(nx,ny,vis,grid);
        }

        return size;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        row = grid.size(), col = grid[0].size();

        vector<vector<int>> vis(row, vector<int>(col, 0));

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] and !vis[i][j]) {
                    int res = dfs(i,j,vis,grid);
                    ans = max(ans, res);
                }
            }
        }
        return ans;
    }
};

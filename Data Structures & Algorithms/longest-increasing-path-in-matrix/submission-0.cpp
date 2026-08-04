class Solution {
public:
    int row,col;
    using vi = vector<int>;
    using vvi = vector<vi>;
    vvi dp;

    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};

    int safe(int x, int y){
        return min(x,y) >= 0 and x < row and y < col;
    }

    int dfs(int i, int j, vvi& grid){
        if(dp[i][j])  return dp[i][j];

        int ans = 1;
        for(int k=0;k<4;k++){
            int nx = i+dx[k], ny = j+dy[k];
            if(safe(nx,ny) and grid[nx][ny] > grid[i][j])   ans = max(ans, dfs(nx,ny,grid)+1);
        }
        return dp[i][j] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& grid) {
        row = grid.size(), col = grid[0].size();
        dp = vvi(row, vi(col, 0));

        int ans = 1;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                ans = max(ans, dfs(i,j,grid));
            }
        }
        return ans;
    }
};

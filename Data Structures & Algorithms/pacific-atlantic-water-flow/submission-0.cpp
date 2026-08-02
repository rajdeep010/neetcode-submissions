class Solution {
    using vi = vector<int>;
    int row, col;
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};

    int safe(int x, int y){
        return min(x,y) >= 0 and x < row and y < col;
    }

public:
    void bfs(int x, int y, vector<vi>& grid, vector<vi>& vis){
        queue<vi> q;
        q.push({x,y});

        while(!q.empty()) {
            vi v = q.front();
            q.pop();
            int x = v[0], y = v[1];

            if(vis[x][y])   continue;
            vis[x][y] = 1;

            for(int i = 0; i < 4; i++) {
                int nx = x+dx[i], ny = y+dy[i];
                if(safe(nx,ny) and grid[nx][ny] >= grid[x][y])  
                    q.push({nx,ny});
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        row = grid.size(), col = grid[0].size();
        vi pac, atl;
        vector<vi> paci(row, vi(col,0)), atlan(row, vi(col,0));

        for(int i = 0;i < row; i++){
            bfs(i,0,grid,paci);
            bfs(i,col-1,grid,atlan);
        }

        for(int j = 0; j < col; j++){
            bfs(0,j,grid,paci);
            bfs(row-1,j,grid,atlan);
        }

        vector<vector<int>> ans;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(paci[i][j] and atlan[i][j])  ans.push_back({i,j});
            }
        }
        return ans;
    }
};

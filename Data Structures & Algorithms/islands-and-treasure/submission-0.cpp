class Solution {
    int row,col;
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};

    using pii = pair<int,int>;
    using pip = pair<int,pii>;

public:
    int safe(int x, int y){
        return min(x,y) >= 0 and x < row and y < col;
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        row = grid.size(), col = grid[0].size();

        vector<vector<int>> vis(row, vector<int>(col, 0));

        priority_queue<pip, vector<pip>, greater<>> pq;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 0) pq.push({0,{i,j}});
            }
        }

        while(!pq.empty())
        {
            auto node = pq.top();
            pq.pop();

            int d = node.first;
            int x = node.second.first;
            int y = node.second.second;

            if(vis[x][y])   continue;
            vis[x][y] = 1;

            for(int i = 0; i < 4; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];

                if(safe(nx,ny) and grid[nx][ny] == 2147483647)
                {
                    if(grid[nx][ny] > d+1)
                    {
                        grid[nx][ny] = d+1;
                        pq.push({grid[nx][ny], {nx,ny}});
                    }
                }
            }
        }
    }
};

class Solution {
    using vi = vector<int>;
    int row, col;
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};

    int safe(int x, int y){
        return min(x,y) >= 0 and x < row and y < col;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        row = grid.size(), col = grid[0].size();
        int cnt = 0;
        queue<vi> q;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 2) q.push({i,j,0});
                if(grid[i][j] == 1) cnt++;
            }
        }

        int ans = 0;
        while(!q.empty()){
            vi v = q.front();
            q.pop();

            int x = v[0], y = v[1], time = v[2];
            ans = max(ans,time);

            for(int i = 0; i < 4; i++) {
                int nx = x+dx[i], ny = y+dy[i];
                if(safe(nx,ny) and grid[nx][ny] == 1){
                    grid[nx][ny] = 2;
                    q.push({nx,ny,time+1});
                    cnt--;
                }
            }
        }

        return cnt == 0 ? ans : -1;
    }
};

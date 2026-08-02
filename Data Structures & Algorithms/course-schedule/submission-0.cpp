class Solution {
public:
    void dfs(int node, vector<vector<int>>& g, vector<int>& color, vector<int>& parent, int& is_cycle){
        color[node] = 2;
        for(auto nbr: g[node]){
            if(color[nbr] == 1){
                dfs(nbr,g, color, parent, is_cycle);
            } else if(color[nbr] == 2) {
                is_cycle = 1;
            }
        }
        color[node] = 3;
    }

    bool canFinish(int n, vector<vector<int>>& prereq) {
        vector<vector<int>> g(n+1);
        for(auto a: prereq) g[a[1]].push_back(a[0]);

        int is_cycle = 0;
        vector<int> color(n,1), parent(n,-1);
        for(int i = 0; i < n; i++) {
            if(color[i] == 1){
                dfs(i,g,color,parent,is_cycle);
            }
            if(is_cycle)    return false;
        }

        cout << is_cycle << endl;
        return is_cycle ? false : true;
    }
};

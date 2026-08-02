class Solution {
public:
    using vvi = vector<vector<int>>;
    using vi = vector<int>;

    vvi g;
    vi vis;
    vi parent;

    void dfs(int node, int par){
        vis[node] = 1;
        parent[node] = par;

        for(auto nbr: g[node]){
            if(nbr == parent[node])  continue;
            if(!vis[nbr])   dfs(nbr, node);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        g = vvi(n);
        vis = vi(n,0);
        parent = vi(n,0);
        for(int i = 0; i < n; i++)  parent[i] = i;

        for(auto e: edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                ans++;
                dfs(i,-1);
            }
        }
        return ans;
    }
};

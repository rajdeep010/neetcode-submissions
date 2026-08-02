class Solution {
public:
    using vi = vector<int>;
    using vvi = vector<vi>;

    vvi g;
    vi color;
    vi ans;
    int is_cycle = 0;

    void dfs(int node){
        color[node] = 2;

        for(auto nbr: g[node]){
            if(color[nbr] == 2){
                is_cycle = 1;
            } else if(color[nbr] == 1){
                dfs(nbr);
            }
        }

        color[node] = 3;
        ans.push_back(node);
    }

    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        g = vvi(n);
        for(auto v: pre)    g[v[1]].push_back(v[0]);

        color = vi(n,1);

        for(int i = 0; i < n; i++){
            if(color[i] == 1){
                dfs(i);
                if(is_cycle == 1)   break;
            }
        }

        if(is_cycle)    return {};
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

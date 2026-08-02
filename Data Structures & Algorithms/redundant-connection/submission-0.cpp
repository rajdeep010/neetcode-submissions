class Solution {
    using vi = vector<int>;
    using vvi = vector<vi>;

    class DSU{
        int n;
        vi size;
        vi parent;
        int num;

        public:
        DSU(int n){
            this->n = n;
            this->size = vi(n,1);
            this->num = n;
            this->parent = vi(n);
            for(int i = 0; i < n; i++)  this->parent[i] = i;
        }

        vector<int> merge(int u, int v){
            int pu = find(u);
            int pv = find(v);

            if(pu == pv)    return {u,v};

            if(size[pu] > size[pv]) {
                size[pu] += size[pv];
                parent[pu] = pv;
            } else {
                size[pv] += size[pu];
                parent[pv] = pu;
            }
            num--;

            return {-1,-1};
        }

        int numComp(){
            return num;
        }

        int find(int node){
            if(node == parent[node])    return node;
            return parent[node] = find(parent[node]);
        }
    };
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        // apti, math, gk, cs fundamentals
        DSU dsu(n+2);
        for(auto e: edges){
            int u = e[0], v = e[1];
            vector<int> ans = dsu.merge(u,v);
            if(ans[0] != -1 and ans[1] != -1)  return e;
        }

        return edges.back();
    }
};







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

        void merge(int u, int v){
            int pu = find(u);
            int pv = find(v);

            if(pu == pv)    return;

            if(size[pu] > size[pv]) {
                size[pu] += size[pv];
                parent[pu] = pv;
            } else {
                size[pv] += size[pu];
                parent[pv] = pu;
            }
            num--;
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
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for(auto e: edges)  dsu.merge(e[0], e[1]);
        return dsu.numComp();
    }
};

class Solution {
public:
    int f(vector<int>& v, int l, int r, vector<vector<int>>& dp){
        if(l>r)  return 0;
        if(dp[l][r] != -1)  return dp[l][r];

        int ans = 0;
        for(int j = l; j <= r; j++){
            int left = f(v,l,j-1,dp);
            int right = f(v,j+1,r,dp);
            int res = left + right + (v[l-1]*v[r+1]*v[j]);
            ans = max(ans,res);
        }
        return dp[l][r] = ans;
    }

    int maxCoins(vector<int>& nums) {
        vector<int> v = {1};
        for(auto a: nums)  v.push_back(a);
        v.push_back(1);

        int nn = v.size();
        vector<vector<int>> dp(nn+1, vector<int>(nn+1,0));

        for(int i = nn-2; i >= 1; i--){
            for(int j = i; j <= nn-2; j++){
                int res = -1e9;
                for(int k=i; k<=j; k++)
                {
                    int left = dp[i][k-1];
                    int right = dp[k+1][j];
                    int now = max(res, left+right+v[i-1]*v[j+1]*v[k]);
                    res = max(now,res);
                }
                dp[i][j] = res;
            }
        }

        return dp[1][nn-2];
    }
};

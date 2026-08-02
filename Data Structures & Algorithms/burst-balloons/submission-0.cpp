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
        int n = nums.size();
        for(int i = 0; i < n; i++)  v.push_back(nums[i]);
        v.push_back(1);

        int nn = nums.size();
        vector<vector<int>> dp(nn+1, vector<int>(nn+1,-1));

        int ans = f(v,1,v.size()-2,dp);
        return ans;
    }
};

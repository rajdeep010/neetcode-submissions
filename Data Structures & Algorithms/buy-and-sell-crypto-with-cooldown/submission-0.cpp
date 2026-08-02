class Solution {
public:
    int f(vector<int>& prices, int i, int buy, vector<vector<int>>& dp){
        int n = prices.size();
        if(i >= n)  return 0;
        if(dp[i][buy] != -1)    return dp[i][buy];

        int ans = 0;
        // i can buy
        if(buy){
            int skip = f(prices,i+1,1,dp);
            int doit = -prices[i]+f(prices,i+1,0,dp);
            ans = max(skip,doit);
        } else {
            int skip = f(prices,i+1,0,dp);
            int doit = prices[i]+f(prices,i+2,1,dp);
            ans = max(skip,doit);
        }

        return dp[i][buy] = ans;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+3, vector<int>(2,0));
        // // dp[i][0] = max if sell

        for(int i = n-1; i >=0; i--){
            dp[i][0] = max(dp[i+1][0], prices[i]+dp[i+2][1]);
            dp[i][1] = max(dp[i+1][1], -prices[i]+dp[i+1][0]);
        }

        return dp[0][1];

        // return f(prices, 0,1,dp);
    }
};

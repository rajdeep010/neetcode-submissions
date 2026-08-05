class Solution {
public:
    int f(vector<int>& nums, int i, int sum, int n, vector<vector<int>>& dp){
        if(sum == 0)    return true;
        if(i >= n and sum)  return false;

        if(dp[i][sum] != -1)    return dp[i][sum];

        int take = 0, notake = 0;
        if(sum >= nums[i])  take = f(nums, i+1, sum-nums[i], n, dp);
        notake = f(nums, i+1, sum, n, dp);

        return dp[i][sum] = take or notake;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto a: nums)   sum += a;
        if(sum&1)   return false;

        vector<vector<int>> dp(n, vector<int>(sum/2+1, -1));
        return f(nums, 0, sum/2, n, dp);
    }
};

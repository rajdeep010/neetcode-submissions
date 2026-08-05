class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            int curr = 0;
            for(int j = i-1; j >= 0; j--){
                if(nums[j] < nums[i] and dp[j] > curr)  curr = dp[j];
            }
            dp[i] = curr+1;
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};

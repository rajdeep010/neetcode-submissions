class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n,0));

        int len = 0, start = 0;
        for(int gap = 0; gap < n; gap++){
            for(int i = 0, j=gap; j < n; i++,j++){
                if(gap == 0)    dp[i][j] = 1;
                else if(gap == 1)    dp[i][j] = (s[i] == s[j]);

                // if extremes are same and i+1....j-1 is palindrome
                else if(s[i] == s[j] and dp[i+1][j-1])   dp[i][j] = 1;

                if(dp[i][j]){
                    len = gap+1;
                    start = i;
                }
            }   
        }

        return s.substr(start,len);
    }
};

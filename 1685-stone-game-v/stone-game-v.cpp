class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int len = 2; len <= n; len++) {

            for (int l = 0; l + len - 1 < n; l++) {

                int r = l + len - 1;

                for (int i = l; i < r; i++) {

                    int left = prefix[i + 1] - prefix[l];
                    int right = prefix[r + 1] - prefix[i + 1];

                    if (left < right) {
                        dp[l][r] = max(
                            dp[l][r],
                            left + dp[l][i]
                        );
                    }
                    else if (right < left) {
                        dp[l][r] = max(
                            dp[l][r],
                            right + dp[i + 1][r]
                        );
                    }
                    else {
                        dp[l][r] = max(
                            dp[l][r],
                            left + dp[l][i]
                        );

                        dp[l][r] = max(
                            dp[l][r],
                            right + dp[i + 1][r]
                        );
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};
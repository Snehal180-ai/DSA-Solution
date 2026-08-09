class Solution {
public:
    int solve(int i, int M, vector<int>& piles,
              vector<vector<int>>& dp,
              vector<int>& suffix) {

        int n = piles.size();

        if (i >= n)
            return 0;

        if (dp[i][M] != -1)
            return dp[i][M];

        int ans = 0;

        for (int X = 1; X <= 2 * M && i + X <= n; X++) {

            int newM = max(M, X);

            int current = suffix[i] -
                          solve(i + X, newM, piles, dp, suffix);

            ans = max(ans, current);
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        vector<int> suffix(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(0, 1, piles, dp, suffix);
    }
};
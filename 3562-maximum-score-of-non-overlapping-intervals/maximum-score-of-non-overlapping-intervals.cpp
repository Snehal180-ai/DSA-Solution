class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<long long, 4>> a(n);

        for (int i = 0; i < n; i++) {
            a[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }

        sort(a.begin(), a.end(), [](auto &x, auto &y) {
            if (x[1] != y[1])
                return x[1] < y[1];
            return x[0] < y[0];
        });

        vector<long long> ends(n);

        for (int i = 0; i < n; i++)
            ends[i] = a[i][1];

        vector<vector<long long>> dp(5, vector<long long>(n + 1, 0));
        vector<vector<vector<int>>> path(5, vector<vector<int>>(n + 1));

        for (int k = 1; k <= 4; k++) {
            for (int i = 1; i <= n; i++) {
                dp[k][i] = dp[k][i - 1];
                path[k][i] = path[k][i - 1];

                long long left = a[i - 1][0];
                long long weight = a[i - 1][2];
                int index = a[i - 1][3];

                int p = lower_bound(ends.begin(), ends.end(), left) - ends.begin();

                long long takeScore = weight + dp[k - 1][p];

                vector<int> takePath = path[k - 1][p];
                takePath.push_back(index);
                sort(takePath.begin(), takePath.end());

                if (takeScore > dp[k][i] ||
                    (takeScore == dp[k][i] && takePath < path[k][i])) {
                    dp[k][i] = takeScore;
                    path[k][i] = takePath;
                }
            }
        }

        vector<int> ans;

        for (int k = 0; k <= 4; k++) {
            if (dp[k][n] > dp[ans.size()][n] ||
                (dp[k][n] == dp[ans.size()][n] && path[k][n] < ans)) {
                ans = path[k][n];
            }
        }

        return ans;
    }
};
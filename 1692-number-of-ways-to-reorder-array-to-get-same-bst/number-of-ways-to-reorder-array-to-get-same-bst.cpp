
class Solution {
    using ll = long long;
    const ll MOD = 1e9 + 7;
    vector<vector<ll>> comb;

    ll solve(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2)
            return 1;

        vector<int> left, right;
        int root = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] < root)
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        ll leftWays = solve(left);
        ll rightWays = solve(right);

        ll ways = comb[n - 1][left.size()];
        ways = ways * leftWays % MOD;
        ways = ways * rightWays % MOD;

        return ways;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        comb.assign(n + 1, vector<ll>(n + 1, 0));

        for (int i = 0; i <= n; i++) {
            comb[i][0] = comb[i][i] = 1;

            for (int j = 1; j < i; j++) {
                comb[i][j] =
                    (comb[i - 1][j - 1] +
                     comb[i - 1][j]) % MOD;
            }
        }

        return (solve(nums) - 1 + MOD) % MOD;
    }
};

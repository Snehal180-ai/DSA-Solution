class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());

        vector<int> primes;
        vector<bool> isPrime(maxVal + 1, true);

        for (int i = 2; i <= maxVal; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
                for (int j = i + i; j <= maxVal; j += i)
                    isPrime[j] = false;
            }
        }

        int p = primes.size();

        vector<vector<int>> exp(n, vector<int>(p, 0));

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            for (int j = 0; j < p; j++) {
                while (x % primes[j] == 0) {
                    exp[i][j]++;
                    x /= primes[j];
                }
            }
        }

        int ans = 1;

        for (int l = 0; l < n; l++) {
            vector<int> sum(p, 0);
            vector<int> mn(p, INT_MAX);
            vector<int> mx(p, 0);

            for (int r = l; r < n; r++) {
                for (int j = 0; j < p; j++) {
                    sum[j] += exp[r][j];
                    mn[j] = min(mn[j], exp[r][j]);
                    mx[j] = max(mx[j], exp[r][j]);
                }

                bool ok = true;

                for (int j = 0; j < p; j++) {
                    if (sum[j] != mn[j] + mx[j]) {
                        ok = false;
                        break;
                    }
                }

                if (ok)
                    ans = max(ans, r - l + 1);
            }
        }

        return ans;
    }
};
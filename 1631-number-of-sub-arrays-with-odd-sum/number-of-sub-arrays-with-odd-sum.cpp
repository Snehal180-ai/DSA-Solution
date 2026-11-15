class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const long long MOD = 1000000007;
        long long even = 1, odd = 0;
        long long ans = 0;
        int parity = 0;

        for (int x : arr) {
            parity ^= (x & 1);

            if (parity == 0) {
                ans = (ans + odd) % MOD;
                even++;
            } else {
                ans = (ans + even) % MOD;
                odd++;
            }
        }

        return ans;
    }
};
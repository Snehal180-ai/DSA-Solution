class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            char expected;

            if (i % 2 == 0)
                expected = '0';
            else
                expected = '1';

            if (s[i] != expected)
                count++;
        }

        return min(count, n - count);
    }
};
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        string ans = "";

        for (int i = 0; i < n; i++) {
            int ones = 0;

            for (int j = i; j < n; j++) {
                if (s[j] == '1')
                    ones++;

                if (ones == k) {
                    string temp = s.substr(i, j - i + 1);

                    if (ans == "" ||
                        temp.length() < ans.length() ||
                        (temp.length() == ans.length() && temp < ans)) {
                        ans = temp;
                    }

                    break;
                }

                if (ones > k)
                    break;
            }
        }

        return ans;
    }
};
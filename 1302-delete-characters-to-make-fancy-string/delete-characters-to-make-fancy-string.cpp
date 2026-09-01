class Solution {
public:
    string makeFancyString(string s) {
        stack<char> st;

        for (char c : s) {
            if (st.size() >= 2) {
                char first = st.top();
                st.pop();

                char second = st.top();
                st.push(first);

                if (first == c && second == c) {
                    continue;
                }
            }

            st.push(c);
        }

        string ans;

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
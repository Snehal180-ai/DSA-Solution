class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);

        for (char ch : s) {

            if (ch == '(') {
                st.push(0);
            }
            else {
                int curr = st.top();
                st.pop();

                int score = (curr == 0) ? 1 : 2 * curr;

                st.top() += score;
            }
        }

        return st.top();
    }
};
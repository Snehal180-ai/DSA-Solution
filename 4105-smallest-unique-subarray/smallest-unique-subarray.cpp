class Solution {
public:
    struct State {
        int len, link;
        int next[26];

        State() {
            len = 0;
            link = -1;
            memset(next, -1, sizeof(next));
        }
    };

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<int> values = nums;
        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            a[i] = lower_bound(values.begin(), values.end(), nums[i]) - values.begin();

        struct Node {
            int len = 0, link = -1;
            unordered_map<int, int> next;
        };

        vector<Node> st(2 * n);
        int sz = 1, last = 0;

        for (int c : a) {
            int cur = sz++;
            st[cur].len = st[last].len + 1;

            int p = last;

            while (p != -1 && !st[p].next.count(c)) {
                st[p].next[c] = cur;
                p = st[p].link;
            }

            if (p == -1) {
                st[cur].link = 0;
            } else {
                int q = st[p].next[c];

                if (st[p].len + 1 == st[q].len) {
                    st[cur].link = q;
                } else {
                    int clone = sz++;
                    st[clone] = st[q];
                    st[clone].len = st[p].len + 1;

                    while (p != -1 && st[p].next[c] == q) {
                        st[p].next[c] = clone;
                        p = st[p].link;
                    }

                    st[q].link = st[cur].link = clone;
                }
            }

            last = cur;
        }

        vector<int> cnt(sz, 0);

        last = 0;

        for (int c : a) {
            last = st[last].next[c];
            cnt[last]++;
        }

        vector<int> order(sz);
        iota(order.begin(), order.end(), 0);

        sort(order.begin(), order.end(),
             [&](int x, int y) {
                 return st[x].len > st[y].len;
             });

        for (int v : order) {
            if (st[v].link != -1)
                cnt[st[v].link] += cnt[v];
        }

        int ans = n;

        for (int v = 1; v < sz; v++) {
            if (cnt[v] == 1) {
                ans = min(ans, st[st[v].link].len + 1);
            }
        }

        return ans;
    }
};
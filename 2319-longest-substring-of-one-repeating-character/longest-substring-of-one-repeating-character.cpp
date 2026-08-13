class Solution {
public:

    struct Node {
        char leftChar, rightChar;
        int leftLen, rightLen;
        int best;
        int len;

        Node() {
            leftChar = rightChar = ' ';
            leftLen = rightLen = best = len = 0;
        }
    };

    vector<Node> tree;

    Node merge(Node a, Node b) {

        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;

        res.len = a.len + b.len;

        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        res.leftLen = a.leftLen;
        res.rightLen = b.rightLen;

        res.best = max(a.best, b.best);

        if (a.rightChar == b.leftChar) {

            res.best = max(res.best, a.rightLen + b.leftLen);

            if (a.leftLen == a.len) {
                res.leftLen = a.len + b.leftLen;
            }

            if (b.rightLen == b.len) {
                res.rightLen = b.len + a.rightLen;
            }
        }

        return res;
    }

    void build(string &s, int node, int l, int r) {

        if (l == r) {
            tree[node].leftChar = s[l];
            tree[node].rightChar = s[l];

            tree[node].leftLen = 1;
            tree[node].rightLen = 1;
            tree[node].best = 1;
            tree[node].len = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(s, node * 2, l, mid);
        build(s, node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int index, char c) {

        if (l == r) {
            tree[node].leftChar = c;
            tree[node].rightChar = c;

            tree[node].leftLen = 1;
            tree[node].rightLen = 1;
            tree[node].best = 1;
            tree[node].len = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (index <= mid)
            update(node * 2, l, mid, index, c);
        else
            update(node * 2 + 1, mid + 1, r, index, c);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        int n = s.size();

        tree.resize(4 * n);

        build(s, 1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {

            update(
                1,
                0,
                n - 1,
                queryIndices[i],
                queryCharacters[i]
            );

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};
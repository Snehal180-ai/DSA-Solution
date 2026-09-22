class Solution {
public:
    struct Node {
        int prod;
        array<int, 5> cnt{};

        Node() {
            prod = 1;
        }
    };

    int k;

    Node mergeNode(const Node &a, const Node &b) {
        Node res;

        res.prod = (a.prod * b.prod) % k;

        for (int r = 0; r < k; r++) {
            res.cnt[r] += a.cnt[r];
        }

        for (int r = 0; r < k; r++) {
            int newR = (a.prod * r) % k;
            res.cnt[newR] += b.cnt[r];
        }

        return res;
    }

    Node makeNode(int value) {
        Node res;

        int r = value % k;
        res.prod = r;
        res.cnt[r] = 1;

        return res;
    }

    vector<int> resultArray(
        vector<int>& nums,
        int k,
        vector<vector<int>>& queries
    ) {
        this->k = k;

        int n = nums.size();

        int size = 1;
        while (size < n)
            size <<= 1;

        vector<Node> tree(2 * size);

        for (int i = 0; i < n; i++) {
            tree[size + i] = makeNode(nums[i]);
        }

        for (int i = size - 1; i >= 1; i--) {
            tree[i] = mergeNode(tree[i << 1],
                                tree[i << 1 | 1]);
        }

        auto update = [&](int pos, int value) {
            int p = size + pos;

            tree[p] = makeNode(value);

            p >>= 1;

            while (p >= 1) {
                tree[p] = mergeNode(tree[p << 1],
                                    tree[p << 1 | 1]);
                p >>= 1;
            }
        };

        auto query = [&](int l) {
            int left = size + l;
            int right = size + n;

            Node leftRes;
            Node rightRes;

            while (left < right) {
                if (left & 1) {
                    leftRes = mergeNode(leftRes, tree[left]);
                    left++;
                }

                if (right & 1) {
                    --right;
                    rightRes = mergeNode(tree[right], rightRes);
                }

                left >>= 1;
                right >>= 1;
            }

            return mergeNode(leftRes, rightRes);
        };

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            nums[index] = value;
            update(index, value);

            Node res = query(start);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};
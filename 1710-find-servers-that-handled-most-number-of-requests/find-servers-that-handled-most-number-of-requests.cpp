class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival,
                               vector<int>& load) {

        set<int> freeServers;

        for (int i = 0; i < k; i++) {
            freeServers.insert(i);
        }

        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> busyServers;

        vector<int> requests(k, 0);

        for (int i = 0; i < arrival.size(); i++) {

            long long time = arrival[i];

            while (!busyServers.empty() &&
                   busyServers.top().first <= time) {

                int server = busyServers.top().second;

                busyServers.pop();

                freeServers.insert(server);
            }

            if (freeServers.empty()) {
                continue;
            }

            int preferred = i % k;

            auto it = freeServers.lower_bound(preferred);

            if (it == freeServers.end()) {
                it = freeServers.begin();
            }

            int server = *it;

            freeServers.erase(it);

            requests[server]++;

            busyServers.push({
                time + load[i],
                server
            });
        }

        int maxRequests = *max_element(
            requests.begin(),
            requests.end()
        );

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            if (requests[i] == maxRequests) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
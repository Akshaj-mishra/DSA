class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                     vector<vector<int>>& queries) {
        vector<pair<int,int>> arr;
        arr.reserve(n);

        for (int i = 0; i < n; i++)
            arr.push_back({nums[i], i});

        sort(arr.begin(), arr.end());

        vector<int> pos(n);
        vector<int> val(n);

        for (int i = 0; i < n; i++) {
            val[i] = arr[i].first;
            pos[arr[i].second] = i;
        }

        // Connected components
        vector<int> comp(n);
        int cid = 0;
        comp[0] = 0;
        for (int i = 1; i < n; i++) {
            if (val[i] - val[i - 1] > maxDiff)
                cid++;
            comp[i] = cid;
        }

        // farthest reachable to the right in one jump
        vector<int> right(n);
        int r = 0;
        for (int i = 0; i < n; i++) {
            while (r + 1 < n && val[r + 1] - val[i] <= maxDiff)
                r++;
            right[i] = r;
        }

        // leftmost reachable in one jump
        vector<int> left(n);
        int l = 0;
        for (int i = 0; i < n; i++) {
            while (val[i] - val[l] > maxDiff)
                l++;
            left[i] = l;
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> upR(LOG, vector<int>(n));
        vector<vector<int>> upL(LOG, vector<int>(n));

        upR[0] = right;
        upL[0] = left;

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                upR[k][i] = upR[k - 1][upR[k - 1][i]];
                upL[k][i] = upL[k - 1][upL[k - 1][i]];
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int a = pos[q[0]];
            int b = pos[q[1]];

            if (a == b) {
                ans.push_back(0);
                continue;
            }

            if (comp[a] != comp[b]) {
                ans.push_back(-1);
                continue;
            }

            int steps = 0;

            if (a < b) {
                int cur = a;
                for (int k = LOG - 1; k >= 0; k--) {
                    if (upR[k][cur] < b) {
                        cur = upR[k][cur];
                        steps += (1 << k);
                    }
                }
                ans.push_back(steps + 1);
            } else {
                int cur = a;
                for (int k = LOG - 1; k >= 0; k--) {
                    if (upL[k][cur] > b) {
                        cur = upL[k][cur];
                        steps += (1 << k);
                    }
                }
                ans.push_back(steps + 1);
            }
        }

        return ans;
    }
};
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Structure to track top 3 maximums in RMQ queries
struct Top3Max {
    int sz = 0;
    pair<int, int> p[3];
};

// Structure to track top 3 minimums in RMQ queries
struct Top3Min {
    int sz = 0;
    pair<int, int> p[3];
};

Top3Max mergeMax(const Top3Max& a, const Top3Max& b) {
    pair<int, int> tmp[6];
    int n = 0;
    for (int i = 0; i < a.sz; ++i) tmp[n++] = a.p[i];
    for (int i = 0; i < b.sz; ++i) tmp[n++] = b.p[i];
    sort(tmp, tmp + n, [](const pair<int, int>& x, const pair<int, int>& y) {
        if (x.first != y.first) return x.first > y.first;
        return x.second < y.second;
    });
    Top3Max res;
    for (int i = 0; i < n; ++i) {
        bool dup = false;
        for (int j = 0; j < res.sz; ++j) {
            if (res.p[j].second == tmp[i].second) {
                dup = true; break;
            }
        }
        if (!dup) {
            res.p[res.sz++] = tmp[i];
            if (res.sz == 3) break;
        }
    }
    return res;
}

Top3Min mergeMin(const Top3Min& a, const Top3Min& b) {
    pair<int, int> tmp[6];
    int n = 0;
    for (int i = 0; i < a.sz; ++i) tmp[n++] = a.p[i];
    for (int i = 0; i < b.sz; ++i) tmp[n++] = b.p[i];
    sort(tmp, tmp + n, [](const pair<int, int>& x, const pair<int, int>& y) {
        if (x.first != y.first) return x.first < y.first;
        return x.second < y.second;
    });
    Top3Min res;
    for (int i = 0; i < n; ++i) {
        bool dup = false;
        for (int j = 0; j < res.sz; ++j) {
            if (res.p[j].second == tmp[i].second) {
                dup = true; break;
            }
        }
        if (!dup) {
            res.p[res.sz++] = tmp[i];
            if (res.sz == 3) break;
        }
    }
    return res;
}

inline int log2_floor(int x) {
    return x == 0 ? 0 : 31 - __builtin_clz(x);
}

class Solution {
    struct Block { int start, end; };
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int base_1s = 0;
        for (char c : s) if (c == '1') base_1s++;

        // Identify all contiguous blocks of '0's
        vector<Block> blocks;
        int idx = 0;
        while (idx < n) {
            if (s[idx] == '0') {
                int st = idx;
                while (idx < n && s[idx] == '0') idx++;
                blocks.push_back({st, idx - 1});
            } else {
                idx++;
            }
        }

        int K = blocks.size();
        if (K < 2) {
            return vector<int>(queries.size(), base_1s);
        }

        // L[i]: length of i-th '0'-block
        vector<int> L(K);
        for (int i = 0; i < K; ++i) L[i] = blocks[i].end - blocks[i].start + 1;

        // W[i]: length of '1'-block between '0'-blocks i and i+1
        // S[i]: sum of adjacent '0'-block lengths L[i] + L[i+1]
        vector<int> W(K - 1), S(K - 1);
        for (int i = 0; i < K - 1; ++i) {
            W[i] = blocks[i + 1].start - blocks[i].end - 1;
            S[i] = L[i] + L[i + 1];
        }

        int logK = log2_floor(K) + 1;
        vector<vector<Top3Max>> st_L(logK, vector<Top3Max>(K));
        vector<vector<Top3Min>> st_W(logK, vector<Top3Min>(K - 1));
        vector<vector<int>> st_S(logK, vector<int>(K - 1));

        // Build Sparse Table for Top 3 Maximums of L
        for (int i = 0; i < K; ++i) {
            st_L[0][i].sz = 1;
            st_L[0][i].p[0] = {L[i], i};
        }
        for (int j = 1; j < logK; ++j) {
            for (int i = 0; i + (1 << j) <= K; ++i) {
                st_L[j][i] = mergeMax(st_L[j - 1][i], st_L[j - 1][i + (1 << (j - 1))]);
            }
        }

        // Build Sparse Tables for W and S
        for (int i = 0; i < K - 1; ++i) {
            st_W[0][i].sz = 1;
            st_W[0][i].p[0] = {W[i], i};
            st_S[0][i] = S[i];
        }
        for (int j = 1; j < logK; ++j) {
            for (int i = 0; i + (1 << j) <= K - 1; ++i) {
                st_W[j][i] = mergeMin(st_W[j - 1][i], st_W[j - 1][i + (1 << (j - 1))]);
                st_S[j][i] = max(st_S[j - 1][i], st_S[j - 1][i + (1 << (j - 1))]);
            }
        }

        auto query_L = [&](int l, int r) -> Top3Max {
            if (l > r) return Top3Max();
            int j = log2_floor(r - l + 1);
            return mergeMax(st_L[j][l], st_L[j][r - (1 << j) + 1]);
        };

        auto query_W = [&](int l, int r) -> Top3Min {
            if (l > r) return Top3Min();
            int j = log2_floor(r - l + 1);
            return mergeMin(st_W[j][l], st_W[j][r - (1 << j) + 1]);
        };

        auto query_S = [&](int l, int r) -> int {
            if (l > r) return 0;
            int j = log2_floor(r - l + 1);
            return max(st_S[j][l], st_S[j][r - (1 << j) + 1]);
        };

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int ql = q[0], qr = q[1];

            // Binary search to find the first '0'-block intersecting [ql, qr]
            auto it_u = lower_bound(blocks.begin(), blocks.end(), ql, [](const Block& b, int val) {
                return b.end < val;
            });
            if (it_u == blocks.end() || it_u->start > qr) {
                ans.push_back(base_1s);
                continue;
            }
            int u = distance(blocks.begin(), it_u);

            // Binary search to find the last '0'-block intersecting [ql, qr]
            auto it_v = upper_bound(blocks.begin(), blocks.end(), qr, [](int val, const Block& b) {
                return val < b.start;
            });
            int v = distance(blocks.begin(), it_v) - 1;

            if (u >= v) {
                ans.push_back(base_1s);
                continue;
            }

            // Truncate edge block lengths to query boundaries
            auto get_L = [&](int idx) {
                if (idx == u) return min(blocks[u].end, qr) - max(blocks[u].start, ql) + 1;
                if (idx == v) return min(blocks[v].end, qr) - max(blocks[v].start, ql) + 1;
                return L[idx];
            };

            Top3Max top3_L = query_L(u + 1, v - 1);
            Top3Max edges;
            edges.sz = 2;
            edges.p[0] = {get_L(u), u};
            edges.p[1] = {get_L(v), v};
            top3_L = mergeMax(top3_L, edges);

            Top3Min top3_W_res = query_W(u, v - 1);
            vector<int> cand_i = {u, v - 1};
            for (int i = 0; i < top3_W_res.sz; ++i) {
                cand_i.push_back(top3_W_res.p[i].second);
            }

            int max_gain = 0;
            for (int i : cand_i) {
                // Option A: Convert merged 0-blocks directly back to 1s
                max_gain = max(max_gain, get_L(i) + get_L(i + 1));
                
                // Option B: Swap with a completely different maximum 0-block
                int best_L = 0;
                for (int k = 0; k < top3_L.sz; ++k) {
                    int j = top3_L.p[k].second;
                    if (j != i && j != i + 1) {
                        best_L = top3_L.p[k].first;
                        break;
                    }
                }
                max_gain = max(max_gain, best_L - W[i]);
            }

            if (u + 1 <= v - 2) {
                max_gain = max(max_gain, query_S(u + 1, v - 2));
            }

            ans.push_back(base_1s + max_gain);
        }

        return ans;
    }
};
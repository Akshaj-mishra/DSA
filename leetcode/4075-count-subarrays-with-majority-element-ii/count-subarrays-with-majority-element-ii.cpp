class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        
        // Transform array: +1 for target, -1 for others
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = (nums[i] == target) ? 1 : -1;
        }
        
        // Build prefix sums
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + arr[i];
        }
        
        // Coordinate compression for Fenwick tree
        vector<int> vals = prefix;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        
        // Map value to index (1-based for BIT)
        unordered_map<int, int> comp;
        for (int i = 0; i < vals.size(); i++) {
            comp[vals[i]] = i + 1;
        }
        
        // Fenwick tree (Binary Indexed Tree)
        int size = vals.size() + 2;
        vector<int> bit(size, 0);
        
        auto update = [&](int idx, int delta) {
            while (idx < size) {
                bit[idx] += delta;
                idx += idx & -idx;
            }
        };
        
        auto query = [&](int idx) {
            int res = 0;
            while (idx > 0) {
                res += bit[idx];
                idx -= idx & -idx;
            }
            return res;
        };
        
        long long result = 0;
        
        // Process prefix sums from left to right
        // For each prefix[i], count previous prefixes < prefix[i]
        for (int i = 0; i <= n; i++) {
            int idx = comp[prefix[i]];
            // Count previous prefixes that are strictly less than current
            result += query(idx - 1);
            // Add current prefix to BIT
            update(idx, 1);
        }
        
        return result;
    }
};
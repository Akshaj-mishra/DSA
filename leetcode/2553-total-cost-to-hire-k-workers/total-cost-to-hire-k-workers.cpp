class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();

        priority_queue<int, vector<int>, greater<int>> leftHeap;
        priority_queue<int, vector<int>, greater<int>> rightHeap;

        int i = 0;
        int j = n - 1;

        for (; i < candidates && i <= j; i++) {
            leftHeap.push(costs[i]);
        }

        for (; j >= n - candidates && j >= i; j--) {
            rightHeap.push(costs[j]);
        }

        long long ans = 0;

        while (k--) {
            int leftMin = leftHeap.empty() ? INT_MAX : leftHeap.top();
            int rightMin = rightHeap.empty() ? INT_MAX : rightHeap.top();

            if (leftMin <= rightMin) {
                ans += leftMin;
                leftHeap.pop();

                if (i <= j) {
                    leftHeap.push(costs[i++]);
                }
            } else {
                ans += rightMin;
                rightHeap.pop();

                if (i <= j) {
                    rightHeap.push(costs[j--]);
                }
            }
        }

        return ans;
    }
};
1class Solution {
2public:
3    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
4        int n = prices.size();
5        vector<long long> profitSum(n + 1);
6        vector<long long> priceSum(n + 1);
7        for (int i = 0; i < n; i++) {
8            profitSum[i + 1] = profitSum[i] + prices[i] * strategy[i];
9            priceSum[i + 1] = priceSum[i] + prices[i];
10        }
11        long long res = profitSum[n];
12        for (int i = k - 1; i < n; i++) {
13            long long leftProfit = profitSum[i - k + 1];
14            long long rightProfit = profitSum[n] - profitSum[i + 1];
15            long long changeProfit = priceSum[i + 1] - priceSum[i - k / 2 + 1];
16            res = max(res, leftProfit + changeProfit + rightProfit);
17        }
18        return res;
19    }
20};
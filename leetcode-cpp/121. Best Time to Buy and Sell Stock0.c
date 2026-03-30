int maxProfit(int* prices, int pricesSize) {
    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < pricesSize; i++) {
        // 如果当前价格更低，更新最低买入价
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } else {
            // 否则尝试卖出
            int profit = prices[i] - minPrice;
            if (profit > maxProfit) {
                maxProfit = profit;
            }
        }
    }

    return maxProfit;
}
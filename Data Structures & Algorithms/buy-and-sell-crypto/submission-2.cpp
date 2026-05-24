class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int min_price = 1e9; // Track the lowest buying price seen so far
        int max_profit = 0;  // Track the highest profit possible

        for (int price : prices) {
            // Update the minimum price if a cheaper buying day is found
            if (price < min_price) {
                min_price = price;
            }
            // Calculate potential profit if sold today and update max_profit
            else if (price - min_price > max_profit) {
                max_profit = price - min_price;
            }
        }

        return max_profit;
    }
};

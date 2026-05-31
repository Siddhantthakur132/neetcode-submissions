class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int min_len = INT_MAX;
        int current_sum = 0;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            // Expand the window by adding the current element
            current_sum += nums[right];

            // Contract the window from the left as long as the condition is met
            while (current_sum >= target) {
                min_len = std::min(min_len, right - left + 1);
                current_sum -= nums[left];
                left++;
            }
        }

        // If min_len was never updated, no valid subarray exists
        return (min_len == INT_MAX) ? 0 : min_len;
    }
};
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      unordered_map<int, int> visited;
        
        for (int i = 0; i < nums.size(); ++i) {
            // Check if the number already exists in our map
            if (visited.count(nums[i])) {
                // Check if the distance between current index and previous index is <= k
                if (i - visited[nums[i]] <= k) {
                    return true;
                }
            }
            // Update the map with the latest index of the number
            visited[nums[i]] = i;
        }
        
        return false;
    }
};
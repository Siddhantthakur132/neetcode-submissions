class Solution {
public:
    int characterReplacement(string s, int k) {
         std::vector<int> count(26, 0);
        int max_count = 0;
        int max_len = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); ++right) {
            count[s[right] - 'A']++;
            max_count = std::max(max_count, count[s[right] - 'A']);
            
            // Current window size is (right - left + 1)
            // Characters to replace = window size - max_count
            if ((right - left + 1) - max_count > k) {
                count[s[left] - 'A']--;
                left++;
            }
            
            max_len = std::max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};

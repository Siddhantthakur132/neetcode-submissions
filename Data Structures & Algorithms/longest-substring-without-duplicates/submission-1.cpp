class Solution {
public:
    int lengthOfLongestSubstring(string s) {
          // Array to store the last seen index of each ASCII character
        std::vector<int> lastPos(128, -1);
        
        int maxLength = 0;
        int left = 0; // Left boundary of the sliding window
        
        for (int right = 0; right < s.length(); ++right) {
            char currentChar = s[right];
            
            // If the character was seen inside the current window, move left boundary
            if (lastPos[currentChar] >= left) {
                left = lastPos[currentChar] + 1;
            }
            
            // Update the last seen position of the character
            lastPos[currentChar] = right;
            
            // Calculate the current window size and update max length
            maxLength = std::max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};

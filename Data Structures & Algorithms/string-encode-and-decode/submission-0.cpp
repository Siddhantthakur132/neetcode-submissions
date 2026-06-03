class Solution {
public:
    // Encodes a list of strings to a single string.
    std::string encode(const std::vector<std::string>& strs) {
        std::string encoded = "";
        for (const std::string& s : strs) {
            // Format: [length] + [#] + [string]
            encoded += std::to_string(s.length()) + "#" + s;
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    std::vector<std::string> decode(const std::string& s) {
        std::vector<std::string> decoded;
        size_t i = 0;
        
        while (i < s.length()) {
            // Find the delimiter after the length prefix
            size_t j = s.find('#', i);
            
            // Extract the length of the upcoming string
            int length = std::stoi(s.substr(i, j - i));
            
            // Extract the actual string based on the decoded length
            std::string str = s.substr(j + 1, length);
            decoded.push_back(str);
            
            // Move the pointer past the current string chunk
            i = j + 1 + length;
        }
        
        return decoded;
    }
};

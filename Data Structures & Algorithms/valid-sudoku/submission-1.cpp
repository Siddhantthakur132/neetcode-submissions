class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<std::string> seen;
        
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char current_val = board[i][j];
                
                // Skip empty cells
                if (current_val != '.') {
                    // Formulate unique string keys for tracking
                    std::string row_key = std::string(1, current_val) + " in row " + std::to_string(i);
                    std::string col_key = std::string(1, current_val) + " in col " + std::to_string(j);
                    std::string box_key = std::string(1, current_val) + " in box " + std::to_string(i / 3) + "-" + std::to_string(j / 3);
                    
                    // If any key already exists, the board is invalid
                    if (seen.count(row_key) || seen.count(col_key) || seen.count(box_key)) {
                        return false;
                    }
                    
                    // Insert the keys into the set
                    seen.insert(row_key);
                    seen.insert(col_key);
                    seen.insert(box_key);
                }
            }
        }
        
        return true;
    }
};

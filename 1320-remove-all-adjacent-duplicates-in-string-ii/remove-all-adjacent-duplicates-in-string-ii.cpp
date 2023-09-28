class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> stack; // Using a stack to keep track of characters and their counts
        
        for (char c : s) {
            if (!stack.empty() && stack.back().first == c) {
                stack.back().second++; // Increment the count if the current character is the same as the previous one
                if (stack.back().second == k) {
                    stack.pop_back(); // If count reaches k, remove the character from the stack
                }
            } else {
                stack.push_back({c, 1}); // Push the character with a count of 1 onto the stack
            }
        }
        
        string result = "";
        for (const auto& p : stack) {
            result += string(p.second, p.first); // Reconstruct the string from the stack
        }
        
        return result;
    }
};
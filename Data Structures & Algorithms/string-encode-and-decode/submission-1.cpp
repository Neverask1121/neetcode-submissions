#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded = "";
        for (const string& s : strs) {
            // Append length, a delimiter '#', then the string itself
            encoded += to_string(s.size()) + '#' + s;
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        while (i < s.size()) {
            // Find the position of the delimiter '#'
            int j = i;
            while (j < s.size() && s[j] != '#') j++;
            // Extract the length (substring from i to j)
            int len = stoi(s.substr(i, j - i));
            // Extract the string of that length (starting right after '#')
            string str = s.substr(j + 1, len);
            decoded.push_back(str);
            // Move to the start of the next chunk
            i = j + 1 + len;
        }
        return decoded;
    }
};
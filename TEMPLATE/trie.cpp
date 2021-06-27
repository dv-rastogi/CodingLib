struct TRIE {
  
    struct NODE {
        int leaf;
        map<char, int> next;
        NODE() {
            leaf = 0;
        }
    };
    
    vector<NODE> nodes;
    
    void clear() {
        nodes.clear();
        nodes.resize(1);
    }
    
    TRIE() {
        clear();
    }
    
    void addString(const string &s) {
        int u = 0;
        for (char ch: s) {
            if (nodes[u].next.find(ch) == nodes[u].next.end()) {
                nodes[u].next[ch] = nodes.size();
                nodes.push_back(NODE{});
            }
            u = nodes[u].next[ch];
        }
        nodes[u].leaf ++;
    }
    
};

TRIE trie;

// https://leetcode.com/problems/number-of-matching-subsequences/
class Solution {
public:
    
    int dfs(int u, int idx, const string &s) {
        int here = 0;
        for (auto [ch, v]: trie.nodes[u].next) {
            int newIdx = idx;
            while (newIdx < (int) s.size() && s[newIdx] != ch) {
                newIdx ++;
            }
            if (newIdx != (int) s.size()) {
                here += trie.nodes[v].leaf + dfs(v, newIdx + 1, s);
            }
        }
        return here;
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = words.size();
        trie.clear();
        for (int i = 0; i < n; ++ i) {
            trie.addString(words[i]);
        }
        return dfs(0, 0, s);
    }
};

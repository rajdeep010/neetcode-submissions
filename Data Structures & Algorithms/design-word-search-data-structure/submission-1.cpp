class TrieNode{
    public:
    int prefix;
    int wordend;
    map<char,TrieNode*> children;

    TrieNode(){
        prefix = wordend = 0;
    }
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(auto ch: word){
            curr->prefix++;
            if(curr->children.find(ch) == curr->children.end()) curr->children[ch] = new TrieNode();
            curr = curr->children[ch];
        }
        curr->wordend++;
    }

    bool dfs(string& word, TrieNode* node, int i){
        if(i >= word.size())    return node->wordend > 0;
        
        bool ans = false;
        for(auto it: node->children){
            if(word[i] == '.' or (it.first == word[i])) 
                ans = ans || dfs(word, it.second, i+1);
        }

        return ans;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        return dfs(word, curr, 0);
    }
};

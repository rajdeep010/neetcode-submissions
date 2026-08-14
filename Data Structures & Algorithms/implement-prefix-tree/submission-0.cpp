class TrieNode{
    public:
    int prefix;
    int wordend;
    map<char,TrieNode*> children;

    TrieNode(){
        prefix = wordend = 0;
    }
};

class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(auto ch: word){
            curr->prefix++;
            if(curr->children.find(ch) == curr->children.end()) curr->children[ch] = new TrieNode();
            curr = curr->children[ch];
        }
        curr->wordend++;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(auto ch: word){
            if(curr->children.find(ch) == curr->children.end()) return false;
            curr = curr->children[ch];
        }
        return curr->wordend > 0;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(auto ch: prefix){
            if(curr->children.find(ch) == curr->children.end()) return false;
            curr = curr->children[ch];
        }
        return true;
    }
};

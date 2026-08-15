class TrieNode{
    public:
    int prefix;
    int wordend;
    string word;
    map<char,TrieNode*> children;

    TrieNode() {
        prefix = wordend = 0;
    }
};

class Trie{
    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode();
    }

    void add(string& s){
        TrieNode* curr = root;
        for(auto ch: s){
            curr->prefix++;
            if(curr->children.find(ch) == curr->children.end()){
                curr->children[ch] = new TrieNode();
            }
            curr = curr->children[ch];
        }
        curr->wordend++;
        curr->word = s;
    }
};


class Solution {
    int row,col;
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
public:
    int safe(int x, int y){
        return min(x,y) >= 0 and x < row and y < col;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* root, vector<string>& v){
        char curr = board[i][j];
        if(curr == '#') return;

        if(root->children.find(curr) == root->children.end())   return;

        TrieNode* next = root->children[curr];
        if(next->wordend > 0){
            v.push_back(next->word);
            next->word = "";
            next->wordend = 0;
        }

        board[i][j] = '#';
        for(int k = 0; k < 4; k++){
            int nx = i+dx[k], ny = j+dy[k];
            if(safe(nx,ny) and board[nx][ny] != '#')    dfs(board, nx, ny, next, v);
        }
        board[i][j] = curr;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        row = board.size(), col = board[0].size();

        Trie* t = new Trie();
        for(auto s: words)  t->add(s);

        vector<string> ans;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                dfs(board, i, j, t->root, ans);
            }
        }
        return ans;
    }
};

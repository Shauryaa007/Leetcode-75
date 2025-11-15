class Node {
    public:
        vector<Node *>link;
        bool isEnd;

        Node() {
        link = vector<Node*>(26, nullptr);
        isEnd = false;
        }

        bool isHaving(char ch)
        {
            return link[ch-'a']!=NULL;
        }

        Node* nextLink(char ch)
        {
            return link[ch - 'a'];
        }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        int n = word.size();
        Node* node = root;
        for (int i = 0; i < n; i++) {
            if (! node->isHaving(word[i])) {
                node->link[word[i] - 'a'] = new Node();
            }
            node = node->nextLink(word[i]);
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        int n = word.size();
        Node* node = root;
        for (int i = 0; i < n; i++) {
            if (! node->isHaving(word[i])) return false;
           node = node->nextLink(word[i]);
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        int n = prefix.size();
        Node* node = root;
        for (int i = 0; i < n; i++) {
            if (! node->isHaving(prefix[i])) return false;
           node = node->nextLink(prefix[i]);
        }
        return true;
    }
};
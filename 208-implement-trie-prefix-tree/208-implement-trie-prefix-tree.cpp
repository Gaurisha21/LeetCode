class Node{
        Node *links[26];
        bool flag=false;
        
        public:
        bool containKey(char ch){
            return (links[ch-'a']!=NULL);
        }
        
        void put(char ch, Node *node){
            links[ch-'a']=node;
        }
        
        Node *get(char ch){
            return links[ch-'a'];
        }
        
        void setFlag(){
            flag=true;
        }
        
        bool isEnd(){
            return flag;
        }
        
};
class Trie {
private:
    Node *root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node *node = root;
        for(int i=0; i<word.size(); i++)
        {
            if(!node->containKey(word[i]))
                node->put(word[i], new Node());
            node = node->get(word[i]);
        }
        node->setFlag();
    }
    
    bool search(string word) {
        Node *node=root;
        for(int i=0; i<word.size(); i++)
        {
            if(node->containKey(word[i]))
                node=node->get(word[i]);
            else 
                return false;
        }
        return node->isEnd();
    }
    
    bool startsWith(string word) {
        Node *node=root;
        for(int i=0; i<word.size(); i++)
        {
            if(node->containKey(word[i]))
                node=node->get(word[i]);
            else 
                return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
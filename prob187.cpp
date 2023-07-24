struct Node{
    Node*links[2];
    bool containsKey(int bit){
        return links[bit]!=NULL;
    }
    Node*getBit(int bit){
        return links[bit];
    }
    void put(int bit,Node*node){
        links[bit]=node;
    }
};
class Trie{
private:
    Node*root;
public:
    Trie(){
        root=new Node();
    }
    void insert(int num){
        Node*node=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(!node->containsKey(bit)){
                node->put(bit,new Node());
            }
            node=node->getBit(bit);
        }
    }
    int getmax(int num){
        Node*node=root;
        int maxi=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(node->containsKey(1-bit)){
                maxi=maxi | (1<<i);
                node=node->getBit(1-bit);
            }else node=node->getBit(bit);
        }
        return maxi;
    }
};
int maximumXor(vector<int> A)
{
    Trie T;
    for(auto it:A)  T.insert(it);
    int maxi=0;
    for(auto it:A){
        maxi=max(maxi,T.getmax(it));
    }
    return maxi;
}
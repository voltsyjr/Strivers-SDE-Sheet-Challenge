#include <bits/stdc++.h> 
struct Node{
    Node* links[26];

    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    Node* getNextNode(char ch){
        return links[ch-'a'];
    }
};

int distinctSubstring(string &word) {
    int cnt=0;
    Node*root=new  Node();
    for(int i=0;i<word.size();i++){
        Node*node=root;
        for(int j=i;j<word.size();j++){
            if(!node->containsKey(word[j])){
                cnt++;
                node->put(word[j],new Node());
            }
            node=node->getNextNode(word[j]);
        }
    }
    return cnt;
}

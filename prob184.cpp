#include <bits/stdc++.h> 
struct Node{
    Node*links[26];
    bool flag=false;
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch, Node*node){
        links[ch-'a']=node;
    }
    Node*getNextNode(char ch){
        return links[ch-'a'];
    }
    void setFlag(){
        flag=true;
    }
    bool isSetFlag(){
        return flag;
    }
};
class Trie{
private:
    Node*root;
public:
    Trie(){
        root=new Node();
    }
    void insert(string &word){
        Node*node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->getNextNode(word[i]);
        }
        node->setFlag();
    }
    bool isComplete(string &word){
        Node*node=root;
        for(int i=0;i<word.size();i++){
            node=node->getNextNode(word[i]);
            if(!node->isSetFlag())return false;
        }
        return node->isSetFlag();
    }
};
string completeString(int n, vector<string> &a){
    Trie T;
    for(auto it:a){
        T.insert(it);
    }
    string complete="";
    for(auto it:a){
        if(T.isComplete(it)){
            if(complete.size()<it.size())complete=it;
            else if(complete.size()==it.size()){
                if(it<complete)complete=it;
            }
        }
    }
    if(complete=="")return "None";
    return complete;
}
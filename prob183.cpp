#include <bits/stdc++.h> 
struct Node{
    Node* links[26];
    int countEndWith=0,countPrefix=0;

    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    Node* getNextNode(char ch){
        return links[ch-'a'];
    }
    void increaseEnd(){
        countEndWith++;
    }
    void increasePrefix(){
        countPrefix++;
    }
    void deleteEnd(){
        countEndWith--;
    }
    void reducePrefix(){
        countPrefix--;
    }
    int getEnd(){
        return countEndWith;
    }
    int getPrefix(){
        return countPrefix;
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
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        Node*node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i]))return 0;
            node=node->getNextNode(word[i]);
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &prefix){
        Node*node=root;
        for(int i=0;i<prefix.size();i++){
            if(!node->containsKey(prefix[i]))return 0;
            node=node->getNextNode(prefix[i]);
        }
        return node->getPrefix();
    }
    void erase(string &word){
        Node*node=root;
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])){
                node=node->getNextNode(word[i]);
                node->reducePrefix();
            }else return;
        }
        node->deleteEnd();
    }
};

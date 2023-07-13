#include<bits/stdc++.h>
class dl{
public:
    int key,val;
    dl *next,*prev;
    dl(int k,int v){
        key=k,val=v;
        next=NULL,prev=NULL;
    }
    dl(){
        next=NULL,prev=NULL;
    }
};
class LRUCache
{
public:
    int size;
    dl *head=new dl(0,0);
    dl *tail=new dl(0,0);
    unordered_map<int,dl *>mp;
    LRUCache(int capacity)
    {
        size=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void deleteNode(dl *node){
            dl*prev=node->prev;
            dl*next=node->next;
            prev->next=next;
            next->prev=prev;
    }
    void insertAfterHead(dl*node){
            dl *next=head->next;
            head->next=node;
            node->prev=head;
            next->prev=node;
            node->next=next;
    }
    int get(int key)
    {
        if(mp.find(key)!=mp.end()){
            dl*node=mp[key];
            deleteNode(node);
            insertAfterHead(node);
            return mp[key]->val;}
        return -1;
    }

    void put(int key, int value)
    {
        if(mp.find(key)!=mp.end()){
            mp[key]->val=value; //update value
            deleteNode(mp[key]);//delete mp[key] from list
            insertAfterHead(mp[key]);//now insert mp[key] next to head;
        }else{
            if(mp.size()<size){
                dl *node=new dl(key,value);
                mp[key]=node;
                insertAfterHead(node);
            }else{
                dl*node=tail->prev;
                mp.erase(node->key);
                deleteNode(node);
                node->key=key;
                node->val=value;
                mp[key]=node;
                insertAfterHead(node);
            }
        }
    }
};

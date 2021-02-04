/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */

// @lc code=start
#include<unordered_map>
#include<iostream>
using namespace std;
// 双向链表+哈希表，双向链表删除和添加是O(1)，哈希表查找和删除插入都是o(1)
// 双向链表尾部保存最近访问的元素，头部是LRU元素
// 双向链表保存key和val，哈希表(key，Node*)，这样就可以快速定位节点
// 访问一个节点，可以表示为删除链表中该节点，同时将该节点添加到尾部
class LRUCache {
public:
    struct Node{
        Node* before;
        Node* next;
        int key;
        int val;//节点的key
        Node(int k,int v):key(k),val(v),before(NULL),next(NULL){}
    };
    int capacity;
    unordered_map<int,Node*> lru_map;
    Node* head;
    Node* tail;
    LRUCache(int capacity) {
        this->capacity = capacity;
        // 两个虚拟头尾节点
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next=tail;
        tail->before = head;
    }
    
    int get(int key) {
        auto itr =lru_map.find(key); 
        if( itr== lru_map.end())
            return -1;
        //把目标节点从链表中删除然后添加到尾部
        Node* del = itr->second;
        del->before->next = del->next;
        del->next->before = del->before;
        Node* node = new Node(key,del->val);
        tail->before->next = node;
        node->next= tail;
        node->before = tail->before;
        tail->before = node;
        delete del;
        lru_map[key] = node;
        return node->val;
    }
    
    void put(int key, int value) {
        auto itr =lru_map.find(key); 
        if( itr == lru_map.end()){
            if(lru_map.size()==capacity){
                // 删除头部节点
                Node* del = head->next;
                head->next = del->next;
                del->next->before = head;
                lru_map.erase(del->key);
                delete del;
            }
            // 尾部插入新节点
            Node* node = new Node(key,value);
            tail->before->next = node;
            node->next= tail;
            node->before = tail->before;
            tail->before = node;
            lru_map[key] = node;
        }
        else{
            Node* del = itr->second;
            del->before->next = del->next;
            del->next->before = del->before;
            lru_map.erase(del->key);
            delete del;
            Node* node = new Node(key,value);
            tail->before->next = node;
            node->next= tail;
            node->before = tail->before;
            tail->before = node;
            lru_map[key] = node;
        } 
    }
};
// int main(){
//     LRUCache s(2);
//     s.put(2,1);
//     s.put(1,1);
//     s.put(2,3);
//     s.put(4,1);
//     cout<<s.get(1)<<endl;
//     cout<<s.get(2)<<endl;
//     return 0;
// }
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end


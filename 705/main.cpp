/*
 * @lc app=leetcode id=705 lang=cpp
 *
 * [705] Design HashSet
 */

// @lc code=start
class MyHashSet {
public:
    int* arr;

    MyHashSet() {
        arr = new int[65536];
        for(int i = 0; i < 65536; ++i){
            arr[i] = -1;
        }
    }

    inline int hash(int key){
        return key & 0xFFFF;
    }
    
    void add(int key) {
        int idx = hash(key);
        while(arr[idx] != -1 && arr[idx] != key){
            idx++;
            if(idx == 65536) idx = 0;
        }
        arr[idx] = key;
    }
    
    void remove(int key) {
        int idx = hash(key);
        while(arr[idx] != -1 && arr[idx] != key){
            idx++;
            if(idx == 65536) idx = 0;
        }
        arr[idx] = -1;
    }
    
    bool contains(int key) {
        int idx = hash(key);
        while(arr[idx] != -1 && arr[idx] != key){
            idx++;
            if(idx == 65536) idx = 0;
        }
        return arr[idx] != -1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end


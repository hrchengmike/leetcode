class LRUCache {
public:
    LRUCache(int capacity) {
        max_size = capacity;
        size = 0;
    }
    
        
    void print_hist(){
        for(int i = 0; i < hist.size(); i++){
            cout << hist[i] << " ";
        }
        cout << endl;
    }
    
    void update_hist(int key){
        hist.erase(remove(hist.begin(), hist.end(), key), hist.end());
        hist.push_back(key);
    }
    
    int get(int key) {
        auto pt = dict.find(key);
        if(pt == dict.end()){
            return -1;
        } else{
            update_hist(key);
            return pt -> second;
        }
    }
    
    void put(int key, int value) {
        auto pt = dict.find(key);
        if(pt != dict.end()){
            dict[key] = value;
            update_hist(key);
            return;
            
        } else{
            if(size == max_size){
                int least_used_key = hist[0];
                hist.erase(hist.begin());
                dict.erase(least_used_key);
                size--;
            }
            dict[key] = value;
            hist.push_back(key);
            size++;
        }
    }
private:
    int size;
    int max_size;
    unordered_map<int, int> dict;
    vector<int> hist;
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
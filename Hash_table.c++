#include<bits/stdc++.h>
using namespace std;
//Design a hash map.
//assumption:: the key is always an integer
//seperate chaning/open  hashing is used for collision handling
class Item{
    private:
    int key;
    int value;

    public:
    Item(int key,int value){
        this->key=key;
        this->value=value;
    }
    
    int getkey(){
        return key;
    }
    int getvalue(){
        return value;
    }
    void setvalue(int value){
        this->value=value;
    }
};

class Hash_table{
    private:
    int size;
    vector<vector<Item>>bucket;

    public:
    Hash_table(int size){
        this->size=size;
        bucket.resize(this->size);
    }
    int compression_function(int key){
        return key%size;
    }
    void insert(int key,int value){
        int hash_index=compression_function(key);
        int exist=0;
        for(auto it=bucket[hash_index].begin();it!=bucket[hash_index].end();it++){
             if((*it).getkey()==key){
                (*it).setvalue(value);
                exist=1;
                break;
            }
        }
        if(!exist)
        bucket.at(hash_index).emplace_back(Item(key,value));
    }

    int at(int key){

        int hash_index=compression_function(key);
        for(auto element:bucket[hash_index]){
            if(element.getkey()==key){
                return element.getvalue();
            }
        }
        bucket.at(hash_index).emplace_back(Item(key,0));
        return 0;
    }

    void erase(int key){
        int hash_index=compression_function(key);
        vector<Item>:: iterator key_iterator=bucket[hash_index].end();
        for(auto it=bucket[hash_index].begin();it!=bucket[hash_index].end();it++){
            if((*it).getkey()==key){
                key_iterator=it;
                break;
            }
        }
        if(key_iterator!=bucket[hash_index].end())
        bucket[hash_index].erase(key_iterator);
    }

    int count(int key){
        int present=0;
        int hash_index=compression_function(key);
        for(auto x:bucket[hash_index]){
            if(x.getkey()==key){
                present=1;
                break;
            }
        }
        return present;
    }

    

};

int main(){
    Hash_table h(7);

    vector<int>v={1,1,2,1,3,2};
    for(auto x:v){
        int freq_count=h.at(x)+1;
        h.insert(x,freq_count);
    }
    cout<<1<<" : "<<h.at(1)<<endl;
    cout<<2<<" : "<<h.at(2)<<endl;
    cout<<3<<" : "<<h.at(3)<<endl;



}
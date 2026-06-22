#ifndef HASH_MAP
#define HASH_MAP

#include <functional>

template <typename Key, typename Value>
struct hash_node
{
    Key key;
    Value value;
    hash_node<Key, Value> *next;
    hash_node() : next(nullptr) {}
    hash_node(const Key &key, const Value &value) : key(key), value(value), next(nullptr) {}
    ~hash_node(){
        delete next;
    }
};

template <typename Key, typename Value>
class hash_map
{
private:
    static constexpr int DEFAULT_BUCKET_SIZE = 16;
    size_t bucket_count, current_size;
    hash_node<Key, Value> **buckets;

public:
    // Constructors - RAII compliant copy constructor, copy assignment operator, move constructor, and destructor
    hash_map();
    hash_map(size_t bucket_count);
    ~hash_map();

    hash_map(const hash_map &other);
    hash_map &operator=(const hash_map &other);
    hash_map(hash_map &&other);
    hash_map &operator=(hash_map &&other);

    // Helper functions - hash
    size_t hash_function(const Key& key) const;
    hash_node<Key,Value>* clone_chain(const hash_node<Key,Value>* node) const;
    void rehash();

    // Core operations - insert, find, contains, remove
    void insert(const Key &key, const Value &value);
    hash_node<Key, Value>* find(const Key &key) const;
    bool contains(const Key &key) const;
    void remove(const Key &key);
    
    // Utilities - size, empty, clear
    size_t size();
    bool empty();
    void clear();
    
    // Operator Overloading - subscript operator for element access
    Value &operator[](const Key &key);
};

template <typename Key, typename Value>
hash_node<Key,Value>* hash_map<Key, Value>::clone_chain(const hash_node<Key,Value>* node) const{
    if(node == nullptr) return nullptr;
    hash_node<Key,Value>* new_node = new hash_node<Key,Value>(node->key, node->value);
    new_node->next = clone_chain(node->next);
    return new_node;
}

template <typename Key, typename Value>
hash_map<Key, Value>::hash_map(const hash_map &other){
    this->bucket_count = other.bucket_count;
    this->current_size = other.current_size;
    this->buckets = new hash_node<Key, Value>*[this->bucket_count];
    for(size_t i=0; i<this->bucket_count; i++){
        this->buckets[i] = clone_chain(other.buckets[i]);
    }
}

template <typename Key, typename Value>
hash_map<Key, Value> &hash_map<Key, Value>::operator=(const hash_map &other){
    if(this == &other){
        return *this;
    }
    // Clear existing content
    for(size_t i=0; i<this->bucket_count; i++){
        delete this->buckets[i];
    }
    delete[] this->buckets;
    
    // Copy new content
    this->bucket_count = other.bucket_count;
    this->current_size = other.current_size;
    this->buckets = new hash_node<Key, Value>*[this->bucket_count];
    for(size_t i=0; i<this->bucket_count; i++){
        this->buckets[i] = clone_chain(other.buckets[i]);
    }
    return *this;
}

template <typename Key, typename Value>
hash_map<Key, Value>::hash_map(hash_map &&other){
    this->bucket_count = other.bucket_count;
    this->current_size = other.current_size;
    this->buckets = other.buckets;
    other.buckets = nullptr;
    other.bucket_count = 0;
    other.current_size = 0;
}

template <typename Key, typename Value>
hash_map<Key, Value> &hash_map<Key, Value>::operator=(hash_map &&other){
    if(this == &other){
        return *this;
    }
    // Clear existing content
    if(buckets){
        for(size_t i=0; i<bucket_count; i++){
            delete buckets[i];
        }
        delete[] buckets;
    }
    
    // Move new content
    this->bucket_count = other.bucket_count;
    this->current_size = other.current_size;
    this->buckets = other.buckets;
    other.buckets = nullptr;
    return *this;
}

template <typename Key, typename Value>
Value &hash_map<Key, Value>::operator[](const Key &key){
    hash_node<Key, Value>* node = find(key);
    if(node == nullptr){
        insert(key, Value{});
        node = find(key);
    }
    return node->value;
}

// Constructors - RAII compliant copy constructor, copy assignment operator, move constructor, and destructor
template <typename Key, typename Value>
hash_map<Key, Value>::hash_map() : bucket_count(DEFAULT_BUCKET_SIZE), current_size(0){
    buckets = new hash_node<Key, Value>*[this->bucket_count];
    for(size_t i=0; i<this->bucket_count; i++) buckets[i] = nullptr;
}

template <typename Key, typename Value>
hash_map<Key, Value>::hash_map(size_t bucket_count) : bucket_count(bucket_count), current_size(0){
    buckets = new hash_node<Key, Value>*[this->bucket_count];
    for(size_t i=0; i<this->bucket_count; i++) buckets[i] = nullptr;
}

template <typename Key, typename Value>
hash_map<Key, Value>::~hash_map(){
    for(size_t i=0; i<this->bucket_count; i++){
        delete this->buckets[i];
    }
    delete[] buckets;
}

// Helpers - hash function
template <typename Key, typename Value>
size_t hash_map<Key, Value>::hash_function(const Key& key) const{
    return std::hash<Key>{}(key) % bucket_count;
}

template <typename Key, typename Value>
void hash_map<Key, Value>::rehash(){
    size_t old_bucket_count = bucket_count;
    hash_node<Key, Value>** old_buckets = buckets;
    bucket_count *= 2;

    hash_node<Key, Value>** new_buckets = new hash_node<Key, Value>*[bucket_count];
    for(size_t i = 0; i < bucket_count; i++) new_buckets[i] = nullptr;

    for(size_t i = 0; i < old_bucket_count; i++){
        hash_node<Key, Value>* bucket = old_buckets[i];
        while(bucket != nullptr){
            size_t new_bucket_number = std::hash<Key>{}(bucket->key) % bucket_count;
            hash_node<Key, Value>* new_bucket = new_buckets[new_bucket_number];

            if(new_bucket == nullptr){
                new_buckets[new_bucket_number] =
                    new hash_node<Key, Value>(
                        bucket->key,
                        bucket->value
                    );
            }
            else{
                while(new_bucket->next != nullptr){
                    new_bucket = new_bucket->next;
                }
                new_bucket->next =
                    new hash_node<Key, Value>(
                        bucket->key,
                        bucket->value
                    );
            }
            bucket = bucket->next;
        }
    }

    for(size_t i = 0; i < old_bucket_count; i++){
        delete old_buckets[i];
    }
    delete[] old_buckets;

    buckets = new_buckets;
}

// Core operations - insert, find, contains, remove
template <typename Key, typename Value>
void hash_map<Key, Value>::insert(const Key &key, const Value &value){
    if(current_size >= bucket_count){
        // Rehashing logic can be implemented here if needed
        rehash();
    }

    size_t bucket_number = this->hash_function(key);
    hash_node<Key, Value> *bucket = buckets[bucket_number];


    if(bucket == nullptr){
        buckets[bucket_number] = new hash_node<Key,Value>(key,value);
        current_size++;
        return;
    }
    
    while(bucket != nullptr){
        if(bucket->key == key){
            bucket->value = value;
            return; 
        }
        if(bucket->next == nullptr) break;
        bucket = bucket->next;
    }
    
    hash_node<Key,Value> *node = new hash_node<Key,Value>(key,value); 
    bucket->next = node;
    current_size++;
}

template <typename Key, typename Value>
hash_node<Key, Value>* hash_map<Key, Value>::find(const Key &key) const{
    size_t bucket_number = this->hash_function(key);
    hash_node<Key, Value> *bucket = buckets[bucket_number];

    if(bucket == nullptr) return nullptr;
    
    while(bucket != nullptr){
        if(bucket->key == key){
            return bucket;  
        }
        bucket = bucket->next;
    }
    return nullptr;
}

template <typename Key, typename Value>
bool hash_map<Key, Value>::contains(const Key &key) const{
    return find(key) != nullptr;
}

template <typename Key, typename Value>
void hash_map<Key, Value>::remove(const Key &key){
    size_t bucket_number = hash_function(key);
    hash_node<Key, Value>* curr = buckets[bucket_number];
    hash_node<Key, Value>* prev = nullptr;
    
    while(curr != nullptr){
        if(curr->key == key){
            if(prev == nullptr) buckets[bucket_number] = curr->next;
            else prev->next = curr->next;
            
            curr->next = nullptr;
            delete curr;

            current_size--;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}


// Utilities - size, empty, clear
template <typename Key, typename Value>
size_t hash_map<Key, Value>::size(){
    return current_size;
}

template <typename Key, typename Value>
bool hash_map<Key, Value>::empty(){
    return current_size == 0;
}

template <typename Key, typename Value>
void hash_map<Key, Value>::clear(){
    for(size_t i=0; i<bucket_count; i++){
        delete buckets[i];
        buckets[i] = nullptr;
    }
    current_size = 0;
}

#endif
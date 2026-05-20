#include "_utility.h"
#include <bits/stdc++.h>

// Custom Constructors
BloomFilter::BloomFilter(){
    this->m = 265; this->n = -1; this->P = -1; this->k = 7;
    bit_array = std::vector<bool>(265,0);
}
BloomFilter::BloomFilter(int m){
    this->m = m; this->n = -1; this->P = -1; this->k = 7;
    bit_array = std::vector<bool>(this->m,0);
}
BloomFilter::BloomFilter(int n, int m){
    this->n = n; this->m = m; this->P = -1;
    this->k = std::ceil(m*std::log(2)/n);
    bit_array = std::vector<bool>(this->m,0);
}

BloomFilter::BloomFilter(int n, double P){
    if(P <= 0 || P >= 1){
        bit_array = std::vector<bool>(265,0);
        return;
    } 
    this->n = n; this->P = P; 
    this->m =  std::abs((n*std::log(P)) / (std::pow(std::log(2), 2)));
    this->k = std::ceil(m*std::log(2)/n);
    bit_array = std::vector<bool>(this->m,0);
}

// Helper Functions
uint32_t BloomFilter::hash(const std::string &word, int seed){
    return std::hash<std::string>{}(word + std::to_string(seed));
}

// Main Functions
bool BloomFilter::find(const std::string &word){
    uint32_t hash1 = this->hash(word, 17);
    uint32_t hash2 = this->hash(word, 31);
    for(int i=0; i<k; i++){
        uint32_t idx = (hash1 + i*hash2) % this->m;
        if(!bit_array[idx]) return false;
    }
    return true;
}
void BloomFilter::insert(const std::string &word){
    uint32_t hash1 = this->hash(word, 17);
    uint32_t hash2 = this->hash(word, 31);
    for(int i=0; i<k; i++){
        uint32_t idx = (hash1 + i*hash2) % this->m;
        bit_array[idx] = true;
    }
}
#include "_utility.h"
#include <bits/stdc++.h>

TrieNode::TrieNode() : end(false), children() {}
TrieNode::~TrieNode() {
    for (auto& pair : children) {
        delete pair.second;
    }
}
bool TrieNode::insert(const std::string &word, int index){
    if(index == word.length()) {
        this->end = true;
        return true;
    }
    char child = word[index];
    auto it = this->children.find(child);
    if(it == this->children.end()){
        this->children[child] = new TrieNode();
    }
    TrieNode *Node = children[child];
    return Node->insert(word, index+1);
}
bool TrieNode::find(const std::string &word, int index){
    if(index == word.length()) return this->end;

    char child = word[index];
    auto it = this->children.find(child);
    if(it != this->children.end()){
        TrieNode *Node = it->second;
        return Node->find(word, index+1);
    }else return false; 
}
bool TrieNode::remove(const std::string &word, int index){
    if(index == word.length()) {
        if(this->end){
            this->end = false;
            return true;
        }else{
            return false;
        }
    }
    char child = word[index];
    auto it = this->children.find(child);
    if(it != this->children.end()){
        TrieNode *Node = it->second;
        return Node->remove(word, index+1);
    }else return false; 
}
bool TrieNode::check_prefix(const std::string &prefix, int index){
    if(index == prefix.length()) return true;
    char child = prefix[index];
    auto it = this->children.find(child);
    if(it != this->children.end()){
        TrieNode *Node = it->second;
        return Node->check_prefix(prefix, index+1);
    }else return false; 
}
std::vector<std::string> TrieNode::find_all_with_prefix(const std::string &prefix, int index){
    if(index == prefix.length()){
        std::vector<std::string> ans = this->find_all_words();
        for(auto &word: ans) word = prefix + word;
        return ans;
    }
    char child = prefix[index];
    auto it = this->children.find(child);
    if(it != this->children.end()){
        TrieNode *Node = it->second;
        return Node->find_all_with_prefix(prefix, index+1);
    }else {
        std::vector<std::string> ans;
        return ans;
    }
}
std::vector<std::string> TrieNode::find_all_words(){
    std::vector<std::string> ans;
    std::string word;
    find_all_words(ans,word);
    return ans;
}
void TrieNode::find_all_words(std::vector<std::string> &ans, std::string &word){
    if(this->end) ans.push_back(word);
    for(const auto &pair: this->children){
        char child = pair.first;
        TrieNode* Node = pair.second;
        word.push_back(child);
        Node->find_all_words(ans,word);
        word.pop_back();
    }
}


Trie::Trie() {
    root = new TrieNode();
}
Trie::Trie(const std::string &word) {
    root = new TrieNode();
    root->insert(word,0);
}
Trie::Trie(const std::vector<std::string> &words){
    root = new TrieNode();
    for(auto &word: words){
        root->insert(word,0);
    }
}
Trie::~Trie() {
    delete root;
}
bool Trie::insert(const std::string &word) {
    return root->insert(word,0);
}
bool Trie::find(const std::string &word) {
    return root->find(word,0);
}
bool Trie::remove(const std::string &word) {
    return root->remove(word, 0);
}
bool Trie::check_prefix(const std::string &prefix){
    return root->check_prefix(prefix,0);
}
std::vector<std::string> Trie::find_all_with_prefix(const std::string &prefix){
    return root->find_all_with_prefix(prefix, 0);
}
std::vector<std::string> Trie::find_all_words(){
    return root->find_all_words();
}
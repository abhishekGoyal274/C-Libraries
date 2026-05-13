#ifndef UTILITY_H   
#define UTILITY_H
#include <bits/stdc++.h>

class Segment_Tree
{
public:
    Segment_Tree *left, *right;
    int val, left_bound, right_bound;
    Segment_Tree();
    Segment_Tree(int val);
    Segment_Tree(int val, Segment_Tree* left, Segment_Tree* right);
    ~Segment_Tree();
};
class Tree
{
public:
    Tree *left, *right;
    int val;
    Tree();
    Tree(int val);
    Tree(int val, Tree* left, Tree* right);
    ~Tree();
};

// Disjoint Set Class
class DisjointSet {
private:
    std::vector<int> parent, rank;
public:
    DisjointSet(int size);
    int find(int u);
    void union_sets(int u, int v);
};

// Trie Node Class
class TrieNode {
private:
    bool end{false};
    std::unordered_map<char, TrieNode*> children;
public:
    TrieNode();
    ~TrieNode();
    bool insert(const std::string &word, int index);
    bool find(const std::string &word, int index);
    bool remove(const std::string &word, int index);
    bool check_prefix(const std::string &prefix, int index);
    std::vector<std::string> find_all_with_prefix(const std::string &prefix, int index);
    std::vector<std::string> find_all_words();
    void find_all_words(std::vector<std::string> &ans, std::string &word);
};
class Trie{
private:
    TrieNode* root;
public:
    Trie();
    Trie(const std::string &word);
    Trie(const std::vector<std::string> &words);
    ~Trie();
    bool insert(const std::string &word);
    bool find(const std::string &word);
    bool remove(const std::string &word);
    bool check_prefix(const std::string &prefix);
    std::vector<std::string> find_all_with_prefix(const std::string &prefix);
    std::vector<std::string> find_all_words();
};

// Sum Tree Functions
Segment_Tree* sum_tree(std::vector<int>& array);
Segment_Tree* build_sum_tree(std::vector<int>& array, int left, int right);
int sum_query(const Segment_Tree* root, const int &start, const int &end);
void sum_update(Segment_Tree* root, const int &index, const int &value);

// Min Tree Functions
Segment_Tree* min_tree(std::vector<int>& array);
Segment_Tree* build_min_tree(std::vector<int>& array, int left, int right);
int min_query(const Segment_Tree* root, const int &start, const int &end);
void min_update(Segment_Tree* root, const int &index, const int &value);

// Max Tree Functions
Segment_Tree* max_tree(std::vector<int>& array);
Segment_Tree* build_max_tree(std::vector<int>& array, int left, int right);
int max_query(const Segment_Tree* root, const int &start, const int &end);
void max_update(Segment_Tree* root, const int &index, const int &value);

#endif 

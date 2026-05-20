#include "_utility.h"
#include <bits/stdc++.h>

// Sum Tree Functions
Segment_Tree* sum_tree(std::vector<int>& array){
    if (array.empty()) return nullptr;
    return build_sum_tree(array, 0, array.size() - 1);
}
Segment_Tree* build_sum_tree(std::vector<int>& array, int left, int right){
    if(left > right) return nullptr;
    if(left == right){
        Segment_Tree* leaf = new Segment_Tree(array[left]);
        leaf->left_bound = leaf->right_bound = left;
        return leaf;
    }
    int mid = left + (right - left) / 2;
    Segment_Tree* left_child = build_sum_tree(array, left, mid);
    Segment_Tree* right_child = build_sum_tree(array, mid + 1, right);
    int sum = 0;
    if(left_child) sum += left_child->val;
    if(right_child) sum += right_child->val;
    Segment_Tree* node = new Segment_Tree(sum, left_child, right_child);
    node->left_bound = left;
    node->right_bound = right;
    return node;
}
int sum_query(const Segment_Tree* root, const int &start, const int &end){
    if(root == NULL || start > end) return 0;
    int left = root->left_bound; 
    int right = root->right_bound; 

    if(start <= left && end >= right) return root->val;
    if(left == start && right == end){
        return root->val;
    }
    int mid = left + (right - left) / 2;
    if(end <= mid) return sum_query(root->left, start, end);
    else if(start > mid) return sum_query(root->right, start, end);
    else return sum_query(root->left, start, mid) + sum_query(root->right, mid+1, end);
}
void sum_update(Segment_Tree* root, const int &index, const int &value){
    if(root == nullptr) return;
    int left = root->left_bound; int right = root->right_bound;
    if (index < left || index > right) return;
    if(left == right && left == index){
        root->val = value;
        return;
    }

    int mid = left + (right - left)/2;
    if(index <= mid) sum_update(root->left, index, value);
    else sum_update(root->right, index, value);

    int sum = 0;
    if(root->left) sum += root->left->val;
    if(root->right) sum += root->right->val;
    root->val = sum;

    return;
}

// Min Tree Functions
Segment_Tree* min_tree(std::vector<int>& array){
    if (array.empty()) return nullptr;
    return build_min_tree(array, 0, array.size() - 1);
}
Segment_Tree* build_min_tree(std::vector<int>& array, int left, int right){
    if(left > right) return nullptr;
    if(left == right){
        Segment_Tree* leaf = new Segment_Tree(array[left]);
        leaf->left_bound = leaf->right_bound = left;
        return leaf;
    }
    int mid = left + (right - left) / 2;
    Segment_Tree* left_child = build_min_tree(array, left, mid);
    Segment_Tree* right_child = build_min_tree(array, mid + 1, right);
    int min = std::min(left_child ? left_child->val : INT_MAX, right_child ? right_child->val : INT_MAX);
    Segment_Tree* node = new Segment_Tree(min, left_child, right_child);
    node->left_bound = left;
    node->right_bound = right;
    return node;
}
int min_query(const Segment_Tree* root, const int &start, const int &end){
    if(root == NULL || start > end) return INT_MAX;
    int left = root->left_bound; 
    int right = root->right_bound; 

    if(start <= left && end >= right) return root->val;
    if(left == start && right == end){
        return root->val;
    }
    int mid = left + (right - left) / 2;
    if(end <= mid) return min_query(root->left, start, end);
    else if(start > mid) return min_query(root->right, start, end);
    else return std::min(min_query(root->left, start, mid), min_query(root->right, mid+1, end));
}
void min_update(Segment_Tree* root, const int &index, const int &value){
    if(root == nullptr) return;
    int left = root->left_bound; int right = root->right_bound;
    if (index < left || index > right) return;
    if(left == right && left == index){
        root->val = value;
        return;
    }

    int mid = left + (right - left)/2;
    if(index <= mid) min_update(root->left, index, value);
    else min_update(root->right, index, value);

    int min = std::min(root->left ? root->left->val : INT_MAX, root->right ? root->right->val : INT_MAX);
    root->val = min;
    return;
}

//  Max Tree Functions
Segment_Tree* max_tree(std::vector<int>& array){
    if (array.empty()) return nullptr;
    return build_max_tree(array, 0, array.size() - 1);
}
Segment_Tree* build_max_tree(std::vector<int>& array, int left, int right){
    if(left > right) return nullptr;
    if(left == right){
        Segment_Tree* leaf = new Segment_Tree(array[left]);
        leaf->left_bound = leaf->right_bound = left;
        return leaf;
    }
    int mid = left + (right - left) / 2;
    Segment_Tree* left_child = build_max_tree(array, left, mid);
    Segment_Tree* right_child = build_max_tree(array, mid + 1, right);
    int max = std::max(left_child ? left_child->val : INT_MIN, right_child ? right_child->val : INT_MIN);
    Segment_Tree* node = new Segment_Tree(max, left_child, right_child);
    node->left_bound = left;
    node->right_bound = right;
    return node;
}
int max_query(const Segment_Tree* root, const int &start, const int &end){
    if(root == NULL || start > end) return INT_MIN;
    int left = root->left_bound; 
    int right = root->right_bound; 

    if(start <= left && end >= right) return root->val;
    if(left == start && right == end){
        return root->val;
    }
    int mid = left + (right - left) / 2;
    if(end <= mid) return max_query(root->left, start, end);
    else if(start > mid) return max_query(root->right, start, end);
    else return std::max(max_query(root->left, start, mid), max_query(root->right, mid+1, end));
}
void max_update(Segment_Tree* root, const int &index, const int &value){
    if(root == nullptr) return;
    int left = root->left_bound; int right = root->right_bound;
    if (index < left || index > right) return;
    if(left == right && left == index){
        root->val = value;
        return;
    }

    int mid = left + (right - left)/2;
    if(index <= mid) max_update(root->left, index, value);
    else max_update(root->right, index, value);

    int max = std::max(root->left ? root->left->val : INT_MIN, root->right ? root->right->val : INT_MIN);
    root->val = max;
    return;
}

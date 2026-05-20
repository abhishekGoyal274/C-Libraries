#include "_utility.h"
#include <bits/stdc++.h>

Segment_Tree::Segment_Tree() : val(0), left_bound(0), right_bound(0), left(nullptr), right(nullptr) {}
Segment_Tree::Segment_Tree(int val) : val(val), left_bound(0), right_bound(0), left(nullptr), right(nullptr) {}
Segment_Tree::Segment_Tree(int val, Segment_Tree* left, Segment_Tree* right) : val(val), left_bound(0), right_bound(0), left(left), right(right) {}
Segment_Tree::~Segment_Tree() {
    delete left;
    delete right;
}

Tree::Tree() : val(0), left(nullptr), right(nullptr) {}
Tree::Tree(int val) : val(val), left(nullptr), right(nullptr) {}
Tree::Tree(int val, Tree* left, Tree* right) : val(val), left(left), right(right) {}
Tree::~Tree() {
    delete left;
    delete right;
}

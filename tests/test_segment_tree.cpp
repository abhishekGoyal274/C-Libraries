// demos/test_segment_tree.cpp

#include <bits/stdc++.h>
#include "_utility.h"

using namespace std;

void test_sum_tree_build()
{
    vector<int> arr = {1,2,3,4,5};

    Segment_Tree* root = sum_tree(arr);

    assert(root->val == 15);

    delete root;

    cout << "[Sum Tree Build] Passed\n";
}

void test_sum_query_full_range()
{
    vector<int> arr = {1,2,3,4,5};

    Segment_Tree* root = sum_tree(arr);

    assert(sum_query(root,0,4) == 15);

    delete root;

    cout << "[Sum Query Full Range] Passed\n";
}

void test_sum_query_partial_range()
{
    vector<int> arr = {1,2,3,4,5};

    Segment_Tree* root = sum_tree(arr);

    assert(sum_query(root,1,3) == 9);

    delete root;

    cout << "[Sum Query Partial Range] Passed\n";
}

void test_sum_query_single_element()
{
    vector<int> arr = {1,2,3,4,5};

    Segment_Tree* root = sum_tree(arr);

    assert(sum_query(root,2,2) == 3);

    delete root;

    cout << "[Sum Query Single Element] Passed\n";
}

void test_sum_update()
{
    vector<int> arr = {1,2,3,4,5};

    Segment_Tree* root = sum_tree(arr);

    sum_update(root,2,10);

    assert(sum_query(root,0,4) == 22);
    assert(sum_query(root,2,2) == 10);

    delete root;

    cout << "[Sum Update] Passed\n";
}

void test_min_tree()
{
    vector<int> arr = {5,3,8,1,9};

    Segment_Tree* root = min_tree(arr);

    assert(min_query(root,0,4) == 1);
    assert(min_query(root,0,2) == 3);

    min_update(root,3,7);

    assert(min_query(root,0,4) == 3);

    delete root;

    cout << "[Min Tree] Passed\n";
}

void test_max_tree()
{
    vector<int> arr = {5,3,8,1,9};

    Segment_Tree* root = max_tree(arr);

    assert(max_query(root,0,4) == 9);
    assert(max_query(root,0,2) == 8);

    max_update(root,4,2);

    assert(max_query(root,0,4) == 8);

    delete root;

    cout << "[Max Tree] Passed\n";
}

void test_negative_values()
{
    vector<int> arr = {-5,-2,-10,-1};

    Segment_Tree* sum_root = sum_tree(arr);
    Segment_Tree* min_root = min_tree(arr);
    Segment_Tree* max_root = max_tree(arr);

    assert(sum_query(sum_root,0,3) == -18);
    assert(min_query(min_root,0,3) == -10);
    assert(max_query(max_root,0,3) == -1);

    delete sum_root;
    delete min_root;
    delete max_root;

    cout << "[Negative Values] Passed\n";
}

void test_single_element_tree()
{
    vector<int> arr = {42};

    Segment_Tree* root = sum_tree(arr);

    assert(sum_query(root,0,0) == 42);

    sum_update(root,0,100);

    assert(sum_query(root,0,0) == 100);

    delete root;

    cout << "[Single Element Tree] Passed\n";
}

void test_multiple_updates()
{
    vector<int> arr = {1,2,3,4,5};

    Segment_Tree* root = sum_tree(arr);

    sum_update(root,0,10);
    sum_update(root,1,20);
    sum_update(root,2,30);

    assert(sum_query(root,0,4) == 69);

    delete root;

    cout << "[Multiple Updates] Passed\n";
}

int main()
{
    cout << "========== SEGMENT TREE TESTS ==========\n\n";

    test_sum_tree_build();
    test_sum_query_full_range();
    test_sum_query_partial_range();
    test_sum_query_single_element();
    test_sum_update();
    test_min_tree();
    test_max_tree();
    test_negative_values();
    test_single_element_tree();
    test_multiple_updates();

    cout << "\nAll Segment Tree Tests Passed Successfully.\n";

    return 0;
}
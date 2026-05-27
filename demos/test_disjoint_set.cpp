// demos/test_disjoint_set.cpp

#include <bits/stdc++.h>
#include "_utility.h"

using namespace std;

void test_initialization()
{
    DisjointSet dsu(5);

    for(int i = 0; i < 5; i++){
        assert(dsu.find(i) == i);
    }

    cout << "[Initialization] Passed\n";
}

void test_basic_union()
{
    DisjointSet dsu(5);

    dsu.union_sets(0,1);

    assert(dsu.find(0) == dsu.find(1));

    cout << "[Basic Union] Passed\n";
}

void test_multiple_unions()
{
    DisjointSet dsu(10);

    dsu.union_sets(1,2);
    dsu.union_sets(2,3);
    dsu.union_sets(3,4);

    assert(dsu.find(1) == dsu.find(4));

    cout << "[Multiple Unions] Passed\n";
}

void test_disconnected_components()
{
    DisjointSet dsu(10);

    dsu.union_sets(1,2);
    dsu.union_sets(3,4);

    assert(dsu.find(1) != dsu.find(3));

    cout << "[Disconnected Components] Passed\n";
}

void test_redundant_union()
{
    DisjointSet dsu(5);

    dsu.union_sets(0,1);
    dsu.union_sets(0,1);

    assert(dsu.find(0) == dsu.find(1));

    cout << "[Redundant Union] Passed\n";
}

void test_large_union_chain()
{
    DisjointSet dsu(1000);

    for(int i = 0; i < 999; i++){
        dsu.union_sets(i, i+1);
    }

    for(int i = 0; i < 1000; i++){
        assert(dsu.find(i) == dsu.find(0));
    }

    cout << "[Large Union Chain] Passed\n";
}

int main()
{
    cout << "========== DISJOINT SET TESTS ==========\n\n";

    test_initialization();
    test_basic_union();
    test_multiple_unions();
    test_disconnected_components();
    test_redundant_union();
    test_large_union_chain();

    cout << "\nAll Disjoint Set Tests Passed Successfully.\n";

    return 0;
}
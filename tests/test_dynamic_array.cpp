// demos/test_dynamic_array.cpp

#include <bits/stdc++.h>
#include "dynamic_array.h"

using namespace std;

void test_default_constructor()
{
    dynamic_array<int> arr;

    cout << "[Default Constructor] Passed\n";
}

void test_fill_constructor()
{
    dynamic_array<int> arr(5, 7);

    for(int i = 0; i < 5; i++){
        assert(arr[i] == 7);
    }

    cout << "[Fill Constructor] Passed\n";
}

void test_push_back()
{
    dynamic_array<int> arr;

    for(int i = 0; i < 1000; i++){
        arr.push_back(i);
    }

    for(int i = 0; i < 1000; i++){
        assert(arr[i] == i);
    }

    cout << "[Push Back + Resize] Passed\n";
}

void test_pop_back()
{
    dynamic_array<int> arr;

    for(int i = 0; i < 10; i++){
        arr.push_back(i);
    }

    arr.pop_back();
    arr.pop_back();

    assert(arr.size() == 8);

    cout << "[Pop Back] Passed\n";
}

void test_bounds_check()
{
    dynamic_array<int> arr(5, 1);

    try{
        arr[100];
        assert(false);
    }
    catch(const std::out_of_range& e){
        cout << "[Bounds Check] Passed\n";
    }
}

void test_copy_constructor()
{
    dynamic_array<int> a(5, 10);

    dynamic_array<int> b = a;

    b[0] = 100;

    assert(a[0] == 10);
    assert(b[0] == 100);

    cout << "[Copy Constructor] Passed\n";
}

void test_copy_assignment()
{
    dynamic_array<int> a(5, 10);
    dynamic_array<int> b;

    b = a;

    b[0] = 200;

    assert(a[0] == 10);
    assert(b[0] == 200);

    cout << "[Copy Assignment] Passed\n";
}

void test_self_assignment()
{
    dynamic_array<int> a(5, 10);

    a = a;

    for(int i = 0; i < 5; i++){
        assert(a[i] == 10);
    }

    cout << "[Self Assignment] Passed\n";
}

void test_move_constructor()
{
    dynamic_array<int> a(5, 10);

    dynamic_array<int> b = std::move(a);

    for(int i = 0; i < 5; i++){
        assert(b[i] == 10);
    }

    cout << "[Move Constructor] Passed\n";
}

void test_move_assignment()
{
    dynamic_array<int> a(5, 10);
    dynamic_array<int> b;

    b = std::move(a);

    for(int i = 0; i < 5; i++){
        assert(b[i] == 10);
    }

    cout << "[Move Assignment] Passed\n";
}

void test_clear()
{
    dynamic_array<int> arr(10, 5);

    arr.clear();

    assert(arr.size() == 0);

    cout << "[Clear] Passed\n";
}

void test_free()
{
    dynamic_array<int> arr(10, 5);

    arr.free();

    arr.push_back(100);

    assert(arr[0] == 100);

    cout << "[Free] Passed\n";
}

int main()
{
    cout << "========== DYNAMIC ARRAY TESTS ==========\n\n";

    test_default_constructor();
    test_fill_constructor();
    test_push_back();
    test_pop_back();
    test_bounds_check();
    test_copy_constructor();
    test_copy_assignment();
    test_self_assignment();
    test_move_constructor();
    test_move_assignment();
    test_clear();
    test_free();

    cout << "\nAll Dynamic Array Tests Passed Successfully.\n";

    return 0;
}
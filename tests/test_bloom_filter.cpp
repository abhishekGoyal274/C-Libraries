// demos/test_bloom_filter.cpp

#include <bits/stdc++.h>
#include "_utility.h"

using namespace std;

void test_basic_insert_find()
{
    BloomFilter filter;

    filter.insert("hello");
    filter.insert("world");

    assert(filter.find("hello"));
    assert(filter.find("world"));

    cout << "[Basic Insert + Find] Passed\n";
}

void test_definitely_absent()
{
    BloomFilter filter;

    filter.insert("apple");

    bool result = filter.find("banana");

    if(!result){
        cout << "[Definitely Absent] Passed\n";
    }
    else{
        cout << "[False Positive Observed] Valid Bloom Behavior\n";
    }
}

void test_duplicate_insert()
{
    BloomFilter filter;

    filter.insert("repeat");
    filter.insert("repeat");
    filter.insert("repeat");

    assert(filter.find("repeat"));

    cout << "[Duplicate Insert] Passed\n";
}

void test_custom_constructor()
{
    BloomFilter filter(1000, 0.01);

    filter.insert("testing");

    assert(filter.find("testing"));

    cout << "[Custom Constructor] Passed\n";
}

void test_invalid_probability()
{
    BloomFilter filter(100, 2.0);

    filter.insert("hello");

    assert(filter.find("hello"));

    cout << "[Invalid Probability Handling] Passed\n";
}

void test_large_dataset()
{
    BloomFilter filter(10000, 0.01);

    for(int i = 0; i < 5000; i++){
        filter.insert("word_" + to_string(i));
    }

    for(int i = 0; i < 5000; i++){
        assert(filter.find("word_" + to_string(i)));
    }

    cout << "[Large Dataset] Passed\n";
}

void test_false_positive_rate()
{
    BloomFilter filter(10000, 0.01);

    for(int i = 0; i < 5000; i++){
        filter.insert("inserted_" + to_string(i));
    }

    int false_positives = 0;

    for(int i = 5000; i < 10000; i++){
        if(filter.find("not_inserted_" + to_string(i))){
            false_positives++;
        }
    }

    cout << "[False Positives Observed] "
         << false_positives
         << "\n";
}

int main()
{
    cout << "========== BLOOM FILTER TESTS ==========\n\n";

    test_basic_insert_find();
    test_definitely_absent();
    test_duplicate_insert();
    test_custom_constructor();
    test_invalid_probability();
    test_large_dataset();
    test_false_positive_rate();

    cout << "\nAll Bloom Filter Tests Completed.\n";

    return 0;
}
// demos/test_trie.cpp

#include <bits/stdc++.h>
#include "_utility.h"

using namespace std;

void test_insert_find()
{
    Trie trie;

    trie.insert("hello");

    assert(trie.find("hello"));
    assert(!trie.find("hell"));

    cout << "[Insert + Find] Passed\n";
}

void test_multiple_insertions()
{
    Trie trie;

    vector<string> words = {
        "apple",
        "banana",
        "grape",
        "orange"
    };

    for(auto &word : words){
        trie.insert(word);
    }

    for(auto &word : words){
        assert(trie.find(word));
    }

    cout << "[Multiple Insertions] Passed\n";
}

void test_prefix()
{
    Trie trie;

    trie.insert("coding");
    trie.insert("coder");

    assert(trie.check_prefix("cod"));
    assert(!trie.check_prefix("xyz"));

    cout << "[Prefix Check] Passed\n";
}

void test_remove()
{
    Trie trie;

    trie.insert("hello");

    assert(trie.find("hello"));

    trie.remove("hello");

    assert(!trie.find("hello"));

    cout << "[Remove] Passed\n";
}

void test_find_all_words()
{
    Trie trie;

    vector<string> words = {
        "cat",
        "car",
        "dog"
    };

    for(auto &word : words){
        trie.insert(word);
    }

    auto result = trie.find_all_words();

    sort(result.begin(), result.end());
    sort(words.begin(), words.end());

    assert(result == words);

    cout << "[Find All Words] Passed\n";
}

void test_find_all_with_prefix()
{
    Trie trie;

    trie.insert("apple");
    trie.insert("application");
    trie.insert("banana");

    auto result = trie.find_all_with_prefix("app");

    sort(result.begin(), result.end());

    vector<string> expected = {
        "apple",
        "application"
    };

    sort(expected.begin(), expected.end());

    assert(result == expected);

    cout << "[Find All With Prefix] Passed\n";
}

void test_duplicate_insert()
{
    Trie trie;

    trie.insert("hello");
    trie.insert("hello");

    assert(trie.find("hello"));

    cout << "[Duplicate Insert] Passed\n";
}

int main()
{
    cout << "========== TRIE TESTS ==========\n\n";

    test_insert_find();
    test_multiple_insertions();
    test_prefix();
    test_remove();
    test_find_all_words();
    test_find_all_with_prefix();
    test_duplicate_insert();

    cout << "\nAll Trie Tests Passed Successfully.\n";

    return 0;
}
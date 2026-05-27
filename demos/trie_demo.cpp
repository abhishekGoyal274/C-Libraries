#include <bits/stdc++.h>
#include "_utility.h"

using namespace std;

int main()
{
    cout << "========== TRIE DEMO ==========\n\n";

    Trie trie;

    while(true)
    {
        cout << "\n";
        cout << "1. Insert Word\n";
        cout << "2. Find Word\n";
        cout << "3. Remove Word\n";
        cout << "4. Check Prefix\n";
        cout << "5. Find All With Prefix\n";
        cout << "6. Find All Words\n";
        cout << "7. Exit\n";

        int choice;
        cin >> choice;

        if(choice == 1)
        {
            string word;

            cout << "Enter word: ";
            cin >> word;

            trie.insert(word);
        }
        else if(choice == 2)
        {
            string word;

            cout << "Enter word: ";
            cin >> word;

            cout << trie.find(word) << endl;
        }
        else if(choice == 3)
        {
            string word;

            cout << "Enter word: ";
            cin >> word;

            trie.remove(word);
        }
        else if(choice == 4)
        {
            string prefix;

            cout << "Enter prefix: ";
            cin >> prefix;

            cout << trie.check_prefix(prefix) << endl;
        }
        else if(choice == 5)
        {
            string prefix;

            cout << "Enter prefix: ";
            cin >> prefix;

            auto words = trie.find_all_with_prefix(prefix);

            for(auto &word : words){
                cout << word << " ";
            }

            cout << endl;
        }
        else if(choice == 6)
        {
            auto words = trie.find_all_words();

            for(auto &word : words){
                cout << word << " ";
            }

            cout << endl;
        }
        else
        {
            break;
        }
    }

    return 0;
}
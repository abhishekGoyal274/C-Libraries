#include <bits/stdc++.h>
#include "_utility.h"

using namespace std;

int main()
{
    cout << "========== BLOOM FILTER DEMO ==========\n\n";

    BloomFilter filter(1000, 0.01);

    while(true)
    {
        cout << "\n";
        cout << "1. Insert Word\n";
        cout << "2. Find Word\n";
        cout << "3. Exit\n";

        int choice;
        cin >> choice;

        if(choice == 1)
        {
            string word;

            cout << "Enter word: ";
            cin >> word;

            filter.insert(word);

            cout << "Inserted.\n";
        }
        else if(choice == 2)
        {
            string word;

            cout << "Enter word: ";
            cin >> word;

            if(filter.find(word)){
                cout << "Possibly Present.\n";
            }
            else{
                cout << "Definitely Not Present.\n";
            }
        }
        else
        {
            break;
        }
    }

    return 0;
}
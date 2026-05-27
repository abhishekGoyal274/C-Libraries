// _main.cpp

#include <bits/stdc++.h>
#include "./_utility.h"
#include "./dynamic_array.h"

using namespace std;

void print_header()
{
    cout << "=========================================\n";
    cout << "        DSA LIBRARY PROJECT\n";
    cout << "=========================================\n\n";
}

void print_menu()
{
    cout << "Available Executables:\n\n";

    cout << "1. Dynamic Array Demo\n";
    cout << "2. Bloom Filter Demo\n";
    cout << "3. Trie Demo\n";
    cout << "4. Disjoint Set Demo\n";
    cout << "5. Segment Tree Demo\n";

    cout << "\n";

    cout << "6. Run All Tests\n";

    cout << "\n";

    cout << "7. Exit\n\n";
}

int main()
{
    while(true)
    {
        print_header();
        print_menu();

        int choice;

        cout << "Enter choice: ";
        cin >> choice;

        cout << "\n";

        if(choice == 1)
        {
            system("./executables/dynamic_array_demo");
        }
        else if(choice == 2)
        {
            system("./executables/bloom_filter_demo");
        }
        else if(choice == 3)
        {
            system("./executables/trie_demo");
        }
        else if(choice == 4)
        {
            system("./executables/disjoint_set_demo");
        }
        else if(choice == 5)
        {
            system("./executables/segment_tree_demo");
        }
        else if(choice == 6)
        {
            system("./tests/run_all_tests.sh");
        }
        else
        {
            cout << "Exiting Project...\n";
            break;
        }

        cout << "\nPress Enter to Continue...";
        cin.ignore();
        cin.get();

        system("clear");
    }

    return 0;
}
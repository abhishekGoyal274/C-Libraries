#include <bits/stdc++.h>
#include "dynamic_array.h"

using namespace std;

void print_array(dynamic_array<int>& arr)
{
    cout << "Array: ";

    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{
    cout << "========== DYNAMIC ARRAY DEMO ==========\n\n";

    dynamic_array<int> arr;

    while(true)
    {
        cout << "\n";
        cout << "1. Push Back\n";
        cout << "2. Pop Back\n";
        cout << "3. Print Array\n";
        cout << "4. Size\n";
        cout << "5. Clear\n";
        cout << "6. Exit\n";

        int choice;
        cin >> choice;

        if(choice == 1)
        {
            int value;
            cout << "Enter value: ";
            cin >> value;

            arr.push_back(value);
        }
        else if(choice == 2)
        {
            arr.pop_back();
        }
        else if(choice == 3)
        {
            print_array(arr);
        }
        else if(choice == 4)
        {
            cout << "Size: " << arr.size() << endl;
        }
        else if(choice == 5)
        {
            arr.clear();
        }
        else
        {
            break;
        }
    }

    return 0;
}
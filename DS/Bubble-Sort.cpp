#include <bits/stdc++.h>

using namespace std;

void printvector(vector < int > & a) {

    for (auto i: a) cout << i << " ";
    cout << endl;
}
void bubblesort(vector < int > a) {
    int size = a.size();
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
    printvector(a);
}
void revbubblesort(vector < int > & a) {
    int size = a.size();
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (a[j] < a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
    printvector(a);
}
int main() {

    cout << "Welcome to bubble sort\n";

    cout << "Please input the size of the array of numbers to be sorted:";

    int n;
    cin >> n;

    cout << "\nPlease the numbers in the array->" << endl;

    vector < int > v;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    while (true) {
        cout << "--------------------------------------------------" << endl;
        cout << "Enter the Number of your choice of sorting" << endl;
        cout << "1. Print array in non-decreasing Order" << endl;
        cout << "2.Print array in non-increasing Order" << endl;
        cout << "3.Enter a new array" << endl;
        cout << "4.Exit the Program" << endl;
        cout << "Enter your choice:";

        int x;
        cin >> x;

        if (x == 1) {
            bubblesort(v);

        } else if (x == 2) {
            revbubblesort(v);

        } else if (x == 3) {
            cout << "\nEnter the size of the new array";
            int k;
            cin >> k;
            v.clear();
            cout << "\nPlease enter the new array";
            for (int i = 0; i < k; ++i) {
                int temp2;
                cin >> temp2;
                v.push_back(temp2);
            }

        } else if (x == 4) {
            cout << "Arigatou" << endl;

            return 0;

        }
    }
}

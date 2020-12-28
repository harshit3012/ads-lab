// In the given range [L, R], print all numbers having unique digits.
// e.g. In range 10 to 20 should print all numbers except 11.

#include <bits/stdc++.h>

#include <iostream>
using namespace std;

vector<int> worker(int l, int r) {
    vector<int> res;
    for (int i = l; i <= r; i++) {
        int num = i;
        bool visited[10] = {false};
        while (num) {
            if (visited[num % 10]) break;
            visited[num % 10] = true;
            num = num / 10;
        }
        if (num == 0) {
            res.push_back(i);
        }
    }
    return res;
}

int main() {
    int l, r;
    cout << "L = ";
    cin >> l;
    cout << "R = ";
    cin >> r;

    vector<int> res1 = worker(l, r);
    vector<int>::iterator ptr;

    cout << "The numbers with unique digits: ";
    for (ptr = res1.begin(); ptr < res1.end(); ptr++)
        cout << *ptr << " ";
    cout << endl;
    return 0;
}
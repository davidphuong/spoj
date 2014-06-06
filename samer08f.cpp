#include <iostream>
#include <vector>
using namespace std;

int main() {
    int input;
    int sum;
    vector<int> storage;

    for (int i = 1; i <= 100; i++) {
        storage.push_back(i * i);
    }

    while (cin >> input && input != 0) {
        for (int i = 0; i < input; i++) {
            sum += storage[i];
        }
        cout << sum << endl;
        sum = 0;
    }

    return 0;
}

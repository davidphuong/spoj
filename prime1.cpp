#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> prime_numbers;

void init_prime();
bool is_prime(int n);

int main() {
    // Initialize vector full of prime numbers
    init_prime();

    int cases;
    cin >> cases;

    for (int i = 0; i < cases; i++) {
        int m;
        int n;

        cin >> m;
        cin >> n;

        for (int j = m; j <= n; j++) {
            if (is_prime(j)) {
                cout << j << endl;
            }
        }

        cout << endl;
    }

    return 0;
}

void init_prime() {
    // 'max' represents all the numbers from 2
    // to max that need to be checked if the number
    // is a prime.
    int max = 31623;

    for (int i = 2; i <= max; i++) {
        if (is_prime(i)) {
            prime_numbers.push_back(i);
        }
    }
}

bool is_prime(int n) {
    if (n == 1) {
        return false;
    } else if (n == 2) {
        return true;
    } else if (n % 2 == 0) {
        // If n is even, then it is a composite number (except 2)
        return false;
    } else {
        // Test only up to sqrt(n), rounded up and use only
        // the prime factors.
        double limit = ceil(sqrt(n));

        for (vector<int>::iterator it = prime_numbers.begin(); it != prime_numbers.end(); it++) {
            if (*it > limit) {
                break;
            }

            if (n % *it == 0) {
                return false;
            }

        }

        return true;
    }
}

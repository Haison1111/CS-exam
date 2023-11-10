#include <iostream>
#include <queue>
#include <vector>

bool isPrime(int num) {
    if (num < 2) {
        return false;
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

bool isSuperPrime(int num) {
    if (!isPrime(num)) {
        return false;
    }

    int temp = num;
    while (temp > 0) {
        temp /= 10;
        if (!isPrime(temp)) {
            return false;
        }
    }

    return true;
}

void superPrimeNumber(int n) {
    std::queue<int> superPrimes;
    std::vector<int> result;

    // Thêm số 2 vào hàng đợi ban đầu
    superPrimes.push(2);

    while (!superPrimes.empty()) {
        int current = superPrimes.front();
        superPrimes.pop();

        if (current <= n) {
            if (isSuperPrime(current)) {
                result.push_back(current);

                // Thêm các số siêu nguyên tố mới vào hàng đợi
                for (int digit = 1; digit <= 9; digit++) {
                    int next = current * 10 + digit;
                    if (next <= n) {
                        superPrimes.push(next);
                    }
                }
            }
        } else {
            break;
        }
    }

    // In ra dãy số siêu nguyên tố
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
}

int main() {
    int n ;

    std::cout << "Nhap so n: ";
    std::cin >> n;

    std::cout << "Cac so sieu nguyen to <= " << n << " la: ";
    superPrimeNumber(n);

    return 0;
}
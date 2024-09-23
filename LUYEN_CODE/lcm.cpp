#include <iostream>
#include <vector>
#include <numeric>

int main() {
    int n;
    std::cout << "Nh?p s? lu?ng s? trong dãy: ";
    std::cin >> n;

    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cout << "Nh?p s? th? " << i + 1 << ": ";
        std::cin >> numbers[i];
    }

    int lcm = std::accumulate(numbers.begin(), numbers.end(), 1, std::lcm);

    std::cout << "B?i chung nh? nh?t c?a dãy s? là: " << lcm << std::endl;

    return 0;
}

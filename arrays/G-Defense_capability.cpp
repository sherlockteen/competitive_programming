#include <iostream>
#include <vector>
#include <numeric>


int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> kingdom(n, std::vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> kingdom[i][j];
        }
    }
    if (n == 1) {
        std::cout << kingdom[0][0];
        return 0;
    }

    int defenseCapability = std::accumulate(kingdom.begin(), kingdom.end(), 0, [](int accumulated,const std::vector<int>& inner) {
        return accumulated + std::accumulate(inner.begin(), inner.end(), 0);
    });

    defenseCapability -= std::accumulate(kingdom.begin() + 1, kingdom.end() - 1, 0, [](int accumulated, const std::vector<int>& inner) {
        return accumulated + std::accumulate(inner.begin() + 1, inner.end() - 1, 0);
    });

    std::cout << defenseCapability;


    return 0;
}

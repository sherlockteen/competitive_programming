#include <iostream>
#include <vector>
#include <functional>

template<typename T>
void print_array(std::vector<T>& arr) {
    for (const auto& el : arr) std::cout << el << " ";
    std::cout << '\n';
}


template<typename T, typename Compare = std::greater<T>>
void sift_down(std::vector<T>& data, size_t i, size_t heap_size, Compare comp) {
    while (true) {
        size_t left = 2 * i + 1;
        size_t right = 2 * i + 2;
        size_t largest = i;
        if (left < heap_size && comp(data[left], data[largest])) {
            largest = left;
        }

        if (right < heap_size && comp(data[right], data[largest])) {
            largest = right;
        }

        if (largest == i) break; // уже находится на правильном месте.

        std::swap(data[i], data[largest]);
        i = largest;
    }
}

template<typename T, typename Compare = std::greater<T>>
void heap_sort(std::vector<T>& arr, Compare comp) {
    size_t n = arr.size();

    // Построение кучи
    for (int i = static_cast<int>(n / 2 - 1); i >= 0; --i) {
        sift_down(arr,i, n, comp);
        std::cout << "heap: ";
        print_array(arr);

    }
   // сортировка
    for (size_t end = n; end > 1 ; --end) {
        std::swap(arr[0], arr[end - 1]);
        sift_down(arr, 0, end - 1, comp);

    }
}


int main() {
    std::vector<int> arr{132,123,1,2541,75,766,756,85323,42342,2234,423,2};
    for (auto& el : arr) {
        std::cout << el << " ";
    }
    std::cout << "\n\n";

    heap_sort(arr, std::greater<>());

    for (auto& el : arr) {
        std::cout << el << " ";
    }

    return 0;
}

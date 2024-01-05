#include <iostream>
#include <vector>

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Выбираем последний элемент в качестве опорного
    int i = low - 1; // Индекс меньшего элемента

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Функция быстрой сортировки
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // arr[pi] находится на правильной позиции
        int pi = partition(arr, low, high);

        // Рекурсивно сортируем элементы перед и после опорного элемента
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int
main()
{
    int num;
    std::cin >> num;
    std::vector<int> vec(num);
    for (int i = 0; i < num; ++i) {
        std::cin >> vec[i];
    }
    quickSort(vec, 0, num - 1);
    for (int i = 0; i < num; ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}
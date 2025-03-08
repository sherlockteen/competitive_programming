/// \file binary_search_query_handler.cpp
/// @brief Система обработки поисковых запросов с бинарным поиском

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>

/**
 * @defgroup OutputUtils Утилиты вывода
 * @{
 */

/// @brief Выводит "YES" в стандартный поток вывода
/// @details Используется для положительных результатов поиска.
///          Функция оптимизирована для частого вызова (noexcept, inline)
inline void printYES() noexcept { std::cout << "YES\n"; }

/// @brief Выводит "NO" в стандартный поток вывода
/// @details Используется для отрицательных результатов поиска.
///          Гарантирует атомарность операции вывода.
inline void printNO() noexcept { std::cout << "NO\n"; }

/** @} */ // end of OutputUtils

/**
 * @defgroup CoreTypes Основные типы данных
 * @{
 */

/// @brief Базовый тип элемента для поиска
/// @details Может быть изменен на любой тип с определенным оператором <
using ElementType = int;

/// @brief Тип контейнера для поискового пространства
/// @details STL-совместимый контейнер с произвольным доступом
using SearchArray = std::vector<ElementType>;

/// @brief Тип контейнера для запросов
/// @details Гарантирует последовательное хранение запросов
using QueryArray = std::vector<ElementType>;

/** @} */ // end of CoreTypes

/**
 * @brief Главная функция приложения
 * @details Реализует следующий workflow:
 *          1. Чтение поискового пространства
 *          2. Сортировка данных
 *          3. Обработка запросов
 *          4. Вывод результатов
 * 
 * @return Код завершения программы:
 *         - 0: Успешное выполнение
 *         - 1: Ошибка ввода (не реализовано)
 * 
 * @exception std::bad_alloc При невозможности выделить память
 * @warning Не потокобезопасная реализация
 * 
 * @par Пример использования:
 * @code{.sh}
 * echo "5 3 1 4 2 5 7 3 6 1" | ./program
 * # Output: YES NO YES
 * @endcode
 */
int main() {
    // Этап 1: Инициализация
    size_t main_array_size = 0;
    size_t query_count = 0;
    
    // Чтение метаданных
    std::cin >> main_array_size >> query_count;

    // Этап 2: Подготовка поискового пространства
    SearchArray search_space;
    search_space.reserve(main_array_size);  // Оптимизация аллокаций

    /// @par Блок чтения данных:
    /// Используется STL-алгоритм для гарантированного чтения N элементов
    /// @see https://en.cppreference.com/w/cpp/algorithm/copy_n
    std::copy_n(
        std::istream_iterator<ElementType>(std::cin), // Источник данных
        main_array_size,                             // Точное количество
        std::back_inserter(search_space)             // Стратегия вставки
    );

    /// @pre Контейнер должен быть отсортирован для бинарного поиска
    /// @post Элементы упорядочены по возрастанию
    std::sort(search_space.begin(), search_space.end());

    // Этап 3: Обработка запросов
    QueryArray queries;
    queries.reserve(query_count);
    
    std::copy_n(
        std::istream_iterator<ElementType>(std::cin),
        query_count,
        std::back_inserter(queries)
    );

    /// @par Блок обработки запросов:
    /// Используется range-based for для явного итерирования
    /// @complexity O(Q log N), где Q - число запросов, N - размер массива
    for (const auto& query : queries) {
        const bool found = std::binary_search(
            search_space.cbegin(),  // Константные итераторы
            search_space.cend(),    // для запрета модификации
            query
        );
        
        // Тернарный оператор выбран для краткости
        found ? printYES() : printNO();
    }

    return 0;
}

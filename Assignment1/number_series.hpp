/// Created by Marius Mikucionis <marius@cs.aau.dk>
/**
 * Definitions of number_series and number_series_wrap classes.
 */

#ifndef INCLUDE_NUMBER_SERIES_H
#define INCLUDE_NUMBER_SERIES_H

#include <vector>
#include <limits>
#include <memory>
#include <iostream>

namespace data_series
{
    class number_series
    {
        std::vector<int> numbers;
        int min = std::numeric_limits<int>::max();
        int max = std::numeric_limits<int>::min();
        int dummy[1000];
    public:
        number_series();
        explicit number_series(unsigned long size);
        number_series(std::initializer_list<int> values);
        void add_value(int value);
        unsigned long size() const;
        int get_min() const;
        int get_max() const;
        std::vector<int> get_numbers() const;
        static number_series make_random(int size);
        number_series operator+(const number_series& other) const;
        number_series& operator+=(const number_series& other);
        [[nodiscard]] int amplitude() const;
        bool operator<(const number_series& other) const;
        bool operator>(const number_series& other) const;
    };

    class number_series_wrap
    {
        number_series_wrap(const number_series& series);

        std::unique_ptr<number_series> ns;
    public:
        number_series_wrap();
        number_series_wrap(std::initializer_list<int> values);
        void add_value(int value);
        unsigned long size() const;
        int get_min() const;
        int get_max() const;
        static number_series_wrap make_random(int size);
        number_series_wrap operator+(const number_series_wrap& other) const;
        number_series_wrap& operator+=(const number_series_wrap& other);
        bool operator<(const number_series_wrap& other) const;
        bool operator>(const number_series_wrap& other) const;
        number_series_wrap(const number_series_wrap &other);
        number_series_wrap& operator=(number_series_wrap&& other) noexcept;
        [[nodiscard]] int amplitude() const;
        };

}  // namespace data_series

#endif  // INCLUDE_NUMBER_SERIES_H

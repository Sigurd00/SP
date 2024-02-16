/// Created by Marius Mikucionis <marius@cs.aau.dk>
/**
 * Definitions/implementation of some number_series methods
 */

#include <random>
#include "number_series.hpp"
#include "algorithm"
namespace data_series
{
    number_series::number_series() = default;

    number_series::number_series(unsigned long size) {
        numbers.reserve(size);
    }
    number_series::number_series(const std::initializer_list<int> values) {
        numbers = values;
        auto pair = std::minmax_element(numbers.begin(), numbers.end());
        min = *pair.first;
        max = *pair.second;
    };

    void number_series::add_value(int value) {
        numbers.push_back(value);
        min = std::min(min, value);
        max = std::max(max, value);
    }

    unsigned long number_series::size() const {
        return numbers.size();
    }

    int number_series::get_max() const {
        return max;
    }

    int number_series::get_min() const {
        return min;
    }

    number_series number_series::make_random(int size) {
        std::random_device rd;  // a seed source for the random number engine
        std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
        std::uniform_int_distribution<> distrib(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());

        // Use distrib to transform the random unsigned int
        auto ns = number_series{};
        for (int n = 0; n != size; ++n)
            ns.add_value(distrib(gen));

        return ns;
    }

    number_series number_series::operator+(const number_series& other) const {
        auto ns = number_series(std::max(this->size(), other.size()));

        for (int i = 0; i < this->size() || i < other.size(); i++) {
            if (i < this->size() && i < other.size()) {
                ns.add_value(this->numbers[i] + other.numbers[i]);
            } else if ( i < this->size()) {
                ns.add_value(this->numbers[i]);
            } else {
                ns.add_value(other.numbers[i]);
            }
        }
        return ns;
    }

    //For my own test
    std::vector<int> number_series::get_numbers() const {
        return this->numbers;
    }

    number_series& number_series::operator+=(const number_series &other) {
        //delegate to + operator
        auto ns = number_series::operator+(other);
        this->numbers = ns.numbers;
        this->min = ns.min;
        this->max = ns.max;
        return *this;
    }

    int number_series::amplitude() const {
        return max - min;
    }

    bool number_series::operator<(const number_series &other) const {
        return this->amplitude() < other.amplitude();
    }

    bool number_series::operator>(const number_series &other) const {
        return this->amplitude() > other.amplitude();
    }

    number_series_wrap::number_series_wrap() = default;

}  // namespace data_series

#include <iostream>
#include <limits>
#include <chrono>
#include <vector>
#include <random>
using namespace std::chrono;
using namespace std;

// Region -- exercise 1
void exercise1() {
    char a = 'a';
    bool b = false;
    cout << a << endl;
    cout << boolalpha << b << endl;
    cout << sizeof(a) << endl;
    cout << sizeof(b) << endl;
    cout << "bool min" << numeric_limits<bool>::max() << endl;
    cout << "bool max" << numeric_limits<bool>::min() << endl;
    cout << "char min" << numeric_limits<char>::max() << endl;
    cout << "char max" << numeric_limits<char>::min() << endl;
}
// End region -- exercise 1

// Region -- exercise 2
union asdf {
        float a;
        unsigned int b;
        char* c[4];
};

void exercise2() {
    //This seg faullts for some reason
    asdf myunion;
    myunion.b = 42069;
    for(int i = 0; i < 4; i++) {
        cout << "char " << i << myunion.c[i] << endl;
    }
}
// End region -- exercise 2

// Region -- exercise 3
double max1(double *a, double *b) {
    return *a < *b ? *b : *a;
}

double max2(double &a, double &b) { 
    return a < b ? b : a;
}

double max3(const double &a, const double &b) { // Const = The function never changes the value of a and b
    return a < b ? b : a; 
}

double max5(double*& a, double*& b) {
    return (*a) < (*b) ? (*b) : (*a);
}

double max6(const double*& a, const double*& b) {
    return (*a) < (*b) ? (*b) : (*a);
}


void exercise3(){
    double a = 5.12;
    double b = 10.40;
    cout << max1(&a, &b) << endl;
    cout << max2(a, b) << endl;
    cout << max3(a, b) << endl;
    //case 4: double* ptr_to_ref = &a; // Attempting to declare a pointer to reference (this will not compile)
    double* ptr_to_a = &a;
    double* ptr_to_b = &b;
    cout << max5(ptr_to_a, ptr_to_b) << endl;
    const double* const_ptr_to_a = &a;
    const double* const_ptr_to_b = &b;
    cout << max6(const_ptr_to_a, const_ptr_to_b) << endl;
}
// End region -- exercise 3

// Region -- exercise 4
class BenchmarkUtility {
    vector<pair<string, double>> benchmarks;
public:
    BenchmarkUtility() = default;
    void bench(void (*func) (), string funcName) {
        auto t0 = high_resolution_clock::now();
        func();
        auto t1 = high_resolution_clock::now();
        double time = duration<double, std::milli>(t1-t0).count();
        benchmarks.push_back(make_pair(funcName, time));
    }
    void print_benches() {
        for (const auto& pair : benchmarks) {
            cout << "Benchmark: " << pair.first << ", Time: " << pair.second << "ms" << endl;
        }
    }
    vector<pair<string, double>> get_benchmarks() const {
        return benchmarks;
    }
};

void exercise4(){
    BenchmarkUtility benchmarks = BenchmarkUtility();
    benchmarks.bench(exercise3, "exercise3");
    benchmarks.print_benches();
}
// End region -- exercise 4

// Region -- exercise 5
void gen_mt19937() {
    // Seed for random number generator
    std::random_device rd;
    // Initialize Mersenne Twister engine
    std::mt19937 gen(rd());
    // Define distribution for real numbers in [0, 1000)
    std::uniform_real_distribution<double> dist(0.0, 1000.0);

    // Number of random numbers to generate
    const int numRandomNumbers = 10000000;

    // Vector to store the random numbers
    vector<double> randomNumbers;
    randomNumbers.reserve(numRandomNumbers);

    // Generate random numbers
    for (int i = 0; i < numRandomNumbers; ++i) {
        randomNumbers.push_back(dist(gen));
    }
}

void exercise5(){
    BenchmarkUtility benchmarks = BenchmarkUtility();
    benchmarks.bench(gen_mt19937, "mt19937");
    benchmarks.print_benches();
}
// End region -- exercise 5

int main() {
    cout << "exercise1" << endl;
    exercise1();
    cout << "exercise2" << endl;
    //exercise2();
    cout << "exercise2 end" << endl;
    cout << "exercise3" << endl;
    exercise3();
    cout << "exercise4" << endl;
    exercise4();
    cout << "exercise5" << endl;
    exercise5();


}
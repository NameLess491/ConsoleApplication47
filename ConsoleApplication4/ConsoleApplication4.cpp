//Клас String
#include <iostream>
#include <cstring>
using namespace std;
class String {
private:
    char* str;
    size_t length;
public:
    String(const char* s = "") {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }
    ~String() {
        delete[] str;
    }
    String operator+(const String& other) const {
        size_t newLength = length + other.length;
        char* newStr = new char[newLength + 1];
        strcpy(newStr, str);
        strcat(newStr, other.str);
        return String(newStr);
    }
    String& operator=(const String& other) {
        if (this != &other) {
            delete[] str;
            length = other.length;
            str = new char[length + 1];
            strcpy(str, other.str);
        }
        return *this;
    }
    void display() const {
        cout << str << endl;
    }
};
//Клас Array
#include <iostream>
using namespace std;
class Array {
private:
    int* arr;
    size_t size;

public:
    Array(size_t s = 0) : size(s) {
        arr = new int[size]();
    }
    ~Array() {
        delete[] arr;
    }
    Array operator+(const Array& other) const {
        Array newArray(size + other.size);
        for (size_t i = 0; i < size; i++) {
            newArray.arr[i] = arr[i];
        }
        for (size_t i = 0; i < other.size; i++) {
            newArray.arr[size + i] = other.arr[i];
        }
        return newArray;
    }
    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] arr;
            size = other.size;
            arr = new int[size];
            for (size_t i = 0; i < size; i++) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }
    int& operator[](size_t index) {
        if (index >= size) {
            throw out_of_range("Index out of range");
        }
        return arr[index];
    }
    void display() const {
        for (size_t i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
//Клас Point
#include <iostream>
using namespace std;
class Point {
private:
    int x, y;
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }
    Point operator-(const Point& other) const {
        return Point(x - other.x, y - other.y);
    }
    Point operator*(int scalar) const {
        return Point(x * scalar, y * scalar);
    }
    Point operator/(int scalar) const {
        if (scalar == 0) throw invalid_argument("Division by zero");
        return Point(x / scalar, y / scalar);
    }
    void display() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};
//Клас Fraction
#include <iostream>
using namespace std;
class Fraction {
private:
    int numerator, denominator;
    void simplify() {
        int gcd = __gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }
public:
    Fraction(int n = 0, int d = 1) : numerator(n), denominator(d) {
        if (denominator == 0) throw invalid_argument("Denominator cannot be zero");
        simplify();
    }
    Fraction operator+(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
    }
    Fraction operator-(const Fraction& other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
    }
    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }
    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) throw invalid_argument("Division by zero");
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }
    void display() const {
        cout << numerator << "/" << denominator << endl;
    }
};
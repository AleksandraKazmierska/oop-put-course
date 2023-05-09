#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

class LogarithmException : public exception {
public:
  LogarithmException(const string& message) : message_(message) {}
    const char* what() const noexcept override {
        return message_.c_str();
    }
private:
    string message_;
};

class InvalidBaseException : public LogarithmException {
    public:
        InvalidBaseException() : LogarithmException("base must be greater than 0.") {}
};

class InvalidNumberException : public LogarithmException {
    public:
        InvalidNumberException() : LogarithmException("number must be greater than 0.") {}
};

class UndefinedResultException : public LogarithmException {
    public:
        UndefinedResultException() : LogarithmException("base and number cannot both be 1.") {}
};

class Logarithm {
    public:
        Logarithm(double base, double number) : base_(base), number_(number) {}
        double Calculate() const
        {
            if (base_ <= 0)
            {
                throw InvalidBaseException();
            }
            if (number_ <= 0) {
                throw InvalidNumberException();
        }
            if (base_ == 1 && number_ == 1) {
                throw UndefinedResultException();
        }
        return log(number_) / log(base_);
    }
private:
    double base_;
    double number_;
};

int main() {
    double base, number;
    cout << "Enter the base: ";
    cin >> base;
    cout << "Enter the number: ";
    cin >> number;
    try {
        Logarithm log(base, number);
        double result = log.Calculate();
        cout << "The logarito the base" << base << " is: " << result << endl;
    }
    catch (const LogarithmException& ex) {
            cout << "Error: " << ex.what() << endl;
            return 1;
    }
    return 0;
}

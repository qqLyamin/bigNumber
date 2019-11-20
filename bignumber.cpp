#include "bignumber.h"
#include <QDebug>

bigNumber::bigNumber(const QString & income)
{
    memset(arr, 0, SIZE_OF_ARRAY * sizeof(short));
    bool isValid = true;
    if (income[0] == '0' && income.length() > 1) isValid = false;
    if (isValid) {
        for (int i = 0; i < income.length(); ++i) {
            if (!income[i].isNumber()) {
                isValid = false;
            }
        }
    }
    if (isValid) {
        short outputIndex = 0;
        int length = income.length();
        QString tmpNumber;
        while ( length > 0 ) {
            for (int i = 0; i < 4 ; ++i, --length) {
                if (length == 0) break;
                tmpNumber += income[length - 1];
            }
            invert_string(tmpNumber);
            arr[outputIndex] = tmpNumber.toShort();
            outputIndex++;
            tmpNumber = "";
        }
        currentSize = outputIndex;
    } else {
        currentSize = 1;
    }
}

bigNumber & bigNumber::operator+(const bigNumber & other)
{
    int saturation = 0;
    short maxSize;
    bool isNegativeAnswer = false;
    maxSize = currentSize > other.currentSize ? currentSize : other.currentSize;

    if (this->isPositive() && other.isPositive()) {
        for ( int i = 0 ; i < maxSize; ++i ) {
            short tmp = arr[i];
            this->arr[i] = (arr[i] + other.arr[i] + saturation) % 10000;
            saturation = (tmp + other.arr[i] + saturation) / 10000;
            isNegativeAnswer = false;
        }
    }

    if (this->isNegative() && other.isNegative()) {
        for ( int i = 0 ; i < maxSize; ++i ) {
            short tmp = arr[i];
            this->arr[i] = (arr[i] + other.arr[i] + saturation) % 10000;
            saturation = (tmp + other.arr[i] + saturation) / 10000;
            isNegativeAnswer = true;
        }
    }

    if (this->isPositive() && other.isNegative()) {
        for ( int i = 0 ; i < maxSize; ++i ) {
            short tmp = arr[i];
            if (*this ->* other) {
                if (arr[i] > other.arr[i]) {
                    this->arr[i] = (arr[i] - other.arr[i]) % 10000;
                } else {
                    this->arr[i] = (10000 + arr[i] - other.arr[i]) % 10000;
                    this->arr[i + 1] -= 1;
                }
                isNegativeAnswer = false;
            } else {
                if (arr[i] < other.arr[i]) {
                    this->arr[i] = (other.arr[i] - arr[i]) % 10000;
                } else {
                    this->arr[i] = (10000 + other.arr[i] - arr[i]) % 10000;
                    this->arr[i + 1] -= 1;
                }
                isNegativeAnswer = true;
            }
        }
    }

    if (this->isNegative() && other.isPositive()) {
        for ( int i = 0 ; i < maxSize; ++i ) {
            short tmp = arr[i];
            if (!(*this ->* other)) {
                if (arr[i] < other.arr[i]) {
                    this->arr[i] = (other.arr[i] - arr[i]) % 10000;
                } else {
                    this->arr[i] = (10000 + other.arr[i] - arr[i]) % 10000;
                    this->arr[i + 1] += 1;
                }
                isNegativeAnswer = false;
            } else {
                if (arr[i] < other.arr[i]) {
                    this->arr[i] = (other.arr[i] - arr[i]) % 10000;
                } else {
                    this->arr[i] = (10000 + other.arr[i] - arr[i]) % 10000;
                    this->arr[i + 1] += 1;
                }
                isNegativeAnswer = true;
            }

        }
    }

    currentSize = maxSize;
    if (saturation) {
        arr[maxSize] = 1;
        currentSize += 1;
    }

    if (isNegativeAnswer) {
        this->setNegative();
    } else {
        this->setPositive();
    }

    return * this;
}

bigNumber & bigNumber::operator=(const bigNumber & other)
{
    currentSize = other.currentSize;
    for (int i = 0; i < currentSize; ++i) {
        arr[i] = other.arr[i];
    }
    return * this;
}

bool bigNumber::operator->*(const bigNumber & other)//thats MOD operator >
{
    if (this->currentSize == other.currentSize) {
        for (int i = currentSize - 1; i > 0; --i) {
            if (this->arr[currentSize - 1] == other.arr[currentSize - 1]) continue;
            return this->arr[currentSize - 1] > other.arr[currentSize - 1];
        }
    } else {
        return this->currentSize > other.currentSize;
    }
}

bool bigNumber::operator>(const bigNumber &other)
{

    if (this->currentSize > other.currentSize && this->isPositive() && other.isPositive()) return true;
    if (this->currentSize > other.currentSize && this->isNegative() && other.isPositive()) return false;
    if (this->currentSize < other.currentSize && this->isPositive() && other.isPositive()) return false;
    if (this->currentSize < other.currentSize && this->isPositive() && other.isNegative()) return true;


    if (this->currentSize == other.currentSize && this->isNegative() && other.isNegative()) {
        if (this->arr[currentSize - 1] > other.arr[currentSize - 1])
            return false;
        return true;
    }

    if (this->currentSize == other.currentSize && this->isPositive() && other.isPositive()) {
        if (this->arr[currentSize - 1] > other.arr[currentSize - 1])
            return true;
        return false;
    }
}

short bigNumber::getSize() const
{
    return currentSize;
}

bool bigNumber::isNegative() const
{
    return Negative;
}

bool bigNumber::isPositive() const
{
    return !Negative;
}

void bigNumber::setNegative()
{
    this->Negative = true;
}

void bigNumber::setPositive()
{
    this->Negative = false;
}

std::ostream& operator<< (std::ostream &out, const bigNumber & number) {
    if (number.isNegative()) out << "-";
    out << number.arr[number.currentSize - 1];
    for (int i = number.currentSize - 2; i >= 0; --i) {
        if (number.arr[i] < 1000) {
            out << "0";
        }
        if (number.arr[i] < 100) {
            out << "0";
        }
        if (number.arr[i] < 10) {
            out << "0";
        }
        out << number.arr[i];
    }
    return out;
}

bool operator==(const bigNumber &left, const bigNumber &right)
{
    if (left.currentSize == right.currentSize) {
        for (int i = 0; i < right.currentSize; ++i) {
            if (left.arr[i] != right.arr[i]) return false;
        }
    } else {
        return false;
    }

    return true;
}

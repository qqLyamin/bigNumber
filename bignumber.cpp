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
        int outputIndex = 0;
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
    int maxSize;
    maxSize = currentSize > other.currentSize ? currentSize : other.currentSize;

    if (currentSize == 1 && arr[0] == 0) {
        for (int i = 0; i < other.currentSize; ++i) {
            this->arr[i] = other.arr[i];
        }
        currentSize = other.currentSize;
        return * this;
    }

    if (other.currentSize == 1 && other.arr[0] == 0) {
        return * this;
    }

    for ( int i = 0 ; i < maxSize; ++i ) {
        short tmp = arr[i];
        this->arr[i] = (arr[i] + other.arr[i] + saturation) % 10000;
        saturation = (tmp + other.arr[i] + saturation) / 10000;
    }

    currentSize = maxSize;
    if (saturation) {
        arr[maxSize] = 1;
        currentSize += 1;
    }

    return * this;
}

bigNumber &bigNumber::operator=(const bigNumber & other)
{
    currentSize = other.currentSize;
    for (int i = 0; i < currentSize; ++i) {
        arr[i] = other.arr[i];
    }
    return * this;
}

short bigNumber::getSize()
{
    return currentSize;
}

std::ostream& operator<< (std::ostream &out, const bigNumber & number) {
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

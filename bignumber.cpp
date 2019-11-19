#include "bignumber.h"
#include <QDebug>

bigNumber::bigNumber(const QString & income)
{
    int outputIndex = 0;
    int LENGTH = income.length();
    QString tmpNumber;
    while ( LENGTH > 0 ) {
        for (int i = 0; i < 4 ; ++i, --LENGTH) {
            if (LENGTH == 0) break;
            tmpNumber += income[LENGTH - 1];
        }
        invert_string(tmpNumber);
        arr[outputIndex] = tmpNumber.toShort();
        outputIndex++;
        tmpNumber = "";
    }
    currentSize = outputIndex;
}

bigNumber & bigNumber::operator+(const bigNumber & other)
{
    bool saturation = false;
    int SIZE;
    SIZE = currentSize > other.currentSize ? currentSize : other.currentSize;

    for ( int i = 0 ; i < SIZE; ++i) {
        if ( arr[i] + other.arr[i] > 9999 || (saturation == true && arr[i] + other.arr[i] > 9998) ) {
            saturation = true;
        } else {
            saturation = false;
        }
        this->arr[i] = (arr[i] + other.arr[i]) % 10000;
        if (saturation) this->arr[i] += 1;
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
    for (int i = number.currentSize - 1; i >= 0; --i) {
        out << number.arr[i];
    }
    return out;
}

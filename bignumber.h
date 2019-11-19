#ifndef BIGNUMBER_H
#define BIGNUMBER_H

#include <QString>

typedef unsigned int quint;

#define MAX_CHAR 512 //максимум знаков в числе
#define BIG_BASE 10000 //база счисления(на ячейку)
#define SIZE_OF_ARRAY MAX_CHAR/2 //10000 - short

template <typename T>
void invert_string( T & tmp ) {
    int size = tmp.length();
    QChar tmpChar;
    for ( int i = 0; i < size / 2; ++i ) {
        tmpChar = tmp[i];
        tmp[i] = tmp[size - i - 1];
        tmp[size - i - 1] = tmpChar;
    }
}

class bigNumber
{
    short arr[SIZE_OF_ARRAY];
    short currentSize = 0;
    quint sizeOfInt = sizeof(int);
public:
    bigNumber(){
        memset(arr, 0, SIZE_OF_ARRAY);
    }
    bigNumber(const QString & income);

    bigNumber & operator+(const bigNumber & other);
    bigNumber & operator=(const bigNumber & other);

    friend std::ostream & operator<< (std::ostream &out, const bigNumber & number);
    short getSize();
};

#endif // BIGNUMBER_H

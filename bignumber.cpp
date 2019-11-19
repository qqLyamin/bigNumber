#include "bignumber.h"
#include <QDebug>

bigNumber::bigNumber(const QString & income)
{
    int outputIndex = 0;
    int LENGTH = income.length() - 1;
    QString tmpNumber;
    while ( LENGTH > 0 ) {
        for (int i = 0; i < 4; ++i, --LENGTH) {
            tmpNumber += income[LENGTH];
        }
        invert_string(tmpNumber);
        arr[outputIndex] = tmpNumber.toShort();
        outputIndex++;
        tmpNumber = "";
    }
}

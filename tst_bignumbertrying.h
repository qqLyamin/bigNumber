#include <QtTest/QTest>
#include <QString>
#include <iostream>

#include "bignumber.h"
#include "bisumms.h"

class bigNumberTrying : public QObject
{
    Q_OBJECT

    int a;
public:
    bigNumberTrying();

private slots:
    void targetCase();
    void targetCase2();

    void caseOfMinus1();

    void caseOfTwoSameNumbers();
    void caseOfTwoSameNumbersWithDifferentSign();
    void caseOfTwoSameNumbersWithDifferentSign2();

    void caseOfTwoSameNumbersWithDifferentSignSwitched();
    void caseOfTwoSameNumbersWithDifferentSignSwitched2();

    void caseWithZeros();
    void caseWithWrongNumbers();

    void caseWithFirstNegative();
    void caseWithSecondNegative();

    void caseTwoBigNegative();
    void caseTwoBigPositive();

    void caseWithNegativeSignFirst();
    void caseWithNegativeSignSecond();
    void caseWithNegativeSignBoth();

    void caseWithFirstBigNegative();
    void caseWithSecondBigNegative();
    void caseWithNegativeSignBothBig();

    void caseWrongMinus();
};

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
    void caseOfTwoSameNumbers();
    void caseWithZeros();
//    void caseWithNegative();
    void caseWithWrongNumbers();
};

//QTEST_APPLESS_MAIN(bigNumberTrying)

//#include "tst_bignumbertrying.moc"

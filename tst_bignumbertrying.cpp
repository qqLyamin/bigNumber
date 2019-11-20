#include "tst_bignumbertrying.h"

bigNumberTrying::bigNumberTrying()
{
    a = 1;
}

void bigNumberTrying::caseOfTwoSameNumbers()
{
    bigNumber A = bigNumber("11111");
    bigNumber B = bigNumber("11111");
    bigNumber result = bigNumber("22222");
    biSumms test = biSumms();

    QCOMPARE(test.getSumm(A, B), result);
}

void bigNumberTrying::caseWithZeros()
{
    bigNumber A = bigNumber("0");
    bigNumber B = bigNumber("0");
    bigNumber result = bigNumber("0");
    biSumms test = biSumms();

    QCOMPARE(test.getSumm(A, B), result);
}

void bigNumberTrying::caseWithWrongNumbers()
{

    bigNumber A = bigNumber("9dfg9");
    bigNumber B = bigNumber("016");
    bigNumber result = bigNumber("0");
    biSumms test = biSumms();

    QCOMPARE(test.getSumm(A, B), result);
}

void bigNumberTrying::caseWithNegative()
{
    bigNumber A = bigNumber("1");
    bigNumber B = bigNumber("-5");
    bigNumber result = bigNumber("-4");
    biSumms test = biSumms();

    QCOMPARE(test.getSumm(A, B), result);
}

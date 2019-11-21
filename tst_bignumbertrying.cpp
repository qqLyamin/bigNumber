#include "tst_bignumbertrying.h"

bigNumberTrying::bigNumberTrying()
{
    a = 1;
}

void bigNumberTrying::targetCase()
{
    bigNumber A = bigNumber("-11112");
    bigNumber B = bigNumber("11111");
    bigNumber result = bigNumber("1");
    result.setNegative();
    biSumms test = biSumms();

    QCOMPARE(test.getSumm(A, B), result);
}

void bigNumberTrying::targetCase2()
{
    bigNumber A = bigNumber("-21212");
    bigNumber B = bigNumber("11212");
    bigNumber result = bigNumber("10000");
    result.setNegative();
    biSumms test = biSumms();

    QCOMPARE(test.getSumm(A, B), result);
}

void bigNumberTrying::caseOfMinus1()
{
    bigNumber A = bigNumber("-1");
    bigNumber B = bigNumber("100000000");
    bigNumber result = bigNumber("99999999");
    biSumms test = biSumms();

    QCOMPARE(test.getSumm(A, B), result);
}

void bigNumberTrying::caseOfTwoSameNumbers()
{
    bigNumber A = bigNumber("11111");
    bigNumber B = bigNumber("11111");
    bigNumber result = bigNumber("22222");
    biSumms test = biSumms();

    QCOMPARE(test.getSumm(A, B), result);
}

void bigNumberTrying::caseOfTwoSameNumbersWithDifferentSign()
{
    bigNumber A = bigNumber("11111");
    bigNumber B = bigNumber("-11111");
    bigNumber result = bigNumber("0");
    biSumms test = biSumms();

    QCOMPARE(test.getSumm(A, B), result);
}

void bigNumberTrying::caseOfTwoSameNumbersWithDifferentSign2()
{
    bigNumber A = bigNumber("32543274572354723");
    bigNumber B = bigNumber("-32543274572354723");
    bigNumber result = bigNumber("0");
    biSumms test = biSumms();

    QCOMPARE(test.getSumm(A, B), result);
}

void bigNumberTrying::caseOfTwoSameNumbersWithDifferentSignSwitched()
{
    bigNumber A = bigNumber("-11111");
    bigNumber B = bigNumber("11111");
    bigNumber result = bigNumber("0");
    biSumms test = biSumms();

    QCOMPARE(test.getSumm(A, B), result);
}

void bigNumberTrying::caseOfTwoSameNumbersWithDifferentSignSwitched2()
{
    bigNumber A = bigNumber("-32543274572354723");
    bigNumber B = bigNumber("32543274572354723");
    bigNumber result = bigNumber("0");
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

void bigNumberTrying::caseWithFirstNegative()
{
    bigNumber A = bigNumber("7");
    A.setNegative();
    bigNumber B = bigNumber("5");
    bigNumber result = bigNumber("2");
    result.setNegative();
    biSumms test = biSumms();

    QCOMPARE(test.getSumm(A, B), result);
}

void bigNumberTrying::caseWithSecondNegative()
{
    bigNumber A = bigNumber("1");
    bigNumber B = bigNumber("5");
    B.setNegative();
    bigNumber result = bigNumber("4");
    result.setNegative();
    biSumms test = biSumms();

    QCOMPARE(test.getSumm(A, B), result);
}

void bigNumberTrying::caseWithFirstBigNegative()
{
    bigNumber A = bigNumber("154678365873287462387648723468723648237648");
    A.setNegative();
    bigNumber B = bigNumber("5");
    bigNumber result = bigNumber("154678365873287462387648723468723648237643");
    result.setNegative();
    biSumms test = biSumms();

    QCOMPARE(test.getSumm(A, B), result);
}

void bigNumberTrying::caseWithSecondBigNegative()
{
    bigNumber A = bigNumber("5");
    bigNumber B = bigNumber("154678365873287462387648723468723648237648");
    B.setNegative();
    bigNumber result = bigNumber("154678365873287462387648723468723648237643");
    result.setNegative();
    biSumms test = biSumms();

    QCOMPARE(test.getSumm(A, B), result);
}

void bigNumberTrying::caseWithNegativeSignBothBig()
{
    bigNumber A = bigNumber("-5123456234237423757635472354273234234234234234234");
    bigNumber B = bigNumber("-154678365873287462387648723468723648237648");
    bigNumber result = bigNumber("5123456388915789630922934741921957702957882471882");
    result.setNegative();
    biSumms test = biSumms();

    QCOMPARE(test.getSumm(A, B), result);
}

void bigNumberTrying::caseWrongMinus()
{
    bigNumber A = bigNumber("5123456234237423757635472354-273234234234234234234");
    bigNumber B = bigNumber("-154678365873287462387648723468723648237648");
    bigNumber result = bigNumber("154678365873287462387648723468723648237648");
    result.setNegative();
    biSumms test = biSumms();
}

void bigNumberTrying::caseTwoBigNegative()
{
    bigNumber A = bigNumber("9111111111111111111111111111112222222222222222");
    A.setNegative();
    bigNumber B = bigNumber("1111111199922222222222299911111111111111111111");
    B.setNegative();
    bigNumber result = bigNumber("10222222311033333333333411022223333333333333333");
    result.setNegative();
    biSumms test = biSumms();

    QCOMPARE(test.getSumm(A, B), result);
}

void bigNumberTrying::caseTwoBigPositive()
{
    bigNumber A = bigNumber("9111111111111111111111111111112222222222222222");
    bigNumber B = bigNumber("1111111199922222222222299911111111111111111111");
    bigNumber result = bigNumber("10222222311033333333333411022223333333333333333");
    biSumms test = biSumms();

    QCOMPARE(test.getSumm(A, B), result);
}

void bigNumberTrying::caseWithNegativeSignFirst()
{
    bigNumber A = bigNumber("-9111");
    bigNumber B = bigNumber("1111");
    bigNumber result = bigNumber("8000");
    result.setNegative();
    biSumms test = biSumms();

    QCOMPARE(test.getSumm(A, B), result);
}

void bigNumberTrying::caseWithNegativeSignSecond()
{
    bigNumber A = bigNumber("1111");
    bigNumber B = bigNumber("-9111");
    bigNumber result = bigNumber("8000");
    result.setNegative();
    biSumms test = biSumms();

    QCOMPARE(test.getSumm(A, B), result);
}

void bigNumberTrying::caseWithNegativeSignBoth()
{
    bigNumber A = bigNumber("-1111");
    bigNumber B = bigNumber("-9111");
    bigNumber result = bigNumber("10222");
    result.setNegative();
    biSumms test = biSumms();

    QCOMPARE(test.getSumm(A, B), result);
}

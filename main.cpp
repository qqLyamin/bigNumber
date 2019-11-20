#include <QCoreApplication>
#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "bignumber.h"
#include "bisumms.h"
#include "tst_bignumbertrying.h"

int main(int argc, char *argv[])
{
    freopen("testing,log", "w", stdout);
    bigNumberTrying * test = new bigNumberTrying;
    QCoreApplication a(argc, argv);

//    bigNumber C = bigNumber("9999999dfsgdfhdfh99999");
//    std::cout << C << std::endl;
//    bigNumber B = bigNumber("1gfhgdfhdfh1");
//    std::cout << B << std::endl;
//    C = C + B;
//    std::cout << C << std::endl;

    QTest::qExec(test, argc, argv);
    return a.exec();
}

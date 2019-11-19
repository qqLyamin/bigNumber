#include <QCoreApplication>
#include <iostream>
#include "bignumber.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    bigNumber B = bigNumber("9-9");
    std::cout << B << std::endl;
    bigNumber C = bigNumber("22222222222222222222222222222222222222222222229333333333333333333333333333333333333333333333");
    std::cout << C << std::endl;
    C = C + B;
    std::cout << C << std::endl;
    return a.exec();
}

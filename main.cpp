#include <QCoreApplication>
#include <iostream>
#include "bignumber.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    bigNumber C = bigNumber("999999999999");
    std::cout << C << std::endl;
    bigNumber B = bigNumber("11");
    std::cout << B << std::endl;
    C = C + B;
    std::cout << C << std::endl;
    return a.exec();
}

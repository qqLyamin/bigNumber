#include <QCoreApplication>
#include "bignumber.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    bigNumber B = bigNumber("12345678");
    return a.exec();
}

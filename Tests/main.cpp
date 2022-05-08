#include <QCoreApplication>
#include "test_and_getvalue.h"
#include "test_not_getvalue.h"

int main(int argc, char *argv[])
{
    Test_And_getValue testAnd;
    Test_Not_getValue testNot;

    QTest::qExec(&testAnd, argc, argv);
    QTest::qExec(&testNot, argc, argv);

    return 0;
}

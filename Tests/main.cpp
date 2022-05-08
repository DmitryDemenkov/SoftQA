#include <QCoreApplication>
#include "test_and_getvalue.h"
#include "test_not_getvalue.h"
#include "test_or_getvalue.h"

int main(int argc, char *argv[])
{
    Test_And_getValue testAnd;
    Test_Not_getValue testNot;
    Test_Or_getValue testOr;

    QTest::qExec(&testAnd, argc, argv);
    QTest::qExec(&testNot, argc, argv);
    QTest::qExec(&testOr, argc, argv);

    return 0;
}

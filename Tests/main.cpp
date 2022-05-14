#include <QCoreApplication>
#include "test_and_getvalue.h"
#include "test_not_getvalue.h"
#include "test_or_getvalue.h"
#include "test_xor_getvalue.h"
#include "test_imply_getvalue.h"
#include "test_eq_getvalue.h"
#include "test_nand_getvalue.h"
#include "test_nor_getvalue.h"

int main(int argc, char *argv[])
{
    Test_And_getValue testAnd;
    Test_Not_getValue testNot;
    Test_Or_getValue testOr;
    Test_Xor_getValue testXor;
    Test_Imply_getValue testImply;
    Test_Eq_getValue testEq;
    Test_Nand_getValue testNand;
    Test_Nor_getValue testNor;

    QTest::qExec(&testAnd, argc, argv);
    QTest::qExec(&testNot, argc, argv);
    QTest::qExec(&testOr, argc, argv);
    QTest::qExec(&testXor, argc, argv);
    QTest::qExec(&testImply, argc, argv);
    QTest::qExec(&testEq, argc, argv);
    QTest::qExec(&testNand, argc, argv);
    QTest::qExec(&testNor, argc, argv);

    return 0;
}

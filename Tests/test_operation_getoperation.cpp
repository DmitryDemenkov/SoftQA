#include "test_operation_getoperation.h"
#include "../TruthTableProject/operation.h"
#include "../TruthTableProject/operations/not.h"
#include "../TruthTableProject/operations/and.h"
#include "../TruthTableProject/operations/or.h"
#include "../TruthTableProject/operations/xor.h"
#include "../TruthTableProject/operations/imply.h"
#include "../TruthTableProject/operations/eq.h"
#include "../TruthTableProject/operations/nand.cpp"
#include "../TruthTableProject/operations/nor.cpp"

Test_Operation_getOperation::Test_Operation_getOperation() { }

Test_Operation_getOperation::~Test_Operation_getOperation() { }

void Test_Operation_getOperation::operationInversion()
{
    Operation* operation = Operation::getOperation("not");

    bool isNot = dynamic_cast<Not*>(operation) != NULL;

    QVERIFY(isNot);
}

void Test_Operation_getOperation::operationConjuction()
{
    Operation* operation = Operation::getOperation("and");

    bool isAnd = dynamic_cast<And*>(operation) != NULL;

    QVERIFY(isAnd);
}

void Test_Operation_getOperation::operationDisjunction()
{
    Operation* operation = Operation::getOperation("or");

    bool isOr = dynamic_cast<Or*>(operation) != NULL;

    QVERIFY(isOr);
}

void Test_Operation_getOperation::operationXOR()
{
    Operation* operation = Operation::getOperation("xor");

    bool isXor = dynamic_cast<Xor*>(operation) != NULL;

    QVERIFY(isXor);
}

void Test_Operation_getOperation::operationImplication()
{
    Operation* operation = Operation::getOperation("imply");

    bool isImply = dynamic_cast<Imply*>(operation) != NULL;

    QVERIFY(isImply);
}

void Test_Operation_getOperation::operationEquivalent()
{
    Operation* operation = Operation::getOperation("eq");

    bool isEq = dynamic_cast<Eq*>(operation) != NULL;

    QVERIFY(isEq);
}

void Test_Operation_getOperation::operationNand()
{
    Operation* operation = Operation::getOperation("nand");

    bool isNand = dynamic_cast<Nand*>(operation) != NULL;

    QVERIFY(isNand);
}

void Test_Operation_getOperation::operationNor()
{
    Operation* operation = Operation::getOperation("nor");

    bool isNor = dynamic_cast<Nor*>(operation) != NULL;

    QVERIFY(isNor);
}

void Test_Operation_getOperation::incorrectOperationName()
{
    Operation* operation = Operation::getOperation("dkgkd");

    bool isNULL = operation == NULL;

    QVERIFY(isNULL);
}

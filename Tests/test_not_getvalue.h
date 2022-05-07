#ifndef TEST_NOT_GETVALUE_H
#define TEST_NOT_GETVALUE_H
#include <QTest>
#include <QObject>

class Test_Not_getValue : public QObject
{
    Q_OBJECT
public:
    Test_Not_getValue();
    ~Test_Not_getValue();

private slots:
    void InversionZero();
    void InversionOne();
    void DoubleInversion();
};

#endif // TEST_NOT_GETVALUE_H

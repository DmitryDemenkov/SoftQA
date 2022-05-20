#ifndef TRUTHTABLESYSTEM_H
#define TRUTHTABLESYSTEM_H
#include <QDomDocument>
#include <QCoreApplication>
#include "node.h"
#include "variable.h"
#include "operation.h"
#include "errorcontroller.h"


/*!
 * \brief Подсистема, составляющая таблицу истинности
 *                    логического выражения на основе дерева разбора
 */
class TruthTableSystem
{
public:
    TruthTableSystem();
    ~TruthTableSystem();

    /*!
     * \brief Задать корень выражения в виде xml узел
     * \param node xml узел
     */
    void setXRootNode(QDomNode xNode);

    /*!
     * \brief Получить таблицу истинности
     *                       и список подвыражений заданного выражения
     * \param values матрица, содержащая таблицу истинности
     * \return список подвыражений
     */
    QStringList getTruthTable(QVector<QVector<int>> & values);

private:
    QDomNode xRootNode;   ///> корневой xml узел входного верева
    int variablesAmount;  ///> количество уникальных переменных в выражении
    QVector<Node*> nodes; ///> список подвыражений исходного выражения
    QVector<QVector<int>> values; ///> матрица значений таблицы истинности
    ErrorController errorController; ///> проверщик ошибок в узлах xml файла

    /*!
     * \brief Создать таблицу истинности
     *          на основе узлов дерева выражения
     */
    void makeTruthTable();

    /*!
     * \brief Преобразовать xml узел в объект класса Node
     *                               и добавить его в вектор
     * \param node xml узел
     * \return указатель на созданный Node
     */
    Node* parseExpression(QDomNode & xNode);

    /*!
     * \brief Найти узел в векторе
     * \param node искомый узел
     * \return указатель на узел из вектора
     */
    Node* findNode(Node* node);

    /*!
     * \brief Вставить узел в вектор
     * \param node узел, который необходимо вставить
     * \return 1, если была вставлена переменная, 0, если операция
     */
    int insertNode(Node* node);

#ifdef QT_DEBUG
    friend class Test_TruthTableSystem_findNode;
    friend class Test_TruthTableSystem_insertNode;
#endif // friend test classes
};

#endif // TRUTHTABLESYSTEM_H

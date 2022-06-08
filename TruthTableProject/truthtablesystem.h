#ifndef TRUTHTABLESYSTEM_H
#define TRUTHTABLESYSTEM_H
#include <QDomDocument>
#include <QCoreApplication>
#include "node.h"
#include "variable.h"
#include "operation.h"
#include "errorcontroller.h"

/*!
 * \file
 * \brief Файл, содержащий описание TruthTableSystem
 */

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
     * \param[in] xNode - xml узел
     */
    void setXRootNode(QDomNode xNode);

    /*!
     * \brief Получить таблицу истинности
     *                       и список подвыражений заданного выражения
     * \param[out] values - матрица, содержащая таблицу истинности
     * \return Список подвыражений
     */
    short* getTruthTable(QStringList &subExpressions, int &rowAmount, int &columnAmount);

private:
    QDomNode xRootNode;   ///< Корневой xml узел входного верева
    int variablesAmount;  ///< Количество уникальных переменных в выражении
    QVector<Node*> nodes; ///< Список подвыражений исходного выражения
    //QVector<QVector<int>> values; ///< Матрица значений таблицы истинности
    ErrorController errorController; ///< Проверщик ошибок в узлах xml файла

    /*!
     * \brief Создать таблицу истинности
     *          на основе узлов дерева выражения
     */
    short* makeTruthTable();

    /*!
     * \brief Преобразовать xml узел в объект класса Node
     *                               и добавить его в вектор
     * \param[in] node - xml узел
     * \return Указатель на созданный Node
     * \throw ErrorController::Error - сообщение об ошибке
     */
    Node* parseExpression(QDomNode & xNode);

    /*!
     * \brief Найти узел в векторе
     * \param[in] node - искомый узел
     * \return Указатель на узел из вектора
     */
    Node* findNode(Node* node);

    /*!
     * \brief Вставить узел в вектор
     * \param[in] node - узел, который необходимо вставить
     * \return 1, если была вставлена переменная, 0, если операция
     */
    int insertNode(Node* node);

#ifdef QT_DEBUG
    friend class Test_TruthTableSystem_findNode;
    friend class Test_TruthTableSystem_insertNode;
    friend class Test_TruthTableSystem_parseExpression;
    friend class Test_TruthTableSystem_makeTruthTable;
#endif // friend test classes
};

#endif // TRUTHTABLESYSTEM_H

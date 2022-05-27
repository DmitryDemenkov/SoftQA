#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <QCoreApplication>
#include <QDomDocument>
#include <QFile>
#include "errorcontroller.h"

/*!
 * \brief Класс подсистемы, осуществляющей чтение и запись в файлы
 */
class FileManager
{
public:
    FileManager();

    /*!
     * \brief Установить имя входного файла
     * \param[in] filename имя входного файла
     * \return true, если файл задан корректно
     */
    bool setInputFile(QString filename);

    /*!
     * \brief Установить имя выходного файла
     * \param[in] filename имя выходного файла
     * \return true, если файл задан корректно
     */
    bool setOutputFile(QString filename);

    /*!
     * \brief Получить корень дерева разбора выражения
     * \return корень дерева разбора
     */
    QDomNode getXRootNode();

    /*!
     * \brief Записать список подвыражений и таблицу истинности в выходной файл
     * \param[in] subExpressions список подвыражений
     * \param[in] values таблица истинности
     */
    void writeOutputFile(QStringList &subExpressions, QVector<QVector<int>> &values);

private:
    QString inputFilename; ///< имя входного файла
    QString outputFilename; ///< имя выходного файла
};

#endif // FILEMANAGER_H

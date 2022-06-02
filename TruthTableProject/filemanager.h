#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <QCoreApplication>
#include <QDomDocument>
#include <QFile>
#include "errorcontroller.h"

/*!
 * \file
 * \brief Файл, содержащий описание FileManager
 */

/*!
 * \brief Класс подсистемы, осуществляющей чтение и запись в файлы
 */
class FileManager
{
public:
    FileManager();

    /*!
     * \brief Установить имя входного файла
     * \param[in] filename - имя входного файла
     * \return true, если файл задан корректно
     * \throw ErrorController::Error - сообщение об ошибке
     */
    bool setInputFile(QString filename);

    /*!
     * \brief Установить имя выходного файла
     * \param[in] filename - имя выходного файла
     * \return true, если файл задан корректно
     * \throw ErrorController::Error - сообщение об ошибке
     */
    bool setOutputFile(QString filename);

    /*!
     * \brief Получить корень дерева разбора выражения
     * \return Корень дерева разбора
     */
    QDomNode getXRootNode();

    /*!
     * \brief Записать список подвыражений и таблицу истинности в выходной файл
     * \param[in] subExpressions - список подвыражений
     * \param[in] values таблица - истинности
     */
    void writeOutputFile(QStringList &subExpressions, QVector<QVector<int>> &values);

private:
    QString inputFilename; ///< Имя входного файла
    QString outputFilename; ///< Имя выходного файла
};

#endif // FILEMANAGER_H

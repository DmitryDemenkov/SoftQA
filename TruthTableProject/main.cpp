#include <QCoreApplication>
#include <iostream>
#include "filemanager.h"
#include "truthtablesystem.h"

/*!
 * \file
 * \brief Файл, содержащий код самой программы
 */

/*!
 * \brief Вывести в консоль сообщение об ошибке
 * \param[in] errorMessage - сообщение об ошибке
 */
void errorPrint(QString &errorMessage)
{
    std::setlocale(LC_ALL, "rus");
    std::cout << QString(errorMessage).toLocal8Bit().data() << std::endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QStringList fileNames = a.arguments();

    if (fileNames.length() < 3)
    {
        QString errorMsg = "Не указаны входной и выходной файлы";
        errorPrint(errorMsg);
        return 0;
    }

    try
    {
        //Считать данные из входного файла
        FileManager manager = FileManager();
        manager.setInputFile(fileNames[1]);
        manager.setOutputFile(fileNames[2]);

        QDomNode node = manager.getXRootNode();

        // Составить список подвыражений и таблицу истинности полученного логического выражения.
        TruthTableSystem table = TruthTableSystem();
        table.setXRootNode(node);

        QStringList list;
        int rowAmount;
        int columnAmount;
        short* val = table.getTruthTable(list, rowAmount, columnAmount);

        // Записать полученные данные в выходной файл
        manager.writeOutputFile(list, val, rowAmount, columnAmount);

    }
    catch (ErrorController::Error error)
    {
        errorPrint(error.errorMessege);
    }

    return 0;
}

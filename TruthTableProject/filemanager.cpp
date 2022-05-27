#include "filemanager.h"

FileManager::FileManager() { }

bool FileManager::setInputFile(QString filename)
{
    ErrorController errorController;

    bool isInputCorrect = errorController.isInputFileCorrect(filename);
    if (isInputCorrect)
        inputFilename = filename;

    return isInputCorrect;
}

bool FileManager::setOutputFile(QString filename)
{
    ErrorController errorController;

    bool isOutputCorrect = errorController.isOutputFileCorrect(filename);
    if (isOutputCorrect)
        outputFilename = filename;

    return isOutputCorrect;
}

QDomNode FileManager::getXRootNode()
{
    QDomDocument doc(inputFilename);
    QFile inputFile(inputFilename);

    inputFile.open(QIODevice::ReadOnly);
    doc.setContent(&inputFile);
    inputFile.close();
    QDomElement docElem = doc.documentElement();
    QDomNode node = docElem.firstChild();

    return node;
}

void FileManager::writeOutputFile(QStringList &subExpressions, QVector<QVector<int>> &values)
{
    QFile outputFile(outputFilename);
    outputFile.open(QIODevice::WriteOnly);
    QTextStream outputStream(&outputFile);

    // Добавить строковые представления узлов в заголовки колонок
    QString string = "";
    for (int i = 0; i < subExpressions.length(); i++)
    {
        string.append(subExpressions[i]);

        if (i < subExpressions.length() - 1)
            string.append(";");
    }
    outputStream << string << Qt::endl;

    // Преобразовать строки матрицы значений в строки выходного файла
    for (int i = 0; i < values.length(); i++)
    {
        string = "";
        for (int j = 0; j < values[i].length(); j++)
        {
            QString number = QString::number(values[i][j]);
            string.append(number);

            if (j < values[i].length() - 1)
                string.append(";");
        }
        outputStream << string << Qt::endl;
    }
    outputFile.close();
}

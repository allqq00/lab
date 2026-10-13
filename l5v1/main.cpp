#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void PrintFile(const string& filePath)
{
    ifstream file(filePath);


    string line;

    bool isEmpty = true;

    while (getline(file, line))
    {
        isEmpty = false;
        cout << line << endl;
    }


    file.close();
}

void checkEmpty(const string& filePath)
{
    ifstream file(filePath);
    if (!file.is_open())
    {
        ofstream outFile(filePath);
        outFile.close();
    }
}

void mergeFiles(const string& file1Path, const string& file2Path, const string& file3Path)
{
    ifstream file1(file1Path);
    ifstream file2(file2Path);
    ofstream file3(file3Path);


    string line1, line2;
    bool hasLine1 = bool(getline(file1, line1));
    bool hasLine2 = bool(getline(file2, line2));

    while (hasLine1 && hasLine2)
    {
        if (line1 <= line2)
        {
            file3 << line1 << endl;
            hasLine1 = bool(getline(file1, line1));
        }
        else
        {
            file3 << line2 << endl;
            hasLine2 = bool(getline(file2, line2));
        }
    }

    while (hasLine1)
    {
        file3 << line1 << endl;
        hasLine1 = bool(getline(file1, line1));
    }

    while (hasLine2)
    {
        file3 << line2 << endl;
        hasLine2 = bool(getline(file2, line2));
    }

    file1.close();
    file2.close();
    file3.close();
}

int main()
{
    string file1Path, file2Path, file3Path;

    cout << "Enter path to first input file: ";
    cin >> file1Path;

    cout << "Enter path to second input file: ";
    cin >> file2Path;

    cout << "Enter path to output file: ";
    cin >> file3Path;

    cout << "\nFile 1" << endl;
    PrintFile(file1Path);

    cout << "\nFile 2" << endl;
    PrintFile(file2Path);


    mergeFiles(file1Path, file2Path, file3Path);
    cout << endl;


    cout << "\nOutput File" << endl;
    PrintFile(file3Path);

    checkEmpty(file3Path);

    return 0;
}

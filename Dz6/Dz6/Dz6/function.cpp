#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

size_t EnterSizeArray(size_t* size)// ���������������� ���� ������� �������
{
    std::cout << "Enter size array:";
    std::cin >> *size;
    return *size;
}

size_t EnterSizeofaTwoDimensionalArray(size_t* SIZEONE, size_t* SIZETWO)//���������������� ���� �������� ������������� �������
{
    std::cout << "Enter size array one:";
    std::cin >> *SIZEONE;
    std::cout << "Enter size array two:";
    std::cin >> *SIZETWO;
    std::cout << std::endl;
    return *SIZEONE, * SIZETWO;
}

size_t ArrayInitialization(size_t* pArray, size_t size)//���������� ������� �� ������� ������ ��������� ������
{
    int y = 1;
    const int step = 2;
    for (size_t i = 0; i < size; i++)
    {
        pArray[i] = y;
        y *= step;
    }
    return *pArray;
}

size_t TwoDimensionalInitialization(size_t** pArray2, size_t sizeone, size_t sizetwo)//���������� ���������� ������������� ������� ���������������� �������
{
    srand(static_cast<unsigned int>(time(NULL)));
    for (size_t i = 0; i < sizeone; i++)
    {
        for (size_t j = 0; j < sizetwo; j++)
        {
            pArray2[i][j] = rand() % 100;
        }
    }
    return  **pArray2;
}

void PrintArray(size_t* pArray, size_t size)//������ ����������� �������
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << pArray[i] << "   ";
    }
}

void PrintTwoDimensionalArray(size_t** pArray2, size_t sizeone, size_t sizetwo)//������ ���������� ������������� �������
{
    for (size_t i = 0; i < sizeone; i++)
    {
        for (size_t j = 0; j < sizetwo; j++)
        {
            std::cout << pArray2[i][j] << "   ";
        }
        std::cout << std::endl;
    }
}
std::string FileNameOne, FileNameTwo, FileNameFree, EntertextOne, EntertextTwo, EntertextFree;
std::string buf1, buf2;

void NewFileTXTandFilling1(std::string* FileNameOne, std::string* EntertextOne)//�������� � ���������� 1-�� txt ����� ����� ����������������� �����
{
    std::cout << "Enter file name one (format 'name.txt')";
    std::cin >> *FileNameOne;
    std::ofstream fout(*FileNameOne);
    std::cout << std::endl;

    std::cout << "Enter text to write to file one:";

    std::cin.clear();
    std::cin.ignore(32767, '\n');
    std::getline(std::cin, *EntertextOne);
    fout << *EntertextOne;
    fout.close();
    std::cout << *EntertextOne << std::endl;
}

void NewFileTXTandFilling2(std::string* FileNameTwo, std::string* EntertextTwo)//�������� � ���������� 2-�� txt ����� ����� ����������������� �����
{

    std::cout << "Enter file name two (format 'name.txt')";
    std::cin >> *FileNameTwo;
    std::ofstream fout(*FileNameTwo);
    std::cout << std::endl;

    std::cout << "Enter text to write to file two:";

    std::cin.clear();
    std::cin.ignore(32767, '\n');
    std::getline(std::cin, *EntertextTwo);
    fout << *EntertextTwo;
    fout.close();
    std::cout << *EntertextTwo << std::endl;
}

void NewfileTXT(std::string* FileNameFree)//�������� txt ����� ��� �������� �������������
{
    std::cout << "Enter file name free (format 'name.txt')";
    std::cin >> *FileNameFree;
    std::ofstream fout(*FileNameFree);
    std::cout << std::endl;
}
void WritingToFile(std::string* buf1, std::string* buf2, std::string* FileNameFree)//���������� 3-�� ����� ������ ������� �� 1-�� � 2-�� ������(����������)
{
    std::ofstream fout(*FileNameFree);
    fout << "Content of the first file: " << *buf1 << std::endl << "Content of the second file: " << *buf2 << std::endl;
    fout.close();
    std::cout << *buf1 << std::endl, std::cout << *buf2 << std::endl;

}

void GluingTextFilesOne(std::string* FileNameFree, std::string* EntertextFree, std::string* buf1, std::string* buf2)//���������� ������ �� 1-�� � 2-�� ����������� � ������ �������� � 3-�
{
    NewFileTXTandFilling1(&FileNameOne, &EntertextOne);
    NewFileTXTandFilling2(&FileNameTwo, &EntertextTwo);

    std::ifstream fin1(FileNameOne);
    std::ifstream fin2(FileNameTwo);
    if (fin1.is_open())
    {
        while (!fin1.eof())
        {
            std::getline(fin1, *buf1);
            std::getline(fin2, *buf2);
        }
        NewfileTXT(FileNameFree);
        WritingToFile(buf1, buf2, FileNameFree);
        fin1.close();
    }
    else
    {
        std::cout << "Error. Can not open file.";
    }
}

void SearchForMatches(std::string* EntertextFree)//����� ����� ��������� ������������� � ������ 3-�� �����(���������� �� ������ ����)
{
    std::string Word;
    std::cout << "Enter your search word: ";
    std::cin >> Word;
    if (EntertextFree->find(Word) != std::string::npos)
    {
        std::cout << "We found ", std::cout << Word;
    }
}

void task_1()//������� 1 ��������� ����������� ������� � ������������� ��������� ������
{
    size_t* pArray;
    size_t SIZE{ 0 };
    EnterSizeArray(&SIZE);
    pArray = new(std::nothrow) size_t[SIZE];
    ArrayInitialization(pArray, SIZE);
    std::cout << "Filled array:  ";
    PrintArray(pArray, SIZE);
    delete[] pArray;
    pArray = nullptr;
    std::cout << std::endl;
}

void task_2()//������� 2 ������� ������� � ���������������� ���������������� �������
{
    size_t** pArray2;
    size_t SIZEONE;
    size_t SIZETWO;
    EnterSizeofaTwoDimensionalArray(&SIZEONE, &SIZETWO);
    pArray2 = new(std::nothrow) size_t * [SIZEONE];
    for (size_t i = 0; i < SIZEONE; i++)
    {
        pArray2[i] = new(std::nothrow) size_t[SIZETWO];
    }
    TwoDimensionalInitialization(pArray2, SIZEONE, SIZETWO);
    PrintTwoDimensionalArray(pArray2, SIZEONE, SIZETWO);
    for (size_t i = 0; i < SIZEONE; i++)
    {
        delete[] pArray2[i];
    }
    delete[] pArray2;
    pArray2 = nullptr;
}

void task_3()//������� 2 txt ����� (����������� � ������� 4)
{
    NewFileTXTandFilling1(&FileNameOne, &EntertextOne);
    NewFileTXTandFilling2(&FileNameTwo, &EntertextTwo);
    std::cout << std::endl << std::endl;
}

void  task_4()//������� 2 txt ����� � ������� �� ���������� � 3-� ����
{
    GluingTextFilesOne(&FileNameFree, &EntertextFree, &buf1, &buf2);
    EntertextFree = buf1 + buf2;
    std::cout << EntertextFree << std::endl;
}

void task_5()//����� ��������� ������������� �����, � ��������� ����� 3, � ������� ��������� ������ 1-�� � 2-�� �����
{
    SearchForMatches(&EntertextFree);
}
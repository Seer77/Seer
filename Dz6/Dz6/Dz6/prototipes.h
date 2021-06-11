#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

size_t EnterSizeArray(size_t* size);// ���������������� ���� ������� �������
size_t EnterSizeofaTwoDimensionalArray(size_t* SIZEONE, size_t* SIZETWO);//���������������� ���� �������� ������������� �������
size_t ArrayInitialization(size_t* pArray, size_t size);//���������� ������� �� ������� ������ ��������� ������
size_t TwoDimensionalInitialization(size_t** pArray2, size_t sizeone, size_t sizetwo);//���������� ���������� ������������� ������� ���������������� �������
void PrintArray(size_t* pArray, size_t size);//������ ����������� �������
void PrintTwoDimensionalArray(size_t** pArray2, size_t sizeone, size_t sizetwo);//������ ���������� ������������� �������

void NewFileTXTandFilling1(std::string* FileNameOne, std::string* EntertextOne);//�������� � ���������� 1-�� txt ����� ����� ����������������� �����
void NewFileTXTandFilling2(std::string* FileNameTwo, std::string* EntertextTwo);//�������� � ���������� 2-�� txt ����� ����� ����������������� �����
void NewfileTXT(std::string* FileNameFree);//�������� txt ����� ��� �������� �������������
void WritingToFile(std::string* buf1, std::string* buf2, std::string* FileNameFree);//���������� 3-�� ����� ������ ������� �� 1-�� � 2-�� ������(����������)
void GluingTextFilesOne(std::string* FileNameFree, std::string* EntertextFree, std::string* buf1, std::string* buf2);//���������� ������ �� 1-�� � 2-�� ����������� � ������ �������� � 3-�
void SearchForMatches(std::string* EntertextFree);//����� ����� ��������� ������������� � ������ 3-�� �����(���������� �� ������ ����)

void task_1();//������� 1 ��������� ����������� ������� � ������������� ��������� ������
void task_2();//������� 2 ������� ������� � ���������������� ���������������� �������
void task_3();//������� 2 txt ����� (����������� � ������� 4)
void  task_4();//������� 2 txt ����� � ������� �� ���������� � 3-� ����
void task_5();//����� ��������� ������������� �����, � ��������� ����� 3, � ������� ��������� ������ 1-�� � 2-�� �����

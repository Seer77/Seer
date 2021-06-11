#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

size_t EnterSizeArray(size_t* size);// Пользовательский ввод размера массива
size_t EnterSizeofaTwoDimensionalArray(size_t* SIZEONE, size_t* SIZETWO);//Пользовательский ввод двойного динамического массива
size_t ArrayInitialization(size_t* pArray, size_t size);//Заполнение массива по условию задачи степенями двойки
size_t TwoDimensionalInitialization(size_t** pArray2, size_t sizeone, size_t sizetwo);//Заполнение двумерного динамического массива псевдослучайными числами
void PrintArray(size_t* pArray, size_t size);//Печать одномерного массива
void PrintTwoDimensionalArray(size_t** pArray2, size_t sizeone, size_t sizetwo);//Печать двумерного динамического массива

void NewFileTXTandFilling1(std::string* FileNameOne, std::string* EntertextOne);//Создание и заполнение 1-го txt файла путем пользовательского ввода
void NewFileTXTandFilling2(std::string* FileNameTwo, std::string* EntertextTwo);//Создание и заполнение 2-го txt файла путем пользовательского ввода
void NewfileTXT(std::string* FileNameFree);//Создание txt файла имя вводится пользователем
void WritingToFile(std::string* buf1, std::string* buf2, std::string* FileNameFree);//заполнение 3-го файла данные берутся из 1-го и 2-го файлов(склеивание)
void GluingTextFilesOne(std::string* FileNameFree, std::string* EntertextFree, std::string* buf1, std::string* buf2);//Извлечение данных из 1-го и 2-го содержимого и склеив вносятся в 3-й
void SearchForMatches(std::string* EntertextFree);//Поиск слова заданного пользователем в данных 3-го файла(склеенного из первых двух)

void task_1();//Задание 1 Выделение одномерного массива и инициализация степенями двойки
void task_2();//Задание 2 Создать матрицу и инициализировать псевдослучайными числами
void task_3();//Создать 2 txt файла (повторяется в задании 4)
void  task_4();//создать 2 txt файла и склеить их содержимой в 3-й файл
void task_5();//Поиск заданного пользователем слово, в содержимо файла 3, в котором соединены данные 1-го и 2-го файла

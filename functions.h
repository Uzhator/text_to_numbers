#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
#include <limits.h>

// Позиция символа в векторе
int getPos(std::vector<char>&, char&);
// Считывание текста
void getText(std::vector<char>&, std::vector<unsigned long long int>&, unsigned long long int&);
// Кодирование
void encoding(std::vector<unsigned long long int>&, std::vector<unsigned long long int>&, unsigned long long int&);
// Кодирование со статическим ключём (выбор 2)
void encodingText(std::vector<unsigned long long int>&, std::vector<char>&, unsigned long long int&);
// Вывод хэша и ключа
void outHashAndKey(std::vector<unsigned long long int>&, std::vector<char>&);
// Получение ключа
void getKey(std::vector<char>&, std::ifstream&);
// Получение хэша
void getHash(std::vector<unsigned long long int>&);
// Раскодировка
void decoding(std::vector<unsigned long long int>&, std::vector<char>&);

#endif

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
#include <limits.h>

// ������ ᨬ���� � �����
int getPos(std::vector<char>&, char&);
// ���뢠��� ⥪��
void getText(std::vector<char>&, std::vector<unsigned long long int>&, unsigned long long int&);
// ����஢����
void encoding(std::vector<unsigned long long int>&, std::vector<unsigned long long int>&, unsigned long long int&);
// ����஢���� � ����᪨� ����� (�롮� 2)
void encodingText(std::vector<unsigned long long int>&, std::vector<char>&, unsigned long long int&);
// �뢮� ��� � ����
void outHashAndKey(std::vector<unsigned long long int>&, std::vector<char>&);
// ����祭�� ����
void getKey(std::vector<char>&, std::ifstream&);
// ����祭�� ���
void getHash(std::vector<unsigned long long int>&);
// ��᪮��஢��
void decoding(std::vector<unsigned long long int>&, std::vector<char>&);

#endif
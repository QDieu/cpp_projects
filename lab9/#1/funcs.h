//
// Created by QDieu on 13.06.2018.
//

#ifndef LAB9_1_FUNCS_H
#define LAB9_1_FUNCS_H

#include <cstring>

bool palindrome (const char *arr);
int getMax (const int *arr, int len);
char getMax (const char *arr);
void conversion(const char *arr, int *out, int &counter);
bool grow(const char *arr);
bool grow(const int *arr, int len);
char getMid(const char *arr);
int getMid(const int *arr, int len);

#endif //LAB9_1_FUNCS_H

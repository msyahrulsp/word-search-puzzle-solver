#ifndef UTIL_H
#define UTIL_H

#include <vector>
#include <string>
#include <tuple>
#include <chrono>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define NORMAL "\x1B[0m"
#define BLACK "\033[30m" 
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m" 
#define BLUE "\033[34m" 
#define MAGENTA "\033[35m"
#define CYAN "\033[36m" 
#define WHITE "\033[37m" 
#define BOLDBLACK "\033[1m\033[30m" 
#define BOLDRED  "\033[1m\033[31m" 
#define BOLDGREEN "\033[1m\033[32m"
#define BOLDYELLOW "\033[1m\033[33m" 
#define BOLDBLUE "\033[1m\033[34m"
#define BOLDMAGENTA "\033[1m\033[35m" 
#define BOLDCYAN "\033[1m\033[36m"
#define BOLDWHITE "\033[1m\033[37m"

void readInput(vector<vector<pair<char, int>>> *mtx, vector<tuple<string, int, int>> *input);

void printLightColor(int num);

void printColor(int num);

void check(vector<vector<pair<char, int>>> &mtx, vector<tuple<string, int, int>> &input, int &comp);

void printResult(vector<vector<pair<char, int>>> mtx, vector<tuple<string, int, int>> input);

#endif
// Mnacci.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <vector>
#include <functional>
#include <numeric>
#include <algorithm>


// sequences
static long long int column2(long long int n);
static long long int column3(long long int n);
static long long int column4(long long int n);
static long long int column5(long long int n);
static long long int column6(long long int n);
static long long int column7(long long int n);
static long long int column8(long long int n);
static long long int column9(long long int n);
static long long int column10(long long int n);
static long long int column11(long long int n);
static long long int column12(long long int n);
static long long int column13(long long int n);
static long long int column14(long long int n);

// data for vector file
std::vector<long long int> mnacci(long long int n, long long int reps);
std::vector<std::vector<long long int>> chebyshev1st(long long int n, long long int reps);
std::vector<long long int> testtheory(long long int n, long long int reps);


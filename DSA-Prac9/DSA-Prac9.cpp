// DSA-Prac9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma once
#include <iostream>
#include <time.h>
#include "heap.h"
#include <chrono>
#include "quick.h"
#include "shell.h"
#include "main.h"

//#include "quick.cpp"
//#include "Shell.cpp"

using namespace std;

int ARRAYSIZE = 100;

int main()
{
    srand(time(NULL));
    runAllBenchmarks();
}

void runAllBenchmarks()
{
    while (ARRAYSIZE < BENCHLIMIT)
    {
        ARRAYSIZE *= 10;
        cout << "\nRUNNING BENCHMARK <<<<< N = " << ARRAYSIZE << " >>>>>\n\n";
        runBenchmark();
    }
}

void runBenchmark()
{
    int* array = buildRandomArray(ARRAYSIZE);

    int benchHeap = heapTest();
    int benchQuick = quickTest();
    int benchShell = shellTest();

    graphResults(benchHeap, benchQuick, benchShell);
}

int* buildRandomArray(int size)
{
    int* array = new int[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 1000;
    }
    return array;
}

int heapTest()
{
    int* arr = buildRandomArray(ARRAYSIZE);
    auto start = chrono::system_clock::now();
    heapSort(arr, ARRAYSIZE - 1);
    auto end = chrono::system_clock::now();
    delete arr;
    return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

int quickTest()
{
    int* arr = buildRandomArray(ARRAYSIZE);
    QuickSort sorter = QuickSort(arr, ARRAYSIZE);
    auto start = chrono::system_clock::now();
    sorter.sort(0, ARRAYSIZE - 1);
    auto end = chrono::system_clock::now();
    delete arr;
    return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

int shellTest()
{
    int* arr = buildRandomArray(ARRAYSIZE);
    auto start = chrono::system_clock::now();
    shellSort(arr, ARRAYSIZE - 1);
    auto end = chrono::system_clock::now();
    delete arr;
    return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}


int max(int a, int b, int c)
{
    int result = a;
    if (b > result)
    {
        result = b;
    }
    if (c > result)
    {
        result = c;
    }
    return result;
}

void graphResults(int h, int q, int s)
{
    int scale = max(h, q, s);

    double hs = (1.0*h) / (1.0*scale);
    double qs = (1.0 * q) / (1.0 * scale);
    double ss = (1.0 * s) / (1.0 * scale);

    int hg = hs * 100;
    int qg = qs * 100;
    int sg = ss * 100;

    cout << "Heap sort  :" << h << "ms\n";
    plotBar(hg);

    cout << "Quick sort :" << q << "ms\n";
    plotBar(qg);

    cout << "Shell sort :" << s << "ms\n";
    plotBar(sg);
}

void plotBar(int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << "/";
    }
    cout << endl << endl;
}
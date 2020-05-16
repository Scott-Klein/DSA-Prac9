#pragma once
#define BENCHLIMIT 1000000


int* buildRandomArray(int size);
int heapTest();
int quickTest();
int shellTest();
int max(int a, int b, int c);
void graphResults(int h, int q, int s);
void plotBar(int length);
void runBenchmark();
void runAllBenchmarks();
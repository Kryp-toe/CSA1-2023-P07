#ifndef LIBARRAY_H_INCLUDED
#define LIBARRAY_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <sstream>

using namespace std;

namespace CellularSpace
{
    const int ERR_ARGC = -1;
    const int ERR_CONV = -2;
    const int ERR_RANGE = -3;
    
    const int ALIVE = 1;
    const int DEAD = 0;
    
    const char charALIVE = '#';
    const char charDEAD = '*';
    
    typedef int* TypeArray;
    
    int GetRand(int Lowest, int Highest);
    int ConvertToInt(string strNum);
    TypeArray AllocateMemory(int intCount);
    void InitialArrayRand(TypeArray arrNums, int intCount, int intLowest, int intHighest);
    void PrintArray(TypeArray arrNums, int intCount);
    void ModifyArray(TypeArray arrNums, int intCount);
    void DealeteLoc(TypeArray& arrNums);
    void pause();
    void CopyArray(TypeArray arrFrom, TypeArray arrTo, int intCount);
    void CompltAutomation(TypeArray arrNums, int intCount);
}

#endif // LIBARRAY_H_INCLUDED
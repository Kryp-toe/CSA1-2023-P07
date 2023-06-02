#include <iostream>
#include <cstdlib>
#include "libArray.h"

using namespace std;

namespace CellularSpace
{
    
    int GetRand(int intLowest, int intHighest)
    {
        int intRange = intHighest - intLowest +1;
        return (rand() % intRange) + intLowest;
    }
    
    int ConvertToInt(string strNum)
    {
        int intNum = 0;
        stringstream ss {strNum};
        ss >> intNum;
        if (ss.fail())
        {
            cerr << "Could not convert " << strNum << " to integer" << endl;
            exit(ERR_CONV);
        }
        return intNum;
    }
    
    TypeArray AllocateMemory(int intCount)
    {
        TypeArray arrNums;
        arrNums = new int[intCount];
        
        //Initialise it to all zero values
        for(int n=0;n<intCount;n++)
        {
            arrNums[n] = 0;
        }
        
        return arrNums;
    }
    
    void InitialArrayRand(TypeArray arrNums, int intCount, int intLowest, int intHighest)
    {
        for(int n=0;n<intCount;n++)
        {
            arrNums[n] = GetRand(intLowest, intHighest);
        }
    }
    
    void PrintArray(TypeArray arrNums, int intCount)
    {
        
        for(int n=0;n<intCount;n++)
        {
            switch (arrNums[n])
            {
                case DEAD:
                {
                    cout << charDEAD;
                    break;
                }
                case ALIVE:
                {
                    cout << charALIVE;
                    break;
                }
                default:
                {
                    cout << endl << "This should not happen, check array for ERRORS" << endl;
                    break;
                }
            }
        }
        cout << endl << endl;
    }
    
    void CopyArray(TypeArray arrFrom, TypeArray arrTo, int intCount)
    {
        for(int n=0;n<intCount;n++)
        {
            arrTo[n] = arrFrom[n];
        }
    }
    
    void DealeteLoc(TypeArray& arrNums)
    {
        delete[] arrNums;
        arrNums = nullptr;
    }
    
    void ModifyArray(TypeArray arrNums, int intCount)
    {
        
        TypeArray arrTemp = AllocateMemory(intCount);
        
        for(int n=0;n<intCount;n++)
        {
            system("clear");
            
            cout << "What would you like to make position " << n+1  
                << " of " << intCount << endl 
                << "0. Dead" << endl 
                << "1. Alive" << endl;
                
            cin >> arrTemp[n];
            
            cout << endl << arrTemp[n] << endl;
            
            if(cin.fail())
            {
                cout << "Invalid Input" << endl
                    << "Please start again" << endl;
                        
                pause();
            }
        }
        
        //Copy the temp array into the origanal array
        CopyArray(arrTemp, arrNums, intCount);
        
        //Delete the memory/location of temp array
        DealeteLoc(arrTemp);
    }
    
    void CompltAutomation(TypeArray arrNums, int intCount)
    {
        
        for(int n=0; n<intCount; n++)
        {
            cout << endl;
            int intPrevInd = n-1;
            int intNextInd = n+1;
            
            if(n<=0)
            {
                intPrevInd = intCount-1;
            }
            
            if(n>=intCount-1)
            {
                intNextInd = 0;
            }
            
            int intPrevNum = arrNums[intPrevInd];
            int intNextNum = arrNums[intNextInd];
            
            //1 = alive(black) 0 = DEAD(white)
            // Part 1
            if(intPrevNum==ALIVE && intNextNum==ALIVE)
            {
                if(arrNums[n]==ALIVE)
                {
                    arrNums[n] = DEAD;
                    cout << endl << "1" << endl;
                    continue;
                }
            }
            
            // Part 2 
            if(intPrevNum==ALIVE && intNextNum==DEAD)
            {
                if(arrNums[n]==ALIVE)
                {
                    arrNums[n] = DEAD;
                    cout << endl << "2" << endl;
                    continue;
                }
            }
            
            // Part 3
            if(intPrevNum==ALIVE && intNextNum==ALIVE)
            {
                if(arrNums[n]==DEAD)
                {
                    arrNums[n] = DEAD;
                    cout << endl << "3" << endl;
                    continue;
                }
            }
            
            // Part 4
            if(intPrevNum==ALIVE && intNextNum==DEAD)
            {
                if(arrNums[n]==DEAD)
                {
                    arrNums[n] = ALIVE;
                    cout << endl << "4" << endl;
                    continue;
                }
            }
            
            // Part 5
            if(intPrevNum==DEAD && intNextNum==ALIVE)
            {
                if(arrNums[n]==ALIVE)
                {
                    arrNums[n] = ALIVE;
                    cout << endl << "5" << endl;
                    continue;
                }
            }
            
            // Part 6
            if(intPrevNum==DEAD && intNextNum==DEAD)
            {
                if(arrNums[n]==ALIVE)
                {
                    arrNums[n] = ALIVE;
                    cout << endl << "6" << endl;
                    continue;
                }
            }
            
            // Part 7
            if(intPrevNum==DEAD && intNextNum==ALIVE)
            {
                if(arrNums[n]==DEAD)
                {
                    arrNums[n] = ALIVE;
                    cout << endl << "7" << endl;
                    continue;
                }
            }
            
            // Part 8
            if(intPrevNum==DEAD && intNextNum==DEAD)
            {
                if(arrNums[n]==DEAD)
                {
                    arrNums[n] = DEAD;
                    cout << endl << "8" << endl;
                    continue;
                }
            }
        }
    }
    
    void pause()
    {
        cin.ignore(100, '\n');
        cout << "Press Enter to continue" << endl;
        cin.get();
    }
    
}


















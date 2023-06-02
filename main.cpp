#include <iostream>
#include <cstdlib>
#include "libArray.h"

using namespace std;
using namespace CellularSpace;

int main (int argc, char** argv)
{
    int intNumRounds = 1;
    char chInput = '\0';
    bool blnContinue = true;
    
    //Seed the rand num generator
    srand(time(nullptr));
    
    //Describe the number of command line arguments
    cout << "The number of arguments:" << argc << endl;
    for(int n=0;n<argc;n++)
    {
        cout << "Argument " << n << " is:" << argv[n] << endl;
    }
    
    //Check for the expected number of arguments.
    if(argc!=4)
    {
        cerr << "Please run the application with " << argv[0] << " <TotalItems> <LowestRandNum> <HighestRandNum>" << endl;
        exit(ERR_ARGC);
    }
    
    //Convert the string arguments into integers
    int intCount = ConvertToInt(argv[1]);
    int intLower = ConvertToInt(argv[2]);
    int intUpper = ConvertToInt(argv[3]);   
    
    //Declare the array and allocate memory
    TypeArray arrNums = AllocateMemory(intCount);
        
    do
    {
        
        system("clear");
        
        cout << "Please select an option." << endl
             << "A: Set Cellular Automaton Rounds" << endl
             << "B: Use Random Values" << endl
             << "C: Set Values Manueally" << endl
             << "D: Run Cellular Automaton" << endl
             << "E: Quit" << endl;
        
        cin >> chInput;
        
        switch(chInput)
        {
            case 'A':
            case 'a':
            {
                cout << "How many rounds of Cellular Automation would you like to have?" << endl;
                cin >> intNumRounds;
                
                break;
            }
            
            case 'B':
            case 'b':
            {
                cout << endl << "Random values have been used:" << endl;
                InitialArrayRand(arrNums, intCount, intLower, intUpper);
                
                cout << charDEAD << " is used for DEAD characters" << endl
                    << charALIVE << " is used for ALIVE characters" << endl
                    << endl << "The first values of the sequence is as follows: " << endl;
                
                PrintArray(arrNums, intCount);
                break;
            }
            
            case 'C':
            case 'c':
            {
                system("clear");
                ModifyArray(arrNums, intCount);
                break;
            }
            
            case 'D':
            case 'd':
            {
                cout << charDEAD << " is used for DEAD characters" << endl
                    << charALIVE << " is used for ALIVE characters" << endl;
                
                PrintArray(arrNums, intCount);
                for(int n=0; n<intNumRounds; n++)
                {
                    CompltAutomation(arrNums, intCount);
                    PrintArray(arrNums, intCount);
                }
                break;
            }
            
            case 'E':
            case 'e':
            {
                blnContinue = false;
                break;
            }
            
            default:
            {
                cerr << "Please enter a valid option." << endl;
                break;
            }
        }
        
        pause();
        
    }while(blnContinue);
    
    pause();
    
    return 0;
}




















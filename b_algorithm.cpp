/*
    data.txt must be formatted as table of values with a space between each entry 
    each table of values must be in order of allocation table, max table, and available table
*/

#include <iostream>
#include <fstream>
using namespace std;

int main(){
    int i = 5;     //hardcoded number of processes, can be easily edited for different data set   
    int j = 3;     //harcoded number of resources
    int k, o, y, x;      //iteration variables
    
    ifstream indata; //declares ifstream object for the input file
    
    //opens file
    indata.open("data.txt");
    if (!indata){ cout << "couldn't open file" << endl; }
    
    //declares containers for each matric in data.txt with i representing number of processes and j 
    //representing number of resources
    int allocated[i][j];       //number of instances of each resource allocated to each process
    int maximum[i][j];         //max number of instances that can be used by each process
    int available[j];          //number of instances of each resource that are available 

    //reads in each value in data.txt one by one and stores it at propper index of the matrix
    for(k = 0; k < i; k++){
        for(o = 0; o < j; o++){
            indata >> allocated[k][o]; 
        }
    }

    //reads in next set of data.txt values and stores in maximum matrix
    for(k = 0; k < i; k++){
        for(o = 0; o < j; o++){
            indata >> maximum[k][o]; 
        }
    }

    //reads in next set of data.txt values and stores in available matrix
    for(o = 0; o < j; o++){
        indata >> available[o]; 
    }

    //closes file
    indata.close();

    //bankers algorithm 
    //creates need matrix, need[i][j] = the max of Rj needed by Pi
    int need[i][j]; 
    for(k = 0; k < i; k++){
        for(o = 0; o < j; o++){
            need[k][o] = maximum[k][o] - allocated[k][o];
        }
    }

    //array of booleans that assesses if Pi is finsished being allocated resources
    bool finish[i]; 
    for(k = 0; k < i; k++){ finish[k] = false; }   //init to false


    //work array that represents the available resources to be worked on 
    int work[j]; 
    for(o = 0; o < j; o++){
        work[o] = available[o];     //initialize with same values as available
    }

    //find sequence for which each instance of each resource can be worked on and finished according to the
    //need matrix
    int correct_sequence[i];                      //array to store correct sequence of processes
    int pNum = 0;                                 //index for correct sequence array
    bool satisfies = true; 
    for(k = 0; k < i; k++){                       // loop through number of processes twice
        for(o = 0; o < i; o++){                   
            if(!f[k]){                            //if process k not finished
                for(y = 0; y < j; y++){           //loop through resources
                    if (need[o][y] > work[y])    //if the need of process o and resource y 
                        satisfies = false;        //exceeds the available for resource y 
                        break;                    //returns out of for loop(line 74)
                }
                if (satisfies == true) {
                    correct_sequence[pNum++] = o; //if process o is worked on and satisfies need < avail it is added to seequence at the correct index
                    for (x = 0; x < j; x++){    //loop through resources and update availability of work
                        work[x] = work[x] + allocated[o][x];
                    }
                    finish[o] = true;           //process o is finished being worked on 
                }
            }
        }
    }

    //check if the sequence is safe by checking if each process is finished
    for(o = 0; o < i; o++){
        if(!finish[o]){
            cout << "Unsafe!\n"; 
            satisfies = false; 
            break;  
        }
    }
    
    if(satisfies == true){
        cout << "Safe! as follows: \n";
        for (k = 0; k < i - 1; k++)
            cout << " P" << correct_sequence[k] << " ->";
            cout << " P" << correct_sequence[k - 1] <<endl;
    }

}
//open data file
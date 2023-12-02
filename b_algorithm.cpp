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
    int k, o;      //iteration variables
    
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
}
//open data file
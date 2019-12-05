/* Author:      Benjamin A Garza III
 * Date:        December 4, 2019
 * Course:      CMPS 3120 - Algorithm Analysis
 * Instructor:  Dr. Chengwei Lei
 * Assignment:  Lab 11
 *
 * Source:      msp.cpp
 * Compile:     g++ -Wall msp.cpp -o msp.out
 * Run:         ./msp.out
 *
 * Purpose:
 */

#include<iostream>
#include<cstdlib>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

/*    Global Variable    */
int graph[][5] = {
    { 0, 5, 7, 0, 2 },
    { 5, 0, 0, 6, 3 },
    { 7, 0, 0, 4, 4 },
    { 0, 6, 4, 0, 5 },
    { 2, 3, 4, 5, 0 }
};

/* Function Declarations */
void printLetter(int i);
void setSize(int *size, int graph[][5]);
void setTrack(int size, bool *track);
void mspPrim(int size, bool track[], int graph[][5], int i);
void mspKrus(int size, bool track[], int graph[][5], int i);

/*         Main          */
int main(int argc, char **argv) {
    int size = 5; 
    bool track[5];

    for(int i = 0; i < size; i++) {
	setTrack(size, track);
        mspPrim(size, track, graph, i);
	cout << endl;
    }

    cout << endl << endl;

    //setTrack(size, track);
    //mspKrus(size, track, graph, 0);

    return 0;
}

/*       Functions       */

void printLetter(int i) {
    char x;
    switch (i) {
	case 0: x = 'A'; break;
	case 1: x = 'B'; break;
	case 2: x = 'C'; break;
	case 3: x = 'D'; break;
	case 4: x = 'E'; break;
	default:
		cout << "Error" << endl;
		return;
    }
    cout << x << " ";
}

//This function finds the msp via Prim's Algorithm
void mspPrim(int size, bool track[], int graph[][5], int i) {
    int index;
    track[i] = true;
    printLetter(i);
    for(int j = 0; j < size; j++)
	if(!track[j] && graph[i][j] != 0) {
	    index = j;
	    break;
	}
    if(size == index)
	return;

    for(int j = 0; j < size; j++)
	if(!track[j])
	    if(graph[i][j] < graph[i][index] && graph[i][j] != 0) {
		index = j;
	    }
    if(size == index)
	return;
    if(!track[index])
	mspPrim(size, track, graph, index);
    for(int j = 0; j < size; j++)
	if(!track[j] && graph[i][j] != 0)
	    mspPrim(size, track, graph, index);

}

//This function finds the msp via Kruskal's Algorithm
void mspKrus(int size, bool track[], int graph[][5], int i) {


} 

void setTrack(int size, bool *track) {
    for(int i = 0; i < size; i++)
	track[i] = false;
}

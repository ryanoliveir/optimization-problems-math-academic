#include <iostream>
#include <math.h>
#include <string>

using namespace std;

void header();
void clear();
void enterInput();
float floatInput();
void minimunCostCalc(float* widthRiverBank,float* distance, float* earthCost, float* waterCost, float* cost);

int main(){

    float widthRiverBank,
    distance,
    earthCost,
    waterCost,
    cost = 0;

    do{
        header();
        clear();
        

        cout << "[*] Please provide the following information:" << endl;
        cout << "[*] Width of river bank (m): ";
        widthRiverBank = floatInput();
        cout << "[*] Distance from the Plant (m): ";
        distance = floatInput();
        cout << "[*] Cable cost in..." << endl;
        cout << "[*] Earth ($): ";
        earthCost = floatInput();
        cout << "[*] Water ($): ";
        waterCost = floatInput();
        // cout << "[*] Type 'q' to exit." << endl;

        minimunCostCalc(&widthRiverBank,&distance, &earthCost, &waterCost,&cost);
        
    } while (true);
   

    
}

void header()
{
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "|       OPTIMIZATION PROBLEM - Power Plant      |" << endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << endl;
}


void clear()
{
    system("clear || cls");
    header();
}

float floatInput(){
    float data;
    cin >> data;
    return data;
        
}

void minimunCostCalc(float* widthRiverBank,float* distance, float* earthCost, float* waterCost, float* cost){
    cout << *widthRiverBank << endl;
    cout << *distance << endl;
    cout << *earthCost << endl;
    cout << *waterCost << endl;
    cout << *cost << endl;

    enterInput();

}


void enterInput()
{
    cout << "\nPress Enter to Continue";
    _flushall();
    cin.ignore();
}
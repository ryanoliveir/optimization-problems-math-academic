#include <iostream>
#include <math.h>
#include <string>

using namespace std;

void header();
void clear();
void enterInput();
double doubleInput();
void minimunCostCalc(double* widthRiverBank,double* distance, double* earthCost, double* waterCost, double* cost, double* riverDistance, double* landDistance);

int main(){

    double widthRiverBank,
    distance,
    earthCost,
    waterCost,
    landDistance,
    riverDistance,
    cost = 0;

    do{
        header();
        clear();
        

        cout << "[*] Please provide the following information:" << endl;
        cout << "[*] Width of river bank (m): ";
        widthRiverBank = doubleInput();
        cout << "[*] Distance from the Plant (m): ";
        distance = doubleInput();
        cout << "[*] Cable cost in..." << endl;
        cout << "[*] Earth ($): ";
        earthCost = doubleInput();
        cout << "[*] Water ($): ";
        waterCost = doubleInput();
        // cout << "[*] Type 'q' to exit." << endl;

        minimunCostCalc(&widthRiverBank, &distance, &earthCost, &waterCost,&cost, &riverDistance, &landDistance);


        cout << "[---------------------------------------------------]" << endl;
        printf("[+] MINIMUN COST TO OPERATION: R$ %.2f\n", abs(cost) );
        printf("[+] Distance in land: %.2f\n", abs(landDistance) );        
        printf("[+] Distance in river: %.2f\n", abs(riverDistance) );
        cout << ("[+] f(x) = 5.[(900^2 + x^2)^0,5] + 4.(300 - x) ") << endl;
        cout << "[---------------------------------------------------]" << endl;
        enterInput();
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

double doubleInput(){
    double data;
    cin >> data;
    return data;
        
}

void minimunCostCalc(double* widthRiverBank,double* distance, double* earthCost, double* waterCost, double* cost, double* riverDistance, double* landDistance){

    double auxEarth,
    auxWater,
    auxiliary_variable,
    x;

    auxWater = pow(*waterCost,2); 
    auxEarth = pow(*earthCost,2); 
    auxiliary_variable = abs( auxWater - auxEarth); 
    x = sqrt(auxEarth * pow(*widthRiverBank, 2) / auxiliary_variable);
    *riverDistance = sqrt(pow(*widthRiverBank, 2) + pow(x,2));
    *landDistance = *distance - x;

    *cost = (*waterCost * *riverDistance) + (*earthCost * *landDistance);    

}

void enterInput()
{
    cout << "\nPress Enter to Continue";
    _flushall();
    cin.ignore();
}
//
//  main.cpp
//  gasAndCarWashProgram
//
//  Created by Muhammad Awan on 3/12/19.
//  Copyright © 2019 Muhammad Awan. All rights reserved.
//

#include <iostream>
#include <iomanip>

using namespace std;

// Global variables/Arrays
int NUM_CUSTOMERS_BY_TYPE[4], NUM_CAR_WASHES_BY_TYPE[4];
float GALLONS_SOLD_BY_TYPE[4], TOTAL_GALLONS, TOTAL_CHARGES;
char WORKING;

// functions
void displayMenu() {
    cout << "\n\nWelcome to the car wash program!" << endl << endl;
    
    cout << "Please choose gas type below:" << endl;
    cout << "1: Economy" << endl << "2: Regular" << endl
    << "3: Mid-Grae" << endl << "4: Premium" << endl;
}

int getGasType() {
    int gasChoice;
    
    cout << endl << "Please enter the number value of the gas you would like: ";
    cin >> gasChoice;
    
    if (gasChoice < 1 || gasChoice > 4) {
        cout << "You entered an incorrect value. Defaulting to 4: Premium " << endl;
        return 4;
    }
    
    return gasChoice;
}

float getGallons() {
    float gallons;
    
    cout << "Enter the amount of gallons you would like: ";
    cin >> gallons;
    
    return gallons;
}

char getCarWash() {
    char userCarWash;
    
    cout << endl << endl << "Would you like a car wash? (Y/N) ";
    cin >> userCarWash;
    
    return userCarWash;
}

float getGasRate (int gasType, float gasRateArray[]) {
    gasType = gasType - 1;
    
    return gasRateArray[gasType];
}

float getWashRate(int gasType, float carWashRateArray[]) {
    gasType = gasType - 1;
    
    return carWashRateArray[gasType];
}

float calcAmount(float perGallonRate, float gallons, float carWashRate) {
    float gasRate = perGallonRate * gallons;
    if (gallons >= 10) {
        gasRate -= 1;
        cout << "\n\nCongratulations! You received a $1 discount!" << endl;
    }
    
    float total = gasRate + carWashRate;
    
    return total; //placeholder
}

// custom functions
void display() {
    //array of strings
    string nameArray[] = {"Economy", "Regular", "Mid-Grade", "Premium"};
    
    cout << endl << "-------------------------------" << endl;
//    cout << endl << endl << "Number of Customers" << endl;
//    cout << setw(20) << left << "Type 1: Economy" << right << NUM_CUSTOMERS_BY_TYPE[0] << endl;
//    cout << setw(20) << left << "Type 2: Regular" << right << NUM_CUSTOMERS_BY_TYPE[1] << endl;
//    cout << setw(20) << left << "Type 3: Mid-Grade" << right << NUM_CUSTOMERS_BY_TYPE[2] << endl;
//    cout << setw(20) << left << "Type 4: Premium" << right << NUM_CUSTOMERS_BY_TYPE[3] << endl;
    
    for (int x = 0; x < 4; ++x) {
        cout  << "Type " << x + 1 << ":" << nameArray[x] << setw(10) << right << NUM_CUSTOMERS_BY_TYPE[x] << endl;
    }
    
    cout << endl << endl << "Number of Car Washes by Type" << endl;
    cout << setw(20) << left << "Type 1: Economy" << right << NUM_CAR_WASHES_BY_TYPE[0] << endl;
    cout << setw(20) << left << "Type 2: Regular" << right << NUM_CAR_WASHES_BY_TYPE[1] << endl;
    cout << setw(20) << left << "Type 3: Mid-Grade" << right << NUM_CAR_WASHES_BY_TYPE[2] << endl;
    cout << setw(20) << left << "Type 4: Premium" << right << NUM_CAR_WASHES_BY_TYPE[3] << endl;
    
    cout << endl << endl << "Number of Gallons Sold by Type" << endl;
    cout << setw(20) << left << "Type 1: Economy" << right << GALLONS_SOLD_BY_TYPE[0] << endl;
    cout << setw(20) << left << "Type 2: Regular" << right << GALLONS_SOLD_BY_TYPE[1] << endl;
    cout << setw(20) << left << "Type 3: Mid-Grade" << right << GALLONS_SOLD_BY_TYPE[2] << endl;
    cout << setw(20) << left << "Type 4: Premium" << right << GALLONS_SOLD_BY_TYPE[3] << endl;
}

void endProgram() {
    char end;
    cout << endl << endl << "Would you like to end the program? (Y/N) ";
    cin >> end;
    
    if (tolower(end) == 'y') {
        WORKING = false;
    }
}

// MAIN
int main(int argc, const char * argv[]) {
    float gasRateArray[] = {2.99, 3.099, 3.199, 3.299};
    float carWashRateArray[] = {3.50, 3.00, 3.00, 2.50};
    WORKING = true;
    
    while (WORKING) {
        displayMenu();
        int userGasType = getGasType();
        int gasIndex = userGasType - 1;
        NUM_CUSTOMERS_BY_TYPE[gasIndex] += 1;
        
        float userGallons = getGallons();
        GALLONS_SOLD_BY_TYPE[gasIndex] += userGallons;
        TOTAL_GALLONS += userGallons;
        
        char userCarWash = getCarWash();
        float userGasRatePerGallon = getGasRate(userGasType, gasRateArray);
        
        float userCarWashRate;
        
        if (tolower(userCarWash) == 'y') {
            userCarWashRate = getWashRate(userGasType, carWashRateArray);
            NUM_CAR_WASHES_BY_TYPE[gasIndex] += 1;
        } else {
            userCarWashRate = 0.0;
        }
        
        float total = calcAmount(userGasRatePerGallon, userGallons, userCarWashRate);
        
        TOTAL_CHARGES += total;
        
        cout << "$" << total << endl;
        
        endProgram();
    }
    
    if (WORKING == false) {
        display();
        
        cout << endl << endl << "Grand Total Gallons Sold: " << TOTAL_GALLONS;
        cout << endl << endl << "Grand Total Charges: $" << TOTAL_CHARGES;
    }
  
    return 0;
}

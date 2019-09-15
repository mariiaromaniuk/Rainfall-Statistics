// Rainfall Statistics
// This program analyzes a year’s worth of rainfall data
// Mariia Romaniuk


#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Function prototypes
string getMonth(int);
void getData(double[], int);
double totalRainfall(double [], int);
double averageRainfall(double [], int);
int driestMonth(double [], int);
int wettestMonth(double [], int);
void displayReport(double, double, int, int, double[], int);


int main() {
    const int mths = 12;
    double rainfall[mths];
    double total, average, least, most;

    getData(rainfall, mths);

    total = totalRainfall(rainfall, mths);
    average = averageRainfall(rainfall, mths);
    least = driestMonth(rainfall, mths);
    most = wettestMonth(rainfall, mths);
    displayReport(total, average, least, most, rainfall, mths);
    
    return 0;
}

//Input the total rainfall for each of 12 months and store the data in the array passed to it
void getData(double rainfall[], int mths) {
    double rain;
    
    cout << "Enter the total rainfall for each of 12 months: \n";
    for (int i = 0; i < mths; i++) {
        do {
            cout << getMonth(i) << ": ";
            cin >> rain;
            
            if (rain < 0)
                cout << "Error! Rainfall amounts must be greater than 0.\n";
            
        } while(rain < 0);
        
        rainfall[i] = rain;
    }
}

//Calculates and returns the total rainfall for the 12 months
double totalRainfall(double rainfall[], int mths) {
    double total = 0;
    
    for (int i = 0; i < mths; i++)
        total += rainfall[i];
    
    return total;
}

//Calculates and returns the average rainfall for the 12 months
double averageRainfall(double rainfall[], int mths) {
    return totalRainfall(rainfall, mths) / mths;
}

//Calculates and retruns the month with the least rainfall
int driestMonth(double rainfall[], int mths) {
    int x;
    double driest = rainfall[0];
    for (int i = 0; i < mths; i++) {
        if(rainfall[i] < driest) {
           driest = rainfall[i];
           x = i;
        }
    }
    return x;
}

//Calculates and returns the month with the most rainfall
int wettestMonth(double rainfall[], int mths) {
    int x;
    double wettest = rainfall[0];
    for (int i = 0; i < mths; i++) {
        if(rainfall[i] > wettest) {
           wettest = rainfall[i];
            x = i;
        }
    }
    return x;
}

//Prints a summary rainfall report
void displayReport(double t, double a, int lr, int mr, double r[], int s) {
    cout << "\n\n    2010 Rain Report for Neversnows County\n\n";
    cout << fixed << showpoint << setprecision(2);
    cout << "Total rainfall: " << t << " inches\n";
    cout << "Average monthly rainfall: " << a << " inches\n";
    cout << "The least rain fell in " << getMonth(lr) << " with " << r[lr] << " inches.\n";
    cout << "The most rain fell in " << getMonth(mr) << " with " << r[mr] << " inches.\n";
}

//Returns a string with the name of the month
string getMonth(int mth) {
    string month;
    switch (mth + 1) {
        case 1 : month = "January";
            break;
        case 2 : month = "February";
            break;
        case 3 : month = "March";
            break;
        case 4 : month = "April";
            break;
        case 5 : month = "May";
            break;
        case 6 : month = "June";
            break;
        case 7 : month = "July";
            break;
        case 8 : month = "August";
            break;
        case 9 : month = "September";
            break;
        case 10: month = "October";
            break;
        case 11: month = "November";
            break;
        case 12: month = "December";
            break;
    }
    return month;
}

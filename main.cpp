#include <iostream>
using namespace std;

void inputTemperatures(double temps[], int days);
double calculateAverage(double temps[], int days);
double findHighest(double temps[], int days);
double findLowest(double temps[], int days);
void weeklyReport(double weeklyData[][7], int weeks);

int main() {
    int days;
    cout<<"Enter number of days to record temperature (max 7):";
    cin>>days;
    if (days < 1 || days > 7) {
        cout << "Invalid number of days!";
        return 1;
    }

    double temperatures[7];

    // Input data
    inputTemperatures(temperatures, days);

    int choice;
    do {
        cout<<"Weather Data Analyzer Menu"<<endl;
        cout<<"1. Show Average Temperature"<<endl;
        cout<<"2. Show Highest Temperature"<<endl;
        cout<<"3. Show Lowest Temperature"<<endl;
        cout<<"4. Weekly Temperature Report (2D Array)"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Choose an option: ";
        cin>>choice;

        switch(choice) {
            case 1:
                cout<<"Average Temperature:"<<calculateAverage(temperatures, days)<<"°C";
                break;

            case 2:
                cout<<"Highest Temperature:"<<findHighest(temperatures, days)<<"°C";
                break;

            case 3:
                cout<<"Lowest Temperature:"<<findLowest(temperatures, days)<<"°C";
                break;

            case 4: {
                double weekData[2][7]; // 2D array for 2 weeks

                cout<<"Enter temperature data for **2 weeks**, 7 days each:"<<endl;
                weeklyReport(weekData, 2);
                break;
            }

            case 5:
                cout<<"Exiting program"<<endl;
                break;

            default:
                cout<<"Invalid option! Try again."<<endl;
        }

    } while (choice != 5);

    return 0;
}

// Function to input daily temperatures
void inputTemperatures(double temps[], int days) {
    cout << "\nEnter temperature for " << days << " days:\n";
    for (int i = 0; i < days; i++) {
        cout << "Day " << i+1 << ": ";
        cin >> temps[i];
    }
}

// Calculate average
double calculateAverage(double temps[], int days) {
    double sum = 0;
    for (int i = 0; i < days; i++) sum += temps[i];
    return sum / days;
}

// Find highest temperature
double findHighest(double temps[], int days) {
    double max = temps[0];
    for (int i = 1; i < days; i++)
        if (temps[i] > max) max = temps[i]; // relational operator
    return max;
}

// Find lowest temperature
double findLowest(double temps[], int days) {
    double min = temps[0];
    for (int i = 1; i < days; i++)
        if (temps[i] < min) min = temps[i];
    return min;
}

// Handle weekly data (2D array)
void weeklyReport(double weeklyData[][7], int weeks) {
    // Input 2D array
    for (int i = 0; i < weeks; i++) {
        cout << "\n--- Week " << i+1 << " ---\n";
        for (int j = 0; j < 7; j++) {
            cout << "Day " << j+1 << ": ";
            cin >> weeklyData[i][j];
        }
    }

    // Display weekly report
    cout << "\n====== Weekly Report ======\n";
    for (int i = 0; i < weeks; i++) {
        cout << "Week " << i+1 << ": ";
        for (int j = 0; j < 7; j++)
            cout << weeklyData[i][j] << " ";
        cout << endl;
    }
}
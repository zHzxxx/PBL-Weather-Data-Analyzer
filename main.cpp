#include <iostream>
#include <limits>
using namespace std;

void inputTemperatures(double temps[], int days);
double calculateAverage(double temps[], int days);
double findHighest(double temps[], int days);
double findLowest(double temps[], int days);
void weeklyReport(double weeklyData[][7], int weeks);

int main() {
    int days;

    // VALIDATE NUMBER OF DAYS (1 to 7, no strings allowed)
    while (true) {
        cout << "Enter number of days to record temperature (max 7): ";
        cin >> days;

        if (cin.fail()) {
            cout << "Invalid input! Please enter a number between 1 and 7.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (days < 1 || days > 7) {
            cout << "Invalid number of days! Please enter between 1 and 7.\n";
            continue;
        }

        break; // valid input
    }

    double temperatures[7];
    inputTemperatures(temperatures, days);

    int choice;

    do {
        cout << "\nWeather Data Analyzer Menu\n";
        cout << "1. Show Average Temperature\n";
        cout << "2. Show Highest Temperature\n";
        cout << "3. Show Lowest Temperature\n";
        cout << "4. Weekly Temperature Report (2D Array)\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input! Enter a number between 1 and 5.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Average Temperature: "
                     << calculateAverage(temperatures, days) << " °C\n";
                break;

            case 2:
                cout << "Highest Temperature: "
                     << findHighest(temperatures, days) << " °C\n";
                break;

            case 3:
                cout << "Lowest Temperature: "
                     << findLowest(temperatures, days) << " °C\n";
                break;

            case 4: {
                double weekData[2][7];
                cout << "\nEnter temperature data for 2 weeks:\n";
                weeklyReport(weekData, 2);
                break;
            }

            case 5:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid option! Please choose between 1 and 5.\n";
        }

    } while (choice != 5);

    return 0;
}

// INPUT DAILY TEMPERATURES
void inputTemperatures(double temps[], int days) {
    cout << "\nEnter temperature for " << days << " days:\n";
    for (int i = 0; i < days; i++) {
        cout << "Day " << i + 1 << ": ";
        cin >> temps[i];
    }
}

// CALCULATE AVERAGE
double calculateAverage(double temps[], int days) {
    double sum = 0;
    for (int i = 0; i < days; i++)
        sum += temps[i];
    return sum / days;
}

// FIND HIGHEST TEMPERATURE
double findHighest(double temps[], int days) {
    double maxTemp = temps[0];
    for (int i = 1; i < days; i++)
        if (temps[i] > maxTemp)
            maxTemp = temps[i];
    return maxTemp;
}

// FIND LOWEST TEMPERATURE
double findLowest(double temps[], int days) {
    double minTemp = temps[0];
    for (int i = 1; i < days; i++)
        if (temps[i] < minTemp)
            minTemp = temps[i];
    return minTemp;
}

// WEEKLY REPORT USING 2D ARRAY
void weeklyReport(double weeklyData[][7], int weeks) {
    for (int i = 0; i < weeks; i++) {
        cout << "Week " << i + 1 << ":\n";
        for (int j = 0; j < 7; j++) {
            cout << "  Day " << j + 1 << ": ";
            cin >> weeklyData[i][j];
        }
    }

    cout << "\nWeekly Temperature Report:\n";
    for (int i = 0; i < weeks; i++) {
        cout << "Week " << i + 1 << ": ";
        for (int j = 0; j < 7; j++)
            cout << weeklyData[i][j] << " ";
        cout << endl;
    }
}

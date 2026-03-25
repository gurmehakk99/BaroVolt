#include <iostream>
#include <string>

using namespace std;

int main() {
    double temp_in, temp_out, volts;
    double k=1.0;
    int mat_type;

    cout << "BAROVOLT SIMULATOR" << endl;
    cout << "Enter the material type (1 for Al, 2 for Cu, 3 for Ceramic):";
    cin >> mat_type;

    //These are relative scaling constants.
    if (mat_type == 1) {
        k = 0.5; // Example value for Aluminium
    } else if (mat_type == 2) {
        k = 0.3; // Example value for Copper
    } else if (mat_type == 3) {
        k = 0.8; // Example value for Ceramic
    } else {
        cout << "Invalid material type. Defaulting to Aluminium." << endl;
        k = 0.5;
    }

    cout <<"Ambient (°C): "; cin >> temp_in;
    cout <<"Target (°C): "; cin >> temp_out;
    cout <<"Voltage (V): "; cin >> volts;

    if (temp_out >= temp_in) {
        cout << "Target temperature must be lower than ambient temperature." << endl;
        return 1;
    }

    //Calculation of the cooling rate.

    double cooling_rate = (volts*0.5)* k;
    double seconds= (temp_in-temp_out)/cooling_rate;

    printf("\nResults:"\
           "\nCooling Rate: %.2f °C/s"\
           "\nTime to reach target temperature: %.2f seconds\n", cooling_rate, seconds);

           return 0;
}
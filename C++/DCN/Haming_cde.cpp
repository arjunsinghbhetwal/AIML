#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Calculate number of parity bits
int calculateParityBits(const string& data) {
    int m = data.length();
    int r = 0;

    while ((1 << r) < (m + r + 1)) {
        r++;
    }

    return r;
}

// Generate Hamming Code
string generateHammingCode(const string& data) {
    int m = data.length();
    int r = calculateParityBits(data);

    int total_bits = m + r;

    // 1-indexed array, so position 0 is unused
    vector<char> hamming(total_bits + 1, '0');

    // Place data bits in positions other than powers of 2
    int j = 0;

    for (int i = 1; i <= total_bits; i++) {

        // Check if i is NOT a power of 2
        if ((i & (i - 1)) != 0) {
            hamming[i] = data[j];
            j++;
        }
    }

    // Calculate parity bits using even parity
    for (int p = 0; p < r; p++) {

        int position = (1 << p);
        int parity = 0;

        for (int i = 1; i <= total_bits; i++) {

            if (i & position) {
                parity ^= (hamming[i] - '0');
            }
        }

        hamming[position] = char(parity + '0');
    }

    // Convert vector to string
    string result = "";

    for (int i = 1; i <= total_bits; i++) {
        result += hamming[i];
    }

    return result;
}


// Find error position
int findErrorPosition(const string& received) {

    int n = received.length();
    int syndrome = 0;

    // Calculate syndrome
    int position = 1;

    while (position <= n) {

        int parity = 0;

        for (int i = 1; i <= n; i++) {

            if (i & position) {
                parity ^= (received[i - 1] - '0');
            }
        }

        if (parity != 0) {
            syndrome += position;
        }

        position *= 2;
    }

    return syndrome;
}


int main() {

    string data;

    cout << "Enter binary data: ";
    cin >> data;

    // Generate Hamming code
    string hamming_code = generateHammingCode(data);

    cout << "\nOriginal Data: " << data << endl;
    cout << "Generated Hamming Code: " << hamming_code << endl;


    // Introduce a single-bit error
    int error_position;

    cout << "\nEnter error position (1-based): ";
    cin >> error_position;

    string received = hamming_code;

    if (error_position >= 1 &&
        error_position <= received.length()) {

        // Flip the bit
        received[error_position - 1] =
            (received[error_position - 1] == '0') ? '1' : '0';
    }

    cout << "Received Code: " << received << endl;


    // Detect error
    int error = findErrorPosition(received);

    if (error == 0) {

        cout << "No error detected." << endl;

    } else {

        cout << "Error detected at position: "
             << error << endl;

        // Correct the error
        string corrected = received;

        corrected[error - 1] =
            (corrected[error - 1] == '0') ? '1' : '0';

        cout << "Corrected Hamming Code: "
             << corrected << endl;
    }

    return 0;
}
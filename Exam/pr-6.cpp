#include <iostream>
#include <fstream>

using namespace std;

class FileManager {
public:
    void readData(const string &filename) {
        ifstream file(filename);

        if (!file) {
            cerr << "Error opening file: " << filename << endl;
            return;
        }

        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
    }
};

int main() {
    FileManager fileManager;
    string filename;

    cout << "Enter the filename to read data from: ";
    cin >> filename;

    fileManager.readData(filename);

    return 0;
}

#include <iostream>

using namespace std;

void printBuildDateTime () {
    cout << __TIMESTAMP__ << endl;
}

int main() {
    printBuildDateTime();
}

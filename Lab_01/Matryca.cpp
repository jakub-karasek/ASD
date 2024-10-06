#include <iostream>
#include <string>
using namespace std;

int main() {
    string tapeta;
    
    cin >> tapeta;
    
    int akt = tapeta[0];
    int lastIndeks = 0;
    int wynik = tapeta.length();

    for (int i = 0; i < tapeta.length(); i++){
        if (tapeta[i] != '*'){
            if (akt == '*'){
                lastIndeks = i;
                akt = tapeta[i];
            }
            else if (akt == tapeta[i]){
                lastIndeks = i;
            } else {
                wynik = min(wynik, i - lastIndeks - 1);
                lastIndeks = i;
                akt = tapeta[i];
            }
        }
    }

    if (wynik == tapeta.length()){
        cout << 1 << endl;
        return 0;
    }

    cout << tapeta.length() - wynik << endl;
    return 0;
}
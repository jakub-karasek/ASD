#include <iostream>
#include <string>
using namespace std;

int main() {
    string wallpaper;
    
    cin >> wallpaper;
    
    int curr = wallpaper[0];
    int lastIndex = 0;
    int result = wallpaper.length();

    for (int i = 0; i < wallpaper.length(); i++){
        if (wallpaper[i] != '*'){
            if (curr == '*'){
                lastIndex = i;
                curr = wallpaper[i];
            }
            else if (curr == wallpaper[i]){
                lastIndex = i;
            } else {
                result = min(result, i - lastIndex - 1);
                lastIndex = i;
                curr = wallpaper[i];
            }
        }
    }

    if (result == wallpaper.length()){
        cout << 1 << endl;
        return 0;
    }

    cout << wallpaper.length() - result << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int singleBaz(vector<int> vec, int length, int k){
    nth_element(vec.begin(), vec.end() - k, vec.end());

    int sum = 0;

    for (int i = (vec.size() - k); i < vec.size(); i++){
        sum += vec.at(i);
    }


    if (sum % 2 == 1){
        return sum;
    }

    int najwP = 0;
    int najwNP = 0;
    int najmP = 0;
    int najmNP = 0;

    for (int i = 0; i <= (length - k) - 1; i++){
        if (vec.at(i) % 2 ==0){
            if (najwP == 0 || najwP < vec.at(i)) najwP = vec.at(i);
        }
        else if (najwNP == 0 || najwNP < vec.at(i)) najwNP = vec.at(i);
    }

    for (int i = (length - k); i < length; i++){
        if (vec[i] % 2 ==0){
            if (najmP == 0 || najmP > vec[i]) najmP = vec[i];
        }
        else if (najmNP == 0 || najmNP > vec[i]) najmNP = vec[i];
    }

    bool PtoNP = (najmP != 0 && najwNP != 0);
    bool NPtoP = (najmNP != 0 && najwP != 0);

    if (PtoNP == false){
        if (NPtoP == false) {
            return -1;
        }
        int diff = najwNP - najmP;
        sum += diff;
    }
    else{ // PtoNP == true
        if (NPtoP == false){
            int diff = najwP - najmNP;
            sum += diff;
        } else{
            int diff = najwP - najmNP;
            if (najwNP - najmP > diff) diff = najwNP - najmP;
            sum += diff;
        }
    }

    return sum;

}

void printArray(vector<int> vec, int len){
    for (int i = 0; i < len; i++){
        cout << vec.at(i) << " ";
    }
    cout << endl;
}

int doItOnce(vector<int> P, vector<int> NP, int len1, int len2, int k){
    int i1 = 1;
    int i2 = 1;
    int sum = 0;
    int count = 0;

    while (i1 < len1 && i2 < len2){
        cout << "k: " << k << " count: " << count << endl;
        if (count == k) { // mamy wszystko
            return sum;
            cout << "wynik: " << sum << endl;
        }

        if (count == (k - 1)){ // brakuje ostatniego
            if (i1 - 1 < len1){ //jest ostatni parszysty
                cout << "dodaje: " << P[i1 - 1] << endl;
                sum += P[i1 - 1];
                cout << "wynik: " << sum << endl;
                return sum;
            }
            cout << "brakuje parzystego" << endl;
            return -1; // brakuje ostatniego
        }

        if (NP[i2 - 1] + NP[i2] >= P[i1 - 1] + P[i1]){ // para nieparzystych jest wieksza
            cout << "dodaje: " << NP[i2 - 1] << " i " << NP[i2] << endl;
            sum += NP[i2 - 1] + NP[i2];
            i2 += 2;
            count += 2;
        }
        else{ // para parzystych wieksza (biore jedna parzysta)
            cout << "dodaje: " << P[i1 - 1] << endl;
            sum += P[i1 - 1];
            count++;
            i1++;
        }
    }

    if (count == (k - 1)){ // brakuje ostatniego
        if (i1 - 1 <= len1){ //jest ostatni parszysty
            cout << "dodaje: " << P[i1 - 1] << endl;
            sum += P[i1 - 1];
            cout << "wynik: " << sum << endl;
            return sum;
        }
        cout << "brakuje parzystego" << endl;
        return -1; // brakuje ostatniego
    }

    if (i2 >= len2){ // zostaly same parzyste
        cout << "zostaly same parzyste" << endl;
        i1--;
        while (count < k){
            if (i1 >= len1){
                cout << "brakuje parzystego" << endl;
                return -1; // brakuje ostatniego
            }
            sum += P[i1];
            count++;
            i1++;
        }
    }

    else{ // zostaly same nieparzyste
        cout << "zostaly same nieparzyste" << endl;
        if ((k - count) % 2 == 0){
            i2--;
            while (count < k){
                if (i2 >= len2){
                    cout << "brakuje nieparzystego" << endl;
                    return -1; // brakuje ostatniego
                }
                sum += NP[i2];
                count++;
                i2++;
            }
        }
        else {
            cout << "wynik parzysty" << endl;
            return -1;
        }

    }

    cout << "wynik: " << sum << endl;
    return sum;



}

int main() {
    /*int length;  // Variable to store the length of the vector
    //cout << "Enter the length of the vector: ";
    cin >> length;

    vector<int> vec;  // Declare an empty vector of integers

    // Take input for all vector elements
    //cout << "Enter " << length << " elements:\n";
    for (int i = 0; i < length; ++i) {
        int element;
        cin >> element;
        vec.push_back(element);  // Add the element to the vector
    }

    int n;  
    cin >> n;
     */

    int n = 0;

    int length = 11;
    vector<int> vec = {1, 1, 2, 2, 4, 5, 5, 6, 7, 8, 9};
    int k = 5;

    vector<int> P;
    vector<int> NP;

    for (int i = length - 1; i >= 0; i--){
        if (vec[i] % 2 == 0) P.push_back(vec[i]);
        else NP.push_back(vec[i]);
    }

    if (NP.empty()) {
        for (int i = 0; i < n; i++){
            cout << -1 << endl;
        }
        return 0;
    }

    int sum = NP.front();
    NP.erase(NP.begin());

    cout << "parzyste: ";
    printArray(P, P.size());
    cout << "nieparzyste: ";
    printArray(NP, NP.size());
    int result = doItOnce(P, NP, P.size(), NP.size(), k - 1);
    //cout << result << endl;

    if (result == -1){
        cout << "nie da sie" << endl;
        return -1;
    }

    sum += result;
    cout << "koncowy wynik: " << sum << endl;
    return 0;

    for (int i = 0; i < n; i++){
        int k;
        cin >> k;
        int result = doItOnce(P, NP, P.size(), NP.size(), k);
        cout << result << endl;
    }


    return 0;
}

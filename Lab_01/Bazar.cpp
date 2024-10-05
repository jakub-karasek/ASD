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

int main() {
    int length;  // Variable to store the length of the vector
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

    for (int i = 0; i < n; i++){
        int k;
        cin >> k;
        int result = singleBaz(vec, length, k);
        cout << result << endl;
    }

    
    return 0;
}

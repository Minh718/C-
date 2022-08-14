#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
using namespace std;
int calculateNoOfWaitingDays(const string input7Str, const string input7Matrix[], const int k)
{
    int N7, d, c;
    int V;
    string s;
    for (size_t i = 0; i < input7Str.length(); i++) {
        if (input7Str[i] == ' ') {
            N7 = stoi(s);
            s = ""; i++;
            for (; i < input7Str.length(); i++) {
                if (input7Str[i] == ' ') {
                    V = stoi(s);
                    s = ""; i++;
                    for (; i < input7Str.length(); i++) {
                        if (input7Str[i] == ' ') {
                            d = stoi(s);
                            s = ""; i++;
                            for (; i < input7Str.length(); i++) {
                                s += input7Str[i];
                                if (i == input7Str.length() - 1) {
                                    c = stoi(s);
                                    s = "";
                                }
                            }
                        }
                        else {
                            s += input7Str[i];
                        }
                    }
                }
                else {
                    s += input7Str[i];
                }
            }
        }
        else {
            s += input7Str[i];
        }
    }
    long long** arr = new long long* [N7];
    int** arr1 = new int* [N7];
    long long** arr2 = new long long* [N7];
    for (int i = 0; i < N7; i++) {
        arr[i] = new long long[N7];
        arr1[i] = new int[N7];
        arr2[i] = new long long[N7];
    }
    size_t kk = -1;
    cout<<kk<<endl;
    for (int i = 0; i < N7; i++) {
        for (int j = 0; j < N7; j++) {
            kk++;
            for (; kk < input7Matrix[0].size(); kk++)
                if (input7Matrix[0][kk] == ' ') {
                    arr[i][j] = atoi(s.c_str());
                    s = "";
                    break;
                }
                else {
                    s += input7Matrix[0][kk];
                    if (kk == input7Matrix[0].size() - 1) {
                        arr[i][j] = atoi(s.c_str());
                        s = "";
                        kk = -1;
                        break;
                    }
                }
        }
    }
     for (int i = 0; i < N7; i++) {
        for (int j = 0; j < N7; j++) {
                cout<<arr[i][j]<<" ";
        }
        cout<<endl;
     }
    for (int l = 1; l < k; l++) {
        kk = -1;
        for (int i = 0; i < N7; i++) {
            for (int j = 0; j < N7; j++) {
                kk++;
                for (; kk < input7Matrix[l].size(); kk++)
                    if (input7Matrix[l][kk] == ' ') {
                        arr1[i][j] = atoi(s.c_str());
                        s = "";
                        break;
                    }
                    else {
                        s += input7Matrix[l][kk];
                        if (kk == input7Matrix[l].size() - 1) {
                            arr1[i][j] = atoi(s.c_str());
                            s = "";
                            kk = -1;
                            break;
                        }
                    }
            }
        }
//        for (int i = 0; i < N7; i++) {
//        for (int j = 0; j < N7; j++) {
//                cout<<arr1[i][j]<<" ";
//        }
//        cout<<endl;
//     }
        for (int i = 0; i < N7; i++) {
            for (int j = 0; j < N7; j++) {
                arr2[i][j] = arr[i][j];
            }
        }
        for (int i = 0; i < N7; i++) {
            for (int j = 0; j < N7; j++) {
                arr[i][j] = 0;
                for (int ii = 0; ii < N7; ii++) {
                    arr[i][j] += arr2[i][ii] * arr1[ii][j];
                }
            }
        }
    }
    for (int i = 0; i < N7; i++) {
        for (int j = 0; j < N7; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << arr[d - 1][c - 1] % V << endl;
    return arr[d - 1][c - 1] % V;
}
int main() {
    ifstream ifs("testcase.txt");
    int k;
    ifs >> k;
    ifs.ignore();
    string* input7Str = new string();
    string* input7Matrix = new string[k];
    getline(ifs, *input7Str);
    for (int i = 0; i < k; i++) {
        getline(ifs, input7Matrix[i]);
    }
    //cout << "Answer for task 7: " << calculateNoOfWaitingDays(*input7Str, input7Matrix, k) << endl;
    calculateNoOfWaitingDays(*input7Str, input7Matrix, k);
}

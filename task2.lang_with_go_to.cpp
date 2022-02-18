#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>


using namespace std;


int main()
{
    ifstream fin("task1.txt");


    vector<string> stop_words = { "for", "of", "the", "of", "on", "in", "a", "an" };
    vector<pair<string, vector<int>>> alphafit(1000000, make_pair("", vector<int>(101, false)));
    int size = 0;
    int curLine = 0;
    string s, line;
    char c;



readLine:
    if (!fin.eof()) {
        getline(fin, line);
        curLine++;
        stringstream ss(line);
    readLabel:
        if (ss >> s) {
            int i = 0;
            bool found = false;
        findLabel:
            if (i < size) {
                if (s == alphafit[i].first) {
                    found = true;
                    int j = 0;
                occurenciesLoop:
                    if (alphafit[i].second[j] == 0) {
                        alphafit[i].second[j] = curLine / 45 + 1;
                        j = 100;
                    }
                    j++;
                    if (j <= 100) {
                        goto occurenciesLoop;
                    }




                    i = size; 
                }
                i++;
                goto findLabel;
            }

            if (!found) {
                alphafit[size].first = s;
                alphafit[size].second[0] = curLine / 45 + 1;
                size++;
            }
            goto readLabel;
        }
        goto readLine;
    }


    int j = 0;
    int i = 0;
    Loop1:
    if (i < size - 1) 
    {
        j = 0;
    Loop2:
        if (j < size - i - 1) 
        {
            if (alphafit[j].first > alphafit[j + 1].first)
            {
                swap(alphafit[j], alphafit[j + 1]);
            }

            j++;
            goto Loop2;
        }
        i++;
        goto Loop1;
    }


    int n = size;
    i = 0;
    print:
    if (i < n) {
        if (alphafit[i].second[100] == 0) {
            cout << alphafit[i].first << '\n';
            int j = 0;
        pr:
            if (alphafit[i].second[j] != 0) {
                cout << alphafit[i].second[j] << ' ';
                j++;
                goto pr;
            }
            cout << endl;
        }
        i++;

        goto print;
    }
    return 0;
}

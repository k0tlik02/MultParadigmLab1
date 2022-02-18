#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <ctype.h>
using namespace std;



int main()
{

    ifstream fin("paradigm.txt");

    int n;
    cin >> n;
    cout << "n=" << n << endl;

    vector<string> stop_words = { "for", "of", "the", "of", "on", "in", "a", "an" };
    vector<pair<string, int>> words(100000);


    int size = 0;
    string word;
    char c;


read_word:
    fin >> word;
    if (isupper(word[0]))
    {
        word[0] += 32;
    }


    int i = 0;
    bool b = false;
search_stop_word:
    if (i < stop_words.size()) {
        if (word == stop_words[i]) {
            goto read_word;
        }
        i++;
        goto search_stop_word;
    }



    i = 0;
    b = false;
findLabel:
    if (i < size) {
        if (word == words[i].first) {
            b = true;
            words[i].second++;
            i = size;
        }
        i++;
        goto findLabel;
    }

    if (!b) {
        words[size++] = make_pair(word, 1);
    }
    if (!fin.eof()) {
        goto read_word;
    }


    int j = 0;

    i = 0;
Loop1:
    if (i < size - 1) {
        j = 0;
    Loop2:
        if (j < size - i - 1)
        {
            if (words[j].second < words[j + 1].second)
            {
                swap(words[j], words[j + 1]);
            }

            j++;
            goto Loop2;
        }
        i++;
        goto Loop1;
    }




    int index = 0;
writting:
    if (index < n) {
        cout << "word: " << words[index].first << " - " << words[index].second << " times" << endl;
        index++;
        goto writting;
    }
}
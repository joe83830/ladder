
#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include "console.h"
#include "set.h"
#include "queue.h"
#include "stack.h"
#include "filelib.h"
#include "simpio.h"

using namespace std;
Set<string> ImportDic(ifstream &in, Set<string> &Words);

int main() {


    ifstream in;

    while (true){

        in.open(getLine("Dictionary file name? "));

        if (in.is_open()){
            break;
        } else if (in.fail()){

            cout << "Unable to open that file.  Try again." << endl;
        }
    }



    //Stuff the words in the dic in the Set
    Set<string> Words;
    Words = ImportDic(in, Words);
    cout << Words.size() << endl;
    in.close();



    cout << "Have a nice day." << endl;
    return 0;
}

Set<string> ImportDic(ifstream &in, Set<string> &Words){

    while(true){

        string line;
        getline(in, line);
        Words.add(line);

        if(in.fail()){

            break;
        }

    }
    return Words;

}

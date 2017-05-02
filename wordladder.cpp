
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
Set<string> ImportDict(ifstream &in, Set<string> &Words);
stack<string> BFS(Set<string> &Words, string &a, string &b);

int main() {

    //Intro
    cout << "Welcome to CS 106B Word Ladder." << endl
         << "Please give me two English words, and I will change the" << endl
         << "first into the second by changing one letter at a time." << endl;

    //Open dict file
    ifstream in;

    while (true){

        in.open(getLine("Dictionary file name? "));

        if (in.is_open()){
            break;
        } else if (in.fail()){

            cout << "Unable to open that file.  Try again." << endl;
        }
    }



    //Stuff the words into the Set
    Set<string> Words;
    Words = ImportDict(in, Words);
    cout << Words.size() << endl;
    in.close();

    //Prompt user for words

    string a, b;

    while (true){

        a = getLine("Word #1 (or Enter to quit):");
        if (a.empty()){

            break;
        }

        b = getLine("Word #2 (or Enter to quit):");
        if (b.empty()){

            break;
        }

        if (!Words.contains(a) || !Words.contains(b)){

            cout << "Invalid word, please enter words again. " << endl;
        } else if (a.length() != b.length()){

            cout << "Two Words have different length, please re-enter. " << endl;

        } else{

            stack<string> A;
            A = BFS(Words, a, b);
            cout << "ur ready to move on to the next step" << endl;
        }

    }



    cout << "Have a nice day." << endl;
    return 0;
}

Set<string> ImportDict(ifstream &in, Set<string> &Words){

    while (true){

        string line;
        getline(in, line);
        Words.add(line);

        if (in.fail()){

            break;
        }

    }
    return Words;

}

stack<string> BFS(Set<string> &Words, string &a, string &b){

    Queue<stack<string> > Tube;
    stack<string> w;
    w.push(a);
    Tube.enqueue(w);

    while (!Tube.isEmpty()){

        stack<string> ss = Tube.dequeue();
        string s = ss.pop();


        for (int i = 0; i < s.length(); i++){

            for (char j = 97; j <= 122; j++){


            }

        }

    }
    return BFS;

}


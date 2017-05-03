
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
Stack<string> BFS(Set<string> &Words, string &a, string &b);

int main() {

    //Intro
    cout << "Welcome to CS 106B Word Ladder." << endl
         << "Please give me two English words, and I will change the" << endl
         << "first into the second by changing one letter at a time." << endl;

    //Open dict file
    ifstream in;

    while (true){

        in.open(trim(toLowerCase(getLine("Dictionary file name? "))));

        if (in.is_open()){
            break;
        } else if (in.fail()){

            cout << "Unable to open that file.  Try again." << endl;
        }
    }

    //Stuff the words into the Set
    Set<string> Words;
    Words = ImportDict(in, Words);
    //cout << Words.contains("caa") << endl;
    in.close();

    //Prompt user for words

    string a, b;

    while (true){

        cout << endl;
        a = trim(toLowerCase(getLine("Word #1 (or Enter to quit):")));
        if (a.empty()){

            break;
        }

        b = trim(toLowerCase(getLine("Word #2 (or Enter to quit):")));
        if (b.empty()){

            break;
        }

        if (!Words.contains(a) || !Words.contains(b)){

            cout << "The two words must be found in the dictionary." << endl;


        } else if (a.length() != b.length()){

            cout << "The two words must be the same length." << endl;


        } else{

            Stack<string> FinalStack = BFS(Words, a, b);
            cout << "A ladder from " << b << " back to " << a << ": " << endl;
            int tempSize = FinalStack.size();
            for (int size = 0; size < tempSize; size ++){

                cout << FinalStack.peek() << " ";
                FinalStack.pop();
            }

            cout << endl;
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

Stack<string> BFS(Set<string> &Words, string &a, string &b){

    //Create an empty queue of stacks.
    Queue<Stack<string> > Tube;

    //Create/add a stack containing {w1} to the queue.
    Stack<string> w;
    w.push(a);
    Tube.enqueue(w);
    Set<string> Used;
    //While the queue is not empty:
    while (!Tube.isEmpty()){

        //Dequeue the partial-ladder stack from the front of the queue.

        Stack<string> ss = Tube.dequeue();
        string s = ss.peek();

        Used.add(s);

        for (int i = 0; i < s.length(); i++){

            s = ss.peek();

            for (char j = 97; j <= 122; j++){

                s[i] = j;

                if (Words.contains(s) && !Used.contains(s) ){
                    if (s == b) {

                        Stack<string> copy = ss;
                        copy.push(s);

                        return copy;
                        break;

                    } else {

                        Stack<string> copy = ss;
                        copy.push(s);

                        Tube.enqueue(copy);

                        Used.add(s);

                    }

                }

            }

        }

    }
    Stack<string> empty;
    empty.push("The two words must be different.");
    return empty;

}

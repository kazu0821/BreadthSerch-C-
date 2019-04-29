

#ifndef ANAGRAMSET_H
#define ANAGRAMSET_H

#include "LetterBag.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


class AnagramSet {

private:
    vector<string> words;


public:

    const LetterBag key;

    friend ostream &operator<<(ostream &out, const AnagramSet &s){
        out << "{" << s.key.toString() <<  ": " ;

        for(int index=0; index < s.getSize(); index++){
            out << s.getWords()[index] << "," ;
        }

        out << "}";

        return out;
    };

// Member functions

    AnagramSet(const LetterBag &theKey){


    };
    void insert(const string &s){
        LetterBag temp(s);
        if(temp == key){
            words.push_back(s);
        }
    };   // insert s into the set of words

    void remove(const string &s){
        int index =0;
        for(index; index< words.size(); index++) {
            if(words[index] == s){
                break;
            }

        }
        if(index <words.size()){
            words.erase(words.begin()+index);

        }
    };   // remove s from the set of words




    int getSize() const{
        return words.size();
    };   // return the number of words, i.e. size of the word set




    bool contains(const string &s){
        if (words.size() == 0) {
            return false;
        }
        else {
            int index = 0;
            for (index; index < words.size(); index++) {

                if (words[index] == s) {
                    return true;
                }
            }
        }
        return false;
    };  // return true iff s is in the word set




    void clear(){
        words.clear();
    };    // remove all the words



    vector<string> getWords() const{
        return words;
    };  // return a copy of the words vector



// we won't need a getKey since the key is a public constant.
};

#endif
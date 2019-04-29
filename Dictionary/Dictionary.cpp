#include "Dictionary.h"
#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// return pointer to the node containing key or return null if not found.
AnagramSet * Dictionary :: find(AnagramSet * head, const LetterBag & key) const {

    for(int i=0;i< tableSize; i++){

        if((head+i) == nullptr);

        else
            if(key == (head+i)->key){
            return head+i;
        }
    }
    return nullptr;

};


// insert a new AnagramSet at the beginning of the chain.
void Dictionary :: insertNew(int index, AnagramSet * toInsert){

    toInsert->next =hashTable[index];
    hashTable[index] =toInsert;

} ;


Dictionary:: Dictionary()  // default constructor: creates an empty dictionary.
{
    clear();
}

Dictionary::Dictionary(string fileName){// insert all words from the file into an empty dictionary.
    ifstream in;
    in.open(fileName);v

    AnagramSet * toInsert;
    string s;
    int index;
    while(in >> s){
       insertNew(index, toInsert);
    }

};
Dictionary::Dictionary(string words[], int arraySize) {// insert all words from the array into an empty dictionary.
    LetterBag key(words);
    int index = hashing(key .toString(), numWords);

    AnagramSet *pointer = hashTable[index];
    while(pointer && pointer->key != key)
        pointer =pointer->next;
    if(pointer != nullptr){
        insertNew(index, pointer);
    }

};


// copy constructor
Dictionary:: Dictionary(const Dictionary & d){


    numWords =d.numWords;

    for(int i=0;i < tableSize;i++){

        insertWords(hashTable);
    }

    //AnagramSet* hashTable[tableSize] = {copyTable };

    for(int i=0;i< numWords;i++){
        hashTable = d.hashTable;
    }



};

Dictionary::~Dictionary(){// destructor

    clear();
};

int Dictionary::hashing(const string key, int size) const
{
    // int s[]={AnagramSet};


    unsigned int h = key[0];
    for (int i = 1; i < key.length(); i++){
       h =2*h+(key[i]-'a');
    }

    return h % size;
}



int Dictionary :: getNumWords() const{
    return numWords;

};  // return number of words.



void Dictionary::clear()
{
    for( int i = 0; i < tableSize; i++ )
    {
        AnagramSet *setPtr = hashTable[i];
        while(setPtr)
        {
            AnagramSet *nextPtr = setPtr->next; // replace setPtr to nextPtr
            delete setPtr;
            setPtr = nextPtr; //remove the setPtr
        }
        hashTable[i] = nullptr;
    }
    numWords = 0;
    return;
}



bool Dictionary :: insertWord(const string &w){
    AnagramSet *temp = findWord(w);
    if(temp == nullptr){
        temp->insert(w);

        return true;
    }
    else{
        return false;
    }

};  // insert a word, return true if wasn’t already there, false if already there.



int Dictionary:: insertWords(const vector<string> v){ // insert multiple words and return how many weren’t already there.

    int n =0;
    for(unsigned i =0; i< v.size();i++){
        if(insertWord(v[i]))
            n++;
    }
    return n;

};

bool Dictionary ::  removeWord(string w){
    AnagramSet *temp = findWord(w);
    if(temp != nullptr){
        temp->remove(w);

        return true;
    }
    else{
        return false;
    }


};  // remove the word. Return true if it was there to be removed and false otherwise.


bool Dictionary :: contains(string word) const{

    AnagramSet *temp = findWord(word);

    if(numWords == 0){
        return false;
    }
    else{
        int index =0;
        for (index; index < numWords; index++){

            if(hashTable[index] == temp){
                return true;
            }
        }
        return false;
    }

} ;

vector<string> Dictionary :: getWords(const string & word) const {




LetterBag temp(word);
AnagramSet *t = findWord(temp.toString());

return t->getWords();







};  // return words that are anagrams for the given word.


AnagramSet * Dictionary ::findWord(const string &w) const{
// return the AnagramSet whose key is goes with the given word.
// loop through hash table and for each index call find above.

    LetterBag key(w);
    int index = hashing(key .toString(), numWords);

    AnagramSet *pointer = hashTable[index];
    while(pointer && pointer->key != key)
        pointer =pointer->next;
    if(pointer != nullptr){
        return pointer;
    }
    return 0;



}

int Dictionary :: getNumAnagrams(const string & word) const{

    LetterBag key(word);
    int index = hashing(key .toString(), numWords);

    AnagramSet *pointer = hashTable[index];
    while(pointer && pointer->key != key)
        pointer =pointer->next;
    if(pointer != nullptr){
        return pointer->getSize();
    }
    return 0;

//return hashTable.size();

};  // return number of anagrammatic forms found for the given word.



void Dictionary :: printDictionary(int limit = tableSize, ostream & out = cout) const{

    for(int i=0, j=0; limit && i< tableSize;i++){
        if(hashTable[i]){
            out << setw(limit);
            AnagramSet *pointer =hashTable[i];
            while(pointer) {
                out << *pointer;
                if (pointer->next) {
                    pointer = pointer->next;
                }
                out << endl;
                j++;
            }
        }
        out << "total words is " << numWords <<" and " << limit << endl;

    }

//
//
//
//Dictionary ::Dictionary() {
//    int tableSize = 10;
//    numWords=0;
//    hashTable = new AnagramSet *[tableSize]();
//
//}
//
//Dictionary::Dictionary(int tS)
//{
//    int tableSize = tS;
//    numWords = 0;
//    hashTable = new AnagramSet *[tableSize]();
//}
//
//Dictionary::Dictionary(string w[], int nW, int tS )
//{
//   int tableSize = tS;
//    numWords = 0;
//    hashTable = new AnagramSet *[tableSize]();
//    for( int i = 0; i < nW; i++ )
//    {
//        insertNew(w[i]);
//    }
//}



//    int index =0;
//out << "{" ;
//for(index; index < numWords;index++){
//    out << hashTable[index] << ",";
//
//}
//
//out << "}";



//void Dictionary::insert( const string w )
//{
//string k = w;
//    sort( k.begin(), k.end() );
//    int hashValue = hashing(k);
//    if( !hashTable[hashValue] )
//    {
//        hashTable[hashValue] = new AnagramSet(k);
//        if( hashTable[hashValue]->insert(w) )
//        {
//            numWords++;
//            return;
//        }
//        return;
//    }
//    AnagramSet *setPtr = hashTable[hashValue];
//    AnagramSet *prePtr = nullptr;
//    while( setPtr && setPtr->key != k )
//    {
//        prePtr = setPtr;
//        setPtr = setPtr->next;
//    }
//    if( setPtr && setPtr->key == k )
//    {
//        if(setPtr->insert(w))
//        {
//            numWords++;
//            return;
//        }
//        return;
//    }
//    setPtr = new AnagramSet(k);
//    if(!setPtr->insert(w) )
//    {
//        return;
//    }
//    prePtr->next = setPtr;
//    numWords++;
//    return;
//}

//void Dictionary::remove( const string w )
//{
//    string k = w;
//    sort( k.begin(), k.end() );
//    int hashValue = hashing(k);
//    AnagramSet *setPtr = hashTable[hashValue];
//    AnagramSet *prePtr = nullptr;
//    while( setPtr && setPtr->key != k )
//    {
//        prePtr = setPtr;
//        setPtr = setPtr->next;
//    }
//    if( !setPtr || setPtr->key != k )
//    {
//        return;
//    }
//    if(!setPtr->remove(w))
//    {
//        return;
//    }
//    if( setPtr->getSize() == 0 )
//    {
//        if( prePtr )
//        {
//            prePtr->next = setPtr->next;
//        }
//        else
//        {
//            hashTable[hashValue] = setPtr->next;
//        }
//        delete setPtr;
//    }
//    numWords--;
//    return;
//}





}; // print AnagramSets in each bucket of table.



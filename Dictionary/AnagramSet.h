
#ifndef ANAGRAMSET_H
#define ANAGRAMSET_H

#include <string>
#include <vector>
#include "LetterBag.h"
using namespace std;


class AnagramSet {
    // output the AnagramSet in a format like {aet: ate, eat, eta, tea}
    // aet is the key as a sorted string and ate, eat ... are the words. 
    //friend ostream & operator<< (ostream & out, const AnagramSet & s);

    friend ostream & operator<< (ostream & out, const AnagramSet & set) {
        out << "{ ";
        out << set.key.toString() << ": ";
        unsigned int sz = set.words.size();
        for (unsigned int i = 0; i < sz; i++) {
            out << set.words[i];
            if (i < sz - 1)
                cout << ",";
            else cout << " ";
        }
        cout << "}";
        return out;
    }
private:
    vector<string> words;
   

public:
    AnagramSet * next;
    const LetterBag key;
    AnagramSet(const LetterBag  & theKey) : key(theKey), next(nullptr)
    {
    }

  
    
    AnagramSet(const LetterBag & theKey, const string & theWord): 
        key(theKey), next(nullptr) {
        insert(theWord);
    }

  
    // insert s into the set of words
    void insert(const string & s) {
        int last = words.size()-1;
        if (words.empty() || s > words[last]) {
            words.push_back(s);
            return;
        }   
        if (s == words[0] || s == words[last])
            return;
        if (s < words[0]) {
            words.insert(words.begin(), s);
            return;
        }
        // there are at least two elements and s is greater than words[0]
        for (vector<string>::iterator i = words.begin() + 1; i != words.end(); i++)
        {
            if (i == words.end()) words.insert(i, s);
            if (s <= *i) {
                if (s != *i)
                    words.insert(i, s);
                return;
            }
        }
    }
    // remove s from the set of words
    void remove(const string & s)
    {
        vector<string>::iterator position = words.end();
        for (vector<string>::iterator i = words.begin();  i != words.end(); i++)
     
            if (*i == s) {
                position = i;
                break;
            }
        if (position != words.end()) words.erase(position);
    }
   
    int getSize() const // return the number of words
    {
        return words.size();
    }
	/*
	int getSize() const {
		return words.getSize();
	}
    */
    // return true if the set of words is empty
    bool isEmpty() const {
        return words.empty();
    }
    /*
	bool isEmpty() const {
		return words.isEmpty();
	}
    */


    bool contains(const string & s) {
        //return words.find(s);
        int i = 0, j = words.size() - 1;
        while (i < j) {
            int mid = (i + j) / 2;
            if (s <= words[mid]) j = mid;
            else i = mid + 1;
        }
        return words[i] == s;
    }

       

	void clear() {
		words.clear();
	}

	bool operator==(const AnagramSet & a) const {
		return key == a.key;
	}
	bool operator!=(const AnagramSet & a) const {
		return key != a.key;
	}

	bool operator<(const AnagramSet & a) const {
		return key < a.key;
	}
	bool operator<=(const AnagramSet & a) const {
		return key <= a.key;
	}

	bool operator>(const AnagramSet & a) const {
		return key > a.key;
	}
	bool operator>=(const AnagramSet & a) const {
		return key >= a.key;
	}
    vector<string> getWords() const {
        return words;
    }


    /*
	static string sortString(string  s) {
			
		for (int i = 0; i< s.length(); i++) {
			int minIndex = i;
			for (int j = i+1; j < s.length(); j++) 
				if (s[j] < s[minIndex])
					minIndex = j;
			swap(s[i], s[minIndex]);	
		}
			return s;
	}
    */

	static string normalize(string s) {
		string t = "";
		for (unsigned int i = 0; i < s.length(); i++) {
			char c = s[i];
			if (c <= 'Z' && c >= 'A')     c += ('a' - 'A');
			if (c <= 'z' && c >= 'a')     t+= c;
		}
		return t;
	}




	

};


#endif

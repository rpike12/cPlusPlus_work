
#include "classes.h"
#include<fstream>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstdlib> 
#include<time.h>
using namespace std;

//WORD

    int Word::get_word_length() const { 
        return wordLen;
    }

    void Word::set_word_length(const int LENGTH) {
        wordLen = LENGTH;
    }

    vector<string> Word::get_sized_word_list() {
        wordFile.open("words.txt");
        vector<string> sortedWordList;
        string word;
        while (wordFile >> word) {
            if (word.length() == wordLen) {  
            sortedWordList.push_back(word);
            }
        }
        return sortedWordList; 
    } // loops to find only words with size wordLen, append all qualifying words to sizedWordList

    void Word::set_sized_word_list(vector<string> wordList) {
        sizedWordList = wordList;
    }


    int Word::get_rand_word() {
        srand(time(0)); 
        rand();
        int size = sizedWordList.size();
        int randIndex = rand() % (size);
        chosenRandWord = sizedWordList[randIndex];
        cout << "Your random word is: " << chosenRandWord << endl;
        return randIndex;
    } // chosen random word from sizedWordList, sets chosen word to chosenRandWord

    void Word::set_index(int indexNum) {
        indexOfRandWord = indexNum;
    }

    vector<vector<char>> Word::split_word_list_into_letters() {
            vector<vector<char>> splitVector;
            for(int i = 0; i < sizedWordList.size(); i++) {
                vector<char> letterVec;
                for(int j = 0; j < sizedWordList[i].length(); j++) {
                    letterVec.push_back(sizedWordList[i][j]);
                } 
                splitVector.push_back(letterVec);
                 
            }
            //use randIndex to get split random word, set split random word, then remove that index and set split word update list

            // for(int k=0; k < splitVector.size(); k++) {
            //         for(int p=0; p < splitVector[k].size(); p++) {
            //             cout << splitVector[k].at(p) << " ";
            //         }
            //         cout << endl;
            //     } 
            
        return splitVector;

    } //splits words into separate letters, puts into own vector then appends to large list of split words
    

    void Word::set_split_words_vector(vector<vector<char>> inputSplitVector) {
        splitWordsVector = inputSplitVector;
    }

    void Word::set_split_word() {
            
            randWordSplit = splitWordsVector[indexOfRandWord];

            // for(int k = 0; k < randWordSplit.size(); k++) {
            //     cout << randWordSplit[k] << " ";
            // }
            // cout << endl;
    }

    void Word::set_split_vector_without_rand_word() {
            splitWordsVector.erase(splitWordsVector.begin() + indexOfRandWord);
            
    }

//ANAGRAM

    vector<string> Word::find_anagrams() { //use splitWordsVector and randWordSplit
    // for each word in splitWordsVector, if all letters in splitWordsVector are in randWordSplit, then append splitWordsVector[i] to anagram list
        for (int i = 0; i < splitWordsVector.size(); i++) {
            int counter = 0;
            for (int j = 0; j < splitWordsVector[i].size(); j++ ) {
                if (find(splitWordsVector[i].begin(), splitWordsVector[i].end(), randWordSplit[j]) != splitWordsVector[i].end()) {
                    counter++; //problem is need if all letters in splitWordsVector[i] are in randWordSplit
                }
            }
            if (counter == splitWordsVector[i].size()) {
                splitAnagramVector.push_back(splitWordsVector[i]); //append splitWordsVector[i] to correct split anagrams list
            }
        

        } //loops through all letter combinations, checks if any combinations match any word in total wordList, if so, appends word to anagramList
        //print if size = 0 then no anagramas, else print anagrams
        
        
        if (splitAnagramVector.size() == 0) { //final print/print results if there are any
            cout << "Your random word doesn't have any anagrams in this word set" << endl;
        }
        else {
            cout << "The following word(s) is/are anagrams of your random word: " << endl;
            for(int k=0; k < splitAnagramVector.size(); k++) {
                    for(int p=0; p < splitAnagramVector[k].size(); p++) {
                        cout << splitAnagramVector[k].at(p);
                    }
                    cout << endl;
            } 
        }
        
    }

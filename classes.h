#ifndef CLASSES_H
#define CLASSES_H

#include<fstream>
#include<vector>
#include<string>
using namespace std;
 

class Word {

    private:
    int wordLen; //user inputted word length
    ifstream wordFile;
    vector<string> sizedWordList; //list of words with size wordLen
    string chosenRandWord; //random word choice
    int indexOfRandWord;
    vector<vector<char>> splitWordsVector;
    vector<char> randWordSplit; // list of letters in chosen word
    vector<vector<char>> splitAnagramVector; 

    vector<string> anagramList; // list of all anagrams possible from letters given by WordRand class

    string inputWord; // word that user inputs


    public:
    int get_word_length() const;
    void set_word_length(const int LENGTH);
    vector<string> get_sized_word_list(); // loops through word file to find only words with size wordLen, append all qualifying words to sizedWordList 
    void set_sized_word_list(vector<string> wordList);
    int get_rand_word(); // chosen random word from sizedWordList, sets chosen word to chosenRandWord
    void set_index(int indexNum);
    vector<vector<char>> split_word_list_into_letters(); //splits words into separate letters, puts into own vectors
    void set_split_words_vector(vector<vector<char>> inputSplitVector);
    void set_split_word(); //sets 4
    void set_split_vector_without_rand_word();
    
    vector<string> find_anagrams(); //loops through all letter combinations, checks if any combinations match any word in total wordList, if so, appends word to anagramList
};


#endif 
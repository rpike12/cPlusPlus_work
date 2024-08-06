/* CSCI 200: Final Project
 *
 * Author: XXXX (Ryan Pike)
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // list here any outside assistance you used/received while following the
 *     // CS@Mines Collaboration Policy and the Mines Academic Code of Honor
 *  https://www.educba.com/c-plus-plus-find/ used to figure out parameters for the .find() function 
 *
 * XXXXXXXX (Anagram algorithm)
 */
#include <iostream>
#include <cstdlib> 
#include <vector>
#include <time.h>
using namespace std;
#include "classes.h"

int main() {

    Word userWord;
    
    int x; // change so no global vars used
    cout << "Input a word length between 3-8 letters" << endl;
    cin >> x;
    
    while (x > 8 || x < 3) {
        cout << "Please input a word length that is between 3-8 letters" << endl;
        cin >> x;
    }  
    
    userWord.set_word_length(x);
    userWord.get_word_length(); //why does vector size equal 0 if I have this and split in there?
    userWord.set_sized_word_list(userWord.get_sized_word_list());
    userWord.set_index(userWord.get_rand_word());
    userWord.set_split_words_vector(userWord.split_word_list_into_letters());
    userWord.set_split_word();
    userWord.set_split_vector_without_rand_word();
    userWord.find_anagrams();
    // 2d vector: split each word in sizedWordList into its own vector of letters
    // then check if all letters in each word that is in sizedWordList, are also in chosenRandWord
    // if all letters that are in a sizedWordList word, are also in chosenRandWord, then it is an anagram of chosenRandWord 

    return 0;
}
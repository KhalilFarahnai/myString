#pragma once
#include<iostream>
#include<string>
#include<cmath>
#include<vector>
using namespace std;

namespace myString {
    //this function for reading string
    string readString() {
        string str;
        cout << "Please enter the string:  ";
        getline(cin, str);
        return str;
    }

    //return sub string
    string subString(int begin, int end, string str)
    {
        if (begin < 0)
            begin = 0;
        if (end > len(str))
            end = len(str);
        string newStr = "";
        for (int i = begin; i < end; i++) {
            newStr += str[i];
        }
        return newStr;
    }

    //delete an interval 
    string remove(int begin, int end, string oldString) {
        return subString(0, begin, oldString) + subString(end, oldString.length(), oldString);
    }

    //return does the word belong to the sentence
    bool WordIsExistInSentence(string sentence, string word) {
        int i;
        for (int i = 0; i < sentence.length() - word.length(); i++)
        {
            if (subString(i, i + word.length(), sentence) == word)
                return true;
        }
        return false;
    }

    //return are the two words equal whether uppercase or lowercase character
    bool isSameWord(string word1, string word2) {
        if (word1.length() != word2.length())
            return false;
        else {
            for (int i = 0; i < word1.length(); i++) {
                if (!((word1[i] == word2[i]) || (word1[i] == word2[i] + 32) || (word1[i] == word2[i] - 32)))
                    return false;
            }
            return true;
        }
    }

    //transfer all uppercase characters
    string upper(string str) {
        for (int i = 0; i < len(str); i++)
        {
            if (str[i] > 96 && str[i] < 123)
                str[i] = str[i] - 32;
        }
        return str;
    }

    //transfer all lowercase characters
    string lower(string str) {
        for (int i = 0; i < len(str); i++)
        {
            if (str[i] > 64 && str[i] < 91)
                str[i] = str[i] + 32;
        }
        return str;
    }

    //return string such that the first is capital and the other is lower case
    string capitalize(string str) {
        int i;
        for (i = 0; i < len(str); i++) {
            if (str[i] > 64 && str[i] < 91) break;
            if (str[i] > 96 && str[i] < 123)
            {
                str[i] = str[i] - 32;
                break;
            }
        }
        for (i = i + 1; i < len(str); i++) {
            if (str[i] > 64 && str[i] < 91)
            {
                str[i] = str[i] + 32;
            }
        }
        return str;
    }

    //takes as parameter starting index and sentence and return the first word
    string cutFirstWord(int begin, string str) {
        string word = "";
        for (int i = begin; i < len(str); i++) {
            if (str[i] != ' ')
                word += str[i];
            else if (word != "")
                break;
        }
        return word;
    }

    //Transfer the first character of all uppercase words
    string title(string str) {
        string  newStr = "";
        for (int i = 0; i < len(str); i++) {
            if (str[i] != ' ') {
                string oneWord = capitalize(cutFirstWord(i, str));
                newStr += oneWord;
                i += oneWord.length() - 1;
            }
            else
                newStr += str[i];
        }
        return newStr;
    }

    //return the position of the first occurrence of character in string
    int find(string str, char c) {
        for (int i = 0; i < len(str); i++) {
            if (str[i] == c)
                return i;
        }
        return -1;
    }

    //return the position of the first occurrence of character in string But the beginning is on the right
    int rFind(string str, char c) {
        for (int i = len(str) - 1; i >= 0; i--) {
            if (str[i] == c)
                return i;
        }
        return -1;
    }

    //return number of occurrences of a character
    int count(string str, int c) {
        int k = 0;
        for (int i = 0; i < len(str); i++)
        {
            if (str[i] == c)
                k++;
        }
        return k;
    }

    //Delete any character written before the sentence
    string left(string str, char c) {
        int i = 0;
        while (str[i] == c)
        {
            i++;
        }
        str = remove(0, i, str);
        return str;
    }

    //Delete any character written after the sentence
    string right(string str, char c) {
        int i = len(str) - 1;
        while (str[i] == c)
        {
            i--;
        }
        str = remove(i, len(str), str);
        return str;
    }

    //Delete any character written before and after the sentence
    string rightLeft(string str, char c) {
        str = right(str, c);
        str = left(str, c);
        return str;
    }

    //reverse words in a sentence
    string reverseOrderWord(string sentence) {
        string newString = "";
        for (int i = sentence.length() - 1; i >= 0; i--)
        {
            string word = "";
            while (sentence[i] != ' ' && i > 0)
            {
                word = sentence[i] + word;
                i--;
            }
            if (i == 0)
                word = sentence[0] + word;
            newString += word + ' ';
        }
        return newString;
    }

    //replace a word with another word in a sentence whether it is majus minus
    string replace(string oldString, string oldWord, string newWord) {
        for (int i = 0; i < oldString.length() - oldWord.length() + 1; i++)
        {
            if (isSameWord(subString(i, i + oldWord.length(), oldString), oldWord))
            {
                oldString = remove(i, i + oldWord.length(), oldString);
                oldString = subString(0, i, oldString) + newWord + subString(i, oldString.length(), oldString);
                i += newWord.length() - 1;
            }
        }
        return oldString;
    }

    //transfer a sentence to words and save thim in vector
    vector <string> sentenceToWords(string sentence, char cut, vector <string> v)
    {
        for (int i = 0; i < sentence.length(); i++)
        {
            string mot = "";
            while (sentence[i] != cut && i < sentence.length())
            {
                mot += sentence[i];
                i++;
            }
            if (mot.length() != 0)
                v.push_back(mot);
        }
        return v;
    }

    //insert a word by position (index)
    string insert(int pos, string word, string sentence) {
        return  subString(0, pos, sentence) + word + subString(pos, sentence.length(), sentence);
    }

    //Delete the last character and return the string
    string removeLastCharacter(string str)
    {
        string s = "";
        for (int i = 0; i < len(str) - 1; i++)
            s += str[i];
        return s;
    }

    //Reverse the string
    string reverse(string str)
    {
        string s = "";
        for (int i = len(str) - 1; i >= 0; i--)
            s += str[i];
        return s;
    }

    //return  true if all character is number
    bool isDecimal(string str) {
        for (int i = 0; i < len(str); i++) {
            if (!(str[i] > 47 && str[i] < 58))
                return false;
        }
        return true;
    }

    //return true if the character is number
    bool isDigit(char c) {
        if (c > 47 && c < 58)
            return true;
        return false;
    }

    //return true if all character is ascii (arabic character non ascii)
    bool isAscii(string str) {
        for (int i = 0; i < len(str); i++) {
            if (!(str[i] > -1 && str[i] < 128))
                return false;
        }
        return true;
    }

    //return true if all  character is number and alphabet
    bool isAllNumberAndAlphabet(string str) {
        if (len(str) == 0)
            return false;
        for (int i = 0; i < len(str); i++) {
            if (!((str[i] > 47 && str[i] < 58) || (str[i] > 64 && str[i] < 91) || (str[i] > 96 && str[i] < 123)))
                return false;
        }
        return true;
    }

    //return true if all character is alphabet
    bool isAlphabet(string str) {
        if (len(str) == 0)
            return false;
        for (int i = 0; i < len(str); i++) {
            if (!((str[i] > 64 && str[i] < 91) || (str[i] > 96 && str[i] < 123)))
                return false;
        }
        return true;
    }

    //return spaces 
    string spaces(int s) {
        string space = "";
        for (int i = 0; i < s; i++) {
            space += ' ';
        }
        return space;
    }

    //changer spaces by number of spaces enter as parameter
    string spaceInSentence(string str, int num)
    {
        if (num < 0)
            return str;
        for (int i = 0; i < len(str); i++) {
            if (str[i] == ' ')
            {
                int numSpace = 0;
                while (i < len(str) && str[i] == ' ')
                {
                    numSpace++;
                    i++;
                }
                str = remove(i - numSpace, i, str);
                str = subString(0, i - numSpace, str) + spaces(num) + subString(i - numSpace, len(str), str);
                i = (i - numSpace) + num;
            }
        }
        return str;
    }

    //return if a variable name respects the programming conditions
    bool isProgrammingName(string str)
    {
        if (str[0] > 47 && str[0] < 58)
            return false;
        for (int i = 0; i < len(str); i++) {
            if (!(str[i] == 95 || (str[i] > 64 && str[i] < 91) || (str[i] > 96 && str[i] < 123)))
                return false;
        }
        return true;
    }

    //return true if all uppercase strings
    bool isUpper(string str)
    {
        for (int i = 0; i < len(str); i++) {
            if (!(str[i] > 64 && str[i] < 91))
                return false;
        }
        return true;
    }

    //return true if all lowerase strings
    bool isLower(string str)
    {
        for (int i = 0; i < len(str); i++) {
            if (!(str[i] > 96 && str[i] < 123))
                return false;
        }
        return true;
    }

    //return true if all character are spaces
    bool allAreSpaces(string str)
    {
        if (len(str) == 0)
            return false;
        for (int i = 0; i < len(str); i++) {
            if (str[i] != 32)
                return false;
        }
        return true;
    }

    //return true if all words degin by uppercase
    bool isTitle(string str)
    {
        string newString;
        return (str == title(str));
    }

    //return true if begin by uppercase
    bool isCapitalize(string str)
    {
        string newString;
        return (str == capitalize(str));
    }

    //separate array words with a string
    string join(string arr[], int length, string word) {
        string newStr;
        for (int i = 0; i < length - 1; i++)
            newStr += arr[i] + word;
        newStr += arr[length - 1];
        return newStr;
    }

    //add character at begining of string

    string AddCharFromBegin(string str, char c) {
        return (c + str);
    }

    //add char to the left such nbChar + lenWord = newLen  
    string lFromatWithCharacter(string sentence, char c, int newLen) {
        int l = len(sentence);
        for (int i = 0; i < newLen - l; i++)
            sentence = AddCharFromBegin(sentence, c);
        return sentence;
    }

    //add char to the right such nbChar + lenWord = newLen
    string rFromatWithCharacter(string sentence, char c, int newLen) {
        int l = len(sentence);
        for (int i = 0; i < newLen - l; i++)
            sentence += c;
        return sentence;
    }

    //add spaces to the right such nbChar + lenWord = newLen
    string rFormat(string str, int newLen) {
        return rFromatWithCharacter(str, ' ', newLen);
    }

    //add spaces to the left such nbChar + lenWord = newLen
    string lFormat(string str, int newLen) {
        return lFromatWithCharacter(str, ' ', newLen);
    }

    //remove first character c
    string lRemoveCharacter(string str, char c) {
        for (int i = 0; i < len(str); i++) {
            if (str[i] == c) {
                str = subString(0, i, str) + subString(i + 1, len(str), str);
                break;
            }
        }
        return str;
    }

    //remove last character c
    string rRemoveCharacter(string str, char c) {
        for (int i = len(str) - 1; i > -1; i--) {
            if (str[i] == c) {
                str = subString(0, i, str) + subString(i + 1, len(str), str);
                break;
            }
        }
        return str;
    }

    //return length of string
    int len(string str) {
        int i = 0;
        while (str != "")
        {
            i++;
            str = removeLastCharacter(str);
        }
        return i;
    }

    //check if char belongs to string
    bool charIsInString(string str, char c) {
        for (int i = 0; i < len(str); i++) {
            if (str[i] == c)
                return true;
        }
        return false;
    }

    // used to delete all the leading characters mentioned in its argument.
    string lStrip(string sentence, string word) {
        while (sentence != "") {
            if (charIsInString(word, sentence[0])) {
                word = lRemoveCharacter(word, sentence[0]);
                sentence = lRemoveCharacter(sentence, sentence[0]);
            }
            else
                break;
        }
        return sentence;
    }

    //used to delete all the trailing characters mentioned in its argument.
    string rStrip(string sentence, string word) {
        while (sentence != "") {
            if (charIsInString(word, sentence[len(sentence) - 1])) {
                word = lRemoveCharacter(word, sentence[len(sentence) - 1]);
                sentence = rRemoveCharacter(sentence, sentence[len(sentence) - 1]);
            }
            else
                break;
        }
        return sentence;
    }

    //delete a part in string provided starting from the beginning
    string removePrefix(string sentence, string word) {
        if (subString(0, len(word), sentence) == word)
            sentence = subString(len(word), len(sentence), sentence);
        return sentence;
    }

    //delete a part in string provided starting from the end
    string removeSuffix(string sentence, string word) {
        if (subString(len(sentence) - len(word), len(sentence), sentence) == word)
            sentence = subString(0, len(sentence) - len(word), sentence);
        return sentence;
    }

    //cut the string to the 3 string by a given character (example: partition(khalilfarhani,f,arr) return [khalil,f,arhani])
    void partition(string sentence, char c, string arr[3]) {
        for (int i = 0; i < len(sentence); i++) {
            if (sentence[i] == c) {
                arr[0] = subString(0, i, sentence);
                arr[1] = c;
                arr[2] = subString(i + 1, len(sentence), sentence);
                break;
            }
        }
    }

    //remove string
    void clear(string& str) {
        str = "";
    }

    //convert char (0....9) to number('0'....'9')
    char intToChar(int number) {
        return char(number + 48);
    }

    //convert char ('0'....'9') to number(0....9)
    int charToInt(char c) {
        return int(c - 48);
    }

    //return position character
    char charAt(string str, int num) {
        for (int i = 0; i < len(str); i++) {
            if (num == i || i == len(str) + num)
                return str[i];
        }
        return char(0);
    }

    //return char position start counter from left
    int lIndexChar(string str, char c) {
        for (int i = 0; i < len(str); i++) {
            if (c == str[i])
               return  i;
        }
        return -1;
    }

    //return char position start counter from right
    int rIndexChar(string str, char c) {
        for (int i = len(str)-1; i >= 0; i--) {
            if (c == str[i])
                return i;
        }
        return -1;
    }

    //return string n times
    string repeat(string str, int time) {
        string newStr = str;
        for (int i = 1; i < time; i++) {
            newStr += str;
        }
        return newStr;
    }

    //return char n times
    string repeatChar(char c, int time) {
        string newStr = "";
        for (int i = 0; i < time; i++) {
            newStr += c;
        }
        return newStr;
    }

    //return as sub String but advance noraml negative value and if parameter (2,6) -> (6,2)
    string subStringAdvanced(int begin, int end, string str)
    {
        int aux,l=len(str);
        if (begin < 0)
            begin = l + begin;
        if (end < 0 && end > -1 * l)
            end = l + end;

        if (end < begin) {
            aux = begin;
            begin = end;
            end = aux;
        }

        if (begin < -1 * l)
            begin = 0;
        if (end > l)
            end = l;

        string newStr = "";
        for (int i = begin; i < end; i++) {
            newStr += str[i];
        }
        return newStr;
    }

    //true if (word = first part of sentence) from the start
    bool startWith(string str,string word, int depart) {
        int l = len(str);
        if (depart < -l)
            depart = 0;
        if (depart < 0)
            depart += l;
        return subString(depart,word.length() + depart,str) == word ? true : false;
    }

    //true if (word = last part of sentence) from the start
    bool endWith(string str, string word, int depart) {
        int l = len(str);
        if (depart < -l)
            depart = 0;
        if (depart < 0)
            depart += l;
        if (l - depart < word.length())  return false;
        return subString(len(str)-word.length(), len(str), str) == word ? true : false;
    }
    
    //true if word included in sentence from the start
    bool include(string str, string word, int depart) {
        int l = len(str);
        if (depart < -l)
            depart = 0;
        if (depart < 0)
            depart += l;
        for (int i = depart; i < l-word.length(); i++) {
            if (subString(i, word.length() + i, str) == word)
                return true;
        }
        return false;
    }

    //return position of first character  word in sentence
    int index(string word, string str) {
        for (int i = 0; i < len(str)-word.length()+1; i++) {
            if (word == subString(i, i + word.length(), str))
                return i;
        }
        return -1;
    }

    //return sub string with begining and length
    string subStringWithLen(int start, int length,string str) {
        return subString(start, start + length, str);
    }

    //swap(str1,str2)  
    void swap(string &str1, string &str2) {
        string tmp;
        tmp = str1;
        str1 = str2;
        str2 = tmp;
    }
}




































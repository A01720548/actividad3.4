/**
 * @file Actividad 3.4
 * @author Esteban de la Maza, Raul Jerlach, Ricardo Jasso
 * @brief
 * @version 0.1
 * @date 2020-10-25
 *
 * @copyright Copyright (c) 2020
 *
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "BinarySearchTree.h"

using namespace std;

/**
 * @brief This function takes the line read from the file
 * and returns a string that has 0s where neeeded
 *
 * Complexity: O(n)
 * @param singleLine String read from file
 * @return string With 0s where needed
 */
string getIp(string singleLine) {
    string formattedString;
    formattedString = singleLine.substr(16);
    string retVal;
    int spacePos;
    vector<string> vec;

    size_t pos = 0;
    string token;
    string delimiter = ".";
    while ((pos = formattedString.find(delimiter)) != string::npos) {
        token = formattedString.substr(0, pos);

        while (token.size() < 3) {
            token = '0' + token;
        }

        formattedString.erase(0, pos + delimiter.length());

        vec.push_back(token);
    }

    while (formattedString.size() < 8) {
        formattedString = '0' + formattedString;
    }

    formattedString = formattedString.substr(0, 7);

    vec.push_back(formattedString);
    for (int i = 0; i < vec.size(); i++) {
        retVal = retVal + vec[i];
    }
    return retVal;
}

/**
 * @brief Recieves the string from file and returns the content
 * of what happened
 *
 * @param singleLine Read from file
 * @return string Content that will be inserted into tree node
 */
string getContent(string singleLine) {
    string content = singleLine.substr(29);
    int spacePos = content.find(" ");
    content = content.substr(spacePos);
    return content;
}
int main() {

    ifstream file("bitacora.txt", ios::binary);
    BinarySearchTree myTree; //recursive list from standard library

    string singleLine;
    while (getline(file, singleLine)) {
        myTree.insert(getIp(singleLine), getContent(singleLine));
    }


    cout << myTree.getSize() << " lines in memory" << endl;
    file.close();

    myTree.getTop5();

    return 0;
}
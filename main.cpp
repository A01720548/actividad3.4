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

    myTree.printPreOrder();

    cout << myTree.getSize() << " lines in memory" << endl;
    file.close();


    /**
         * @brief This for loop will output into our file the ips that meet the criteria
         * Complexity: O(n)
         */
         // ofstream sorted("result.txt", ios::binary);
         // for (list<string>::iterator i = start; i != end; i++)
         //     sorted << *i << endl;

         // sorted << *end << endl;
    return 0;
}
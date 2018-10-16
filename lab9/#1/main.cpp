#include <iostream>
#include <fstream>
#include "funcs.h"
#include <cstring>

using namespace std;

int main() {
    ifstream in("input.txt");
    while (1) {
        if (in.eof())
            break;

        bool isDigit = false;
        char buf[100];
        int data[100]{0},counter=0;
        in >> buf;

        if (isdigit(buf[0])) {
			conversion(buf, data, counter);
            isDigit = true;
        };
        if (palindrome(buf)) {
            if (isDigit) cout << getMax(data,counter) << " ";
            else cout << getMax(buf) << " ";
        }
        else if (grow(data,counter) || grow(buf))
        {
            if (isDigit) 
				cout << getMid(data,counter) << " ";
            else 
				cout << getMid(buf) << " ";
        }
        else cout << buf << " ";
	}
    in.close();
    return 0;
}

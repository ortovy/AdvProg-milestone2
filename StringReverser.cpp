//
// Created by omer on 12/01/2020.
//

#include "StringReverser.h"
#include <string>
string StringReverser::solve(string s) {
    int len = s.length();
    for (int i = 0; i < len / 2; i++) {
        swap(s[i], s[len - i - 1]);
    }
    return s;
}
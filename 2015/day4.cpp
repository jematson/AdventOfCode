#include <iostream>
#include <string>
#include "md5.h"

using namespace std;

string input = "yzbqklnj";

void part1() {

    auto num = 1;

    while (true) {

        auto plug = input + to_string(num);

        auto thing = md5(plug);

        if (thing.substr(0,5) == "00000") {
            cout << plug << endl;
            cout << thing << endl;
            break;
        }

        num++;
    }

    cout << "Part 1 Answer: " << num << endl;
}

void part2() {

    auto num = 1;

    while (true) {

        auto plug = input + to_string(num);

        auto thing = md5(plug);

        if (thing.substr(0,6) == "000000") {
            cout << plug << endl;
            cout << thing << endl;
            break;
        }

        num++;
    }

    cout << "Part 2 Answer: " << num << endl;
}


int main() {
    part1();
    part2();

    return 0;
}
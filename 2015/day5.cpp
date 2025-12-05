#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void part1() {

    string input;
    ifstream File("input.txt");

    auto total = 0;

    while(getline(File, input)) {

        int vowels = 0;
        bool twice = false;

        // Check for forbidden strings
        if (input.find("ab") == string::npos &&
            input.find("cd") == string::npos &&
            input.find("pq") == string::npos &&
            input.find("xy") == string::npos) {

            
            for (auto i = 0; i < input.length(); i++) {
                char c = input[i];

                // Check for vowels
                if (c == 'a' ||
                    c == 'e' ||
                    c == 'i' ||
                    c == 'o' ||
                    c == 'u')
                    vowels++;
                
                // Check for doubles
                if (i < input.length()-1) {
                    if (c == input[i+1])
                        twice = true;
                }
            }

            if (vowels >= 3 && twice)
                total++; 
        }
    }

    cout << "Part 1 Answer: " << total << endl;

}

void part2() {

    string input;
    ifstream File("input.txt");

    while(getline(File, input)) {

    }

    cout << "Part 2 Answer: " << "" << endl;
}

int main() {

    part1();
    part2();

    return 0;
}
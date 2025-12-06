#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void part1() {

    string input;
    ifstream File("input.txt");
    
    vector<long> first;
    vector<long> second;
    vector<long> third;
    vector<long> fourth;
    vector<string> ops;

    int line = 1;
    while(getline(File, input)) {
        string curr = "";

        for (char c : input) {
            if (c == ' ') {
                if (curr != "") {
                    if (line == 1)
                        first.push_back(stol(curr));
                    else if (line == 2)
                        second.push_back(stol(curr));
                    else if (line == 3)
                        third.push_back(stol(curr));
                    else if (line == 4)
                        fourth.push_back(stol(curr));
                    else if (line == 5)
                        ops.push_back(curr);
                    
                    curr = "";
                }
            
            } else {
                curr += c;
            }
        }

        if(curr != "") {
            if (line == 1)
                first.push_back(stoi(curr));
            else if (line == 2)
                second.push_back(stoi(curr));
            else if (line == 3)
                third.push_back(stoi(curr));
            else if (line == 4)
                fourth.push_back(stoi(curr));
            else if (line == 5)
                ops.push_back(curr);
        }

        line++;
    }
    


    size_t total = 0;

    for (int i = 0; i < first.size(); i++) {
        if (ops[i] == "+") {
            total += (first[i] + second[i] + third[i] + fourth[i]);
        } else if (ops[i] == "*") {
            total += (first[i] * second[i] * third[i] * fourth[i]);
        }
    }

    cout << "Part 1 Answer: " << total << endl << endl;

}

void part2() {

    string input;
    ifstream File("input.txt");
    
    vector<string> lines;

    int line = 0;
    while(getline(File, input)) {
        lines.push_back(input);
        line++;
    }

    vector<vector<string>> operands;

    vector<string> chunk = {"","","",""};

    // Handle lines with numbers
    int index = 0;
    for(int i = 0; i < lines[0].length(); i++) {

        // Reached end of single problem column
        if (lines[0][i] == ' ' && lines[1][i] == ' ' && lines[2][i] == ' ' && lines[3][i] == ' ') {
            operands.push_back({});

            // Parse vertically
            int chunk_length = chunk[0].length();

            for (int j=0; j<chunk_length; j++) {
                
                string first_value = chunk[0][j] == ' ' ? "" : string(1, chunk[0][j]);
                operands[index].push_back(first_value);

                if (chunk[1][j] != ' ') {
                    operands[index][j].push_back(chunk[1][j]);
                }
                if (chunk[2][j] != ' ') {
                    operands[index][j].push_back(chunk[2][j]);
                }
                if (chunk[3][j] != ' ') {
                    operands[index][j].push_back(chunk[3][j]);
                }
            }

            index++;
            chunk = {"","","",""};

        // Add digits
        } else {
            for (int j=0; j<4; j++) {
                chunk[j].push_back(lines[j][i]);
            }
                
        }
    }
    // Handle last problem (Doesn't have column of spaces after it)
    operands.push_back({});
    int chunk_length = chunk[0].length();
    for (int j=0; j<chunk_length; j++) {
        
        string first_value = chunk[0][j] == ' ' ? "" : string(1, chunk[0][j]);
        operands[index].push_back(first_value);

        if (chunk[1][j] != ' ') {
            operands[index][j].push_back(chunk[1][j]);
        }
        if (chunk[2][j] != ' ') {
            operands[index][j].push_back(chunk[2][j]);
        }
        if (chunk[3][j] != ' ') {
            operands[index][j].push_back(chunk[3][j]);
        }
    }

    // Handle operator line
    string curr = "";
    index = 0;

    for(char c : lines[4]) {
        if (c == ' ') {
            if (curr != "") {
                operands[index].push_back(curr);
                index++;
                curr = "";
            }
        } else {
            curr += c;
        }
    }
    if (curr != "")
        operands[index].push_back(curr);

    
    for(auto problem : operands) {
        for (auto x : problem) {
            cout << x << ".";
        }
        cout << endl;
    }
    

    // Do arithmetic operations
    size_t total = 0;

    for(auto problem : operands) {
        size_t answer = stol(problem[0]);

        if(problem.back() == "+") {
            for (int i = 1; i < problem.size()-1; i++)
                answer += stol(problem[i]);

        } else if (problem.back() == "*") {
            for (int i = 1; i < problem.size()-1; i++)
                answer *= stol(problem[i]);
        }
        total += answer;
    }

    cout << endl;
    cout << "Part 2 Answer: " << total << endl;
}

int main() {

    part1();
    part2();

    return 0;
}
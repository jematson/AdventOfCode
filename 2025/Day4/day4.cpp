#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void part1() {
    vector<vector<int>> diagram;

    // Read input into matrix
    string input;
    ifstream File("input.txt");
    while(getline(File, input)) {
        vector<int> line;
        for (char c : input) {
            if (c == '.')
                line.push_back(0);
            else if (c == '@')
                line.push_back(1);
        }
        diagram.push_back(line);
    }

    auto total_rolls = 0;
    auto height = diagram.size();
    auto width = diagram[0].size();


    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {

            // Ignore empty spaces
            if (diagram[row][col] == 0)
                continue;

            int sum = 0;
            
            // top
            if (row > 0)
                sum += diagram[row-1][col];

            // right
            if (col < width-1)
                sum += diagram[row][col+1];

            // left
            if (col > 0)
                sum += diagram[row][col-1];

            // bottom
            if (row < height-1)
                sum += diagram[row+1][col];

            // top left
            if (row > 0 && col > 0)
                sum += diagram[row-1][col-1];

            // top right
            if (row > 0 && col < width-1)
                sum += diagram[row-1][col+1];

            // bottom left
            if (row < height-1 && col > 0)
                sum += diagram[row+1][col-1];

            // bottom right
            if (row < height-1 && col < width-1)
                sum += diagram[row+1][col+1];

            if (sum < 4)
                total_rolls++;
        }
    }

    cout << "Part 1 Answer: " << total_rolls << endl;

}

void part2() {
        vector<vector<int>> diagram;

    // Read input into matrix
    string input;
    ifstream File("input.txt");
    while(getline(File, input)) {
        vector<int> line;
        for (char c : input) {
            if (c == '.')
                line.push_back(0);
            else if (c == '@')
                line.push_back(1);
        }
        diagram.push_back(line);
    }

    auto total_rolls = 0;
    auto height = diagram.size();
    auto width = diagram[0].size();


    while (true) {
        bool removed = false;

        for (int row = 0; row < height; row++) {
            for (int col = 0; col < width; col++) {

                // Ignore empty spaces
                if (diagram[row][col] == 0)
                    continue;

                int sum = 0;
                
                // top
                if (row > 0)
                    sum += diagram[row-1][col];
                // right
                if (col < width-1)
                    sum += diagram[row][col+1];
                // left
                if (col > 0)
                    sum += diagram[row][col-1];
                // bottom
                if (row < height-1)
                    sum += diagram[row+1][col];
                // top left
                if (row > 0 && col > 0)
                    sum += diagram[row-1][col-1];
                // top right
                if (row > 0 && col < width-1)
                    sum += diagram[row-1][col+1];
                // bottom left
                if (row < height-1 && col > 0)
                    sum += diagram[row+1][col-1];
                // bottom right
                if (row < height-1 && col < width-1)
                    sum += diagram[row+1][col+1];

                if (sum < 4) {
                    total_rolls++;
                    // Remove roll
                    diagram[row][col] = 0;
                    removed = true;
                }
            }
        }

        if (!removed) 
            break;
    }

    cout << "Part 2 Answer: " << total_rolls << endl;
}

int main() {

    part1();
    part2();

    return 0;
}
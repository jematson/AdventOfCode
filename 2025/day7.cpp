// day7.cpp
// Jenae Matson
// 2025-12-07
// Solution for Advent of Code 2025 Day 7

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void part1() {

    string input;
    ifstream File("input.txt");

    // Store file input;
    vector<vector<char>> graph;
    int index = 0;
    while(getline(File, input)) {
        graph.push_back({});
        for(int i=0; i<input.length(); i++) {
            char c = input[i];
            graph[index].push_back(c);
        }
        index++;
    }

    vector<int> beams(graph[0].size(), 0);

    size_t splits = 0;

    for(int line=0; line < graph.size(); line++) {
        for(int col=0; col < graph[0].size(); col++) {

            char c = graph[line][col];

            // Start of tachyon beam
            if (c == 'S') {
                beams[col] = 1;
            }

            // Beam split
            if (c == '^' && beams[col] == 1) {
                splits++;
                beams[col] = 0;
                beams[col+1] = 1;
                beams[col-1] = 1;
            }
        }
    }

    cout << "Part 1 Answer: " << splits << endl;

}

void part2() {

    string input;
    ifstream File("input.txt");

    // Store file input;
    vector<vector<char>> graph;
    int index = 0;
    while(getline(File, input)) {
        graph.push_back({});
        for(int i=0; i<input.length(); i++) {
            char c = input[i];
            graph[index].push_back(c);
        }
        index++;
    }

    vector<int> beams(graph[0].size(), 0);
    size_t timelines = 0;

    for(int line=0; line < graph.size(); line++) {
        for(int col=0; col < graph[0].size(); col++) {

            char c = graph[line][col];

            // Start of tachyon beam
            if (c == 'S') {
                beams[col] = 1;
            }

            // Beam split
            if (c == '^' && beams[col] == 1) {
                beams[col] = 0;
                beams[col+1] = 1;
                beams[col-1] = 1;
            }
        }

    }

    cout << "Part 2 Answer: " << "" << endl;
}

int main() {

    part1();
    part2();

    return 0;
}
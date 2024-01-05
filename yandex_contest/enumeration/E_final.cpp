#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void generateBrackets(int n, int openRound, int closeRound, int openSquare, int closeSquare, string current, vector<string>& result) {
    if (current.length() == 2 * n) {
        result.push_back(current);
        return;
    }

    if (openRound < n) {
        generateBrackets(n, openRound + 1, closeRound, openSquare, closeSquare, current + '(', result);
    }

    if (closeRound < openRound) {
        generateBrackets(n, openRound, closeRound + 1, openSquare, closeSquare, current + ')', result);
    }

    if (openSquare < n) {
        generateBrackets(n, openRound, closeRound, openSquare + 1, closeSquare, current + '[', result);
    }

    if (closeSquare < openSquare) {
        generateBrackets(n, openRound, closeRound, openSquare, closeSquare + 1, current + ']', result);
    }
}

int main() {
    int n;
    cin >> n;

    vector<string> result;
    generateBrackets(n, 0, 0, 0, 0, "", result);

    sort(result.begin(), result.end());

    for (const string& sequence : result) {
        cout << sequence << '\n';
    }

    return 0;
}
#include <iostream>

using namespace std;

void show_updated(char b[3][3], char word, char chance) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (b[i][j] == word) {
                b[i][j] = chance;
            }
            cout << b[i][j] << "   ";
        }
        cout << endl;
    }
}

char check(char b[3][3]) {
    string x, y, z = " ", k = " ";
    for (int i = 0; i < 3; i++) {
        x = " ", y = " ";
        for (int j = 0; j < 3; j++) {
            x += b[i][j];
            y += b[j][i];
            if (i == j) z += b[i][j];
            if (j == (3 - i - 1))k += b[i][j];
        }

        if (x == " XXX" || y == " XXX") {
            return 'X';
        } else if (x == " OOO" || y == " OOO") {
            return 'O';
        }
        int count = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (b[i][j] == 'X' || b[i][j] == 'O') count += 1;
            }
        }

        if (count == 8) return 't';
    }


    if (z == " XXX" || k == " XXX") return 'X';
    else if (z == " OOO" || k == " OOO") return 'O';
    return 'c';

}

int main() {
    char b[3][3];
    char initializer = 'a';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            b[i][j] = initializer;
            initializer += 1;

        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << b[i][j] << "   ";
        }
        cout << endl;


    }

    cout
            << "                                                                         WELCOME TO TIC TAC TOE                                                                                  "
            << endl;
    string name1, name2;
    cout << "Enter the name of the 1st player : " << ' ';
    cin >> name1;
    cout << "Enter the name of the 2nd player : " << ' ';
    cin >> name2;
    char p1choice, p2choice;
    cout << "Enter your  symbol  " << name1 << " -->";
    cin >> p1choice;
    if (p1choice == 'X' || p1choice == 'x') {
        p2choice = 'O';
        p1choice = 'X';
    } else {
        p1choice = 'O';
        p2choice = 'X';
    }
    cout << name2 << "your choice symbol is " << p2choice << endl;
    char c = 'c';
    int chance_observer = 1;
    cout << "player1 u go first " << endl;

    while (c == 'c' && c != 'X' && c != 'O' && c != 't') {
        char word;
        if (chance_observer == 1) {
            cout << p1choice << ": ";
            cin >> word;
            show_updated(b, word, p1choice);
            c = check(b);
            chance_observer = 2;

        } else if (chance_observer == 2) {
            cout << p2choice << ": ";
            cin >> word;
            show_updated(b, word, p2choice);
            c = check(b);
            chance_observer = 1;
        }

    }
    if (c == p1choice) {
        cout << name1 << "  Wins 🎊🎊🎉🎊🎊🎉🎊🎊🎉🎊🎊";
    } else if (c == p2choice) {
        cout << name2 << "  Wins 🎊🎊🎉🎊🎊🎉🎊🎊🎉🎊🎊";
    } else if (c == 't') {
        cout << "Ohhhhh... the match ties 😑";
    }

}

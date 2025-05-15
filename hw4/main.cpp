#include <iostream>
using namespace std;

class TicTacToe {
private:
    char board[9];
    char currentPlayer;

public:
    TicTacToe() {
        for (int i = 0; i < 9; ++i)
            board[i] = '1' + i;  // 初始化為 '1' ~ '9'
        currentPlayer = 'X';
    }

    void printHeader() {
        cout << "-- Tic Tac Toe -- CSIE@CGU\n";
        cout << "Player 1 (X) - Player 2 (O)\n";
        printBoard();
    }

    void printBoard() {
        for (int i = 0; i < 9; i += 3) {
            cout << board[i] << " | " << board[i + 1] << " | " << board[i + 2] << "\n";
            if (i < 6)
                cout << "--+---+--\n";
        }
    }

    bool placeMark(int pos) {
        if (pos < 1 || pos > 9) return false;
        if (board[pos - 1] == 'X' || board[pos - 1] == 'O') return false;
        board[pos - 1] = currentPlayer;
        return true;
    }

    bool checkWin() {
        int winPatterns[8][3] = {
            {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // 橫列
            {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // 直行
            {0, 4, 8}, {2, 4, 6}             // 斜線
        };

        for (int i = 0; i < 8; ++i) {
            int a = winPatterns[i][0];
            int b = winPatterns[i][1];
            int c = winPatterns[i][2];
            if (board[a] == currentPlayer &&
                board[b] == currentPlayer &&
                board[c] == currentPlayer)
                return true;
        }
        return false;
    }

    bool checkDraw() {
        for (int i = 0; i < 9; ++i) {
            if (board[i] != 'X' && board[i] != 'O')
                return false;
        }
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    void play() {
        printHeader();
        while (true) {
            cout << "==> Player " << (currentPlayer == 'X' ? "1 (X)" : "2 (O)") << ", enter a number:\n";
            int pos;
            while (true) {
                cin >> pos;
                if (placeMark(pos)) break;
                cout << "==> Invalid value, please enter again\n";
            }

            printBoard();

            if (checkWin()) {
                cout << "==> Player " << (currentPlayer == 'X' ? "1" : "2") << " wins!\n";
                break;
            }
            if (checkDraw()) {
                cout << "==> Game draw\n";
                break;
            }
            switchPlayer();
        }
    }
};

int main() {
    TicTacToe game;
    game.play();
    return 0;
}

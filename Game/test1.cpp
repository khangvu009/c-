#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

const int BOARD_SIZE = 8;
const int CONSOLE_WINDOW_WIDTH = 80; // Adjust these values based on your console window size
const int CONSOLE_WINDOW_HEIGHT = 24;
bool whiteCanCastleKingSide = true;
bool whiteCanCastleQueenSide = true;
bool blackCanCastleKingSide = true;
bool blackCanCastleQueenSide = true;
int enPassantTargetX = -1;
int enPassantTargetY = -1;

struct Move {
    int startX, startY, endX, endY;
};

// Function to print the chessboard
void printChessboard(char board[BOARD_SIZE][BOARD_SIZE]) {
    system("CLS");
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
}

// Function to initialize the chessboard
void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    // Set up the initial position of the chess pieces
    char initialBoard[BOARD_SIZE][BOARD_SIZE] = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},  // 1st row: Black pieces
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},  // 2nd row: Black pawns
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},  // 3rd row: Empty
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},  // 4th row: Empty
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},  // 5th row: Empty
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},  // 6th row: Empty
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},  // 7th row: White pawns
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}   // 8th row: White pieces
    };

    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            board[i][j] = initialBoard[i][j];
        }
    }
}

// Function to check if a move is within board limits
bool isWithinBoard(int x, int y) {
    return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
}

// Function to check if the destination square is empty or contains an opponent's piece
bool isDestinationValid(char board[BOARD_SIZE][BOARD_SIZE], int endX, int endY, char piece) {
    char destPiece = board[endX][endY];
    return destPiece == ' ' || islower(destPiece) != islower(piece);
}

// Function to check if the move for a pawn is legal
bool isValidPawnMove(char board[BOARD_SIZE][BOARD_SIZE], int startX, int startY, int endX, int endY, char piece) {
    int direction = (piece == 'P') ? -1 : 1; // White pawns move up, black pawns move down
    if (startY == endY && board[endX][endY] == ' ') {
        // Move forward
        if (endX == startX + direction) {
            return true;
        }
        // Move two squares forward from initial position
        if ((piece == 'P' && startX == 6 && endX == 4) || (piece == 'p' && startX == 1 && endX == 3)) {
            enPassantTargetX = endX;
            enPassantTargetY = endY;
            return true;
        }
    } else if (abs(startY - endY) == 1 && endX == startX + direction) {
        // Capture diagonally
        if (board[endX][endY] != ' ' && islower(board[endX][endY]) != islower(piece)) {
            return true;
        }
        // En passant
        if (board[endX][endY] == ' ' && endX == enPassantTargetX && endY == enPassantTargetY) {
            board[startX][endY] = ' '; // Remove the captured pawn
            return true;
        }
    }
    return false;
}

// Function to check if the move for a rook is legal
bool isValidRookMove(char board[BOARD_SIZE][BOARD_SIZE], int startX, int startY, int endX, int endY, char piece) {
    if (startX == endX) {
        // Move horizontally
        int step = (endY > startY) ? 1 : -1;
        for (int y = startY + step; y != endY; y += step) {
            if (board[startX][y] != ' ') return false;
        }
        return true;
    }
    if (startY == endY) {
        // Move vertically
        int step = (endX > startX) ? 1 : -1;
        for (int x = startX + step; x != endX; x += step) {
            if (board[x][startY] != ' ') return false;
        }
        return true;
    }
    return false;
}

// Function to check if the move for a knight is legal
bool isValidKnightMove(char board[BOARD_SIZE][BOARD_SIZE], int startX, int startY, int endX, int endY, char piece) {
    int dx = abs(endX - startX);
    int dy = abs(endY - startY);
    return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
}

// Function to check if the move for a bishop is legal
bool isValidBishopMove(char board[BOARD_SIZE][BOARD_SIZE], int startX, int startY, int endX, int endY, char piece) {
    if (abs(startX - endX) == abs(startY - endY)) {
        int xStep = (endX > startX) ? 1 : -1;
        int yStep = (endY > startY) ? 1 : -1;
        for (int x = startX + xStep, y = startY + yStep; x != endX; x += xStep, y += yStep) {
            if (board[x][y] != ' ') return false;
        }
        return true;
    }
    return false;
}

// Function to check if the move for a queen is legal
bool isValidQueenMove(char board[BOARD_SIZE][BOARD_SIZE], int startX, int startY, int endX, int endY, char piece) {
    return isValidRookMove(board, startX, startY, endX, endY, piece) || isValidBishopMove(board, startX, startY, endX, endY, piece);
}
// Function to check if the move for a king is legal
bool isValidKingMove(char board[BOARD_SIZE][BOARD_SIZE], int startX, int startY, int endX, int endY, char piece) {
    if (abs(startX - endX) <= 1 && abs(startY - endY) <= 1) return true;

    // Castling logic
    if (piece == 'K') {
        // King side castling
        if (endX == 7 && endY == 6 && whiteCanCastleKingSide) {
            if (board[7][5] == ' ' && board[7][6] == ' ' && board[7][7] == 'R') {
                // Perform castling
                board[7][5] = 'R';
                board[7][7] = ' ';
                return true;
            }
        }
        // Queen side castling
        if (endX == 7 && endY == 2 && whiteCanCastleQueenSide) {
            if (board[7][1] == ' ' && board[7][2] == ' ' && board[7][3] == ' ' && board[7][0] == 'R') {
                // Perform castling
                board[7][3] = 'R';
                board[7][0] = ' ';
                return true;
            }
        }
    }
    if (piece == 'k') {
        // King side castling
        if (endX == 0 && endY == 6 && blackCanCastleKingSide) {
            if (board[0][5] == ' ' && board[0][6] == ' ' && board[0][7] == 'r') {
                // Perform castling
                board[0][5] = 'r';
                board[0][7] = ' ';
                return true;
            }
        }
        // Queen side castling
        if (endX == 0 && endY == 2 && blackCanCastleQueenSide) {
            if (board[0][1] == ' ' && board[0][2] == ' ' && board[0][3] == ' ' && board[0][0] == 'r') {
                // Perform castling
                board[0][3] = 'r';
                board[0][0] = ' ';
                return true;
            }
        }
    }
    return false;
}

// Function to validate the move based on the piece type
bool isValidMove(char board[BOARD_SIZE][BOARD_SIZE], int startX, int startY, int endX, int endY) {
    char piece = board[startX][startY];
    if (!isWithinBoard(endX, endY) || !isDestinationValid(board, endX, endY, piece)) return false;

    switch (piece) {
        case 'P':
        case 'p': return isValidPawnMove(board, startX, startY, endX, endY, piece);
        case 'R':
        case 'r': return isValidRookMove(board, startX, startY, endX, endY, piece);
        case 'N':
        case 'n': return isValidKnightMove(board, startX, startY, endX, endY, piece);
        case 'B':
        case 'b': return isValidBishopMove(board, startX, startY, endX, endY, piece);
        case 'Q':
        case 'q': return isValidQueenMove(board, startX, startY, endX, endY, piece);
        case 'K':
        case 'k': return isValidKingMove(board, startX, startY, endX, endY, piece);
        default: return false;
    }
}

// Function to move a piece if the move is legal
bool movePiece(char board[BOARD_SIZE][BOARD_SIZE], int startX, int startY, int endX, int endY) {
    char piece = board[startX][startY];
    if (isValidMove(board, startX, startY, endX, endY)) {
        board[endX][endY] = piece;
        board[startX][startY] = ' ';

        // Disable castling rights if king or rook moved
        if (piece == 'K') {
            whiteCanCastleKingSide = false;
            whiteCanCastleQueenSide = false;
        }
        if (piece == 'k') {
            blackCanCastleKingSide = false;
            blackCanCastleQueenSide = false;
        }
        if (startX == 7 && startY == 0) whiteCanCastleQueenSide = false;
        if (startX == 7 && startY == 7) whiteCanCastleKingSide = false;
        if (startX == 0 && startY == 0) blackCanCastleQueenSide = false;
        if (startX == 0 && startY == 7) blackCanCastleKingSide = false;

        // Handle en passant capture
        if (piece == 'P' && endX == 3 && startX == 4 && startY != endY && board[endX][endY] == ' ') {
            board[4][endY] = ' ';
        }
        if (piece == 'p' && endX == 4 && startX == 3 && startY != endY && board[endX][endY] == ' ') {
            board[3][endY] = ' ';
        }

        return true;
    }
    return false;
}

// Function to convert chess notation to board indices
pair<int, int> chessNotationToIndices(string notation) {
    int row = 8 - (notation[1] - '0');
    int col = notation[0] - 'a';
    return make_pair(row, col);
}

// Function to find the king's position on the board
pair<int, int> findKingPosition(char board[BOARD_SIZE][BOARD_SIZE], char king) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == king) {
                return make_pair(i, j);
            }
        }
    }
    return make_pair(-1, -1); // King not found
}

// Function to check if a position is under attack
bool isPositionUnderAttack(char board[BOARD_SIZE][BOARD_SIZE], int x, int y, bool isWhite) {
    char black = 'b'; // Declare 'black' variable here
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            char piece = board[i][j];
            if ((isWhite && islower(piece)) || (!isWhite && isupper(piece))) {
                if (isValidMove(board, i, j, x, y)) {
                    return true;
                }
            }
        }
    }
    return false;
}


// Function to check if the king is in check
bool isKingInCheck(char board[BOARD_SIZE][BOARD_SIZE], bool isWhite) {
    pair<int, int> kingPosition = findKingPosition(board, isWhite ? 'K' : 'k');
    return isPositionUnderAttack(board, kingPosition.first, kingPosition.second, isWhite);
}

// Function to generate all possible moves for a player
vector<Move> generateAllMoves(char board[BOARD_SIZE][BOARD_SIZE], bool isWhite) {
    vector<Move> moves;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            char piece = board[i][j];
            if ((isWhite && isupper(piece)) || (!isWhite && islower(piece))) {
                for (int x = 0; x < BOARD_SIZE; ++x) {
                    for (int y = 0; y < BOARD_SIZE; ++y) {
                        if (isValidMove(board, i, j, x, y)) {
                            moves.push_back({i, j, x, y});
                        }
                    }
                }
            }
        }
    }
    return moves;
}

// Function to check if the current player is in checkmate or stalemate
bool isCheckmateOrStalemate(char board[BOARD_SIZE][BOARD_SIZE], bool isWhite) {
    vector<Move> moves = generateAllMoves(board, isWhite);
    for (Move move : moves) {
        char tempBoard[BOARD_SIZE][BOARD_SIZE];
        memcpy(tempBoard, board, sizeof(tempBoard));
        movePiece(tempBoard, move.startX, move.startY, move.endX, move.endY);
        if (!isKingInCheck(tempBoard, isWhite)) {
            return false;
        }
    }
    return true;
}

// Function to check if the game is a draw
bool isDraw(char board[BOARD_SIZE][BOARD_SIZE]) {
    // Example conditions for a draw:
    // - Insufficient material
    // - Threefold repetition
    // - Fifty-move rule
    // For simplicity
    // Check if there's insufficient material for either side to checkmate
    int whitePieces = 0, blackPieces = 0;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            char piece = board[i][j];
            if (piece == 'K' || piece == 'Q' || piece == 'R' || piece == 'B' || piece == 'N' || piece == 'P') {
                ++whitePieces;
            } else if (piece == 'k' || piece == 'q' || piece == 'r' || piece == 'b' || piece == 'n' || piece == 'p') {
                ++blackPieces;
            }
        }
    }
    return (whitePieces == 0 && blackPieces == 0) || // Both sides have insufficient material
           (whitePieces == 1 && blackPieces == 1);   // Only kings left on the board
}

// Function to handle player moves
void handleClick(char board[BOARD_SIZE][BOARD_SIZE], int mouseX, int mouseY) {
    // Convert mouse coordinates to board indices
    int startY = mouseX / (CONSOLE_WINDOW_WIDTH / BOARD_SIZE);
    int startX = BOARD_SIZE - 1 - mouseY / (CONSOLE_WINDOW_HEIGHT / BOARD_SIZE);
    
    // Determine the end position based on mouse click
    // Assuming the destination square is the same as the starting square for simplicity
    int endX = startX;
    int endY = startY;

    if (movePiece(board, startX, startY, endX, endY)) {
        printChessboard(board);
        if (isCheckmateOrStalemate(board, true)) {
            cout << "Checkmate! Black wins!" << endl;
            exit(0);
        } else if (isCheckmateOrStalemate(board, false)) {
            cout << "Checkmate! White wins!" << endl;
            exit(0);
        } else if (isDraw(board)) {
            cout << "Draw!" << endl;
            exit(0);
        }
    } else {
        cout << "Invalid move!" << endl;
    }
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    initializeBoard(board);
    printChessboard(board);

    bool isWhiteTurn = true;

    while (true) {
        int mouseX, mouseY;

        // Get input from the player
        cout << "Enter mouse coordinates (x y): ";
        cin >> mouseX >> mouseY;

        // Handle the move
        handleClick(board, mouseX, mouseY);

        // Switch turns
        isWhiteTurn = !isWhiteTurn;
    }

    return 0;
}


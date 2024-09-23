#include <iostream>
#include <sstream>
#include <vector>
#include <limits>
#include <algorithm>

enum Piece { EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING };
enum Color { WHITE, BLACK, NONE };

struct Square {
    Piece piece;
    Color color;

    Square() : piece(EMPTY), color(NONE) {}
};

class Move {
public:
    int startX, startY, endX, endY;

    Move(int sx, int sy, int ex, int ey) : startX(sx), startY(sy), endX(ex), endY(ey) {}
};

class ChessBoard {
public:
    Square board[8][8];

    ChessBoard() {
        setupBoard();
    }

    void setupBoard() {
        // Set up pawns
        for (int i = 0; i < 8; ++i) {
            board[1][i].piece = PAWN;
            board[1][i].color = WHITE;
            board[6][i].piece = PAWN;
            board[6][i].color = BLACK;
        }

        // Set up other pieces (simplified)
        board[0][0].piece = board[0][7].piece = ROOK; board[0][0].color = board[0][7].color = WHITE;
        board[0][1].piece = board[0][6].piece = KNIGHT; board[0][1].color = board[0][6].color = WHITE;
        board[0][2].piece = board[0][5].piece = BISHOP; board[0][2].color = board[0][5].color = WHITE;
        board[0][3].piece = QUEEN; board[0][3].color = WHITE;
        board[0][4].piece = KING; board[0][4].color = WHITE;

        board[7][0].piece = board[7][7].piece = ROOK; board[7][0].color = board[7][7].color = BLACK;
        board[7][1].piece = board[7][6].piece = KNIGHT; board[7][1].color = board[7][6].color = BLACK;
        board[7][2].piece = board[7][5].piece = BISHOP; board[7][2].color = board[7][5].color = BLACK;
        board[7][3].piece = QUEEN; board[7][3].color = BLACK;
        board[7][4].piece = KING; board[7][4].color = BLACK;
    }

    void printBoard() {
        for (int r = 0; r < 8; ++r) {
            for (int c = 0; c < 8; ++c) {
                switch (board[r][c].piece) {
                    case PAWN: std::cout << (board[r][c].color == WHITE ? "P " : "p "); break;
                    case KNIGHT: std::cout << (board[r][c].color == WHITE ? "N " : "n "); break;
                    case BISHOP: std::cout << (board[r][c].color == WHITE ? "B " : "b "); break;
                    case ROOK: std::cout << (board[r][c].color == WHITE ? "R " : "r "); break;
                    case QUEEN: std::cout << (board[r][c].color == WHITE ? "Q " : "q "); break;
                    case KING: std::cout << (board[r][c].color == WHITE ? "K " : "k "); break;
                    default: std::cout << ". ";
                }
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
};

class EvaluationWeights {
public:
    double materialBalance = 0.4;
    double pieceActivity = 0.2;
    double kingSafety = 0.15;
    double controlOfKeySquares = 0.1;
    double positionalFactors = 0.1;
    double tacticalEvaluation = 0.03;
    double strategicConsiderations = 0.02;
};

std::vector<Move> generateLegalMoves(ChessBoard& board, Color side) {
    std::vector<Move> moves;

    for (int r = 0; r < 8; ++r) {
        for (int c = 0; c < 8; ++c) {
            if (board.board[r][c].color == side) {
                switch (board.board[r][c].piece) {
                    case PAWN:
                        generatePawnMoves(board, r, c, moves, side);
                        break;
                    case KNIGHT:
                        generateKnightMoves(board, r, c, moves, side);
                        break;
                    case BISHOP:
                        generateBishopMoves(board, r, c, moves, side);
                        break;
                    case ROOK:
                        generateRookMoves(board, r, c, moves, side);
                        break;
                    case QUEEN:
                        generateQueenMoves(board, r, c, moves, side);
                        break;
                    case KING:
                        generateKingMoves(board, r, c, moves, side);
                        break;
                    default:
                        break;
                }
            }
        }
    }

    return moves;
}

void generatePawnMoves(ChessBoard& board, int startX, int startY, std::vector<Move>& moves, Color side) {
    int direction = (side == WHITE) ? 1 : -1;

    // Move one square forward
    int endX = startX + direction;
    int endY = startY;
    if (endX >= 0 && endX < 8 && board.board[endX][endY].piece == EMPTY) {
        moves.push_back(Move(startX, startY, endX, endY));
    }

    // Move two squares forward (initial pawn move)
    if ((side == WHITE && startX == 1) || (side == BLACK && startX == 6)) {
        endX = startX + 2 * direction;
        endY = startY;
        if (endX >= 0 && endX < 8 && board.board[endX][endY].piece == EMPTY &&
            board.board[startX + direction][startY].piece == EMPTY) {
            moves.push_back(Move(startX, startY, endX, endY));
        }
    }

    // Capture diagonally
    endX = startX + direction;
    endY = startY + 1;
    if (endX >= 0 && endX < 8 && endY >= 0 && endY < 8 &&
        board.board[endX][endY].piece != EMPTY && board.board[endX][endY].color != side) {
        moves.push_back(Move(startX, startY, endX, endY));
    }

    endY = startY - 1;
    if (endX >= 0 && endX < 8 && endY >= 0 && endY < 8 &&
        board.board[endX][endY].piece != EMPTY && board.board[endX][endY].color != side) {
        moves.push_back(Move(startX, startY, endX, endY));
    }

    // Add more complex rules like en passant here
}

void generateKnightMoves(ChessBoard& board, int startX, int startY, std::vector<Move>& moves, Color side) {
    // Implement knight moves
}

void generateBishopMoves(ChessBoard& board, int startX, int startY, std::vector<Move>& moves, Color side) {
    // Implement bishop moves
}

void generateRookMoves(ChessBoard& board, int startX, int startY, std::vector<Move>& moves, Color side) {
    // Implement rook moves
}

void generateQueenMoves(ChessBoard& board, int startX, int startY, std::vector<Move>& moves, Color side) {
    // Implement queen moves
}

void generateKingMoves(ChessBoard& board, int startX, int startY, std::vector<Move>& moves, Color side) {
    // Implement king moves
}

double evaluatePosition(ChessBoard& board, EvaluationWeights weights) {
    double score = 0.0;

    // Example: Evaluate material balance
    double materialScore = 0.0;
    for (int r = 0; r < 8; ++r) {
        for (int c = 0; c < 8; ++c) {
            Piece piece = board.board[r][c].piece;
            Color color = board.board[r][c].color;
            if (piece != EMPTY) {
                double pieceValue = 0.0;
                switch (piece) {
                    case PAWN: pieceValue = 1.0; break;
                    case KNIGHT: pieceValue = 3.0; break;
                    case BISHOP: pieceValue = 3.0; break;
                    case ROOK: pieceValue = 5.0; break;
                    case QUEEN: pieceValue = 9.0; break;
                    case KING: pieceValue = 0.0; break; // King value is not counted
                    default: break;
                }
                materialScore += (color == WHITE ? pieceValue : -pieceValue);
            }
        }
    }
    score += weights.materialBalance * materialScore;
}
double evaluatePosition(ChessBoard& board, EvaluationWeights weights) {
    double score = 0.0;

    // Example: Evaluate material balance
    double materialScore = 0.0;
    for (int r = 0; r < 8; ++r) {
        for (int c = 0; c < 8; ++c) {
            Piece piece = board.board[r][c].piece;
            Color color = board.board[r][c].color;
            if (piece != EMPTY) {
                double pieceValue = 0.0;
                switch (piece) {
                    case PAWN: pieceValue = 1.0; break;
                    case KNIGHT: pieceValue = 3.0; break;
                    case BISHOP: pieceValue = 3.0; break;
                    case ROOK: pieceValue = 5.0; break;
                    case QUEEN: pieceValue = 9.0; break;
                    case KING: pieceValue = 0.0; break; // King value is not counted
                    default: break;
                }
                materialScore += (color == WHITE ? pieceValue : -pieceValue);
            }
        }
    }
    score += weights.materialBalance * materialScore;

    // Example: Evaluate piece activity, king safety, control of key squares, etc.
    // You can add more detailed evaluation based on specific piece types and their positions

    return score;
}

double evaluateMoveQuality(ChessBoard& board, Move move, EvaluationWeights weights) {
    // Make the move on a temporary board
    ChessBoard newBoard = board;
    newBoard.board[move.endX][move.endY] = newBoard.board[move.startX][move.startY];
    newBoard.board[move.startX][move.startY] = Square();

    // Evaluate the position after making the move
    return evaluatePosition(newBoard, weights);
}

std::string getMoveQuality(double score) {
    if (score >= 1.0)
        return "Great";
    else if (score >= 0.5)
        return "Good";
    else if (score >= 0.0)
        return "Normal";
    else
        return "Bad";
}

int main() {
    ChessBoard board;
    EvaluationWeights weights;

    std::string input;
    Color playerColor = WHITE;

    while (true) {
        // Print board
        board.printBoard();

        // Check if it's player's turn
        if (playerColor == WHITE) {
            std::cout << "Your move (format: startX startY endX endY, e.g., 1 0 2 0): ";
            std::getline(std::cin, input);
            std::istringstream iss(input);
            int startX, startY, endX, endY;
            if (!(iss >> startX >> startY >> endX >> endY)) {
                std::cout << "Invalid input. Please try again.\n";
                continue;
            }

            // Validate move (simplified for now)
            bool moveFound = false;
            std::vector<Move> legalMoves = generateLegalMoves(board, WHITE);
            for (const auto& move : legalMoves) {
                if (move.startX == startX && move.startY == startY && move.endX == endX && move.endY == endY) {
                    // Make the move
                    board.board[endX][endY] = board.board[startX][startY];
                    board.board[startX][startY] = Square();
                    moveFound = true;

                    // Evaluate move quality
                    double moveQuality = evaluateMoveQuality(board, move, weights);
                    std::cout << "Move quality: " << getMoveQuality(moveQuality) << "\n";
                    break;
                }
            }

            if (!moveFound) {
                std::cout << "Invalid move. Please try again.\n";
                continue;
            }
        } else {
            // AI's turn
            std::cout << "AI is thinking...\n";

            double bestScore = -std::numeric_limits<double>::infinity();
            Move bestMove(0, 0, 0, 0);

            std::vector<Move> legalMoves = generateLegalMoves(board, BLACK);
            for (const auto& move : legalMoves) {
                ChessBoard newBoard = board;
                newBoard.board[move.endX][move.endY] = newBoard.board[move.startX][move.startY];
                newBoard.board[move.startX][move.startY] = Square();
                double score = evaluateMoveQuality(newBoard, move, weights);
                if (score > bestScore) {
                    bestScore = score;
                    bestMove = move;
                }
            }

            // Make AI move
            board.board[bestMove.endX][bestMove.endY] = board.board[bestMove.startX][bestMove.startY];
            board.board[bestMove.startX][bestMove.startY] = Square();

            // Output AI's move
            std::cout << "AI's move: (" << bestMove.startX << ", " << bestMove.startY << ") -> (" << bestMove.endX << ", " << bestMove.endY << ")\n";
            std::cout << "Move quality: " << getMoveQuality(bestScore) << "\n";
        }

        // Switch player turn
        playerColor = (playerColor == WHITE) ? BLACK : WHITE;
    }

    return 0;
}


#include <iostream>
#include <vector>
#include <climits>

const int BOARD_SIZE = 8;

// Function to evaluate a board position (simplified, just for demonstration)
int evaluate(const std::vector<std::vector<bool>>& board) {
    // Placeholder evaluation function
    // In a real scenario, evaluate based on pawn structure, king safety, etc.
    int evaluation = 0;
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            if (board[row][col]) {
                // Example: Reward advancing pawns towards promotion
                if (row == 6) {
                    evaluation += 100;  // Example value, could be adjusted
                }
                // Example: Penalize isolated pawns
                if (col > 0 && !board[row][col - 1] && (row == 0 || !board[row - 1][col - 1])) {
                    evaluation -= 20;  // Example value, could be adjusted
                }
                if (col < BOARD_SIZE - 1 && !board[row][col + 1] && (row == 0 || !board[row - 1][col + 1])) {
                    evaluation -= 20;  // Example value, could be adjusted
                }
            }
        }
    }
    return evaluation;
}

// Function to generate all possible moves for pawns
std::vector<std::vector<std::vector<bool>>> generate_pawn_moves(const std::vector<std::vector<bool>>& board, bool is_white_turn) {
    std::vector<std::vector<std::vector<bool>>> new_boards;

    int start_row = is_white_turn ? 1 : 6;
    int direction = is_white_turn ? 1 : -1;

    for (int col = 0; col < BOARD_SIZE; ++col) {
        if (board[start_row][col]) {
            // Move one square forward
            if (start_row + direction >= 0 && start_row + direction < BOARD_SIZE) {
                if (!board[start_row + direction][col]) {
                    std::vector<std::vector<bool>> new_board = board;
                    new_board[start_row][col] = false;
                    new_board[start_row + direction][col] = true;
                    new_boards.push_back(new_board);
                }
            }
            // Move two squares forward from starting position
            if ((is_white_turn && start_row == 1) || (!is_white_turn && start_row == 6)) {
                if (!board[start_row + 2 * direction][col] && !board[start_row + direction][col]) {
                    std::vector<std::vector<bool>> new_board = board;
                    new_board[start_row][col] = false;
                    new_board[start_row + 2 * direction][col] = true;
                    new_boards.push_back(new_board);
                }
            }
            // Capture diagonally (to the left)
            if (col > 0 && board[start_row + direction][col - 1] != is_white_turn) {
                std::vector<std::vector<bool>> new_board = board;
                new_board[start_row][col] = false;
                new_board[start_row + direction][col - 1] = true;
                new_boards.push_back(new_board);
            }
            // Capture diagonally (to the right)
            if (col < BOARD_SIZE - 1 && board[start_row + direction][col + 1] != is_white_turn) {
                std::vector<std::vector<bool>> new_board = board;
                new_board[start_row][col] = false;
                new_board[start_row + direction][col + 1] = true;
                new_boards.push_back(new_board);
            }
        }
    }

    return new_boards;
}

// Minimax algorithm with alpha-beta pruning
int minimax(std::vector<std::vector<bool>>& board, int depth, bool maximizing_player, int alpha, int beta) {
    if (depth == 0) {
        return evaluate(board);
    }

    if (maximizing_player) {
        int max_eval = INT_MIN;
        std::vector<std::vector<std::vector<bool>>> possible_moves = generate_pawn_moves(board, true);
        for (auto& move : possible_moves) {
            int eval = minimax(move, depth - 1, false, alpha, beta);
            max_eval = std::max(max_eval, eval);
            alpha = std::max(alpha, eval);
            if (beta <= alpha) {
                break;
            }
        }
        return max_eval;
    } else {
        int min_eval = INT_MAX;
        std::vector<std::vector<std::vector<bool>>> possible_moves = generate_pawn_moves(board, false);
        for (auto& move : possible_moves) {
            int eval = minimax(move, depth - 1, true, alpha, beta);
            min_eval = std::min(min_eval, eval);
            beta = std::min(beta, eval);
            if (beta <= alpha) {
                break;
            }
        }
        return min_eval;
    }
}

// Function to map evaluation score to qualitative assessment
std::string evaluate_move(int evaluation) {
    if (evaluation >= 1000)
        return "Best Move";
    else if (evaluation >= 700)
        return "Brilliant";
    else if (evaluation >= 500)
        return "Great Move";
    else if (evaluation >= 300)
        return "Excellent";
    else if (evaluation >= 0)
        return "Good";
    else if (evaluation > -100)
        return "Inaccuracy";
    else if (evaluation > -500)
        return "Mistake";
    else
        return "Blunder";
}

int main() {
    // Initialize a board (assuming 8x8 board for simplicity)
    std::vector<std::vector<bool>> board(BOARD_SIZE, std::vector<bool>(BOARD_SIZE, false));

    // Set initial position for pawns
    board[1][3] = true;  // Example: White pawn at d2
    board[6][4] = true;  // Example: Black pawn at e7

    // Example: Evaluate moves 5 moves ahead
    int evaluation = minimax(board, 5, true, INT_MIN, INT_MAX);

    // Map evaluation score to qualitative assessment
    std::string assessment = evaluate_move(evaluation);

    std::cout << "Evaluation of the board after 5 moves ahead: " << assessment << std::endl;

    return 0;
}


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <unordered_map>

int score_round(std::string);

int main() {
    std::ifstream file("../input.txt");
    std::string line;
    std::vector<int> scores;

    while (std::getline(file, line)) {
        scores.push_back(
                    score_round(line)
                );
    }
    std::cout << "Total score: " << std::accumulate(scores.begin(), scores.end(), 0);
}

int score_round(std::string str) {
    int play_score;
    int outcome_score;
    char play = str.back();
    char opponent = str.at(0);
    int matchup;
    std::unordered_map<char, int> play_score_map;

    play_score_map['X'] = 1;
    play_score_map['Y'] = 2;
    play_score_map['Z'] = 3;
    play_score_map['A'] = 1;
    play_score_map['B'] = 2;
    play_score_map['C'] = 3;
    
    matchup = play_score_map.at(play) - play_score_map.at(opponent);

    if (matchup == 1 || matchup == -2) {
        outcome_score = 6;
    } else if (matchup == -1 || matchup == 2) {
        outcome_score = 0;
    } else {
        outcome_score = 3;
    }

    outcome_score += play_score_map.at(play);

    return outcome_score;
}



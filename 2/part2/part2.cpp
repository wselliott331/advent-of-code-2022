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
    char play = str.back();
    char opponent = str.at(0);
    int matchup;
    std::unordered_map<char, int> play_score_map;

    play_score_map['X'] = 0;
    play_score_map['Y'] = 3;
    play_score_map['Z'] = 6;
    play_score_map['A'] = 1;
    play_score_map['B'] = 2;
    play_score_map['C'] = 3;
    
    matchup = play_score_map.at(play) - play_score_map.at(opponent);

    if (abs(matchup) == 2 || matchup == 3) {
        play_score = 1; //Rock
    } else if (matchup == 5 || matchup == 1 || matchup == -3) {
        play_score = 2; //Paper
    } else {
        play_score = 3; //Scissors
    }

    play_score += play_score_map.at(play);

    return play_score;
}



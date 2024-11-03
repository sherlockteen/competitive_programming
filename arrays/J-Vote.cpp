#include <iostream>
#include <vector>
#include <algorithm>


int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> score(n);
    std::vector<std::vector<int>> voted(n, std::vector<int>(n, 0));

    for (int i = 0; i < m; ++i) {
        int worker;
        int votedPerson;
        int typeVote;
        std::cin >> worker >> votedPerson >> typeVote;
        worker--;
        votedPerson--;

        // проверка на голосование за самого себя
        if (worker == votedPerson) { continue; }

        // проверка на единственность голоса
        if (voted[worker][votedPerson] == 1) {
            continue;
        }

        // подсчёт голосов
        score[votedPerson] += typeVote;
        voted[worker][votedPerson] = 1;
    }

    auto maxScore = std::max_element(score.begin(), score.end());
    auto personWithMaxScore = std::count(score.begin(), score.end(), *maxScore);

    if (*maxScore > 0 && personWithMaxScore == 1) {
        int index = static_cast<int>(std::distance(score.begin(), maxScore));
        std::cout << index + 1;
    }
    else {
        std::cout << -1;
    }

    return 0;
}

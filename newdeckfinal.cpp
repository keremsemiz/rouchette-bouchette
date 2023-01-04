#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

int main()
{
    const int num_trial = 1000000;
    std::random_device rd;
    std::mt19937 g(rd());

    vector<int> selected_cards = {
        10, 10,
        9, 9,
        3, 5,
        5, 2,
        6, 2,
        4, 3,
        8, 4,
        2, 2,
        4, 3,
        4, 4,
        8, 3,
        6, 3,
        8, 7,
        6, 2,
        3, 5,
        6, 5,
        3, 7,
        4, 5,
        7, 8,
        8, 9,
    };
    vector<int> original_cards = selected_cards;
    int count = 0;
    int num_pairs = 0;
    for(int i=0; i<num_trial; ++i) {
        selected_cards = original_cards;
        std::shuffle(selected_cards.begin(), selected_cards.end(), g);

        while (selected_cards.size() >= 2)
        {
            int add = selected_cards[0] + selected_cards[1];
            if (add > 9)
                num_pairs++;

            selected_cards.erase(selected_cards.begin(), selected_cards.begin() + 2);

            count++;
        }
    }

    float probability = (float)num_pairs / count;

    cout << "Probability of getting a pair that adds up to more than 9: " << probability << endl;

    return 0;
}

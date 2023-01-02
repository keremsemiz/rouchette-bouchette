#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> selected_cards = {2, 5, 1, 5, 3, 5, 2, 2, 2, 6, 2, 5, 3, 4, 3, 3, 2, 6, 2, 3, 5, 2, 3, 4, 4, 2, 2, 4, 3, 4, 2, 6, 1, 3, 1, 3, 5, 1, 1, 1};

  // Add high-valued cards to the deck
  selected_cards.push_back(10);
  selected_cards.push_back(10);
  selected_cards.push_back(9);
  selected_cards.push_back(9);

  // Count the number of pairs that add up to more than 9
  int num_pairs = 0;
  for (int i = 0; i < selected_cards.size(); i++) {
    for (int j = i + 1; j < selected_cards.size(); j++) {
      if (selected_cards[i] + selected_cards[j] > 9) {
        num_pairs++;
      }
    }
  }

  // Calculate the probability of getting a pair that adds up to more than 9
  int total_pairs = selected_cards.size() * (selected_cards.size() - 1) / 2;
  float probability = (float) num_pairs / total_pairs;

  cout << "Probability of getting a pair that adds up to more than 9: " << probability << endl;
  for (int i=0;i<40;i++){
    cout<<selected_cards[i]<<",";
  }

  return 0;
}

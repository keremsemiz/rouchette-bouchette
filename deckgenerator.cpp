#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  vector<int> cards;
  for (int i = 1; i <= 10; i++) {
    cards.push_back(i);
  }

  int num_cards = 40;
  vector<int> selected_cards;
  while (num_cards > 0) {
    // Randomly select a card
    int index = rand() % cards.size();
    int card = cards[index];

    // Add the card to the selected set if the total value is less than 9
    if ((selected_cards.empty() || (card + selected_cards.back()) < 9)) {
      selected_cards.push_back(card);
      num_cards--;
    }
  }

  // Print the selected cards
  cout << "Selected cards: ";
  for (int i = 0; i < selected_cards.size(); i++) {
    cout << selected_cards[i] << " ";
  }
  cout << endl;

  return 0;
}

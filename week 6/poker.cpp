#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

enum class Suit{
    Clubs,
    Diamonds,
    Hearts,
    Spades
};

class Card{
private:
    int rank;
    int suit;
public:
    Card(int rank):rank(rank%13), suit(rank/13) {}
    friend std::ostream& operator <<(std::ostream& banana, const Card & c){
        return banana << "[" << c.rank << "," << c.suit << "]";
    }
};

class Deck{
    std::vector<Card> deck;
    void load(){
         for(int i=0;i<52;i++){
            deck.push_back(Card(i));
        }

        bool empty(){
            return !deck.size() > 0;
        }
    }
public:
    Deck(){
        load(); // load the deck
    }

    void reset(){
        deck.clear(); // clears the deck vector
        load(); // calls the load method
    }

    void shuffle(){
        static std::mt19937 engine(std::random_device{}());
        std::shuffle(deck.begin(), deck.end(), engine);
    }

    void print(){
        for (auto &c : deck) {
            std::cout << c << " ";
        }
        std::cout << std::endl;
    }
    Card deal(){
        if (!empty()){ 
             Card c = deck.back();
             deck.pop_back();
            return c;
        }
        else
        {    
        cout << "throw empty error" << endl;
        exit(0);
        }
    }
};

class Hand{

};


int main(){
    Deck deck;
    deck.shuffle();
    deck.print();

}
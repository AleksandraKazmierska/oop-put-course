#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <exception>
#include <cctype>

class WordLibraryInterface {
public:
    virtual std::string getRandomWord() const = 0;
};

class AnimalWordLibrary : public WordLibraryInterface {
private:
    std::vector<std::string> animalWords;

public:
    AnimalWordLibrary() {
        animalWords = { "cat", "dog", "bird", "penguin","alligator","giraffe","tiger","butterfly","raccoon","stingray","sparrow","pigeon","tortoise","wasp","bumblebee","cangaroo","monkey","elephant","cheetach","hyena","otter","reindeer","hedgehog","gorilla","snake","bear","boar","whale","dolphin","jellyfish","herring","octopus","lizard","zebra","lion","tiger","crocodile","squirrel","toad","hare","badger","woodpecker","camel","eagle","wolf" };
        srand(static_cast<unsigned int>(time(0)));
    }

    std::string getRandomWord() const override {
        int randomIndex = rand() % animalWords.size();
        return animalWords[randomIndex];
    }
};

class ProfessionWordLibrary : public WordLibraryInterface {
private:
    std::vector<std::string> professionWords;

public:
    ProfessionWordLibrary() {
        professionWords = { "doctor", "teacher", "nurse","firefighter","dentist","policeman","architect","actress","singer","accountant","judge","farmer","plumber","mechanic","baker","surgeron","carpenter","scientist","lawyer","postman","politician","hairdresser","programmer","businessman","electrician","journalist","librarian","lifeguard","fisherman","engineer","cleaner","astronomer","banker" };
        srand(static_cast<unsigned int>(time(0)));
    }

    std::string getRandomWord() const override {

        int randomIndex = rand() % professionWords.size();
        return professionWords[randomIndex];
    }
};

class ObjectWordLibrary : public WordLibraryInterface {
private:
    std::vector<std::string> objectWords;

public:
    ObjectWordLibrary() {
        objectWords = { "car", "cupboard", "fridge","computer","backpack","clock","pencil","bike","table","chair","wardrobe","bottle","coin","smartphone","wallet","umbrella","lighter","lipstic","scissors","notebook","laptop","toothbrush","headphone","sunglasses","televison","pillow","blanket","can","plate","mug","purse","carpet","keyboard","ball","newspaper"};
        srand(static_cast<unsigned int>(time(0)));
    }

    std::string getRandomWord() const override {

        int randomIndex = rand() % objectWords.size();
        return objectWords[randomIndex];
    }
};

class HangmanGameInterface {
public:
    virtual void chooseRandomWord(const WordLibraryInterface& wordLibrary) = 0;
    virtual void play() = 0;
};

class HangmanGame : public HangmanGameInterface {
private:
    int maxGuesses;
    std::string secretWord;
    std::vector<char> guessedLetters;

public:
    HangmanGame(int maxGuesses, const std::string& secretWord) : maxGuesses(maxGuesses), secretWord(secretWord) {}
    void chooseRandomWord(const WordLibraryInterface& wordLibrary) override {
        try {
            secretWord = wordLibrary.getRandomWord();
        } catch (const std::exception& e) {
            std::cout << "An exception occurred while choosing a random word: " << e.what() << std::endl;
            throw;
        }
    }

    std::string getSecretWord() const {
        return secretWord;
    }

    void play() override {
    int remainingGuesses = maxGuesses;
    bool won = false;

    displayWordProgress();

    while (remainingGuesses > 0) {
        std::cout << "Guess a letter: ";
        char guess;
        std::cin >> guess;

        if (!std::isalpha(guess)) {
            throw std::invalid_argument("Invalid input. Please enter a letter.");
        }

        guess = std::tolower(guess);

        if (guessedLetters.size() > 0 && isGuessed(guess)) {
            std::cout << "This letter has already been guessed. Try again." << std::endl;
            continue;
        }

        guessedLetters.push_back(guess);

        if (isGuessCorrect(guess)) {
            std::cout << "Correct guess!" << std::endl;
            if (isWordGuessed()) {
                won = true;
                break;
            }
        } else {
            remainingGuesses--;
            std::cout << "Incorrect guess! Remaining attempts: " << remainingGuesses << std::endl;

            drawHangman(remainingGuesses);
        }

        displayGuessedLetters();
        displayWordProgress();
    }

    if (won) {
        std::cout << "Congratulations, you guessed the word: " << secretWord << std::endl;
    } else {
        std::cout << "Game over! The word was: " << secretWord << std::endl;
    }
}


private:
    bool isGuessed(char letter) {
        for (char guessedLetter : guessedLetters) {
            if (guessedLetter == letter) {
                return true;
            }
        }
        return false;
    }

    bool isGuessCorrect(char letter) {
        for (char secretLetter : secretWord) {
            if (secretLetter == letter) {
                return true;
            }
        }
        return false;
    }

    bool isWordGuessed() {
        for (char secretLetter : secretWord) {
            if (!isGuessed(secretLetter)) {
                return false;
            }
        }
        return true;
    }

    void displayGuessedLetters() {
        std::cout << "Used letters: ";
        for (char letter : guessedLetters) {
            std::cout << letter << " ";
        }
        std::cout << std::endl;
    }

    void displayWordProgress() {
        for (char letter : secretWord) {
            if (isGuessed(letter)) {
                std::cout << letter << " ";
            } else {
                std::cout << "_ ";
            }
        }
        std::cout << std::endl;
    }

    void drawHangman(int remainingGuesses) {
        std::cout << "  _____" << std::endl;
        std::cout << " |     |" << std::endl;
        std::cout << " |     " << (remainingGuesses < 6 ? "O" : " ") << std::endl;
        std::cout << " |    " << (remainingGuesses < 4 ? "/" : " ") << (remainingGuesses < 5 ? "|" : " ") << (remainingGuesses < 3 ? "\\" : " ") << std::endl;
        std::cout << " |    " << (remainingGuesses < 2 ? "/" : " ") << " " << (remainingGuesses < 1 ? "\\" : " ") << std::endl;
        std::cout << " |" << std::endl;
        std::cout << "_|_" << std::endl;
        std::cout << std::endl;
    }
};

class MenuInterface {
public:
    virtual void displayOptions() = 0;
    virtual void selectOption() = 0;
    virtual bool running() const = 0;
    virtual ~MenuInterface() {}
};

class Menu : public MenuInterface {
private:
    int option;
    bool isRunning;

public:
    Menu() : option(0), isRunning(true) {
    }

    void displayOptions() override {
        std::cout << "==== MENU ====" << std::endl;
        std::cout << "1. Play" << std::endl;
        std::cout << "2. Quit" << std::endl;
    }

    void selectOption() override {
    std::cout << "Select an option: ";
    std::cin >> option;

    try {
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            throw std::runtime_error("Invalid input. Please enter a valid option.\n");
        }

        switch (option) {
            case 1:
                playGame();
                break;
            case 2:
            std::cout<<"Game session ended"<<std::endl;
                isRunning = false;
                break;
            default:
                throw std::runtime_error("Invalid option. Please try again.\n");
        }
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

    bool running() const override {
        return isRunning;
    }

    ~Menu() {
    }

private:
     void playGame() {
    WordLibraryInterface* wordLibrary = nullptr;
    HangmanGameInterface* game = nullptr;

    try {
        std::string categoryInput;
        std::cout << "==== CATEGORY ====" << std::endl;
        std::cout << "1. Animal" << std::endl;
        std::cout << "2. Profession" << std::endl;
        std::cout << "3. Object" << std::endl;
        std::cout << "Choose a category number: ";
        std::cin >> categoryInput;

        if (categoryInput.size() != 1 || categoryInput[0] < '1' || categoryInput[0] > '3') {
            throw std::runtime_error("Invalid category. Please try again.\n");
        }

        int category = categoryInput[0] - '0';

        switch (category) {
            case 1:
                wordLibrary = new AnimalWordLibrary();
                break;
            case 2:
                wordLibrary = new ProfessionWordLibrary();
                break;
            case 3:
                wordLibrary = new ObjectWordLibrary();
                break;
        }

        game = new HangmanGame(6,"");
        game->chooseRandomWord(*wordLibrary);
        game->play();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    delete wordLibrary;
    delete game;
}

};
//Unit testing
void runTests() {
    AnimalWordLibrary animalWordLibrary;
    ProfessionWordLibrary professionWordLibrary;
    ObjectWordLibrary objectWordLibrary;
   
    std::cout << "Animal Word Library Test:\n" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::string word = animalWordLibrary.getRandomWord();
        std::cout << "Random Word: " << word << std::endl;
    }
    std::cout<<"________________________\n"<<std::endl;
   
    std::cout << "Profession Word Library Test:\n" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::string word = professionWordLibrary.getRandomWord();
        std::cout << "Random Word: " << word << std::endl;
    }
    std::cout<<"________________________\n"<<std::endl;
   
    std::cout << "Object Word Library Test:\n" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::string word = objectWordLibrary.getRandomWord();
        std::cout << "Random Word: " << word << std::endl;
    }
     std::cout<<"________________________\n"<<std::endl;
   
    std::cout << "Hangman Game Test:\n" << std::endl;
    HangmanGame game(6, "elephant");
    game.play();
}

int main() {
    //runTests();

    Menu menu;
    while (menu.running()) {
        menu.displayOptions();
        menu.selectOption();
    }

    return 0;
}

int main() {
    //runTests();

    Menu menu;
    while (menu.running()) {
        menu.displayOptions();
        menu.selectOption();
    }

    return 0;
}

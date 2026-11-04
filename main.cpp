#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Heap.h"
#include "Heapsort.h"
#include "MergeSort.h"
#include "TextBox.h"
#include "InputTextBox.h"
#include "Dropdown.h"

// for data:
#include "csvreader.h"
#include "gameData.h"

using namespace std;

int main () {
<<<<<<< Updated upstream
    // loading the info:
    CSVReader reader;
    gameData data;
    reader.loadCSV("gamedatabase.csv", data);

    sf::Font font("../BoldPixels.ttf");
=======
    // variables for heaps:
    string cost;
    string genre;
    string company;
    string games;
>>>>>>> Stashed changes

    // variables for visuals:
    unsigned int width = 1024;
    unsigned int height = 712;

    sf::Font font("../BoldPixels.ttf");

    sf::Color bgGrey(76, 69, 76);
    sf::Color lightPink(255, 192, 222);
    sf::Color pink(237, 150, 215);
    sf::Color lightPurple(163, 69, 161);
    sf::Color blank(0,0,0,0);

    TextBox groupName(width / 2.0f, 65.f, 36, 0, 0, "SAC-RELIGIOUS PRODUCTIONS", font, lightPurple, blank, blank);
    TextBox titleText((width - 440.f) / 2.0f, 125.f, 60, 440, 60.f, "Pick a game", font, lightPurple,pink, lightPurple);
    TextBox credits(width / 2.0f, 670.f, 24, 0, 0, "Sara Mann, Camryn Walter, Andy Tran @ 2026", font, lightPurple, blank, blank);

    float W = 440.f;
    float H = 48.f;
    float X = (width - W) / 2.0f;

    Dropdown costDropdown(X, 245.f, 24, W, H, "MONEY", {"Free", "< $10", "< $30", "< $50", "< $70", "< $90"}, font, lightPink, pink, lightPurple);
    Dropdown descriptionDropdown(X, 345.f, 24, W, H, "DESCRIPTION", {"Action", "Indie", "RPG", "Strategy", "Multiplayer", "Casual"}, font, lightPink, pink, lightPurple);
    InputTextBox companyDropdown(X, 445.f, 24, W, H, "COMPANY", font, lightPink, pink, lightPurple, false);
    InputTextBox numGames(X, 545.f, 24, W, H, "HOW MANY", font, lightPink, pink, lightPurple, true);
    vector<TextBox*> uiElements = {&groupName, &titleText, &credits, &costDropdown, &descriptionDropdown, &companyDropdown, &numGames};

    // creating main window frame
    sf::RenderWindow homeWindow(sf::VideoMode({width, height}), "Pick a game");
    while (homeWindow.isOpen()) {

        while (const optional event = homeWindow.pollEvent()) {
            // ONLY close when if x is pressed
            if (event->is <sf::Event::Closed>()) {
                homeWindow.close();
            }

            for (auto* elem: uiElements) {
                elem->handleEvent(*event, homeWindow);
            }

            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Enter) {
                    bool allInputsFilled = true;
                    std::vector<std::string> collectedInputs;

                    // checking  InputTextBoxes for input
                    for (auto* elem : uiElements) {
                        if (auto* inputBx = dynamic_cast<InputTextBox*>(elem)) {
                            std::string val = inputBx->getInput();

                            if (val.empty()) {
                                allInputsFilled = false;
                                break;
                            }
                            collectedInputs.push_back(val);
                        }
                    }

                    // if all textboxes are filled, the program is closed and the lists are outputted!!
                    // not completed yet, just a shell to see that the program works as intended
                    if (allInputsFilled && !collectedInputs.empty()) {
                        cost = collectedInputs[0];
                        genre = collectedInputs[1];
                        company = collectedInputs[2];
                        games = collectedInputs[3];

                        maxHeap costHeap(cost);
                        maxHeap genreHeap(genre);
                        maxHeap companyHeap(company);
                        maxHeap numGamestHeap(games);

                        std::cout << "------------------------------------\n";
                        for (size_t i = 0; i < collectedInputs.size(); ++i) {
                            std::cout << "Input " << (i + 1) << ": " << collectedInputs[i] << "\n";
                        }
                        std::cout << "------------------------------------\n";

                        homeWindow.close();
                    } else {
                        // warns user that they MUST fill in the text box!
                        std::cout << "All input fields MUST be filled before pressing Enter!\n";
                        homeWindow.close();
                    }
                }
            }
        }
        // home window visuals
        homeWindow.clear(bgGrey);

        // drawling all base UI components
        for (auto* elem : uiElements) {
            elem->draw(homeWindow);
        }

        // re-drawling ONLY the dropdown options so they are on top of everything else!
        for (auto* elem : uiElements) {
            if (auto* dropdown = dynamic_cast<Dropdown*>(elem)) {
                dropdown->drawOpenListOnly(homeWindow);
            }
        }

        homeWindow.display();
    }

    return 0;
}

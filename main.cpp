#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include "Heap.h"
#include "HeapSort.h"
#include "MergeSort.h"
#include "TextBox.h"
#include "InputTextBox.h"
#include "Dropdown.h"

// for data:
#include "csvreader.h"
#include "gameData.h"

using namespace std;

int main () {
    // loading the info:
    CSVReader reader;
    gameData data;
    reader.loadCSV(string(PROJECT_DIR) + "gamedatabase.csv", data);
    
    // variables for heaps:
    string cost;
    string genre;
    string company;
    string games;

    // variables for visuals:
    unsigned int width = 1024;
    unsigned int height = 712;

    sf::Font font(string(PROJECT_DIR) + "BoldPixels.ttf");

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

    Dropdown costDropdown(X, 245.f, 24, W, H, "MONEY", {"Free", "$1 - $10", "$10 - $30", "$30 - $50", "$50 - $70", "$70 - $90", "> $90"}, font, lightPink, pink, lightPurple);
    Dropdown genreDropdown(X, 345.f, 24, W, H, "GENRE", {"Action", "Indie", "RPG", "Strategy", "Multiplayer", "Casual"}, font, lightPink, pink, lightPurple);

    // old input we had that we decided to remove
    // InputTextBox companyDropdown(X, 445.f, 24, W, H, "COMPANY", font, lightPink, pink, lightPurple, false);

    InputTextBox numGames(X, 445.f, 24, W, H, "HOW MANY", font, lightPink, pink, lightPurple, true);
    vector<TextBox*> uiElements = {&groupName, &titleText, &credits, &costDropdown, &genreDropdown, &numGames};

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
                    if (allInputsFilled && !collectedInputs.empty()) {
                        cost = collectedInputs[0];
                        genre = collectedInputs[1];
                        games = collectedInputs[2];

                        // cost dropdown -> price range: above minPrice, up to maxPrice
                        double minPrice = -1, maxPrice = 0;    // "Free" -> only $0 games
                        if (cost == "$1 - $10")       { minPrice = 0;  maxPrice = 10; }
                        else if (cost == "$10 - $30") { minPrice = 10; maxPrice = 30; }
                        else if (cost == "$30 - $50") { minPrice = 30; maxPrice = 50; }
                        else if (cost == "$50 - $70") { minPrice = 50; maxPrice = 70; }
                        else if (cost == "$70 - $90") { minPrice = 70; maxPrice = 90; }
                        else if (cost == "> $90")     { minPrice = 90; maxPrice = 1e9; }

                        // "Multiplayer" is a category in the data, the rest are genres
                        string category = "";
                        if (genre == "Multiplayer") {
                            category = "Multi-player";
                            genre = "";
                        }
                        int k = stoi(games);

                        // same games go into both algorithms
                        vector<game> matches;
                        for (const game& g : data.filterGames(genre, category, maxPrice)) {
                            if (g.get_price() > minPrice) {
                                matches.push_back(g);
                            }
                        }
                        heapSorter heapS("recommendations");
                        mergeSorter mergeS("recommendations");
                        vector<game> heapTop, mergeTop;

                        // timing each one (best of 5 so the numbers dont jump around)
                        double heapMs = 1e9, mergeMs = 1e9;
                        for (int run = 0; run < 5; run++) {
                            vector<game> heapCopy = matches;
                            vector<game> mergeCopy = matches;

                            auto t0 = chrono::steady_clock::now();
                            heapTop = heapS.topK(heapCopy, k);
                            auto t1 = chrono::steady_clock::now();
                            mergeTop = mergeS.topK(mergeCopy, k);
                            auto t2 = chrono::steady_clock::now();

                            heapMs = min(heapMs, chrono::duration<double, milli>(t1 - t0).count());
                            mergeMs = min(mergeMs, chrono::duration<double, milli>(t2 - t1).count());
                        }

                        // printing results
                        cout << "------------------- HEAP SORT -------------------\n";
                        cout << matches.size() << " games matched, top " << k << ":\n";
                        for (int i = 0; i < heapTop.size(); i++) {
                            cout << "  " << (i + 1) << ". " << heapTop[i].get_title() << " (" << heapTop[i].get_recommendations() << " recs, $" << heapTop[i].get_price() << ")\n";
                        }
                        cout << "\n------------------- MERGE SORT -------------------\n";
                        cout << matches.size() << " games matched, top " << k << ":\n";
                        for (int i = 0; i < mergeTop.size(); i++) {
                            cout << "  " << (i + 1) << ". " << heapTop[i].get_title() << " (" << heapTop[i].get_recommendations() << " recs, $" << heapTop[i].get_price() << ")\n";
                        }
                        if (heapTop.empty()) {
                            cout << "  no games found\n";
                        }
                        cout << "\n------------------ SORTING TIMES -----------------";
                        cout << "\nHeap Sort:  " << heapMs << " ms\n";
                        cout << "Merge Sort: " << mergeMs << " ms\n";
                        cout << "--------------------------------------------------\n";

                        homeWindow.close();
                    } else {
                        // warns user that they MUST fill in the text box!
                        std::cout << "Number of recommendations wanted MUST be filled"
                                     " before pressing Enter!\n";
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

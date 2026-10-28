// adding header
#include "gameData.h"

/////////////////////// data heaps ////////////////////////////// 
// creating a filter of all of the games, if they are matching what they want it will go in the new list:
vector<game> gameData::filterGames(string publisher, string genre, string category, double maxPrice) {
    // creating a vector for the games that fit
    vector<game> matchingGames;

    for (const game& currentGame : allGames) {
        // if has all things: 
        if (!publisher.empty() && currentGame.get_publisher() != publisher) {
            continue;
        }
        if (currentGame.get_price() > maxPrice) {
            continue;
        }
        vector<string> genres = currentGame.get_genres();
        if (!genre.empty() && find(genres.begin(), genres.end(), genre) == genres.end()) {
            continue;
        }
        vector<string> categories = currentGame.get_categories();
        if (!category.empty() && find(categories.begin(), categories.end(), category) == categories.end()) {
            continue;
        }
        matchingGames.push_back(currentGame);
    }
    return matchingGames;
};

// adding new games to the heaps/ with correct data 
void gameData::addGame(game newGame) {
    // adding game to the list of all games:
    allGames.push_back(newGame);

    //// developer heap
    // if the genre doesnt exist yet:
    if (developerHeaps.find(newGame.get_developer()) == developerHeaps.end()) {
        maxHeap newHeap("recommendations");
        developerHeaps.insert({ newGame.get_developer(), newHeap });
    }
    // add new game:
    developerHeaps[newGame.get_developer()].insert(newGame);

    //// publisher heap
    if (publisherHeaps.find(newGame.get_publisher()) == publisherHeaps.end()) {
        maxHeap newHeap("recommendations");
        publisherHeaps.insert({ newGame.get_publisher(), newHeap });
    }
    publisherHeaps[newGame.get_publisher()].insert(newGame);

    //// genre heaps
    vector<string> genres = newGame.get_genres();
    for (int i = 0; i < genres.size(); i++) {
        string genre = genres[i];
        if (genreHeaps.find(genre) == genreHeaps.end()) {
            maxHeap newHeap("recommendations");
            genreHeaps.insert({ genre, newHeap });
        }
        genreHeaps[genre].insert(newGame);
    }

    //// category heaps
    vector<string> categories = newGame.get_categories();
    for (int i = 0; i < categories.size(); i++) {
        string category = categories[i];
        if (categoryHeaps.find(category) == categoryHeaps.end()) {
            maxHeap newHeap("recommendations");
            categoryHeaps.insert({ category, newHeap });
        }
        categoryHeaps[category].insert(newGame);
    }
};


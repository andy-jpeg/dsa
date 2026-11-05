// adding header
#include "gameData.h"
#include "HeapSort.h"

/////////////////////// data heaps ////////////////////////////// 
// creating a filter of all of the games, if they are matching what they want it will go in the new list:
vector<game> gameData::filterGames(string genre, string category, double maxPrice) {
    // creating a vector for the games that fit
    vector<game> tryGames;

    //making a shorter list of games that they have to sort through, going to heap for games that match
    // if has all things -> getting the heap that correlates with the cateagory
    if (!genre.empty() && (genreHeaps.find(genre) != genreHeaps.end())) {
        tryGames = genreHeaps[genre].getHeap();
    }
    else if (!category.empty() && (categoryHeaps.find(category) != categoryHeaps.end())) {
        tryGames = categoryHeaps[category].getHeap();
    }
    else {
       tryGames = allGames;
    }

    // now that we have the heap with games we need to make sure that it fits the other wants, 
    vector<game> matchingGames;

    for (const game& currentGame : tryGames) {
        if (currentGame.get_price() > maxPrice) {
            continue;
        }

        // making sure it is the right genre/catagory: 
        vector<string> genres = currentGame.get_genres();
        vector<string> categories = currentGame.get_categories();

        if (!genre.empty() && (find(genres.begin(), genres.end(), genre) == genres.end())) {
            continue;
        }
        if (!category.empty() && (find(categories.begin(), categories.end(), category) == categories.end())) {
            continue;
        }

        // add game:
        matchingGames.push_back(currentGame);
    }

    return matchingGames;
};


// filtering through the games and getting only the top num of games that the person asked for:
vector<game> gameData::recommendGames(string genre, string category, double maxPrice, int k) {
    // getting the heaps from filtering:
    vector<game> matchingGames = filterGames(genre, category, maxPrice);
    
    // sort them in the heap
    heapSorter sorter("recommendations");
     
    return sorter.topK(matchingGames, k);
}


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

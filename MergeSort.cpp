// adding header
#include "MergeSort.h"


/////////////////////// merge sort //////////////////////////////
mergeSorter::mergeSorter(string infoNeeded) {
    this->infoNeeded = infoNeeded;
};


//// sorting:
// split in half, sort each half, merge them back
void mergeSorter::mergeSort(vector<game>& games, vector<game>& temp, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSort(games, temp, left, mid);
    mergeSort(games, temp, mid + 1, right);
    merge(games, temp, left, mid, right);
};

// merging two sorted halves: [left, mid] and [mid + 1, right]
void mergeSorter::merge(vector<game>& games, vector<game>& temp, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int spot = left;

    while (i <= mid && j <= right) {
        // <= keeps tied games in og order (stable)
        if (getInfo(games[i]) <= getInfo(games[j])) {
            temp[spot] = std::move(games[i]);
            i++;
        }
        else {
            temp[spot] = std::move(games[j]);
            j++;
        }
        spot++;
    }

    // leftovers
    while (i <= mid) {
        temp[spot] = std::move(games[i]);
        i++;
        spot++;
    }
    while (j <= right) {
        temp[spot] = std::move(games[j]);
        j++;
        spot++;
    }

    // copy back
    for (int x = left; x <= right; x++) {
        games[x] = std::move(temp[x]);
    }
};


//// funcs:
// lowest -> highest
void mergeSorter::sort(vector<game>& games) {
    if (games.size() < 2) {
        return;
    }

    // one extra vector for the whole sort -> O(n) space
    vector<game> temp(games.size());
    mergeSort(games, temp, 0, games.size() - 1);
};

// k highest, highest first (reorders games)
vector<game> mergeSorter::topK(vector<game>& games, int k) {
    vector<game> best;

    if (k > (int)games.size()) {
        k = games.size();
    }
    if (k <= 0) {
        return best;
    }

    // cant stop early -> sort everything, grab from the back
    sort(games);

    for (int i = 0; i < k; i++) {
        best.push_back(games[games.size() - 1 - i]);
    }

    return best;
};

double mergeSorter::getInfo(const game& currentGame) {
    if (infoNeeded == "recommendations") {
        return currentGame.get_recommendations();
    }
    if (infoNeeded == "price") {
        return currentGame.get_price();
    }
    return 0;
};

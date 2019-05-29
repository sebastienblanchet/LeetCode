#include <iostream>
#include <vector>

// given idx, element and length print [a_0, ... , a_n-1]
void brackets(int i, int el, int n) {
    if (i == 0) {
        std::cout << "[" << el << ", ";

    }
    else if (i == n - 1) {
        std::cout << el << "]";
    }

    else {
        std::cout << el << ", ";
    }
}

// 1D vect
void printvect1d(std::vector<int> &vectin) {
    for (int i = 0; i < vectin.size(); ++i) {
        brackets(i, vectin[i], vectin.size());
    }
}

// 2D vect
void printvect2d(std::vector< std::vector<int> > &vectin) {
    for (int i = 0; i < vectin.size(); ++i) {
        for ( int j = 0; j < vectin[i].size(); ++j) {
            brackets(j, vectin[i][j], vectin[i].size());
        }
    }
}

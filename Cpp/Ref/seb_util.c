#include <iostream>
#include <vector>
#include <string>

// UTILS------------------------------------------------------------
// given idx, element and length print [a_0, ... , a_n-1]
template<typename T>
void brackets(int i, T el, int n){
      if(i==0){
          std::cout <<"[" << el << ", ";

      }
      else if (i == n - 1){
          std::cout << el << "]";
      }

      else{
          std::cout << el << ", ";
      }
}

// 1D vect
template<typename T>
void printvect1d(std::vector<T> &vectin){
    if(vectin.size() !=1){
        for(int i = 0; i < vectin.size(); ++i){
            brackets<T>(i, vectin[i], vectin.size());
        }
    }
    else{std::cout<<"["<<vectin[0] <<"]";}
    std::cout << std::endl;
}

// 2D vect
void printvect2d(std::vector< std::vector<int> > &vectin){
  for(int i = 0; i < vectin.size(); ++i){
      for( int j = 0; j < vectin[i].size(); ++j){
          brackets(j, vectin[i][j], vectin[i].size());
      }
      // brackets(i, vectin[i], vectin.size());
  }
}

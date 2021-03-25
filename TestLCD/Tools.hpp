//
//  Tools.hpp
//  TestLCD
//
//  Created by zm on 2021/3/25.
//

#ifndef Tools_hpp
#define Tools_hpp

#include <stdio.h>

#include <iostream>
#include <vector>

using namespace std;

class Tool {
public:
    void printVector(vector<int>& vec)
    {
        vector<int>::iterator it = vec.begin();
        while (it != vec.end()) {
            cout<<*it<<" ";
            it++;
        }
        cout<<endl;
    }

    void printMatrix(vector<vector<int>>& matrix)
    {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }

        cout<<endl;
    }
};

#endif /* Tools_hpp */

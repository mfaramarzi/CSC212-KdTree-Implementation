#include<iostream>
#include<vector>


int main(){

    std::vector<int>v1 = {1,2,3,4};

    std::vector<int> v2;

    v2 = std::vector<int>(v1.begin() + 1, v1.end());

    for(int i = 0 ; i < v2.size() ; i++){

        std::cout<<v2[i];
    }
}
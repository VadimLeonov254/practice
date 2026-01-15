#include<iostream>
#include<vector>
#include<random>

int main(){
    
    int n, a;

    std::cout << "Enter the side of the matrix: ";
    std::cin >> n;
    std::vector<int> temp(n);
    std::vector<std::vector<int>> matrix(n);

    for(int i = 0; i < n; i++){
        for(int k = 0; k < n; k++){
            temp[k] = rand() % 10;
        }
        matrix[i] = temp;
    }

    for(int i = 0; i < n; i++){
        for(int k = 0; k < n; k++){
            std::cout << matrix[i][k] << " ";
        }
        std::cout << '\n';
    }
    
    for(int i = 0; i < n; i++){
        std::vector<int>temp = matrix[i];
        for(int k = 0; k < n; k++){
            
        }

    } 
    std::cout << '\n';

    for(int i = 0; i < n; i++){
        for(int k = 0; k < n; k++){
            std::cout << matrix[i][k] << " ";
        }
        std::cout << '\n';
    }
    
    std::cout << '\n';

}

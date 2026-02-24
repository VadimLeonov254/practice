#include<iostream>
#include<vector>
#include<map>

int main(){
    
    std::map<char, int> freq;

    std::string word;
    std::cout << "Enter the word: ";
    std::cin >> word;
    
    int num;
    std::cout << "Enter the max number of characters that could be changed: ";
    std::cin >> num;
    
    char let;

    int freqq = 0;
    int dif_num = 0;   
    int streak = 1;

    for(int i = 0, k = 1; k < word.size();){
        if(word[i] == word[k]){
            
        } 
    }

    std::cout << freqq << '\n' << let << '\n';
}

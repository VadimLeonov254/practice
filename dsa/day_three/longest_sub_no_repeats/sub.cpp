#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<cmath>

int main(){
    

    std::cout << "Enter the word: ";
    std::string word;
    std::cin >> word;
    int maxi = 0; 
    std::vector<int> nums;
    
    std::map<char, int> letters;

    int len = 0;
    
    for(int i = 0; i < word.size(); i++){
        if(letters.find(word[i]) == letters.end()){
            letters.emplace(word[i], 1);
        }else{
            letters[word[i]]++;
        }
    }

    for(int l = 0, r = word.size() - 1;;){
        if(word[l] != word[r] && letters[word[l]] == 1 && letters[word[r]] == 1){
            std::cout << std::abs(r-l+1) << '\n';
            break;
        }else if(word[l] != word[r] && letters[word[l]] > 1 && letters[word[r]] == 1){
            letters[word[l]]--;
            l++;
            if(letters[word[l-1]] > 1){
                r--;
            }
        }else if(word[l] != word[r] && letters[word[l]] == 1 && letters[word[r]] > 1){
            letters[word[r]]--;
            r--;
            if(letters[word[r+1]] > 1){
                l++;
            }
        }else if(word[l] == word[r]){
            l++;
            r--;
        }else if(word[l] != word[r] && letters[word[l]] > 1 && letters[word[r]] > 1){
            letters[word[l]]--;
            letters[word[r]]--;
            r--;
            l++;
        }
    }

}

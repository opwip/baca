// Yaroslav Kolesnik
#include <iostream>
#include <string>
using namespace std;

string remove_at(string str, int index) {
    string str_out = "";
    str_out.resize(str.size() - 1);
    for (int i = 0; i < index; i++) {
        str_out[i] = str[i];
    }
    for (int i = index; i < str.size() - 1; i++) {
        str_out[i] = str[i + 1];
    }
    return str_out;
}

string remove_from_to(string str, int index1, int index2) {
    while (index1 <= index2--) {
        str = remove_at(str, index1);
    }
    return str;
}

string add_after_index(string str, char symbol, int index){
    string str_out = "";
    str_out.resize(str.size() + 1);
    for (int i = 0; i <= index; i++){
        str_out[i] = str[i];
    }
    str_out[++index] = symbol;
    for (int i = index; i < str.size(); i++){
        str_out[i+1] = str[i];
    }
    return str_out;
}

string add_to_the_end(string str, char symbol){
    return add_after_index(str, symbol, str.size() - 1);
}
string UsunSlowo(string str, int num) {
    int word_start = -1;
    int word_end = -1;
    int word_counter = 0;
    bool is_a_word = false;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] != ' ') {
            if (!is_a_word) {
                is_a_word = true;
                if (word_counter == num) {
                    return remove_from_to(str, word_start, word_end);
                }
                word_counter++;
                word_start = i;
				word_end = word_start;
            } else {
                word_end = i;
            }
        } else {
            is_a_word = false;
        }
    }
    if (word_counter == num) {
        return remove_from_to(str, word_start, word_end);
    }
    return str;
}

string NajwiekszeSlowo(string str){
    bool is_a_word = false;
    string word_max = "";
    string word = "";

    for (int i = 0; i < str.size(); i++){
       
        if (str[i] != ' ') {
            if (!is_a_word){
                is_a_word = true;
                word = add_to_the_end(word, str[i]);
            }
            else{
                word = add_to_the_end(word, str[i]);
            }
            
        }
        else{
            is_a_word = false;
            word = "";
        } 
        if (word > word_max){
            word_max = word;
        }
        
    }

    return word_max;
}

string NormalizujNapis(string str){
    string str_out = str;
    int end = str_out.size();
    int space_start = 0;
    int space_end = 0;
    int i = 0;
    while (i < end){
        if (str_out[i] == ' '){
			if (str_out[i-1] == ' '){
                str_out = remove_at(str_out, i);
                i--;
                end--;
            }
			if (i == 0 || i == end - 1){
				str_out = remove_at(str_out, i);
				i--;
                end--;
			}
        }
        i++;
    }
    i = 0;
	
    end = str_out.size();
    bool dot_comma = false;
    while (i < end){
        
        if (dot_comma){
            if (str_out[i] != ' '){

                str_out = add_after_index(str_out, ' ', i-1);

                i++;
                end++;

            }
            dot_comma = false;
        }
        if (str_out[i] == '.' || str_out[i] == ','){
            
            if (str_out[i-1] == ' '){
                str_out = remove_at(str_out, i-1);
                i--;
                end--;
            }
            dot_comma = true;
        }
        else{
            dot_comma = false;
        }
        i++;
    }
   
    return str_out;
}
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

string remove_last(string str){
    if (str.size() >= 1){
        return remove_at(str, str.size() - 1);
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

string add_b4_index(string str, char symbol, int index){
    string str_out = "";
    str_out.resize(str.size() + 1);
    for (int i = 0; i < index; i++){
        str_out[i] = str[i];
    }
    str_out[index] = symbol;
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

string FormatujNapis(string str, string arg1, string arg2, string arg3){
    string str_out = "";
    int where_to_format = 0;
    for (int i = 0; i < str.size(); i++){
        if (str[i] == '{'){
            where_to_format = i;
			i++;
			while (str[i] != '}'){
				if (str[i] == 'p'){
                    
					i += 2;
					int quantity = 0;
					while (str[i] != ':'){
						switch (str[i]) {
							case '0': quantity = quantity * 10 + 0; break;
							case '1': quantity = quantity * 10 + 1; break;
							case '2': quantity = quantity * 10 + 2; break;
							case '3': quantity = quantity * 10 + 3; break;
							case '4': quantity = quantity * 10 + 4; break;
							case '5': quantity = quantity * 10 + 5; break;
							case '6': quantity = quantity * 10 + 6; break;
							case '7': quantity = quantity * 10 + 7; break;
							case '8': quantity = quantity * 10 + 8; break;
							case '9': quantity = quantity * 10 + 9; break;
						}
						i++;
					}
                    char to_add = str[++i];
                    for (int counter = 0; counter < quantity; counter++){
                        str_out = add_to_the_end(str_out, to_add);
                    }
                    
                    i++;
				}
                else if (str[i] == 'u'){
                    i += 2;
					int quantity = 0;
					while (str[i] != '}'){
						switch (str[i]) {
							case '0': quantity = quantity * 10 + 0; break;
							case '1': quantity = quantity * 10 + 1; break;
							case '2': quantity = quantity * 10 + 2; break;
							case '3': quantity = quantity * 10 + 3; break;
							case '4': quantity = quantity * 10 + 4; break;
							case '5': quantity = quantity * 10 + 5; break;
							case '6': quantity = quantity * 10 + 6; break;
							case '7': quantity = quantity * 10 + 7; break;
							case '8': quantity = quantity * 10 + 8; break;
							case '9': quantity = quantity * 10 + 9; break;
						}
						i++;
					}
                    i+=quantity;
                    break;

                }
                else if (str[i] == 'U'){
                    i += 2;
					int quantity = 0;
					while (str[i] != '}'){
						switch (str[i]) {
							case '0': quantity = quantity * 10 + 0; break;
							case '1': quantity = quantity * 10 + 1; break;
							case '2': quantity = quantity * 10 + 2; break;
							case '3': quantity = quantity * 10 + 3; break;
							case '4': quantity = quantity * 10 + 4; break;
							case '5': quantity = quantity * 10 + 5; break;
							case '6': quantity = quantity * 10 + 6; break;
							case '7': quantity = quantity * 10 + 7; break;
							case '8': quantity = quantity * 10 + 8; break;
							case '9': quantity = quantity * 10 + 9; break;
						}
						i++;
					}
                    for (int k = 0; k < quantity; k++){
                        str_out = remove_last(str_out);
                    }
                    break;

                }
                else if (str[i] == 'w'){
                    i += 2;
					string to_add;
                    switch (str[i])
                    {
                        case '1': to_add = arg1; break;
                        case '2': to_add = arg2; break;
                        case '3': to_add = arg3; break;
                    }
                    for (int k = 0; k < to_add.size(); k++){
                        str_out = add_to_the_end(str_out, to_add[k]);
                    }
                    i++;

                }
                else if (str[i] == 'W'){
                    i += 2;
					string to_add;
                    switch (str[i])
                    {
                        case '1': to_add = arg1; break;
                        case '2': to_add = arg2; break;
                        case '3': to_add = arg3; break;
                    }
                    i += 2;
                    int quantity = 0;
                    while (str[i] != '}'){
						switch (str[i]) {
							case '0': quantity = quantity * 10 + 0; break;
							case '1': quantity = quantity * 10 + 1; break;
							case '2': quantity = quantity * 10 + 2; break;
							case '3': quantity = quantity * 10 + 3; break;
							case '4': quantity = quantity * 10 + 4; break;
							case '5': quantity = quantity * 10 + 5; break;
							case '6': quantity = quantity * 10 + 6; break;
							case '7': quantity = quantity * 10 + 7; break;
							case '8': quantity = quantity * 10 + 8; break;
							case '9': quantity = quantity * 10 + 9; break;
						}
						i++;
					}
                    
                    if (quantity < to_add.size()){
                        for (int k = 0; k < quantity; k++){
                            str_out = add_to_the_end(str_out, to_add[k]);
                        }
                    }
                    else if (quantity > to_add.size()){
                        for (int k = 0; k < to_add.size(); k++){
                            str_out = add_to_the_end(str_out, to_add[k]);
                        }
                        for (int k = 0; k < quantity - to_add.size(); k++){
                            str_out = add_to_the_end(str_out, ' ');
                        }
                    }

                }
            }
            
		}
		else{
			str_out = add_to_the_end(str_out, str[i]);
            
		}
    }
    return str_out;
}
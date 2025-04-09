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
bool compare(string tab1[], string tab2[], int num) {
	bool result = true;

	for(int i = 0; i < num; i = i + 1)
		result = result && (tab1[i] == tab2[i]);

	return result;
}

int main() {
	//TEST 1
	string t1_b[] = {"{p:5:x}ABCD{p:5:y}{p:0:z}X Y Z{p:9:V}", "abc", "cdef", "xyz"};
	string t1_a[] = {"{p:5:x}ABCD{p:5:y}{p:0:z}X Y Z{p:9:V}", "abc", "cdef", "xyz"};
	string t1c = "xxxxxABCDyyyyyX Y ZVVVVVVVVV";

	string t1r = FormatujNapis(t1_b[0], t1_b[1], t1_b[2], t1_b[3]);

	bool m1 = compare(t1_b, t1_a, 4) && t1r == t1c;
    
	//TEST 2
	string t2_b[] = {"ABCD{u:0}{u:6}{u:3} X Y Z{u:9}", "abc", "cdef", "gh"};
	string t2_a[] = {"ABCD{u:0}{u:6}{u:3} X Y Z{u:9}", "abc", "cdef", "gh"};
	string t2c = "ABCDX Y Z";

	string t2r = FormatujNapis(t2_b[0], t2_b[1], t2_b[2], t2_b[3]);
	bool m2 = compare(t2_b, t2_a, 4) && t2r == t2c;
    
	//TEST 3
	string t3_b[] = {"{U:9}ABCD{U:1}X Y Z{U:1}FGHIJ{U:7}", "abc", "cdef", "gh"};
	string t3_a[] = {"{U:9}ABCD{U:1}X Y Z{U:1}FGHIJ{U:7}", "abc", "cdef", "gh"};
	string t3c = "ABCX ";

	string t3r = FormatujNapis(t3_b[0], t3_b[1], t3_b[2], t3_b[3]);
    
	bool m3 = compare(t3_b, t3_a, 4) && t3r == t3c;
    cout << t3r.size() << ' ' << t3c.size() <<(m3 ? "[\033[32mOK\033[0m]    " : "[\033[31mANS\033[0m] ! ") << "#3" << "_1\n";

	//TEST 4
	string t4_b[] = {"{w:1}{w:1}{w:2}ABCD{w:1} {w:3}X Y{w:2} Z{w:1}", "ab1", "cd2", "ef3"};
	string t4_a[] = {"{w:1}{w:1}{w:2}ABCD{w:1} {w:3}X Y{w:2} Z{w:1}", "ab1", "cd2", "ef3"};
	string t4c = "ab1ab1cd2ABCDab1 ef3X Ycd2 Zab1";

	string t4r = FormatujNapis(t4_b[0], t4_b[1], t4_b[2], t4_b[3]);

	bool m4 = compare(t4_b, t4_a, 4) && t4r == t4c;
    cout << t4r.size() << ' ' << t4c.size() <<(m4 ? "[\033[32mOK\033[0m]    " : "[\033[31mANS\033[0m] ! ") << "#3" << "_1\n";
	//TEST 5
	string t5_b[] = {"{W:1:4}{W:2:5}{W:1:9}{W:3:0}{W:3:1}", "abcd1234", "efgh", "69"};
	string t5_a[] = {"{W:1:4}{W:2:5}{W:1:9}{W:3:0}{W:3:1}", "abcd1234", "efgh", "69"};
	string t5c = "abcdefgh abcd1234 6";

	string t5r = FormatujNapis(t5_b[0], t5_b[1], t5_b[2], t5_b[3]);

	bool m5 = compare(t5_b, t5_a, 4) && t5r == t5c;

	//TEST 6
	string t6_b[] = {"A{p:4:a}le {w:1}tra nudny t{w:1}t. {u:3}UsuCam{U:2}{W:2:3}{W:3:3}.", "eks", "zy", "niebyt"};
	string t6_a[] = {"A{p:4:a}le {w:1}tra nudny t{w:1}t. {u:3}UsuCam{U:2}{W:2:3}{W:3:3}.", "eks", "zy", "niebyt"};
	string t6c = "Aaaaale ekstra nudny tekst. Czy nie.";

	string t6r = FormatujNapis(t6_b[0], t6_b[1], t6_b[2], t6_b[3]);

	bool m6 = compare(t6_b, t6_a, 4) && t6r == t6c;

	//TEST 7
	string t7_b[] = {"", "", "", ""};
	string t7_a[] = {"", "", "", ""};
	string t7c = "";

	string t7r = FormatujNapis(t7_b[0], t7_b[1], t7_b[2], t7_b[3]);

	bool m7 = compare(t7_b, t7_a, 4) && t7r == t7c;

	//TEST 8
	string t8_b[] = {"{w:1}{w:2}{w:3}", "", "", ""};
	string t8_a[] = {"{w:1}{w:2}{w:3}", "", "", ""};
	string t8c = "";

	string t8r = FormatujNapis(t8_b[0], t8_b[1], t8_b[2], t8_b[3]);

	bool m8 = compare(t8_b, t8_a, 4) && t8r == t8c;



	//RESULTS
	const char test_name[] = "form";
	
	cout << (m2 ? "[\033[32mOK\033[0m]    " : "[\033[31mANS\033[0m] ! ") << test_name << "_2\n";
	cout << (m3 ? "[\033[32mOK\033[0m]    " : "[\033[31mANS\033[0m] ! ") << test_name << "_3\n";
	cout << (m4 ? "[\033[32mOK\033[0m]    " : "[\033[31mANS\033[0m] ! ") << test_name << "_4\n";
	cout << (m5 ? "[\033[32mOK\033[0m]    " : "[\033[31mANS\033[0m] ! ") << test_name << "_5\n";
	cout << (m6 ? "[\033[32mOK\033[0m]    " : "[\033[31mANS\033[0m] ! ") << test_name << "_6\n";
	cout << (m7 ? "[\033[32mOK\033[0m]    " : "[\033[31mANS\033[0m] ! ") << test_name << "_7\n";
	cout << (m8 ? "[\033[32mOK\033[0m]    " : "[\033[31mANS\033[0m] ! ") << test_name << "_8\n";

	return !(m1 && m2 && m3 && m4 && m5 && m6 && m7 && m8);
}

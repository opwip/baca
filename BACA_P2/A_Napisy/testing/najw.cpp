#include <iostream>
#include <string>

using namespace std;

string add_after_index(string str, char symbol, int index){
    string str_out = "";
    str_out.resize(str.size() + 1);
    for (int i = 0; i <= index; i++){
        str_out[i] = str[i];
    }
    str_out[index + 1] = symbol;
    for (int i = index; i < index; i++){
        str_out[i+1] = str[i];
    }
    return str_out;
}

string add_to_the_end(string str, char symbol){
    return add_after_index(str, symbol, str.size() - 1);
}

string NajwiekszeSlowo(string str){
    bool is_a_word = false;
    string word_max = "";
    string word = "";

    for (int i = 0; i < size(str); i++){
       
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

int main() {
	//TEST 1
	string t1b = "0000  abcd  ABCD  ABCDEF  ab 0";
	string t1a = "0000  abcd  ABCD  ABCDEF  ab 0";

	string t1c = "abcd";

	string t1r = NajwiekszeSlowo(t1b);

	bool m1 = t1b == t1a && t1c == t1r;

	//TEST 2
	string t2b = "    000 111 222 aa bb cc A B C    ";
	string t2a = "    000 111 222 aa bb cc A B C    ";

	string t2c = "cc";

	string t2r = NajwiekszeSlowo(t2b);

	bool m2 = t2b == t2a && t2c == t2r;

	//TEST 3
	string t3b = "    ";
	string t3a = "    ";

	string t3c = "";

	string t3r = NajwiekszeSlowo(t3b);

	bool m3 = t3b == t3a && t3c == t3r;


	//RESULTS
	const char test_name[] = "najw";
	cout << (m1 ? "[\033[32mOK\033[0m]    " : "[\033[31mANS\033[0m] ! ") << test_name << "_1\n";
	cout << (m2 ? "[\033[32mOK\033[0m]    " : "[\033[31mANS\033[0m] ! ") << test_name << "_2\n";
	cout << (m3 ? "[\033[32mOK\033[0m]    " : "[\033[31mANS\033[0m] ! ") << test_name << "_3\n";

	return !(m1 && m2 && m3);
}

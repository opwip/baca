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
    return remove_at(str, str.size() - 1);
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

int main() {
	//TEST 1
	string t1b = "   Hello  ,world  ";
	string t1a = "   Hello  ,world  ";

	string t1c = "Hello, world";

	string t1r = NormalizujNapis(t1b);
	bool m1 = t1b == t1a && t1c == t1r;

	//TEST 2
	string t2b = "  .  Hello,world  .Hi there. ";
	string t2a = "  .  Hello,world  .Hi there. ";


	string t2c = ". Hello, world. Hi there.";

	string t2r = NormalizujNapis(t2b);

	bool m2 = t2b == t2a && t2c == t2r;

	//TEST 3
	string t3b = " , ";
	string t3a = " , ";

	string t3c = ",";

	string t3r = NormalizujNapis(t3b);

	bool m3 = t3b == t3a && t3c == t3r;


	//RESULTS
	const char test_name[] = "norm";
	cout << (m1 ? "[\033[32mOK\033[0m]    " : "[\033[31mANS\033[0m] ! ") << test_name << "_1\n";
	cout << (m2 ? "[\033[32mOK\033[0m]    " : "[\033[31mANS\033[0m] ! ") << test_name << "_2\n";
	cout << (m3 ? "[\033[32mOK\033[0m]    " : "[\033[31mANS\033[0m] ! ") << test_name << "_3\n";

	return !(m1 && m2 && m3);
}

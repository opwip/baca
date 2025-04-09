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
string FormatujNapis(string source, string p1, string p2, string p3);
string NajwiekszeSlowo(string source);
string NormalizujNapis(string source);

int main() {
	//TEST 1
	string t1b = "0000  abcd  ABCD  ABCDEF  ab 0";
	string t1a = "0000  abcd  ABCD  ABCDEF  ab 0";

	string t1c = "0000  abcd    ABCDEF  ab 0";

	string t1r = UsunSlowo(t1b, 3);

	bool m1 = t1b == t1a && t1c == t1r;

	//TEST 2
	string t2b = "    000 111 222 aa bb cc A B C    ";
	string t2a = "    000 111 222 aa bb cc A B C    ";

	string t2c = "     111 222 aa bb cc A B C    ";

	string t2r = UsunSlowo(t2b, 1);
	bool m2 = t2b == t2a && t2c == t2r;

	//TEST 3
	string t3b = "Smok Wawelski ryczy k uciesze gawiedzi";
	string t3a = "Smok Wawelski ryczy k uciesze gawiedzi";

	string t3c = "Smok Wawelski ryczy k uciesze ";

	string t3r = UsunSlowo(t3b, 6);
	cout << t3r << endl << t3c << endl << t3r.size() << t3c.size();
	bool m3 = t3b == t3a && t3c == t3r;


	//RESULTS
	const char test_name[] = "usun";
	cout << (m1 ? "[\033[32mOK\033[0m]    " : "[\033[31mANS\033[0m] ! ") << test_name << "_1\n";
	cout << (m2 ? "[\033[32mOK\033[0m]    " : "[\033[31mANS\033[0m] ! ") << test_name << "_2\n";
	cout << (m3 ? "[\033[32mOK\033[0m]    " : "[\033[31mANS\033[0m] ! ") << test_name << "_3\n";

	return !(m1 && m2 && m3);
}

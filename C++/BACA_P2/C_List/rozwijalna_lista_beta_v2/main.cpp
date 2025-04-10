//
//		PROGRAMOWANIE 2
//		ZADANIE C - ROZWIJALNA LISTA
//
//		PROGRAM URUCHAMIAJĄCY
//		WERSJA CPP
//
#include <iostream>

using namespace std;

#define BYTE unsigned char
#define OBJECT_TYPE unsigned long long
#define LABEL_INITIALIZED_VAL 0xa1b2c3d4

BYTE SIZE = 0;
bool print_node_ids = false;
struct NODE_STRUCT {
	OBJECT_TYPE* object;
	BYTE use;
	NODE_STRUCT* next;

	unsigned long long _label_initialized = 0; //user does not initialize this value nore the label, so we check if it matched LABEL_INITIALIZED_VAL (highly unlikely to match with random value uninitialized).
	char _node_label = 'X';
};

#include "source.cpp"

void print_node(NODE_STRUCT* node) {
	if(node == NULL) {
		cout << "[NULL NODE]" << endl;
		return;
	}

	if(node -> use == 0) {
		cout << "[EMPTY NODE]" << endl;
		return;
	}
	if(print_node_ids) {
		if(node -> _label_initialized == LABEL_INITIALIZED_VAL)
			cout << node -> _node_label << ":\t";
		else
			cout << "X:\t";
	}

	for(BYTE i = 0; i < node -> use; i = i + 1)
		cout << node -> object[i] << "\t";
	for(BYTE i = node -> use; i < SIZE; i = i + 1)
		cout << "X\t";
	cout << endl;
}

void print_object(NODE_STRUCT* node, BYTE index) {
	if(node == NULL) {
		cout << "[NULL OBJECT]" << endl;
		return;
	}

	OBJECT_TYPE* obj = node -> object + index;
	cout << "OBJECT "<< *obj;

	if(print_node_ids && node -> _label_initialized == LABEL_INITIALIZED_VAL)
		cout <<" ON " << node -> _node_label;

	cout << endl;
	return;
}

void print_chain(NODE_STRUCT* root) {
	if(root == NULL) {
		cout << "[EMPTY CHAIN]" << endl;
		return;
	}
	cout << "=====BEGIN PRINT=====" << endl;
	NODE_STRUCT* current = root;
	while(current != NULL) {
		print_node(current);
		current = current -> next;
	}
	cout << "======END PRINT======" << endl;
}

void set_label(NODE_STRUCT* node, char label) {
	if(node == NULL)
		return;
	node -> _node_label = label;
	node -> _label_initialized = LABEL_INITIALIZED_VAL;
}

void init(NODE_STRUCT** root, unsigned int elements) {
	unsigned int counter = 0;

	char current_label = 'A';
	while(counter < elements) {
		unsigned int elements_to_init;
		if(elements - counter < SIZE)
			elements_to_init = elements - counter;
		else
			elements_to_init = SIZE;

		NODE_STRUCT* new_node = NewNode();
		new_node -> _node_label = current_label;
		new_node -> _label_initialized = LABEL_INITIALIZED_VAL;
		current_label = current_label + 1;
		new_node -> use = elements_to_init;
		for(unsigned int i = 0; i < elements_to_init; i = i + 1)
			new_node -> object[i] = counter + i;

		counter = counter + elements_to_init;

		new_node -> next = NULL;
		*root = new_node;
		root = &(new_node -> next);
	}

}

int main() {
	unsigned short _size;
	cin >> _size >> print_node_ids;
	SIZE = _size;

	NODE_STRUCT* root = NULL;
	NODE_STRUCT* node_memory;
	BYTE index_memory;

	string operation;
	while(true) {
		cin >> operation;

		if(operation.length() >= 1 && operation[0] == '#') {
			string tmp;
			getline(cin, tmp);
			continue;
		}

		if(operation == "I") {
			unsigned int number;
			cin >> number;
			init(&root, number);
			continue;
		}

		if(operation == "L") {
			char label;
			cin >> label;
			set_label(node_memory, label);
			continue;
		}

		if(operation == "P") {
			print_chain(root);
			continue;
		}

		if(operation == "Q") {
			Clear(&root);
			return 0;
		}

		if(operation == "M") {
			print_object(node_memory, index_memory);
			continue;
		}

		if(operation == "CL") {
			Clear(&root);
			continue;
		}

		if(operation == "AF") {
			unsigned long long number;
			cin >> number;
			AddFirst(&root, &number);
			continue;
		}

		if(operation == "AL") {
			unsigned long long number;
			cin >> number;
			AddLast(&root, &number);
			continue;
		}

		// if(operation == "GF") {
		// 	GetFirst(root, &node_memory, &index_memory);
		// 	continue;
		// }

		// if(operation == "GP") {
		// 	GetPrev(root, node_memory, index_memory, &node_memory, &index_memory);
		// 	continue;
		// }

		// if(operation == "GN") {
		// 	GetNext(root, node_memory, index_memory, &node_memory, &index_memory);
		// 	continue;
		// }

		// if(operation == "GL") {
		// 	GetLast(root, &node_memory, &index_memory);
		// 	continue;
		// }

		// if(operation == "IP") {
		// 	unsigned long long number;
		// 	cin >> number;
		// 	InsertPrev(&root, node_memory, index_memory, &number);
		// 	continue;
		// }

		// if(operation == "IN") {
		// 	unsigned long long number;
		// 	cin >> number;
		// 	InsertNext(root, node_memory, index_memory, &number);
		// 	continue;
		// }

		// if(operation == "RF") {
		// 	RemoveFirst(&root);
		// 	continue;
		// }

		// if(operation == "RP") {
		// 	RemovePrev(&root, node_memory, index_memory);
		// 	continue;
		// }

		if(operation == "RC") {
			RemoveCurrent(&root, node_memory, index_memory);
			continue;
		}

		// if(operation == "RN") {
		// 	RemoveNext(root, node_memory, index_memory);
		// 	continue;
		// }

		// if(operation == "RL") {
		// 	RemoveLast(&root);
		// 	continue;
		// }

		// if(operation == "XF") {
		// 	unsigned long long number;
		// 	cin >> number;
		// 	Find(root, &number, &node_memory, &index_memory);
		// 	continue;
		// }

		// if(operation == "XC") {
		// 	Compress(root);
		// 	continue;
		// }

		// if(operation == "XR") {
		// 	Reverse(root);
		// 	continue;
		// }
	}
}

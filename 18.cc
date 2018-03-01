#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;


class Node
{
public:
	Node(int v){
		value = v;
	}
	int calcMaxPath(){
		if(maxPath == 0){
			int r = 0, l = 0;
			if(left != NULL)
				l = left->calcMaxPath();
			if(right != NULL)
				r = right->calcMaxPath();
			maxPath = max(r,l) + value;
		}
		return maxPath;
	}
	void printtree (Node n){
		cout << "{" << n.value;
		if(n.left != NULL){
			cout << ",";
			printtree(*n.left);
		}
		if(n.right != NULL){
			cout << ",";
			printtree(*n.right);
		}
		cout << "}";
	}			
	int maxPath = 0;
	int value;
	Node * right = NULL;
	Node * left = NULL;
};


int main(int argc, char *argv[])
{
	if(argc == 2){
		//Build tree, First read and create nodes
		vector<Node> tree;
		fstream fin;
		fin.open(argv[1],ifstream::in);
		string line, elem;
		int rows = 0;
		while(getline(fin,line)){
			istringstream nodes(line);
			rows++;
			while(getline(nodes, elem, ' ')){
				Node * ptr = new Node(stoi(elem));
				tree.push_back(*ptr);
			}
		}
		//Link Parents to Children
		int row = 1;
		int count = 0;
		for(int i = 0; i < tree.size()-rows;i++){
			tree[i].left = &tree[i+row];
			tree[i].right = &tree[i+1+row];			
			if(row == ++count){
				count = 0;
				row++;
			}
		}
		cout << tree[0].calcMaxPath() << "\n";
		
		//Find max path
	}
	return 0;
}


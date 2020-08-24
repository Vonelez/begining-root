#include "read_tree.h"
Read_Tree::Read_Tree(TTree *straw){
	read_tree(straw);
}

Read_Tree::~Read_Tree() = default;

void Read_Tree::read_tree(TTree *straw){
	straw -> SetBranchAddress("nt00", &nt00);
	straw -> SetBranchAddress("tt00", &tt00);
	straw -> SetBranchAddress("nt08", &nt08);
	straw -> SetBranchAddress("tt08", &tt08);
	std::cout << "the Tree was read" << std::endl;
}

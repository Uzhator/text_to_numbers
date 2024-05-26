#include "functions.h"

using namespace std;

int getPos(vector<char>& vec, char& ch){
	for(unsigned long long int i = 0; i < vec.size(); i++){
		if(vec[i] == ch){return i;}
	}
	return -1;
}

void getText(vector<char>& v_ch, vector<unsigned long long int>& v_ind, unsigned long long int& M){
	char ch;

	ifstream in("in.txt");
	if(in.is_open()){
		while(in.get(ch)){
			if(getPos(v_ch, ch) == -1){v_ch.push_back(ch);}
			v_ind.push_back(getPos(v_ch, ch));
		}
		M = v_ch.size() + 1;
	}
	in.close();
}

void encoding(vector<unsigned long long int>& v_hash, vector<unsigned long long int>& v_ind, unsigned long long int& M){
	unsigned long long int hash = 0, tM = 1, N = log(ULLONG_MAX) / log(M);

	for(unsigned long long int i = 0; i < v_ind.size(); i++){
		hash += tM * (v_ind[i] + 1);
		tM *= M;;
		if(i % N == N - 1 || i == v_ind.size() - 1){
			v_hash.push_back(hash);
			hash = 0;
			tM = 1;
		}
	}
}

void encodingText(vector<unsigned long long int>& v_hash, vector<char>& v_ch, unsigned long long int& M){
	char ch;
	ifstream in_key("in_key.txt");
	if(in_key.is_open()){
		getKey(v_ch, in_key);
	}
	in_key.close();
	M = v_ch.size() + 1;
	unsigned long long int hash = 0, tM = 1, N = log(ULLONG_MAX) / log(M), n = 0;
	bool f;
	
	ifstream in("in.txt");
	if(in.is_open()){
		while(in.get(ch)){
			if(getPos(v_ch, ch) == -1){cout << "Невозможно закодировать данным ключом\n"; exit(1);}
			hash += tM * (getPos(v_ch, ch) + 1);
			tM *= M;
			n++;
			f = true;
			if(n % N == N - 1){
				v_hash.push_back(hash);
				hash = 0;
				tM = 1;
				n = 0;
				f = false;
			}
		}
		if(f){
			v_hash.push_back(hash);
			hash = 0;
			tM = 1;
			n = 0;
		}
	}
	in.close();
}

void outHashAndKey(vector<unsigned long long int>& v_hash, vector<char>& v_ch){
	ofstream out_hash("hash.txt");
	ofstream out_key("out_key.txt");
	if(out_hash.is_open() && out_key.is_open()){
		for(unsigned long long int i = 0; i < v_hash.size(); i++){
			out_hash << v_hash[i] << " ";
		}
		for(unsigned long long int i = 0; i < v_ch.size(); i++){
			out_key << v_ch[i];
		}
	}
	out_hash.close();
	out_key.close();
}

void getKey(vector<char>& v_ch, ifstream& in){
	char ch;
	while(in.get(ch)){
		v_ch.push_back(ch);
	}
}

void getHash(vector<unsigned long long int>& v_hash){
	unsigned long long int hash;

	ifstream in_hash("hash.txt");
	if(in_hash.is_open()){
		while(in_hash >> hash){
			v_hash.push_back(hash);
		}
	}
	in_hash.close();
}

void decoding(vector<unsigned long long int>& v_hash, vector<char>& v_ch){
	unsigned long long int M = v_ch.size() + 1, tM = 1;

	ofstream out("out.txt");
	if(out.is_open()){
		for(unsigned long long int p = 0; p < v_hash.size(); p++){
			while(v_hash[p] / tM % M - 1 != -1){
				out << v_ch[v_hash[p] / tM % M - 1];
				tM *= M;
			}
			tM = 1;
		}
	}
	out.close();
}
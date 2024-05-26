#include "functions.h"

using namespace std;

int main(){
	bool loop = true;
	int choice;

	unsigned long long int M;
	vector<char> v_ch;
	vector<unsigned long long int> v_ind;

	vector<unsigned long long int> v_hash;

	while(loop){
		cout << "1 - закодировать\n";
		cout << "2 - закодировать по in_key.txt\n";
		cout << "3 - закодировать по in_key.txt с добавлением недостающих символов\n";
		cout << "4 - раскодировать\n";
		cout << "0 - выход\n";
		cin >> choice;

		v_ch.clear();
		v_ind.clear();
		v_hash.clear();
		
		switch(choice){
			case 1:{
				getText(v_ch, v_ind, M);
				encoding(v_hash, v_ind, M);
				outHashAndKey(v_hash, v_ch);
				break;
			}
			case 2:{
				encodingText(v_hash, v_ch, M);
				outHashAndKey(v_hash, v_ch);
				break;
			}
			case 3:{
				ifstream in_key("in_key");
				if(in_key.is_open()){
					getKey(v_ch, in_key);
				}
				in_key.close();
				getText(v_ch, v_ind, M);
				encoding(v_hash, v_ind, M);
				outHashAndKey(v_hash, v_ch);
				break;
			}
			case 4:{
				ifstream out_key("out_key.txt");
				if(out_key.is_open()){
					getKey(v_ch, out_key);
				}
				out_key.close();
				getHash(v_hash);
				decoding(v_hash, v_ch);
				break;
			}
			case 0:{
				loop = false;
				break;
			}
			default:{
				loop = false;
				break;
			}
		}
	}

	return 0;
}
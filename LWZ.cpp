#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <cstring>

using namespace std;

class HashTable{
	//const static int size = 4096;
	int size;
	char *array[];

	int hash(char *s){
		unsigned int code = 0;
		for(int i=0; i<s.size(); ++i) code+=s[i];
		return code%size;
	}

	public:
	void insert(char *s){
		int h = hash(s);
		for(int i=0; i<size; ++i){
			if(!array[(h+i*i)%size]){
				array[(h+i*i)%size] = s;
				//cout<<s<<" "<<(h+i*i)%size<<"\n";
				return;
			}
		}
		resize();
		insert(s);
		return;
	}

	char* get(int i){
		return array[i];
	}

	int check(string s){
		int h = hash(s);
		for(int i=0; array[(h+i*i)%size].compare("\0")!=0 && i<size; ++i){
			if(array[(h+i*i)%size].compare(s)==0) return (h+i*i)%size;
		}
		return -1;
	}

	void resize(){
		//char *new_array[]
		size*=2;
		char **old_array = array;
		array = new char*[size];
		for(int i=0;i<size/2;++i){
			if(old_array[i]){
				insert(old_array[i]);
			}
		}
		for(int i = 0; i<old_array.size(); ++i)
		delete[] old_array[i];
		delete old_array;
	}

	HashTable(){
		size = 512;
		array = new char*[size];
		char s;
		for(int i=0; i<256; ++i){
			s=i;
			array[i] = string(1,s);
		}
		for(int i=256; i<size; ++i) array[i] = NULL;
	}
	~HashTable(){
		for(int i=0; i<array.size();++i)
		delete[] array[i];
		delete array;
	}
};
/*
class Encoder{
	HashTable map;

	public:
	Encoder(char *path1, char *path2){
		string p;
		char c;
		int val;
		ofstream fout;
		ifstream fin;
		fin.open(path1);
		fout.open(path2);

		while(fin.get(c)){
			string temp = p+c;
			val = map.check(temp.c_str());
			if(val!=-1){
				p += c;
			} else{

				map.insert(strcat(p,c));
				//cout<<map.check(p+c)<<p<<"\n";
				fout<<map.check(p)<<"\n";
				strcpy(p,c); // p = c;
			}
		}
		fout<<map.check(p);
		//cout<<val<<p<<"\n";
	}
};

class Decoder{
	HashTable map;

	public:
	Decoder(char *path2){
		ifstream fin;
		fin.open(path2);

		int old;
		int nw;
		char *s;
		char c;

		while(fin>>nw){
			//cout<<nw<<"\n";
			char *str = map.get(nw);
			if(!str){
				s = map.get(old);
				s+=c;
			} else{
				s = str;
			}
			c = s[0];
			map.insert(map.get(old)+c);
			old = nw;
		}
	}
};
*/

int main(int argc, char const *argv[]){
	// instructions
	// Type anything in file a.txt and the compressed version is stored in b.txt
	// enjoy life
	// if(argc>2){
	// 	Encoder(string(argv[1]),string(argv[2]));
	// 	Decoder(string(argv[2]));
	// }else cout<<"Too less arguments\n";

	

	return 0;
}
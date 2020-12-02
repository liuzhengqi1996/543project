#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;

string add_10(string input,int seed){
    for(int i=0;i<10;i++){
	char ch;
	srand(seed+11987*i);
        ch = (char)(random()%(127-33) + 33);
        input.push_back(ch);
    }
    return input;
}

string change_13(string input,int seed){
    int n = input.size();
    srand(seed);
    for (int i =0;i<n;i++){
	srand(seed+2373*i);
        int r = random()%100;
	if (r < 14){
	    srand(seed+1067*i);
	    input[i] = (char)(random()%(127-33) +33);
	}
    }
    return input;
}

int main(int argc, char* argv[]){
    if (argc<3){
    	cout<<"wrong input! "<<endl;
	return -1;
    }

    int prng_seed = stoi(argv[1]);
    int num_of_iterations = stoi(argv[2]);

    vector<string> init_vector;
    
    ifstream file;
    string init;
    file.open("seed");
    while(file){
        getline(file,init);	
	init_vector.push_back(init);
    }
    file.close();
    init_vector.pop_back();
    int length = init_vector.size(); 
    vector<string> B(length);
    for(int i = 0; i<num_of_iterations;i++){
        	
        if ( i >1 && i%500 == 0 ){
	    for (int j =0;j<length;j++){ 
		    
	    init_vector[j] = add_10(init_vector[j],prng_seed+10067*i);
	    }
	}
        
	for (int j =0 ;j<length;j++){
	 B[j] = change_13(init_vector[j],prng_seed+1059*i);
	                            }
	
	 
	for (int j =0 ;j<length;j++){
           cout<<B[j]<<endl;
	}
//cout<<'\n'<<endl;
    } 

        

 
 return 0;   
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <unistd.h>
#include <stdio.h>
using namespace std;

int main(){
	string line;
	long m = 1;
	long n  = 1;
	long x = 0;
	long sum = 0;
	int counter = 0;
	int i;
	char c;

	vector<long> a;
	
	while(x<4000000){
		x = m + n;
		a.push_back(x);
		m = n;
		n = x;
		counter ++;
	}
	copy(a.begin(), a.end(), ostream_iterator<long>(cout, "\n")); //Printing out the values of vector
	
	

	cout << a[counter -2] << endl; 
	cout << "-----------------------------------" << endl;

	for(i=0; i< a.size() -1; i++){
		if(a[i]%2 == 0){
			cout << a[i] << endl;
			sum = sum + a[i];
		}
	}
	cout << "--------" << endl;
	cout << sum << endl;
//Writing the result to file
	ifstream existFile("result2.txt");
	if(existFile){
		cout << "File aready exist" << endl;
		cout << "The content is following: " << endl;
		ifstream existFile("result2.txt");
		if(existFile.is_open()){
			while(existFile.good()){
				getline(existFile, line);
				cout << line << endl;
			}
			cout << "----------------End of file.";
			cout << "Do you want to rewrite the file?(y/n) " << endl;
			cin >> c; if(c == 'y'){
				ofstream myfile("C:\\Users\\jimmy\\Desktop\\C++\\ProjectEuler\\result2.txt"); 
				if(myfile.is_open())
				{
					myfile << "The sum of even numbered fibbonaci numbers under 4 mil. is: " << sum << endl;
					myfile.close();

				}
				else cout << "Unable to open file." << endl;

			}


		}
		
		else cout << "Unable to open file" << endl;
	}

	else{
		ofstream myfile("C:\\Users\\jimmy\\Desktop\\C++\\ProjectEuler\\result2.txt"); 
		if(myfile.is_open())
		{
			myfile << "The sum of even numbered fibbonaci numbers under 4 mil. is: " << sum << endl;
			myfile.close();

		}
		else cout << "Unable to open file." << endl;
	}
//--get current dirrectory
char * dir = getcwd(NULL, 0); // Platform-dependent, see reference link below    
printf("Current dir: %s", dir);


return 0;
}

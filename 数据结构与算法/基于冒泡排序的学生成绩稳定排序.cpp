#include <iostream>
#include <cstring>
using namespace std;


struct student{
	int id;
	char name[20];
	int score;
};

student* stu(int n){
	student* s = new student[n];
	for(int i =0; i < n; i++){
		cin>>s[i].id >>s[i].name>>s[i].score;
	}
	return s;
}


void bubble(student* stu, int n){                  
	for(int i =0; i < n-1;i++){
		int flag = false;
		for(int j = 0; j < n-1-i; j++){
			if(stu[j].score < stu[j+1].score){
				student temp = stu[j];
				stu[j] = stu[j+1];
				stu[j+1] = temp;
				flag = true; 
			}
		}
		if(flag == false) break;
	}
}


void prt(student* s, int n){
	for(int i = 0; i < n; i++){
		cout<< s[i].id << " " <<s[i].name  << " "<<s[i].score;
		cout<< endl; 
	}
}

int main(){
	int n;
	cin>> n;
	student* s = stu(n);
	bubble(s,n);
	prt(s,n);
	delete[] s;
	return 0;
}

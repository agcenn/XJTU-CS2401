#include <iostream>
#include <cstring>
using namespace std;

struct student{
	int id;
	char name[20];
	int score;
};

student *stu(int n){
	student *s = new student[n];
	for(int i = 0; i < n; i++){
		cin>> s[i].id >> s[i].name >> s[i].score;
}
	return s;
}

void select(student *stu,int n){
	for(int i = 0; i < n-1; i++){
		int max = i;
		for(int j = i+1; j < n; j++){
			if(stu[j].score >stu[max].score){
				max = j;
			}
		}
		student temp = stu[i];
		stu[i] = stu[max];
		stu[max] = temp;
	}
}



void prt(student *s, int n){
	for(int i = 0; i< n;i++){
		cout<< s[i].id <<s[i].name <<s[i].score;
			cout<< endl;
	}
		   
}         

int main(){
	int n;
	cin>> n;
	student *arr = stu(n);
	select(arr,n);
	prt(arr,n);
	
	return 0;
	
}

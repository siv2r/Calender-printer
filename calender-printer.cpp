#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *hor;
	node *ver;
};

node* initcal(){
	node *C = NULL, *hptr, *vptr, *prev_hptr, *prev_vptr;
	
	for(int i=0; i<21; i++){
		node *temp1 = new node;
		temp1->data = 0;
		temp1->hor = NULL;
		temp1->ver = NULL;
		if(i == 0){
			C = hptr = vptr = temp1;
		}
		hptr->hor = temp1;
		prev_hptr = hptr;
		prev_vptr = prev_hptr;
		hptr = hptr->hor;
		vptr = hptr;		
		for(int j=1; j<20; j++){
			if(i>0) prev_vptr = prev_vptr->ver;
			node *temp2 = new node;
			temp2->data = 0;
			temp2->hor = NULL;
			temp2->ver = NULL;
			vptr->ver = temp2;
			vptr = vptr->ver;
			if(i>0) prev_vptr->hor = vptr;
		}
	}
	return C; 
}

void display(node* C){
		node *hptr, *vptr;
		hptr = vptr = C;
		while(vptr){
			while(hptr){
				if(!(hptr->data/10)) cout<<" "<<hptr->data<<" ";
				else cout << hptr->data << " ";
				hptr = hptr->hor;
			}
			cout<<"\n";
			vptr = vptr->ver;
			hptr = vptr;
		}
}

int month_days(int month, int year){
	if(month == 1 && (year%4 == 0)){
		if(year%100 == 0){
			if(year%400 == 0) return 29;
			else return 28;
		}
		else return 29;
	}
	else if(month == 0|| month == 2|| month == 4|| month == 6|| month == 7||
	month == 9|| month == 11) return 31;
	else return 30;
}

int storemonth(node *C, int month, int begins, int year){
	node *vptr = C, *hptr,*ptr=C;
	int row = month/3, col = month%3, i = 0, j = 0, count = 0, lvl=1;
	int days = month_days(month, year);
	while(i < row*5){
		ptr = ptr->ver;
		i++;
	}
	while(j < col*7){
		ptr = ptr->hor;
		j++;
	}
	vptr = ptr;
	hptr = vptr;
	while(begins--){
		hptr = hptr->hor;
		count++;
	}
	hptr->data = 1;
	for(int i=2; i<=days; i++){
		if(((count == 7)||(count==6&&lvl==1)) && lvl<=5){
			vptr = vptr->ver;
			lvl++;
			hptr = vptr;
			count = 0;
		}
		else hptr = hptr->hor;
		if(lvl==6){
			vptr = ptr;
			hptr = vptr;
		}
		hptr->data = i;
		count++;
	}
	if(count == 7) count = 0;
	return count; 
}

void neatprint(node *C){
	for(int j=0; j<4; j++){
		for(int i=0; i<3; i++){
			if(j==0&&i==0) cout<<"  "<<"  "<<"  "<<"  "<<" "<<"January"<<"              "
				<<"  "<<"  "<<"  "<<"  "<<" "<<"February"<<"             "
					<<"  "<<"  "<<"  "<<"  "<<" "<<"March"<<"                "<<"\n";
			if(j==1&&i==0) cout<<"  "<<"  "<<"  "<<"  "<<" "<<"April"<<"                "
			             <<"  "<<"  "<<"  "<<"  "<<" "<<"May"<<"                  "
			             <<"  "<<"  "<<"  "<<"  "<<" "<<"June"<<"                 "<<"\n";
			if(j==2&&i==0) cout<<"  "<<"  "<<"  "<<"  "<<" "<<"July"<<"                 "
							   <<"  "<<"  "<<"  "<<"  "<<" "<<"August"<<"               "
							   <<"  "<<"  "<<"  "<<"  "<<" "<<"September"<<"            "<<"\n";
			if(j==3&&i==0) cout<<"  "<<"  "<<"  "<<"  "<<" "<<"October"<<"              "
						       <<"  "<<"  "<<"  "<<"  "<<" "<<"November"<<"             "
							   <<"  "<<"  "<<"  "<<"  "<<" "<<"December"<<"             "<<"\n";
			cout<<"Su"<<"  "<<"Mo"<<"  "<<"Tu"<<"  "
					<<"We"<<"  "<<"Th"<<"  "<<"Fr"<<"  "<<"Sa"<<"    ";
		}
		cout<<"\n";
		node *vptr, *hptr;
		if(j==0)vptr = C;
		hptr = vptr;
		for(int i=0; i<5; i++){
			int count = 0;
			while(hptr){
				if((count == 7)){
					cout<<"  ";
					count = 0;
				}
				if(hptr->data == 0) cout<<"    ";
				else if(!(hptr->data/10)) cout<<" "<<hptr->data<<"  ";
				else cout<<hptr->data<<"  ";
				count++;
				hptr = hptr->hor;
			}
			vptr = vptr->ver;
			hptr = vptr;
			cout<<"\n";
		}
		cout<<"\n\n\n\n";
	}
}

		
int main(){
	int year, first_day;
	int month;
	cout<<"Enter year and the first day of that year :"<<"\n"
			<<"Example: 1999 3"<<"\n"<<"year first_day :";
	cin>>year>>first_day;
	cout<<"\n\n";
	node* C = initcal();
	for(int i=0; i<12; i++){
		first_day = storemonth(C, i, first_day, year);
	}	
	neatprint(C); 	
}
	
	


























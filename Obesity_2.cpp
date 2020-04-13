#include <vector>
#include <iostream>
#include <graphics.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <dos.h>
#include <conio.h>
#include <windows.h>

using namespace std;
const int size=30;

class point{
	public:
		
	vector<vector<int> >grid;
	vector<vector<int> >generate;
	vector<vector<int> >risks;
	vector<vector<int> >store;
	vector<vector<int> >limit;
	vector<vector<int> >cells;
	vector<vector<int> >n_risks;
	
	int state;
	int count=0;
	int counter=0;
	int t=1;
	bool metraw=false;
	int s=-1;
	int diafora=0;
	int k=0;
	int l=0;
	int times=0;
	int total=0;
	int total1, total2;
	int sum=0;
	bool draw=true;
	bool flag=false;
	
void drawLine(int x, int y){
int l=7;
int step=20;
	if(state==0)
		setcolor(5);
		
    else if(state==1)
    	setcolor(15);
	
    else if(state==2)
    	setcolor(14);
    	
    else if(state==3)
    	setcolor(2);
    else
    	setcolor(0);
    	
    for(int i=0; i<5; i++)
    line(x*l+step,y*l+i,x*l+step+5,y*l+i);
}

bool compare(int a, int b){
	bool n=false;
	for(int x=0; x<cells.size(); x++){
		if((a==store[x][0]) && (b==store[x][1])){
			generate[a][b]=3;
			n=true;
			return n;
		}		
	}
}

void newstate(int osum,int hsum, int i, int j){

	int stoixeio=cells[i][j];
	int risk=risks[i][j];
	
 
	if((stoixeio==0) || (stoixeio==1)){
		if((hsum-risk)<0){		
			generate[i][j]=0;
		}else if((hsum-risk)<=1){
			generate[i][j]=1;
		}else if((hsum-risk)<=3){
			generate[i][j]=2;
		}else if((hsum-risk)>3){
			generate[i][j]=3;
		}

				
	}else if((stoixeio==3) || (stoixeio==2)){
		if((osum+risk)>11){
			generate[i][j]=0;
		}else if((osum+risk)>=9){
			generate[i][j]=1;
		}else if((osum+risk)>=7){
			generate[i][j]=2;
		}else if((osum+risk)<7){
			generate[i][j]=3;
		}
	
	}else if(stoixeio==4){
		generate[i][j]=4;
	}
}

void changes(int a, int b){
	int fores=0;
	
	for(int i=a; i<b; i++){
	for(int j=0; j<cells.size(); j++){
		
		if(cells[i][j]==0){
			
				if(limit[i][j]>5){
					s++;
					store[counter][0]=i;
					store[counter][1]=j;
					
					fores++;
					counter++;
					cells[i][j]=3;				
					cout<<s<<")(i, j)="<<i<<","<<j<<endl;
					if(fores>=2){
						i=cells.size();
						j=cells.size();
					}	
					}
				}
		}
	}
	}

int stable(){
flag=true;	
for(int i=0; i<cells.size(); i++){
	for(int j=0; j<cells.size(); j++){
		if(cells[i][j]!=generate[i][j]){
			flag=false;
			i=cells.size();
			j=cells.size();
		}
	}
	}
	return(flag);
	
}

void Generate(){
	
bool same=false;
total1=total2=0;

same=stable();

if(times<5)
	same=stable();
else
	same=true;
	
if((same==true) && (diafora-s>=1)) {
count++;
		
draw=false;
times=0;	
	
	for(int i=0; i<cells.size(); i++){
		for(int j=0; j<cells.size(); j++){
			if(cells[i][j]==0)
				total1++;
			if(cells[i][j]==1)
				total2++;	
		}
	}
	if(count==1){
		cout<<"Sta8erh katastash \n \n";
		total=total1+total2;
	}
		
	cout<<"Arithmos paxusarkwn="<<total1<<endl;
	cout<<"Arithmos oriaka paxusarkwn="<<total2<<endl;
	cout<<"Sunolikos arithmos="<<total1+total2<<"\n \n";
	if(count>1){
		diafora=total-(total1+total2);
		cout<<"O arithmos twn keliwn stis katastaseis 0, 1 meiw8hke kata "<<diafora<<endl;
		total=total1+total2;
	}
	if(count>2)
		cout<<"Pros8hkh "<<diafora-s<<" ugiwn atomwn"<<endl;
		
	if(count==1){
		
		cout<<"Plegma sta8erhs katastashs: \n";
		for(int i=0; i<cells.size(); i++){
			for(int j=0; j<cells.size(); j++){
				cout<<cells[i][j]<<" ";
			}
			cout<<endl;
		}	
		cout<<endl;
	}
	if(diafora-s>=1){
	s=0;	
	cout<<"Ta kelia sta opoia ginetai parembash einai: \n";
	changes(0, cells.size()/4);
	changes(cells.size()/4, cells.size()/2);
	changes(cells.size()/2, 3*cells.size()/4);
	changes(3*cells.size()/4, cells.size());
	
		
	for(int i=0; i<cells.size(); i++){
		for(int j=0; j<cells.size(); j++){
			state=cells[i][j];
			drawLine(j,i);
				
			}
			cout<<endl;
		}
		
	}else{
		cout<<"Telos parembasewn";
	}
	
	if(count==1)	s=-1;

		
}else if(same==true && diafora-s<1){
		cout<<" ";
	
}else{
		
		for(int i=0; i<cells.size(); i++){
			for(int j=0; j<cells.size(); j++){
				cells[i][j]=generate[i][j];
			}
		}
	
		cout<<"Plegma epomenhs genias: \n";
		for(int i=0; i<cells.size(); i++){
			for(int j=0; j<cells.size(); j++){
				cout<<cells[i][j]<<" ";
				
			}
			cout<<endl;
		}
	
		for(int i=0; i<cells.size(); i++){
		for(int j=0; j<cells.size(); j++){
			state=generate[i][j];
			drawLine(j,i);
			}
		}

	times++;
				
	}
	cout<<endl;
		
}

void neighbors(){
	int ob,heal,sum;
	int size=cells.size();
	bool normal=false;
	int c=0;
	
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			
			ob=0;
			heal=0;
			
			if(i!=0){
				if((cells[i-1][j]==0 || cells[i-1][j]==1)){
					ob++;	
				}else{
					if(cells[i-1][j]!=4)		
					heal++;
						
				}
			}
			
			if(j!=0){
				if((cells[i][j-1]==0 || cells[i][j-1]==1)){
				ob++;	
			}else{
				if(cells[i][j-1]!=4)
				heal++;
				
			}
			}
			
			if(i!=size-1){
				if((cells[i+1][j]==0 || cells[i+1][j]==1)){
				ob++;	
			}else{
				if(cells[i+1][j]!=4)
				heal++;
				
			}	
			}
			
			if(j!=size-1){
					if((cells[i][j+1]==0 || cells[i][j+1]==1)){
				ob++;	
			}else{
				if(cells[i][j+1]!=4)
				heal++;
				
			}		
			}
		
			if(i!=0 && j!=0){
				if((cells[i-1][j-1]==0 || cells[i-1][j-1]==1)){
				ob++;	
			}else{
				if(cells[i-1][j-1]!=4)
				heal++;
				
			}
			}
			
			if(i!=size-1 && j!=0){
				if((cells[i+1][j-1]==0 || cells[i+1][j-1]==1) ){
				ob++;	
			}else{
				if(cells[i+1][j-1]!=4)
				heal++;
				
			}
			}
			
			if(i!=size-1 && j!=size-1){
				if((cells[i+1][j+1]==0 || cells[i+1][j+1]==1) ){
					ob++;	
				}else{
					if(cells[i+1][j+1]!=4)
					heal++;
					
				}	
			}
			
			if(i!=0 && j!=size-1){
				if((cells[i-1][j+1]==0 || cells[i-1][j+1]==1) ){
				ob++;	
			}else{
				if(cells[i-1][j+1]!=4)
				heal++;
				
			}
		}
		limit[i][j]=ob;
		
		if(t>1){
			normal=compare(i,j);
			if(normal==false)	
				newstate(ob,heal,i,j);
		}else{
			newstate(ob,heal,i,j);
		}
		t++;
							
		}	
	}
	
Generate();
}

int findAverage(int a, int b){
	
	int avg=0;
	for(int x=a; x<a+2; x++){
		for(int y=b; y<b+2; y++){
			avg+=risks[x][y];
		}
	}
	return avg/4;
}

int findMajority(int a, int b){

	int c0,c1,c2,c3,c4, max, max2;
	int number=4;
	c0=c1=c2=c3=c4=max=max2=0;
		
	for(int x=a; x<(a+2); x++){
		
		for(int y=b; y<(b+2); y++){
			if(grid[x][y]==0){
				c0++;
			}else if(grid[x][y]==1){
				c1++;
			}else if(grid[x][y]==2){
				c2++;
			}else if(grid[x][y]==3){
				c3++;
			}else {
				c4++;
			}
		}
	
	}
	
	if(c0>max)	max=c0;
	if(c1>max)	max=c1;
	if(c2>max)	max=c2;
	if(c3>max)	max=c3;
	if(c4>max)	max=c4;
	
	
	if((max>2) || ((c4==1) && (max==2))){
		if(max==c0)			return 0;
		else if(max==c1)	return 1;
		else if(max==c2)	return 2;
		else if(max==c3)	return 3;
		else				return 4;	
	}else{
		if(c4>0){
			for(int x=0; x<c4; x++){
				number--;
			}
		}
			
		max=(1*c1+2*c2+3*c3)/number;
		return(max);
	}
	
	
}

int join(){
	
	int k,l,v1,v2;
	
	k=0;
	for(int i=0; i<grid.size()-1; i+=2){	
		l=0;
		for(int j=0; j<grid.size()-1; j+=2){
			
			v1=findMajority(i, j);
			cells[k][l]=v1;
			
			v2=findAverage(i, j);
			n_risks[k][l]=v2;
			
			if(l>=grid.size()-2)		
				l=grid.size();
				
			l++;
		}
		k++;
		if(k>=grid.size()-2){
			k=grid.size();
		}
}
cout<<"Plegma me 4 geitones/keli:  \n";
for(int i=0; i<cells.size(); i++){	
	for(int j=0; j<cells.size(); j++){
		cout<<cells[i][j]<<" ";
	}
	cout<<endl;
}
cout<<endl;
for(int i=0; i<cells.size(); i++){	
	for(int j=0; j<cells.size(); j++){
		state=cells[i][j];
		drawLine(j,i);
		
	}
}

}
void initiallization(){
			
	for(int i=0; i<size; i++){
		
		vector<int>temp;
		vector<int>stuff;
		vector<int>r;

		vector<int>l;
		
	for(int j=0; j<size; j++){
		temp.push_back(rand()%5);
		stuff.push_back(0);
		r.push_back(rand()%8);
		
		l.push_back(0);
		
	}
	grid.push_back(temp);
	generate.push_back(stuff);
	risks.push_back(r);
	
	limit.push_back(l);
	
}
for(int i=0; i<50; i++){
	vector<int>str;
	for(int j=0; j<2; j++){
		str.push_back(0);
	}
	store.push_back(str);
}


for(int i=0; i<size/2; i++){
	vector<int>p1;
	vector<int>p2;
	for(int j=0; j<size/2; j++){
		p1.push_back(1);
		p2.push_back(4);
	}
	cells.push_back(p1);
	n_risks.push_back(p2);
}
cout<<" \n Arxiko plegma me 1 atomo/keli: \n";
for(int i=0; i<grid.size(); i++){	
	for(int j=0; j<grid.size(); j++){
		cout<<grid[i][j]<<" ";
	}
	cout<<endl;
}
cout<<endl;
}
};

int main(){
	   
    int gd = DETECT, gm;  
    int count=0;
    initgraph(&gd, &gm, ""); 
	
 	point a;
 	a.initiallization();
	a.join();
 	delay(500);
	
	for(int i=0; i<30; i++){
 		
    	a.neighbors();
		delay(200);
		
	}	
    
    getch(); 
    closegraph(); 
  
    return 0; 
}


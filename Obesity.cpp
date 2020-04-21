#include <vector>
#include <iostream>
#include <graphics.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>


using namespace std;
const int size=20;

class point{
	public:
		
	vector<vector<int> >grid;
	vector<vector<int> >generate;
	vector<vector<int> >risks;
	vector<int> store;
	vector<vector<int> >limit;
	
	int state;
	int count=0;
	int counter=0;
	int t=1;
	int result=size/10;
	bool metraw=false;
	int s=-1;
	int diafora=0;
	int times=0;
	int total=0;
	int total1, total2;
	int sum=0;
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
	
	for(int i=0; i<store.size(); i+=2){
		
			if(a==store[i] && b==store[i+1]){
				
				generate[a][b]=3;
				n=true;
				return n;
			}
		
	}
}
	
void newstate(int osum,int hsum, int i, int j){

	int stoixeio=grid[i][j];
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
	for(int j=0; j<grid.size(); j++){
		
		if(grid[i][j]==0){
			
				if(limit[i][j]>5){
					s++;
					store.push_back(i);
					store.push_back(j);
					
					fores++;
					
					grid[i][j]=3;				
					cout<<s<<")(i, j)="<<i<<","<<j<<endl;
					if(fores>=result){
						i=grid.size();
						j=grid.size();
					}	
					}
				}
		}
	}
	}

int stable(){
flag=true;	
for(int i=0; i<grid.size(); i++){
	for(int j=0; j<grid.size(); j++){
		if(grid[i][j]!=generate[i][j]){
			flag=false;
			i=grid.size();
			j=grid.size();
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
	
	
if((same==true) && (diafora-s>0)) {

count++;
times=0;	
	
	for(int i=0; i<grid.size(); i++){
		for(int j=0; j<grid.size(); j++){
			if(grid[i][j]==0)
				total1++;
			if(grid[i][j]==1)
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
		for(int i=0; i<grid.size(); i++){
			for(int j=0; j<grid.size(); j++){
				cout<<grid[i][j]<<" ";
			}
			cout<<endl;
		}	
		cout<<endl;
	}
	if(diafora-s>0){
	s=0;	
	cout<<"Ta kelia sta opoia ginetai parembash einai: \n";
	
	changes(0, grid.size()/4);
	changes(grid.size()/4, grid.size()/2);
	changes(grid.size()/2, 3*grid.size()/4);
	changes(3*grid.size()/4, grid.size());

		
	for(int i=0; i<grid.size(); i++){
		for(int j=0; j<grid.size(); j++){
			state=grid[i][j];
			drawLine(j,i);
				
			}
			cout<<endl;
		}
		
	}else{
		cout<<"Telos parembasewn";
	}
	
	if(count==1)	s=-1;

		
}else if(same==true && diafora-s<=0){
		cout<<" ";
	
}else{
		
		for(int i=0; i<grid.size(); i++){
			for(int j=0; j<grid.size(); j++){
				grid[i][j]=generate[i][j];
			}
		}
		
		cout<<"Plegma epomenhs genias: \n";
		for(int i=0; i<grid.size(); i++){
			for(int j=0; j<grid.size(); j++){
				cout<<grid[i][j]<<" ";
				
			}
			cout<<endl;
		}
	
		for(int i=0; i<grid.size(); i++){
		for(int j=0; j<grid.size(); j++){
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
	int size=grid.size();
	bool normal=false;
	int c=0;
	
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			
			ob=0;
			heal=0;
			
			if(i!=0){
				if((grid[i-1][j]==0 || grid[i-1][j]==1)){
					ob++;	
				}else{
					if(grid[i-1][j]!=4)		
					heal++;
						
				}
			}
			
			if(j!=0){
				if((grid[i][j-1]==0 || grid[i][j-1]==1)){
				ob++;	
			}else{
				if(grid[i][j-1]!=4)
				heal++;
				
			}
			}
			
			if(i!=size-1){
				if((grid[i+1][j]==0 || grid[i+1][j]==1)){
				ob++;	
			}else{
				if(grid[i+1][j]!=4)
				heal++;
				
			}	
			}
			
			if(j!=size-1){
					if((grid[i][j+1]==0 || grid[i][j+1]==1)){
				ob++;	
			}else{
				if(grid[i][j+1]!=4)
				heal++;
				
			}		
			}
		
			if(i!=0 && j!=0){
				if((grid[i-1][j-1]==0 || grid[i-1][j-1]==1)){
				ob++;	
			}else{
				if(grid[i-1][j-1]!=4)
				heal++;
				
			}
			}
			
			if(i!=size-1 && j!=0){
				if((grid[i+1][j-1]==0 || grid[i+1][j-1]==1) ){
				ob++;	
			}else{
				if(grid[i+1][j-1]!=4)
				heal++;
				
			}
			}
			
			if(i!=size-1 && j!=size-1){
				if((grid[i+1][j+1]==0 || grid[i+1][j+1]==1) ){
					ob++;	
				}else{
					if(grid[i+1][j+1]!=4)
					heal++;
					
				}	
			}
			
			if(i!=0 && j!=size-1){
				if((grid[i-1][j+1]==0 || grid[i-1][j+1]==1) ){
				ob++;	
			}else{
				if(grid[i-1][j+1]!=4)
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
 	delay(500);
	
	for(int i=0; i<30; i++){
 		
    	a.neighbors();
		delay(200);
		
	}	
    
    getch(); 
    closegraph(); 
  
    return 0; 
}



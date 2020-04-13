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
const int size=20;

class point{
	
	public:
		
	vector<vector<int> >grid;
	vector<vector<int> >generate;
	vector<vector<int> >risks;
	vector<vector<int> >store;
	vector<vector<int> >limit;
	int state;
	
	bool metraw=false;
	int times=0;
	int total=0;
	int sum=0;
	bool draw=true;
	bool flag=false;
	int count=0;
	int counter=0;
	int diafora=0;
	int s=-1;
	int t=1;
void drawLine(int x, int y){
	
	int l=7;
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
    line(x*l+20,y*l+i,x*l+25,y*l+i);
       
}

bool compare(int a, int b){
	bool n=false;
	for(int x=0; x<grid.size(); x++){
		if((a==store[x][0]) && (b==store[x][1])){
			generate[a][b]=3;
			n=true;
			return n;
		}		
	}
}

void newstate(int osum1,int hsum1,int osum2, int hsum2,int i, int j){
	
	int stoixeio=grid[i][j];
	int risk=risks[i][j];
	int hsum=hsum1+hsum2/2;
	int osum=osum1+osum2/2;
	
	if((stoixeio==0) || (stoixeio==1)){
		if((hsum-risk)<3){		
			generate[i][j]=0;
		}else if((hsum-risk)<=4){
			generate[i][j]=1;
		}else if((hsum-risk)<=6){
			generate[i][j]=2;
		}else if((hsum-risk)>6){
			generate[i][j]=3;
		}

				
	}else if((stoixeio==3) || (stoixeio==2)){
		if((osum+risk)>15){
			generate[i][j]=0;
		}else if((osum+risk)>=13){
			generate[i][j]=1;
		}else if((osum+risk)>=11){
			generate[i][j]=2;
		}else if((osum+risk)<11){
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
			
				if(limit[i][j]>9){
					s++;
					store[counter][0]=i;
					store[counter][1]=j;
					
					fores++;
					counter++;
					
					grid[i][j]=3;				
					cout<<s<<")(i, j)="<<i<<","<<j<<endl;
					
					if(fores>=1){
						i=grid.size();
						j=grid.size();
					}	
					}
				}
		}
	}
	}


bool stable(){
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
int total1, total2;
total1=total2=0;

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
	int ob1,ob2,heal1,heal2,sum;
	int size=grid.size();
	bool normal=false;
	int c=0;
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			
			ob1=ob2=0;
			heal1=heal2=0;
		
			if(i!=0){
				if((grid[i-1][j]==0 || grid[i-1][j]==1)){
					ob1++;	
				}else{
					if(grid[i-1][j]!=4)		
					heal1++;
						
				}
			}
			
			
			
			if(j!=0){
				if((grid[i][j-1]==0 || grid[i][j-1]==1)){
				ob1++;	
			}else{
				if(grid[i][j-1]!=4)
				heal1++;
				
			}
			}
			
			
			
			if(i!=size-1){
				if((grid[i+1][j]==0 || grid[i+1][j]==1)){
				ob1++;	
			}else{
				if(grid[i+1][j]!=4)
				heal1++;
				
			}	
			}
			
			
			
			if(j!=size-1){
				if((grid[i][j+1]==0 || grid[i][j+1]==1)){
				ob1++;	
			}else{
				if(grid[i][j+1]!=4)
				heal1++;
				
			}		
			}
			
			
		
			if(i!=0 && j!=0){
				if((grid[i-1][j-1]==0 || grid[i-1][j-1]==1)){
				ob1++;	
			}else{
				if(grid[i-1][j-1]!=4)
				heal1++;
				
			}
			}
			
		
			
			if(i!=size-1 && j!=0){
				if((grid[i+1][j-1]==0 || grid[i+1][j-1]==1) ){
				ob1++;	
			}else{
				if(grid[i+1][j-1]!=4)
				heal1++;
				
			}
			}
			
			
			
			if(i!=size-1 && j!=size-1){
				if((grid[i+1][j+1]==0 || grid[i+1][j+1]==1) ){
					ob1++;	
				}else{
					if(grid[i+1][j+1]!=4)
					heal1++;
					
				}	
			}
			
			
			
			if(i!=0 && j!=size-1){
				if((grid[i-1][j+1]==0 || grid[i-1][j+1]==1) ){
				ob1++;	
			}else{
				if(grid[i-1][j+1]!=4)
				heal1++;
				
			}
		}
				
			if(i>1){
				if((grid[i-2][j]==0 || grid[i-2][j]==1)){
					ob2++;	
				}else{
					if(grid[i-2][j]!=4)		
					heal2++;
						
				}	
			}


		if(j>1){
				if((grid[i][j-2]==0 || grid[i][j-2]==1)){
					
				ob2++;	
			}else{
				if(grid[i][j-2]!=4)
				heal2++;
				
			}
			}

		if(i<size-2){
				if((grid[i+2][j]==0 || grid[i+2][j]==1)){
				
				ob2++;	
			}else{
				if(grid[i+2][j]!=4)
				heal2++;
				
			}
			}

		if(j<size-2){
				if((grid[i][j+2]==0 || grid[i][j+2]==1)){
					
					ob2++;	
				}else{
					if(grid[i][j+2]!=4)
						heal2++;
				
				}		
			}

		if(i>1 && j>1){
				if((grid[i-2][j-2]==0 || grid[i-2][j-2]==1)){
				
				ob2++;	
			}else{
				if(grid[i-2][j-2]!=4)
				heal2++;
				
			}
			}

		if(i<(size-2) && j>1){
				if((grid[i+2][j-2]==0 || grid[i+2][j-2]==1) ){
				
				ob2++;	
			}else{
				if(grid[i+2][j-2]!=4)
				heal2++;
				
			}
			}
		if(i<(size-2) && j<(size-2)){
				if((grid[i+2][j+2]==0 || grid[i+2][j+2]==1) ){
					
					ob2++;	
				}else{
					if(grid[i+2][j+2]!=4)
					heal2++;
					
				}
			}

		if(i>1 && j<(size-2)){
			if((grid[i-2][j+2]==0 || grid[i-2][j+2]==1) ){
				
				ob2++;	
			}else{
				if(grid[i-2][j+2]!=4)
				heal2++;
				
			}
		}
		
		if(i>1 && j!=0){
			if((grid[i-2][j-1]==0 || grid[i-1][j-1]==1) ){
				
				ob2++;	
			}else{
				if(grid[i-2][j-1]!=4)
				heal2++;
				
			}
		}
		
		if(i>1 && i<size-1){
			if((grid[i-2][j+1]==0 || grid[i-2][j+1]==1) ){
				
				ob2++;	
			}else{
				if(grid[i-2][j+1]!=4)
				heal2++;
				
			}
		}
		
		if(i!=0 && j<(size-2)){
			if((grid[i-1][j+2]==0 || grid[i-1][j+2]==1) ){
				
				ob2++;	
			}else{
				if(grid[i-1][j+2]!=4)
				heal2++;
				
			}
		}
		
		if(i<(size-1) && j<(size-2)){
			if((grid[i+1][j+2]==0 || grid[i+1][j+2]==1) ){
				
				ob2++;	
			}else{
				if(grid[i+1][j+2]!=4)
				heal2++;
				
			}
		}
		
		if(i<(size-2) && j<(size-1)){
			if((grid[i+2][j+1]==0 || grid[i+2][j+1]==1) ){
				
				ob2++;	
			}else{
				if(grid[i+2][j+1]!=4)
				heal2++;
				
			}
		}
		
		if(i<(size-2) && j!=0){
			if((grid[i+2][j-1]==0 || grid[i+2][j-1]==1) ){
				
				ob2++;	
			}else{
				if(grid[i+2][j-1]!=4)
				heal2++;
				
			}
		}
		
		if(i<(size-1) && j>1){
			if((grid[i+1][j-2]==0 || grid[i+1][j-2]==1) ){
				
				ob2++;	
			}else{
				if(grid[i+1][j-2]!=4)
				heal2++;
				
			}
		}
		
		if(i!=0 && j>1){
			if((grid[i-1][j-2]==0 || grid[i-1][j-2]==1) ){
				
				ob2++;	
			}else{
				if(grid[i-1][j-2]!=4)
				heal2++;
				
			}
		
		}

		limit[i][j]=ob1+ob2/2;
		
		if(t>1){
			normal=compare(i,j);
			if(normal==false)	
				newstate(ob1,heal1,ob2,heal2,i,j);
		}else{
			newstate(ob1,heal1,ob2,heal2,i,j);
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
for(int i=0; i<50; i++){
	vector<int>str;
	for(int j=0; j<2; j++){
		str.push_back(0);
	}
	store.push_back(str);
}
cout<<"Arxiko plegma: \n";
for(int i=0; i<grid.size(); i++){	
	for(int j=0; j<grid.size(); j++){
		cout<<grid[i][j]<<" ";
	}
	cout<<endl;
}

for(int i=0; i<grid.size(); i++){	
	for(int j=0; j<grid.size(); j++){
		state=grid[i][j];
		drawLine(j,i);
	}
}
}
	
};

int main(){
	
   
    int gd = DETECT, gm;  
    
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





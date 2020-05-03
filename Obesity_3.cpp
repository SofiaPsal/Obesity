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
	vector<int> store;
	vector<vector<int> >limit;
	vector<vector<int> >numNeighb;
	int state;
	int times=0;
	int total=0;
	int sum=0;
	int result=size/20;
	bool flag=false;
	bool f=false;
	int count=0;
	int counter=0;
	int diafora=0;
	int s=-1;
	int t=0;
	
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
	
	for(int i=0; i<store.size(); i+=2){
		
			if(a==store[i] && b==store[i+1]){
				
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

void newstate_simple(int osum,int hsum, int i, int j){
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
			
				if(limit[i][j]>9){
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
	
int exit_code = 10; 
bool same=false;
int total1, total2, total3, total4, total5;
total1=total2=total3=total4=total5=0;

if(times<10)
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
			if(grid[i][j]==2)
				total3++;
			if(grid[i][j]==3)
				total4++;
			if(grid[i][j]==4)
				total5++;	
		}
	}
	if(count==1){
		cout<<"Sta8erh katastash \n \n";
		total=total1+total2;
		
		cout<<"Plegma sta8erhs katastashs: \n";
		for(int i=0; i<grid.size(); i++){
			for(int j=0; j<grid.size(); j++){
				cout<<grid[i][j]<<" ";
			}
			cout<<endl;
		}	
		cout<<endl;
	}

	cout<<"Arithmos paxusarkwn="<<total1<<endl;
	cout<<"Arithmos oriaka paxusarkwn="<<total2<<endl;
	cout<<"# Oriaka ugieis="<<total3<<endl;
	cout<<"# Ygieis="<<total4<<endl;
	cout<<"# Kena kelia="<<total5<<endl;
	cout<<"Sunolikos arithmos="<<total1+total2<<"\n \n";
	if(count>1){
		diafora=total-(total1+total2);
		cout<<"O arithmos twn keliwn stis katastaseis 0, 1 meiw8hke kata "<<diafora<<endl;
		total=total1+total2;
	}
	if(count>2)
		cout<<"Pros8hkh "<<diafora-s<<" ugiwn atomwn"<<endl;
		
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
		delay(1000);
    _Exit(exit_code);
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
	int ob1,ob2,heal1,heal2,sum,c;
	int size=grid.size();
	bool normal=false;

	
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			sum=c=0;
			ob1=ob2=0;
			heal1=heal2=0;
		
			if(i!=0){
				sum++;
				if((grid[i-1][j]==0 || grid[i-1][j]==1)){
					ob1++;	
				}else{
					if(grid[i-1][j]!=4)		
					heal1++;
						
				}
			}
			
			
			
			if(j!=0){
				sum++;
				if((grid[i][j-1]==0 || grid[i][j-1]==1)){
				ob1++;	
			}else{
				if(grid[i][j-1]!=4)
				heal1++;
				
			}
			}
			
			
			
			if(i!=size-1){
				sum++;
				if((grid[i+1][j]==0 || grid[i+1][j]==1)){
				ob1++;	
			}else{
				if(grid[i+1][j]!=4)
				heal1++;
				
			}	
			}
			
			
			
			if(j!=size-1){
				sum++;
				if((grid[i][j+1]==0 || grid[i][j+1]==1)){
				ob1++;	
			}else{
				if(grid[i][j+1]!=4)
				heal1++;
				
			}		
			}
			
			
		
			if(i!=0 && j!=0){
				sum++;
				if((grid[i-1][j-1]==0 || grid[i-1][j-1]==1)){
				ob1++;	
			}else{
				if(grid[i-1][j-1]!=4)
				heal1++;
				
			}
			}
			
		
			
			if(i!=size-1 && j!=0){
				sum++;
				if((grid[i+1][j-1]==0 || grid[i+1][j-1]==1) ){
				ob1++;	
			}else{
				if(grid[i+1][j-1]!=4)
				heal1++;
				
			}
			}
			
			
			
			if(i!=size-1 && j!=size-1){
				sum++;
				if((grid[i+1][j+1]==0 || grid[i+1][j+1]==1) ){
					ob1++;	
				}else{
					if(grid[i+1][j+1]!=4)
					heal1++;
					
				}	
			}
			
			
			
			if(i!=0 && j!=size-1){
				sum++;
				if((grid[i-1][j+1]==0 || grid[i-1][j+1]==1) ){
				ob1++;	
			}else{
				if(grid[i-1][j+1]!=4)
				heal1++;
				
			}
		}
					
			if(i>1){
				c++;
				if((grid[i-2][j]==0 || grid[i-2][j]==1)){
					ob2++;	
				}else{
					if(grid[i-2][j]!=4)		
					heal2++;
						
				}	
			}


		if(j>1){
			c++;
				if((grid[i][j-2]==0 || grid[i][j-2]==1)){
					
				ob2++;	
			}else{
				if(grid[i][j-2]!=4)
				heal2++;
				
			}
			}

		if(i<size-2){
			c++;
				if((grid[i+2][j]==0 || grid[i+2][j]==1)){
				
				ob2++;	
			}else{
				if(grid[i+2][j]!=4)
				heal2++;
				
			}
			}

		if(j<size-2){
			c++;
				if((grid[i][j+2]==0 || grid[i][j+2]==1)){
					
					ob2++;	
				}else{
					if(grid[i][j+2]!=4)
						heal2++;
				
				}		
			}

		if(i>1 && j>1){
			c++;
				if((grid[i-2][j-2]==0 || grid[i-2][j-2]==1)){
				
				ob2++;	
			}else{
				if(grid[i-2][j-2]!=4)
				heal2++;
				
			}
			}

		if(i<(size-2) && j>1){
			c++;
				if((grid[i+2][j-2]==0 || grid[i+2][j-2]==1) ){
				
				ob2++;	
			}else{
				if(grid[i+2][j-2]!=4)
				heal2++;
				
			}
			}
		if(i<(size-2) && j<(size-2)){
			c++;
				if((grid[i+2][j+2]==0 || grid[i+2][j+2]==1) ){
					
					ob2++;	
				}else{
					if(grid[i+2][j+2]!=4)
					heal2++;
					
				}
			}

		if(i>1 && j<(size-2)){
			c++;
			if((grid[i-2][j+2]==0 || grid[i-2][j+2]==1) ){
				
				ob2++;	
			}else{
				if(grid[i-2][j+2]!=4)
				heal2++;
				
			}
		}
		
		if(i>1 && j!=0){
			c++;
			if((grid[i-2][j-1]==0 || grid[i-1][j-1]==1) ){
				
				ob2++;	
			}else{
				if(grid[i-2][j-1]!=4)
				heal2++;
				
			}
		}
		
		if(i>1 && j<size-1){
			c++;
			if((grid[i-2][j+1]==0 || grid[i-2][j+1]==1) ){
				
				ob2++;	
			}else{
				if(grid[i-2][j+1]!=4)
				heal2++;
				
			}
		}
		
		if(i!=0 && j<(size-2)){
			c++;
			if((grid[i-1][j+2]==0 || grid[i-1][j+2]==1) ){
				
				ob2++;	
			}else{
				if(grid[i-1][j+2]!=4)
				heal2++;
				
			}
		}
		
		if(i<(size-1) && j<(size-2)){
			c++;
			if((grid[i+1][j+2]==0 || grid[i+1][j+2]==1) ){
				
				ob2++;	
			}else{
				if(grid[i+1][j+2]!=4)
				heal2++;
				
			}
		}
		
		if(i<(size-2) && j<(size-1)){
			c++;
			if((grid[i+2][j+1]==0 || grid[i+2][j+1]==1) ){
				
				ob2++;	
			}else{
				if(grid[i+2][j+1]!=4)
				heal2++;
				
			}
		}
		
		if(i<(size-2) && j!=0){
			c++;
			if((grid[i+2][j-1]==0 || grid[i+2][j-1]==1) ){
				
				ob2++;	
			}else{
				if(grid[i+2][j-1]!=4)
				heal2++;
				
			}
		}
		
		if(i<(size-1) && j>1){
			c++;
			if((grid[i+1][j-2]==0 || grid[i+1][j-2]==1) ){
				
				ob2++;	
			}else{
				if(grid[i+1][j-2]!=4)
				heal2++;
				
			}
		}
		
		if(i!=0 && j>1){
			c++;
			if((grid[i-1][j-2]==0 || grid[i-1][j-2]==1) ){
				
				ob2++;	
			}else{
				if(grid[i-1][j-2]!=4)
				heal2++;
				
			}
		
		}
		if(t==0){
			numNeighb[i][j]=sum;
			
		}
		if(count==1){
			numNeighb[i][j]=sum+c;
		}
	
		limit[i][j]=ob1+ob2/2;	
		
		if(count==0){
			newstate_simple(ob1,heal1,i,j);
		}else{
			normal=compare(i,j);
			if(normal==false)
				newstate(ob1,heal1,ob2,heal2,i,j);
			else
				generate[i][j]=3;
		}		
					
		}
	}
		if(t==0){
		cout<<"Arithmos geitonwn me aktina geitonias 1 \n";
	for(int i=0; i<grid.size(); i++){	
	for(int j=0; j<grid.size(); j++){
		cout<<numNeighb[i][j]<<" ";
	}
	cout<<endl;
}				
	}
		
		if(count==1 && f==false){
			f=true;
		cout<<"Arithmos geitonwn me aktina geitonias 2 \n";
	for(int i=0; i<grid.size(); i++){	
	for(int j=0; j<grid.size(); j++){
		cout<<numNeighb[i][j]<<" ";
	}
	cout<<endl;
}
}
t++;

Generate();
}	

void initiallization(){
		int t1, t2, t3, t4, t5;
	t1=t2=t3=t4=t5=0;	
	for(int i=0; i<size; i++){
		
		vector<int>temp;
		vector<int>stuff;
		vector<int>r;
		vector<int>n;
		vector<int>l;
	for(int j=0; j<size; j++){
		temp.push_back(rand()%5);
		stuff.push_back(0);
		r.push_back(rand()%8);
		l.push_back(0);
		n.push_back(0);
	}
	grid.push_back(temp);
	generate.push_back(stuff);
	risks.push_back(r);
	limit.push_back(l);
	numNeighb.push_back(n);
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
for(int i=0; i<grid.size(); i++){
		for(int j=0; j<grid.size(); j++){
			if(grid[i][j]==0)
				t1++;
			if(grid[i][j]==1)
				t2++;
			if(grid[i][j]==2)
				t3++;
			if(grid[i][j]==3)
				t4++;
			if(grid[i][j]==4)
				t5++;	
		}
	}
	cout<<"Arithmos paxusarkwn="<<t1<<endl;
	cout<<"Arithmos oriaka paxusarkwn="<<t2<<endl;
	cout<<"# Oriaka ugieis="<<t3<<endl;
	cout<<"# Ygieis="<<t4<<endl;
	cout<<"# Kena kelia="<<t5<<endl;
}
	
};

int main(){
	

    int gd = DETECT, gm;  
    
    initgraph(&gd, &gm, ""); 
	
 	point a;
 	a.initiallization();
 	delay(50);
 
 	
    for(;true;){
 		if(GetAsyncKeyState(VK_ESCAPE))
    {
        cout << "ESCAPE-PRESSED" << endl;
        Sleep(1000);
        return 0;
    }else{
    	a.neighbors();
		delay(50);
		
	}
		
	}	
	
    
    getch(); 
    closegraph(); 
  
    return 0; 
}





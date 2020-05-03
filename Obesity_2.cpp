#include <vector>
#include <iostream>
#include <graphics.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>


using namespace std;
const int size=30;

class point{
	public:
		
	vector<vector<int> >grid;
	vector<vector<int> >generate;
	vector<vector<int> >risks;
	vector<int> store;
	vector<vector<int> >limit;
	vector<vector<int> >cells;
	vector<vector<int> >n_risks;
	
	int state;
	int count=0;
	int counter=0;
	int result=size/10;
	bool metraw=false;
	int s=-4;
	int t=0;
	int diafora=1;
	int times=0;
	int total=0;
	int total1, total2;
	bool flag=false;
	
void drawLine(int x, int y){
int l=7;
int step=40;
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
					cout<<s<<")(i, j)="<<i/2<<","<<j/2<<endl;
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
int exit_code=10;
int total1, total2, total3, total4, total5;
total1=total2=total3=total4=total5=0;

same=stable();

if(times<10)
	same=stable();
else
	same=true;
	
	
if((same==true) && diafora>0) {

count++;
times=0;	

	for(int i=0; i<cells.size(); i++){
		for(int j=0; j<cells.size(); j++){
			if(cells[i][j]==0)
				total1++;
			if(cells[i][j]==1)
				total2++;
			if(cells[i][j]==2)
				total3++;
			if(cells[i][j]==3)
				total4++;
			if(cells[i][j]==4)
				total5++;	
		}
	}

	if(count==1){
		cout<<"Sta8erh katastash \n \n";
		total=total1+total2;
		
		cout<<"Plegma sta8erhs katastashs: \n";
		for(int i=0; i<cells.size(); i++){
			for(int j=0; j<cells.size(); j++){
				cout<<cells[i][j]<<" ";
			}
			cout<<endl;
		}	
		cout<<endl;
	}
			
	cout<<"Arithmos paxusarkwn="<<4*total1<<endl;
	cout<<"Arithmos oriaka paxusarkwn="<<4*total2<<endl;
	cout<<"# Oriaka ugieis="<<4*total3<<endl;
	cout<<"# Ygieis="<<4*total4<<endl;
	cout<<"# Kena kelia="<<4*total5<<endl;
	cout<<"Sunolikos arithmos="<<4*(total1+total2)<<"\n \n";
	if(count>1){
		diafora=total-(total1+total2);
		cout<<"O arithmos twn keliwn stis katastaseis 0, 1 meiw8hke kata "<<4*total-4*(total1+total2)<<endl;
		total=total1+total2;
	}
	

	if(diafora>0){
	s=0;	
	cout<<"Ta kelia sta opoia ginetai parembash einai: \n";
	
	changes(0, grid.size()/4);
	changes(grid.size()/4, grid.size()/2);
	changes(grid.size()/2, 3*grid.size()/4);
	changes(3*grid.size()/4, grid.size());

	join();
	for(int i=0; i<cells.size(); i++){
		for(int j=0; j<cells.size(); j++){
			state=cells[i][j];
			drawLine(j,i);
				
			}
			cout<<endl;
		}
	
	}else{
		cout<<"Telos parembasewn \n";
		delay(1000); 
		_Exit(exit_code);
	}

}else if(same==true && diafora<=0){
	cout<<" ";

}else{
		
		for(int i=0; i<grid.size(); i++){
			for(int j=0; j<grid.size(); j++){
				grid[i][j]=generate[i][j];
			}
		}
		join();
		cout<<"Plegma epomenhs genias: \n";
		for(int i=0; i<cells.size(); i++){
			for(int j=0; j<cells.size(); j++){
				cout<<cells[i][j]<<" ";
				
			}
			cout<<endl;
		}
	
		for(int i=0; i<cells.size(); i++){
		for(int j=0; j<cells.size(); j++){
			state=cells[i][j];
			drawLine(j,i);
			}
		}
		
	times++;
			
	}
	cout<<endl;
		
}

void neighbors(){
	int ob,heal,sum;
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
		
		if(count>=1){
			normal=compare(i,j);
			if(normal==false)	
				newstate(ob,heal,i,j);
			else
				generate[i][j]=3;
		}else{
			newstate(ob,heal,i,j);
		}
		
							
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

	int c0,c1,c2,c3,c4,c,max,max2;
	int number=4;
	c0=0;
	c1=0;
	c2=0;
	c3=0;
	c4=0;
	c=0;
	max=0;
	max2=0;
	
		
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
		
		if(((c1+2*c2+3*c3) % number)/number >=0.5)
			c=1;
		else
			c=0;
		return(max+c);
	}
	
	
}
int join(){
	
	int k,l;
	int t1, t2, t3, t4, t5;
	t1=t2=t3=t4=t5=0;
	t++;
	k=0;
	for(int i=0; i<grid.size()-1; i+=2){	
		l=0;
		for(int j=0; j<grid.size()-1; j+=2){
			
			cells[k][l]=findMajority(i, j);

			n_risks[k][l]=findAverage(i, j);
			
			if(l>=grid.size()-2)		
				l=grid.size();
				
			l++;
		}
		k++;
		if(k>=grid.size()-2){
			k=grid.size();
		}
}
if(t==1){
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
for(int i=0; i<cells.size(); i++){
		for(int j=0; j<cells.size(); j++){
			if(cells[i][j]==0)
				t1++;
			if(cells[i][j]==1)
				t2++;
			if(cells[i][j]==2)
				t3++;
			if(cells[i][j]==3)
				t4++;
			if(cells[i][j]==4)
				t5++;	
		}
	}
	cout<<"Arithmos paxusarkwn="<<4*t1<<endl;
	cout<<"Arithmos oriaka paxusarkwn="<<4*t2<<endl;
	cout<<"# Oriaka ugieis="<<4*t3<<endl;
	cout<<"# Ygieis="<<4*t4<<endl;
	cout<<"# Kena kelia="<<4*t5<<endl;
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
 	delay(50);
 	a.join();
 	
	
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




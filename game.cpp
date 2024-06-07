#include<iostream>
using namespace std;

char space[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row,col;
char token='X';
string name1,name2;
bool tie=false;

void TicTacToeStructure(){
cout<<"   |   |   "<<endl;
cout<<" "<<space[0][0]<<" | "<<space[0][1]<<" | "<<space[0][2]<<" "<<endl;
cout<<"___|___|___"<<endl;
cout<<"   |   |   "<<endl;
cout<<" "<<space[1][0]<<" | "<<space[1][1]<<" | "<<space[1][2]<<" "<<endl;
cout<<"___|___|___"<<endl;
cout<<"   |   |   "<<endl;
cout<<" "<<space[2][0]<<" | "<<space[2][1]<<" | "<<space[2][2]<<" "<<endl;
cout<<"   |   |   "<<endl;
}


void TicTacToeInput(){
int digit;
if(token=='X'){
cout<<name1<<" please enter : ";
cin>>digit;
}
if(token=='0'){
cout<<name2<<" please enter : ";
cin>>digit;
}
if(digit==1){
row=0,col=0;
}
else if(digit==2){
row=0,col=1;
}
else if(digit==3){
row=0,col=2;
}
else if(digit==4){
row=1,col=0;
}
else if(digit==5){
row=1,col=1;
}
else if(digit==6){
row=1,col=2;
}
else if(digit==7){
row=2,col=0;
}
else if(digit==8){
row=2,col=1;
}
else if(digit==9){
row=2,col=2;
}
else{
cout<<"Invalid ..."<<endl;
}
if(token=='X' && (space[row][col]!='X' && space[row][col]!='0')){
space[row][col]='X';
token='0';
}
else if(token=='0' && (space[row][col]!='X' && space[row][col]!='0')){
space[row][col]='0';
token='X';
}
else{
cout<<"There is no empty space"<<endl;
TicTacToeInput();
}
}

bool TicTacToeCheckGameEnd(){
for(int i=0; i<3;i++){
if(((space[i][0]==space[i][1]) && (space[i][1]==space[i][2])) || ((space[0][i]==space[1][i]) && (space[0][i]==space[2][i]))){
return  true;
}
}
if(((space[0][0]==space[1][1])&&(space[0][0]==space[2][2])) || ((space[0][2]==space[1][1])&&(space[0][2]==space[2][0]))){
return true;
}
for(int i=0; i<3; i++){
for(int j=0; j<3; j++){
if(space[i][j]!='X' && space[i][j]!='0'){
return false;
}
}
}
tie=true;
return true;
}


int main(){

cout<<"Enter the name of first player : ";
getline(cin,name1);
cout<<"Enter the name of second player : ";
getline(cin,name2);
cout<<endl<<name1<<" is first player so "<<name1<<" will play first "<<endl;
cout<<endl<<name2<<" is second player so "<<name2<<" will play first "<<endl;

while(!TicTacToeCheckGameEnd()){
TicTacToeStructure();
TicTacToeInput();
TicTacToeCheckGameEnd();
}
if(token=='X' && tie==false){
cout<<name2<<" wins"<<endl;
}
else if(token=='0' && tie==false){
cout<<name1<<" wins"<<endl;
}
else{
cout<<"Draw ...."<<endl;
}
return 0;
}
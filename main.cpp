#include<iostream>
#include<conio.h>
#include<string>
#include <windows.h>
using namespace std;


void gameintro(){  //game intorduction

    cout<<"🍭🍭 Welcome to the Endless maze game! 🍭🍭"<<endl;
    cout<<"There is no any way out of here unless you reach 🏁"<<endl;
    cout<<"                                                              "<<endl;
    cout<<"The game will start now, have fun 🎉"<<endl;
    cout<<"                                                              "<<endl;


}
void displaymaze(string maze[7][8]){   //print the maze for one run
    for(int i=0;i<7;i++){
    for(int j=0;j<8;j++)
    cout<<maze[i][j];
    cout<<endl;
} 
}

char movement(char c){     //get the player movement
    if((c=='w')||(c=='W'))
    return 'a';    

    else if((c=='s')||(c=='S'))
    return 'b';

    else if((c=='a')||(c=='A'))
    return 'c';

    else if((c=='d')||(c=='D'))
    return 'd';

    else 
    return 'e';
} 



void playermov(char c,int &row, int &col){  //apply the player movement
     switch(c){
        case 'a':{
        if((row>0)&&(row<=6))
        row--;
        break;}

        case 'b': {
        if((row>=0)&&(row<6))
        row++;
        break;}

        case 'c':
        if((col>0)&&(col<=7)){
        col--;}
        break;

        case 'd':
        if((col>=0)&&(col<7)){
        col++;}
        break;

        case 'e':
        {cout<<"Invalid movement"<<endl;
        cout<<"Use WASD to move"<<endl;}
        break;
    }
}

    void updatemaze(string maze[7][8], int row, int col,char c)  //move the player and clean the place
    {
        string player=" 🫣";
        maze[row][col]= player;

        switch(c){
        case 'a':{
        row++;
        maze[row][col]=" 🛣️d";
        break;}

        case 'b':{  
        row--;
       maze[row][col]=" 🛣️";
       break;
    }

        case 'c':{
        col++;
        maze[row][col]=" 🛣️";
        break;}

        case 'd':
        {
        col--;
        maze[row][col]=" 🛣️";
        break;}

    }


}
 


void mazegame(){          //maze shape;

string maze[7][8]={
                  {" 🫣"," 🛣️"," 🛣️"," 🛣️"," 🛣️"," 🛣️"," 🛣️"," 🛣️ "},
                  {" 🛣️"," 🛣️"," 🛣️"," 🛣️"," 🛣️"," 🛣️"," 🛣️"," 🛣️ "},
                  {" 🛣️"," 🛣️"," 🛣️"," 🛣️"," 🛣️"," 🛣️"," 🛣️"," 🛣️ "},
                  {" 🛣️"," 🛣️"," 🛣️"," 🛣️"," 🛣️"," 🛣️"," 🛣️"," 🛣️ "},
                  {" 🛣️"," 🛣️"," 🛣️"," 🛣️"," 🛣️"," 🛣️"," 🛣️"," 🛣️ "},
                  {" 🛣️"," 🛣️"," 🛣️"," 🛣️"," 🛣️"," 🛣️"," 🛣️"," 🛣️ "},
                  {" 🛣️"," 🛣️"," 🛣️"," 🛣️"," 🛣️"," 🛣️"," 🛣️"," 🏁 "}                
            
};

    string player;
    player=" 🫣";
    char c;  //the player movement(WASD)
    int row=0;
    int col=0;
    
    gameintro();

    cout<<"        Use W S A D to move      "<<endl;
    displaymaze(maze);

    do{
        c = getch(); 
        c=movement(c);
        playermov(c,row,col);
        updatemaze(maze,row,col,c);   
        cout<<"-------------------------------------------------"<<endl;
        displaymaze(maze);
        }while(player!=maze[6][7]);
    cout<<"                                                 dd"<<endl;
     cout<<"🎊 Congratulations! You finished the maze!🎊"<<endl;;

    }

    

    
int main(){
    SetConsoleOutputCP(CP_UTF8);
    mazegame();


return 0;
}


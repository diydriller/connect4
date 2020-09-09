#include <iostream>
#include <cstring>
#include "board.h"



tic::tic(){
	
	//board setting
	
	row_size=7;
	col_size=7;
	
	board=new char*[row_size];
	for(int i=0;i<row_size;i++){
		board[i]=new char[col_size];
		for(int j=0;j<col_size;j++){
			board[i][j]=' ';	
		}
	}
	
	moves=new move[col_size];
	for(int i=0;i<col_size;i++){
		moves[i].col_idx=-1;
		moves[i].row_idx=-1;
	}
}

tic& tic::operator=(tic &t){
	
	row_size=t.row_size;
	col_size=t.col_size;
	player=t.player;
	for(int i=0;i<row_size;i++){
		for(int j=0;j<col_size;j++){
			board[i][j]=t.board[i][j];
		}
	}
	return *this;
}


void tic::possible_move(){
	
	// find possible move 
	
	for(int i=0;i<col_size;i++){
		for(int j=row_size-1;j>=0;j--){
			if(board[j][i]==' '){
				moves[i].col_idx=i;
				moves[i].row_idx=j;
				break;
			}
		}
	}
}

void tic::display(){
	
	cout<<endl;
   
	for(int i=0;i<col_size;i++){
		cout<<"C"<<i<<"  ";
	}
	cout<<endl;
	
	for(int i=0;i<row_size;i++){
		for(int j=0;j<col_size;j++){
			cout<<board[i][j]<<" | ";
		}
		cout<<endl;
		for(int j=0;j<col_size;j++){
			cout<<"----";
		}
		cout<<endl;
		
	}
	cout<<endl;
}


bool tic::is_win(){
	
	
	
	//horizon check
	for(int i=0;i<row_size;i++){
		for(int j=0;j<col_size;j++){
			if(j+3>=col_size) continue;
			
			char c1=board[i][j];
			char c2=board[i][j+1];
			char c3=board[i][j+2];
			char c4=board[i][j+3];
			
			if(player==c1&&c1==c2&&c2==c3&&c3==c4){
				display();
				
				if(user_first&&player=='X'||!user_first&&player=='O') cout<<"user win"<<endl;
				else if(user_first&&player=='O'||!user_first&&player=='X') cout<<"AI win"<<endl;
				return true;
			}
		}
	}
	
	//vertical check
	for(int i=0;i<row_size;i++){
		for(int j=0;j<col_size;j++){
			
			if(i+3>=row_size) continue;
			
			char r1=board[i][j];
			char r2=board[i+1][j];
			char r3=board[i+2][j];
			char r4=board[i+3][j];
			
			if(player==r1&&r1==r2&&r2==r3&&r3==r4){
				display();
				
				if(user_first&&player=='X'||!user_first&&player=='O') cout<<"user win"<<endl;
				else if(user_first&&player=='O'||!user_first&&player=='X') cout<<"AI win"<<endl;
				return true;
				
			}
		}
	}
	
	//left diagonal check
	for(int i=0;i<row_size;i++){
		for(int j=0;j<col_size;j++){
			
			if(i+3>=row_size) continue;
			if(j+3>=col_size) continue;
			
			char rc1=board[i][j];
			char rc2=board[i+1][j+1];
			char rc3=board[i+2][j+2];
			char rc4=board[i+3][j+3];
			
			if(player==rc1&&rc1==rc2&&rc2==rc3&&rc3==rc4){
				display();
				
				if(user_first&&player=='X'||!user_first&&player=='O') cout<<"user win"<<endl;
				else if(user_first&&player=='O'||!user_first&&player=='X') cout<<"AI win"<<endl;
				return true;
			}
		}
	}
	
	//right diagonal check
	for(int i=0;i<row_size;i++){
		for(int j=0;j<col_size;j++){
			if(i-3<0) continue;
			if(j+3>=col_size) continue;
			
			char rc1=board[i][j];
			char rc2=board[i-1][j+1];
			char rc3=board[i-2][j+2];
			char rc4=board[i-3][j+3];
			
			if(player==rc1&&rc1==rc2&&rc2==rc3&&rc3==rc4){
				display();
				
				if(user_first&&player=='X'||!user_first&&player=='O') cout<<"user win"<<endl;
				else if(user_first&&player=='O'||!user_first&&player=='X') cout<<"AI win"<<endl;
				return true;
			}
			
		}
	}
	
	display();
	return false;

}

bool tic::is_empty(){
	
	for(int i=0;i<row_size;i++){
		for(int j=0;j<col_size;j++){
			if(board[i][j]!=' ') return false;
		}
	}
	return true;
}


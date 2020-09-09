#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
#include "board.h"
#include "tree.h"
#include "minmax.h"
using namespace std;


int main(){
	
	//choice ( user first vs ai first )
	bool user_first;
	while(1){
		string choice;
		cout<<"Do you want to play first? (y/n) : ";
		cin>>choice;
		getchar();
		if(choice.compare("y")==0){
			user_first=true;
			break;
		}
		else if(choice.compare("n")==0){
			user_first=false;
			break;
		}
		else cout<<"please enter correct answer"<<endl;
	}
	
	//game board 
	tic *board=new tic;
	board->user_first=user_first;
	board->display();
	board->player='O';
	int col_size=board->col_size;
	int row_size=board->row_size;

	
	
	//game start
	do{
		tree *head= new tree;
		*(head->tree_board)=*(board);
		head->tree_board->player=board->player;
		
		if(head->tree_board->player=='O') head->tree_board->player='X';
		else head->tree_board->player='O';
	
			
		//first move
		if(head->tree_board->is_empty()){
			
			if(user_first){
				int c;
				cout<<"user's turn"<<endl;
				while(1){
					cout<<"select column: ";
					cin>>c;
					getchar();
					if(c<0||c>=col_size) cout<<"please enter right column"<<endl;
					else break;
				}
				
				head->tree_board->board[row_size-1][c]=head->tree_board->player;
			}
			
			else{
				srand((unsigned int)time(NULL));
				int random_col_idx=rand()%col_size;
				head->tree_board->board[row_size-1][random_col_idx]=head->tree_board->player;
			}
			 
			*board=*(head->tree_board);
		}
		// after move
		else{
			
			if(user_first){
				
				//ai
				if(head->tree_board->player=='O'){
					
					cout<<"AI's turn"<<endl;
					
					head->tree_board->player='X'; 
					
					int value=minmax().min_max(head,0,'O');
					head->tree_board->possible_move();
					
					int r,c;
					for(int i=0;i<head->children_num;i++){
						if(value==head->children[i]->value){
							c=i;
							r=head->tree_board->moves[i].row_idx;
							
							break;
						}
					}
					
					head->tree_board->board[r][c]='O';
					head->tree_board->player='O'; 
					
					
					
					
				}
				
				//user
				else if(head->tree_board->player=='X'){
					cout<<"user's turn"<<endl;
					int r,c;
					while(1){
						cout<<"select column: ";
						cin>>c;
						getchar();
						if(c<0||c>=col_size) cout<<"please enter right column"<<endl;
						else	break;
					}
					
					do{
						head->tree_board->possible_move();
						for(int i=0;i<col_size;i++){
							if(head->tree_board->moves[i].col_idx==c){
								r=head->tree_board->moves[i].row_idx;
							}
						}
					}while(r==-1);
					
					head->tree_board->board[r][c]=head->tree_board->player;
					
						
				}
				
			}
			
			else{
				
				//user
				if(head->tree_board->player=='O'){
					cout<<"user's turn"<<endl;
					int r,c;
					while(1){
						cout<<"select column: ";
						cin>>c;
						getchar();
						if(c<0||c>=col_size) cout<<"please enter right column"<<endl;
						else break;
					}
					
					do{
						head->tree_board->possible_move();
						for(int i=0;i<col_size;i++){
							if(head->tree_board->moves[i].col_idx==c){
								r=head->tree_board->moves[i].row_idx;
							}
						}
					}while(r==-1);
					
					head->tree_board->board[r][c]=head->tree_board->player;
					
				}
				//ai
				else if(head->tree_board->player=='X'){
				    
				    cout<<"AI's turn"<<endl;
				    
				    head->tree_board->player='O'; 
				    
					int value=minmax().min_max(head,0,'X');
					
					head->tree_board->possible_move();
					int r,c;
					for(int i=0;i<head->children_num;i++){
						if(value==head->children[i]->value){
							c=i;
							r=head->tree_board->moves[i].row_idx;
						}
					}
					
					head->tree_board->board[r][c]='X';	
					head->tree_board->player='X';
							
						
				}
				
			}
			
			*(board)=*(head->tree_board);
			board->player=head->tree_board->player;
		
		
		}
	}while(!board->is_win());
}

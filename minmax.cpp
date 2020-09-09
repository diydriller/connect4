#include <climits>
#include <cstdlib>
#include <iostream>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))

#include "minmax.h"

minmax::minmax(){
	
}
char minmax::reverse(char player){
	if(player=='O') return 'X';
	else return 'O';
}

int minmax::min_max(tree*head,int depth,char player){
	
	
	if(head->is_deep(depth)){
		return head->calc_value(player);
	}
	
	//max
	if(head->tree_board->player!=player){
		
		int max_val=INT_MIN;
		for(int i=0;i<head->children_num;i++){
			if(head->children[i]!=NULL){
				
				//value vary according to depth
				int val=min_max(head->children[i],depth+1,player);
				val+=(head->children[i]->calc_value(player)-head->children[i]->calc_value(reverse(player)))*(1000-depth);
				head->children[i]->value=val;
				max_val=max(val,max_val);
				
			}
		}
		head->value=max_val;
	 
		return max_val;
		
	}
	//min
	else{
		int min_val=INT_MAX;
		for(int i=0;i<head->children_num;i++){
			if(head->children[i]!=NULL){
				
				//value vary according to depth 
				int val=min_max(head->children[i],depth+1,player);
				val+=(head->children[i]->calc_value(player)-head->children[i]->calc_value(reverse(player)))*(1000-depth);
				head->children[i]->value=val;
				min_val=min(val,min_val);
			
			}
		}
		head->value=min_val;
	
		return min_val;
		
	}
	
	
	
	
	
}

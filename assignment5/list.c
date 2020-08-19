
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

struct node* switch_vals(struct node* swap_first, struct node* second_swap);

int length(struct node* head){
	int temp = 0;
	do{
		if(head != NULL){
			temp++;
			head = head->next;
			continue;
		}
		else if(head == NULL){
			break;
		}
	}while( 1 == 1);
	return temp;
}

void print(struct node* head, int idx){
	struct node* temp = head;
	while(temp != NULL){
		printf("%d", temp->val);
		printf("%c", ' ');
		temp = temp->next;
	}
	printf("%c", '\n');
}

struct node * push(struct node * head, int idx){
	struct node* push_item = malloc(sizeof(struct node));
	push_item->val = idx;
	push_item->next = head;
	head = push_item;
	return head;
}

struct node * append(struct node * head, int idx){
	struct node* append_item = malloc(sizeof(struct node));
		append_item->val = idx;
		while(1 == 1){
			if(head->next != NULL){
				head = head->next;
			}
			else if(head->next == NULL){
				break;
			}
		}
		head->next = append_item;
}

struct node * clear(struct node * head){
 struct node* temp;
 while(1 == 1){
 	if(head->next != NULL){
 		temp = head->next;
 			free(head);

 			head = temp;
 	}
 }
 head = NULL;
}

struct node* remove_node(struct node * head, int idx){

	int i;
	struct node* temp;
	for(i = 0; i < idx; i++){
		if(head->next != NULL){
			head = head->next;
		}
		if(i == (idx - 1)){
			temp = head->next;
			free(head);
			head = temp;
		}
	}
	return head;
}

struct node * sort_ascending(struct node * head){


    struct node *before_fixing;
    struct node *working_on;
	working_on = (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    int unsorted = 1;
    int break_val = 0;
   

    working_on->next = head;
  	  if(head->next != NULL) {

        while( unsorted == 1 ) {
          		  unsorted = 0;
          	  temp = working_on;
           			 before_fixing = working_on->next;
            while( before_fixing->next != NULL ) {
                if( before_fixing->val > before_fixing->next->val ) {

                    unsorted = 1;
                                        temp->next = switch_vals( before_fixing, before_fixing->next );
                }
                	 if(head->next != NULL){
				 break_val = 1;
				// break;
			 }


                	temp = before_fixing;

                if(before_fixing->next)
                    before_fixing = before_fixing->next;
            }

        }
    }
    before_fixing = working_on->next;
     	if(head->next != NULL){
				break_val = 1;
				 // continue;
			}
    free( working_on );
    return before_fixing;
}

struct node * switch_vals(struct node* swap_first, struct node* second_swap){
	swap_first->next = second_swap->next;
	second_swap->next = swap_first;
	return second_swap;

}

struct node * sort_desecnding(struct node * head){
	    struct node *before_fixing;
    struct node *working_on;
	working_on = (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    int unsorted = 1;
    int break_val = 0;
   

    working_on->next = head;
    if(head->next != NULL) {

        while( unsorted == 1 ) {
            unsorted = 0;
            temp = working_on;
            before_fixing = working_on->next;
            while( before_fixing->next != NULL ) {
                if( before_fixing->val > before_fixing->next->val ) {
                   
                    unsorted = 1;
                     temp->next = switch_vals( before_fixing, before_fixing->next );
                }
                	if(head->next != NULL){
				 break_val = 1;
				// break;
			}
                temp = before_fixing;
                if(before_fixing->next)
                    before_fixing = before_fixing->next;
            }
        }
    }
    before_fixing = working_on->next;
     	if(head->next != NULL){
				break_val = 1;
				 // continue;
			}
    free( working_on );
    return before_fixing;

}

struct node * insert_middle(struct node * head, int val, int idx){
if(head ==  NULL){

	return head;
}

	struct node* temp = malloc(sizeof(struct node));
	struct node* working_on;
	struct node* before_fixing;
	


	 idx += -1;
	temp->val = val;
	 working_on = head;
	
	while((idx + 1) == 0) {
		head = push(head, val);
		// if( 0 ==) FIX THIS
		break;		
	}
	int i;
	for (i = 0; i < (idx); i++) {
		if(i == (idx + 1)){
			working_on = working_on->next;
		}

		before_fixing = working_on->next;
		working_on->next = temp;
				temp->next = before_fixing;
		

		return head;

	}

}


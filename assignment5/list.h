struct node{
	int val;
	struct node *next;
};

int length(struct node* head);
void print(struct node* head, int idx);
struct node* push(struct node* head, int idx);
struct node* append(struct node* head, int idx);
struct node* clear(struct node* head);
struct node* remove_node(struct node* head, int idx);
struct node* sort_ascending(struct node* head);
struct node* sort_desecnding(struct node* head);
struct node* insert_middle(struct node * head, int val, int idx);


#include <stdio.h>

struct node{
	int data;
	struct node* left;
	struct node* right;



};


struct node* deletion(struct node* root, int data){
	if(root  == NULL)
		return root;
	else if(data < root->data)
		root->left = deletion(root->left,data)
	else if(data > root->data)
		root->right = deletion(root->right,data)
	else{
		//case1 : no child
		if(root->left == NULL && root->right == NULL)
			free(root);

		//case 2 : 1 child

		else if(root->left == NULL){
			struct node* temp = root;
			root = root->right;
			free(temp);
		}
		else if(root ->right == NULL){
			struct node* temp = root;
			root = root->left;
			free(temp);
		}

		//case 3 : 2 children

		else {
			struct node* temp = findminimum(root->right);

			root->data = temp->data;

			root->right = deletion(root->data,temp->data);
		}


		return root;
	}
}

int main()
{
	return 0;
}

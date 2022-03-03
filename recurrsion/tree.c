#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct _node_ {
	unsigned char v;
	struct _node_ *child;
	struct _node_ *next;
};

//abc -> a b c
//
//
//

void print(struct _node_ *root)
{
	printf("%c\n", root->v);
	printf("%c", root->child->v);

	struct _node_ *i = root->next;

	while (i != 0) {
		printf("%c", i->v);
		i = i->next;
}
}

void add(struct _node_ *root, unsigned char v)
{
	if (root->child == 0)  { 
		root->child = malloc(sizeof(struct _node_));
		memset(root->child, 0, sizeof(struct _node_));
		root->child->v = v;
		goto exit;
	}


	if(root->next == 0) {
		root->next = malloc(sizeof(struct _node_));
        memset(root->next, 0, sizeof(struct _node_));
		root->next->v = v;
		goto exit;
	}
	struct _node_ *i = root->next;

	while( i->next != 0) i = i->next;
	i->next = malloc(sizeof(struct _node_));
    memset(i->next, 0, sizeof(struct _node_));
	i->next->v = v;

exit: return;
}

#define val(n, m, v) n->m = v

int main()
{
	struct _node_ *root = 0;

	root = malloc(sizeof(struct _node_));
	memset(root, 0, sizeof(struct _node_));

	val(root, v, 'a');
	add(root, 'b');
	add(root, 'c');
	print(root);
	return 1;
}

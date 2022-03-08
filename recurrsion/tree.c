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
//a->b->c
#ifdef _DBG_
#define dbg printf
#else 
#define dbg 
#endif
int get_siblings(struct _node_ *root)
{
	struct _node_ *child = root->child, *sib = root->next;
	int c = 0;

	if(child == 0) return c;

	++c;

	if (sib == 0) return c;

	while (sib != 0) {
		c++;
		sib = sib->next;
	}

	return c;


}
void print_descendants(struct _node_ *root, struct _node_ *base)
{

	int s = get_siblings(root);
	struct _node_ *t = root;

	dbg("no of siblings  %4p %d\n", root, s);

	if (s == 0) {
		dbg("no child return\n");
		return;
	}


	//dbg("node value %4p root, %c\n", root, root->v);

	for( int i = 0; i < s; ++i) {
		//get child and then siblings
		if (i == 0) {
			print_descendants(t->child, base);
			dbg("child node value %4p root, %c\n", t->child, t->child->v);
			dbg("%c", t->child->v);
			dbg("\n%4p %4p %4p\n", root, t, base);
			if ( root == base) dbg("%c\n",root->v );
		}
		else {
			print_descendants(t->next + i - 1, base );
			dbg("sibling node value %4p root, %c\n", t->next + i - 1, (t->next + i -1)->v);
			dbg("%c", (t->next + i -1 )->v);
			if ( root == base) dbg("%c\n",root->v );
		}
	
	}

}

void print(struct _node_ *root)
{
	dbg("%c\n", root->v);
	dbg("%c \n", root->child->v);

	struct _node_ *i = root->next;

	while (i != 0) {
		dbg("%c", i->v);
		i = i->next;
}
}

void add_child(struct _node_ *root, unsigned char v)
{
	if (root->child == 0)  { 
		root->child = malloc(sizeof(struct _node_));
		memset(root->child, 0, sizeof(struct _node_));
		root->child->v = v;
		dbg("child %4p %4c\n", root->child, v);
	}
}



void add_siblings(struct _node_ *root, unsigned char v)
{
#if 0
	if (root->child == 0)  { 
		root->child = malloc(sizeof(struct _node_));
		memset(root->child, 0, sizeof(struct _node_));
		root->child->v = v;
		goto exit;
	}
#endif

	if(root->next == 0) {
		root->next = malloc(sizeof(struct _node_));
        memset(root->next, 0, sizeof(struct _node_));
		root->next->v = v;
		//child next point to sibling
		//root->child->next = root->next;
		dbg("sib %4p %4c\n", root->next, v);
		goto exit;
	}
	struct _node_ *i = root->next;

	while( i->next != 0) i = i->next;
	i->next = malloc(sizeof(struct _node_));
    memset(i->next, 0, sizeof(struct _node_));
	i->next->v = v;
	dbg("sibs %4p %4c\n", i->next, v);
	//i->child->next = i->next;

exit: return;
}

#define val(n, m, v) n->m = v

int main()
{
	struct _node_ *root = 0;

	root = malloc(sizeof(struct _node_));
	memset(root, 0, sizeof(struct _node_));

	val(root, v, 'a');
	dbg("root %4p %c\n", root,root->v);
	add_child(root, 'b');
    add_siblings(root, 'c');
	add_child(root->child, 'x');
	add_child(root->next, 'y');
    //add_child(root, 'c');
    //add_child(root->next, 'b');
	//print(root);
	print_descendants(root, root);
	return 1;
}

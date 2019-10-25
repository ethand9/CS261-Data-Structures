#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/time.h>
#include "avl.h"

struct AVLnode {
	TYPE         val;
	struct AVLnode *left;
	struct AVLnode *right;
	int height;
};
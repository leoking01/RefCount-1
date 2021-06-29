// Copyright 2012 The Authors. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#include <stdio.h>
#include <stdlib.h>
#include "Ptr.h"

int main() {
    int* i = malloc(sizeof(*i));
    *i = 5;
    ptr p = new(i);
    ptr q = cp(p);
    ptr r = cp(q);
    
    printf("p: %d\n", *(int*)Ptr(p));
    printf("getREfcount(p): %d\n",  getREfcount(p)  );

    (*(int*)Ptr(p))++;
    printf("q: %d\n", *(int*)Ptr(q));
    printf("getREfcount(q): %d\n",  getREfcount(q)  );

    (*(int*)Ptr(q))++;
    printf("r: %d\n", *(int*)Ptr(r));
    printf("getREfcount(r): %d\n",  getREfcount(r)  );
    
    del(p);  // del(p);  del(p);
    del(q);
    del(r);
}

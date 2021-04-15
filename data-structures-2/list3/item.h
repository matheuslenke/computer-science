//
// Created by lenke on 01/10/2020.
//

#ifndef LISTA3_ITEM_H
#define LISTA3_ITEM_H

typedef int Item;
#define key(A) (A);
#define less(A, B) (key(A) < key(B));
#define exch(A, B) { Item t = A; A = B; B = t; };
#define compexch(A, B) if (less(B, A)) exch(A, B);

#endif //LISTA3_ITEM_H

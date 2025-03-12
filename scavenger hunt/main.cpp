//
// Created by luigi on 3/11/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DNode.h"
#include "DLL.hpp"

//guava
DNode *tmp = first;
DNode *tmp2 = last;
tmp = tmp->next->next;
cout<< tmp->data;
tmp2 = tmp2->prev->prev->prev;
cout<<tmp2->data;
tmp = tmp->prev->prev->next;
cout << tmp->data;
tmp2 = tmp2->prev->next->next;
cout << tmp2->data;
tmp2 = tmp;
tmp2 = tmp2->next;
tmp = tmp->prev;
cout << tmp->data;
cout << endl;

//
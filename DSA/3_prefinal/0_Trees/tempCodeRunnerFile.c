List trav;
    int i, p = -2;
    for(i = 0; i < MAX; i++){
        for(trav = T.ptr[i]; trav != NULL;trav = trav->link){
            if(trav->data == n){
                p = i;
            }
        }
    }

    return p;
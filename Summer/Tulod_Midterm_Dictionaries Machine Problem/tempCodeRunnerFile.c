
    //  if(newNode != NULL){
    //     for(temp = SL; *temp != NULL && (strcmp((*temp)->stud.idNum, S.idNum) < 0); temp = &(*temp)->next){}
    //     if(*temp != NULL && strcmp((*temp)->stud.idNum, S.idNum) != 0){
    //         newNode->stud = S;
    //         newNode->next = *temp;
    //         *temp = newNode;
    //         retVal = 1;
    //     }else if(*temp != NULL && strcmp((*temp)->stud.idNum, S.idNum) == 0){
    //         printf("Student %s already exists.\n", S.idNum);
    //         free(newNode);
    //     }

    //     for (y = 0; y < YEARLEVELS; y++) {
    //         for (trav = &D[x].programStuds[y]; *trav != NULL; trav = &(*trav)->next) {
    //             if ((((*trav)->stud.info & 128) != 128)) {
    //                 temp = *trav;
    //                 *trav = (*trav)->next;
    //                 studRec insertRec;
    //                 strcpy(insertRec.studID, temp->stud.idNum);
    //                 insertRec.sName = temp->stud.name;
    //                 insertStudSet(inactiveStud[programHash(temp->stud.info)], insertRec);
    //                 free(temp);
    //                 D[x].studCtr--;
    //             }
    //         }
    //     }
    // }
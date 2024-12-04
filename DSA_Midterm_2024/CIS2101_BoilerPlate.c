/***************************************************************************
 * Name:                        //Lastname, Firstname [CIS 2101 group #]   *
 * Date: March 11, 2024                                                    *
 *                                                                         *
 *                                                                         *
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUMPROGRAMS 4
#define YEARLEVELS 4
#define MAXSTUDS 100

//Data Structure Definition
typedef struct{
    char fName[64];
    char mi;
    char lName[32];
}studName;

typedef unsigned char personalInfo;
/*Given 8 bits: 0000 0000
 
 Bits
 8    = Status:            0 - Inactive, 1 - Active
 7    = Nationality:       0 - Filipino, 1 - Foreigner
 6    = Enrollment Status: 0 - Regular, 1 - Irregular
 5    = Gender:            0 - Male, 1 - Female
 3-4  = Year Level:        00 - 1st, 01 - 2nd, 10 - 3rd, 11 - 4th
 1-2  = Program:           00 - CS, 01 - IT, 10 - IS, 11 - MATH
 
 For example:
 1001 1001 would represent an Active Regular 3rd Year Filipino Female IT Student
*/

typedef struct{
    char idNum[9];
    studName name;
    personalInfo info;
}student;

typedef struct{
    student studs[MAXSTUDS];
    int numStuds;
}arrListStud;



typedef struct studNode{
    student stud;
    struct studNode* next;
}studNode, *studLL;

typedef studLL studDict[YEARLEVELS];

typedef struct{
    studDict programStuds;
    int studCtr;               /* refers to the total number of students in the PROGRAM. */
}dcismNode;

typedef dcismNode dcismDict[NUMPROGRAMS];

typedef struct{
    char studID[9];
    studName sName;
}studRec;

typedef struct{
    studRec studs[MAXSTUDS];
    int count;
}sNode, *studSet;               /* array representation of a Set of studRecs */

//Function Prototypes
//-----Problem #1 Prototypes-----
arrListStud populateStudentList(void); // Reads the file containing student records and returns student 
                                       //   records to the calling function
                                       // PARTIAL CODE is provided

void generateStudentFile(void);   //Creates a file of student records
char* getProgram(personalInfo I);  //Returns the string equivalent of the program (BSCS, BSIT, BSIS, BSMATH)
                                   //  of the provided personalInfo. 
                                   
int yearLevelHash(personalInfo I);     //Returns the year level 
                                   
void displayArrListStud(arrListStud A); //Displays ID, Complete name, Program (Course) and year

//------Problem #2 Prototypes
void initDCISMDict(dcismDict D);        //Initializes the given dcismDict to be empty
void convertToDCISMDict(dcismDict D, arrListStud SL); //Inserts the LIST of students in arrListStud
                                                      //  to their proper place in the dcismDict
void displayStudLL(studLL SL) ;        // Displays the contents of a given studLL.
                                       // PARTIAL CODE is provided 

void displayDCISMDict(dcismDict D);     //Displays all the students in the dcismDict by program and year level.
                                        // PARTIAL CODE is provided;  Calls displayStudLL().

//------Problem #3 Prototypes

studSet* removeInactiveStudents(dcismDict D);   //Given dcismDict D, the function deletes student records
                                               //  that have the status "inactive" and place in an array of studSets
                                               // Deleted students will be stored in proper array of studSets
															  //   based on their program (course).
															  // Array of studSets will be returned to the calling function 
															  		    
void displayStudSets(studSet* S);             // Displays the ID, Firstname and Lastname of inactive students 
                                              //    for each program.
void displayPersonalInfo(personalInfo I);
studSet* removeActiveStudents(dcismDict D);
																			                         
/************************************************************************************
 * READ ME FIRST before ANSWERING                                                   *
 *   0)  CHANGE the name of the file to:  CIS2101_YourlastNameXX.c                  *
                                     XX is the first 2 letters of your firstname    *
 *   1)  To facilitate the checking of the machine problem, follow the instructions *
 *       in each PROBLEM #.                                                         *
 *   2)  To accomplish the task for each PROBLEM, a series of function calls may be *
 *       necessary.                                                                 *  
 *   3)  Write you answer BELOW THE COMMENTS. DO NOT DELETE COMMENTS                *
 *   4)  Uncomment or copy the print statement in each PROBLEM#  if the task is     *
 *       completed.                                                                 *
 ***********************************************************************************/                         
int main(void)
{
   /*-------------------------------------------------------------------------
    * 	Problem #1  :: 1) Populate the list by calling populateStudentList  *
    *                   2) Calls displayArrListStud()                        *
    *------------------------------------------------------------------------*/	
   printf("\n\n\nProblem #1:: ");
   printf("\n------------\n");
    arrListStud AL = populateStudentList();
    displayArrListStud(AL);
   
    /*-------------------------------------------------------------------------
    * 	Problem #2  :: 1) Call initDCISMDict()                               *
    *                   2) Call convertToDCISMDict()                          *
    *                   3) Call displayDCISMDict()                            *
	 *-------------------------------------------------------------------------*/	    
   printf("\n\n\nProblem #2:: ");
   printf("\n------------\n");
   dcismDict D;
    initDCISMDict(D);
    convertToDCISMDict(D, AL);
    displayDCISMDict(D);
    /*-------------------------------------------------------------------------
    * 	Problem #3  :: 1) Call removeInactiveStudents() passing dcismDict in *
    *                          problem #2                                     *
    *                   2) Call displayDCISMDict(D);                          *
    *                   3) Call displayStudSets(inactive);                    *
	 *-------------------------------------------------------------------------*/	  
    printf("\n\n\nProblem #3:: ");
    printf("\n------------\n");
    studSet* stud;
    // stud = removeInactiveStudents(D);
    stud = removeActiveStudents(D);
    displayDCISMDict(D);
    displayStudSets(stud);
    return 0;
}                                  
                                       

/*****************************************************************************************
 *  Functions for Problem # 1                                                            *
 *****************************************************************************************/      
 //-----------------------------------------------------------------------------------------
// populateStudentList(). The function will read a file containing student records and   
// returns the student records to the calling function in the form of an arrListStud..
//
// PARTIAL CODE is provide.
//-----------------------------------------------------------------------------------------
arrListStud populateStudentList(void)
{
    FILE* fp;
    student* studs;
    int dataCount;
   
    
    if((fp = fopen("students.bin", "rb"))== NULL){
        puts("Unsuccessful in opening students.txt");
    }else{
        fseek(fp, 0, 2);
        dataCount = (int) ftell(fp) / sizeof(student);
        studs = (student*) malloc (sizeof(student) * dataCount);
        if(studs != NULL){
            fseek(fp, 0, 0);
            fread(studs, sizeof(student), dataCount, fp);
        }
        
		//Put your CODE here
        arrListStud retStuds;
        retStuds.numStuds = 0;
        int x;
        for (x = 0; x < dataCount; x++) {
            retStuds.studs[x] = studs[x];
            retStuds.numStuds++;
        }
         return retStuds;
    }
    
     
}

//-----------------------------------------------------------------------------------------
// getProgram(). Return the string equivalent of the program of the provided personalInfo.
//-----------------------------------------------------------------------------------------
char* getProgram(personalInfo I)
{
  //Write your code here   
    char *retString = (char*)malloc(sizeof(char) * 5);
    switch (I & 3) {
        case 0:
            strcpy(retString, "CS");
            break;
        case 1:
            strcpy(retString, "IT");
            break;
        case 2:
            strcpy(retString, "IS");
            break;
        case 3:
            strcpy(retString, "MATH");
            break;
        default:
            printf("Out of bounds!");
    }
    return retString;
}

//-----------------------------------------------------------------------------------------
// programHash(). Returns the integer equivalent of the bits that represent a student's program.
//-----------------------------------------------------------------------------------------
int yearLevelHash(personalInfo I)
{
     //Write your code here
     return ((I & 12) >> 2) + 1;
}



//---------------------------------------------------------------------------------------------
// displayArrListStud(). Displays the ID, Firstname, Lastname, Program (course) and year level.
//  Calls getProgram() and yearLevelHash() to determine the Program and year level.
//
//  PARTIAL CODE is provided
//-----------------------------------------------------------------------------------------
void displayArrListStud(arrListStud A)
{
   int x;
   
   printf("%-10s", "Id Number");
   printf("%-10s", "fName");
   printf("%-10s", "lName");
   printf("%-10s", "Program");      //Program and Year should be included in the display, though
   printf("%-10s", "Year");         //   it is not included in the sample display.
   printf("Number of students: %-10d", A.numStuds);
//    printf("%-10s", "Gender");
//    printf("%-10s", "personalInfo");
     
   //Write your code here.   
    for (x = 0; x < A.numStuds; x++) {
        printf("\n%-10s", A.studs[x].idNum);
        printf("%-10s", A.studs[x].name.fName);
        printf("%-10s", A.studs[x].name.lName);
        printf("%-10s", getProgram(A.studs[x].info));      //Program and Year should be included in the display, though
        printf("%-10d", yearLevelHash(A.studs[x].info)); 
        // printf("%-10d", A.studs[x].info);
        // printf("%-10s", ((A.studs[x].info & 16) == 16) ? "FEMALE" : "MALE");
        // displayPersonalInfo(A.studs[x].info);
    }
    
    
    
    
}


/*****************************************************************************************
 *  Functions for Problem # 2                                                            *
 *****************************************************************************************/      
//-----------------------------------------------------------------------------------------
// programHash(). Returns the integer equivalent of the bits that represent a student's program.
//-----------------------------------------------------------------------------------------
int programHash(personalInfo I)
{
     //Write your code
     return I & 3;
}


//-----------------------------------------------------------------------------------------
// insertStudLL(). Inserts into the sorted studSet based on the student's ID number.
//  All elements in the studLL should be unique. The function will return 1 if the insert was successful and 0 if not.
//-----------------------------------------------------------------------------------------

int insertStudLL(studLL* SL, student S)
{
     //Write your code
    studLL* trav, temp;
    temp = (studLL)malloc(sizeof(studNode));
    if (temp != NULL) {
        for (trav = SL; *trav != NULL && strcmp((*trav)->stud.idNum, S.idNum) < 0; trav = &(*trav)->next){}
        if (*trav != NULL && strcmp((*trav)->stud.idNum, S.idNum) == 0) {
            temp = NULL;
        } else {
            temp->stud = S; 
            temp->next = *trav;
            *trav = temp;
        }
    }
    return (temp != NULL) ? 1 : 0;
}


//-----------------------------------------------------------------------------------------
// displayStudLL(). The function will display the contents of a given studLL.
//-----------------------------------------------------------------------------------------
void displayStudLL(studLL SL)
{
    if(SL != NULL){
       printf("\nYear %d\n\n", yearLevelHash(SL->stud.info));        //Complete the code and Uncomment
        printf("%-10s", "Id Number");
        printf("%-10s", "fName");
        printf("%-10s", "lName");
        printf("%-10s", "Program");
        printf("%-10s", "Year");
        printf("%-10s", "Gender");
        printf("%-15s", "Enrollment");
        printf("%-15s", "Nationality");
        printf("%-10s\n", "Status");
        
        //Write your code here 
        studLL curr;
        for (curr = SL; curr != NULL; curr = curr->next) {
            printf("%-10s", curr->stud.idNum);
            printf("%-10s", curr->stud.name.fName);
            printf("%-10s", curr->stud.name.lName);
            printf("%-10s", getProgram(curr->stud.info));
            printf("%-10d", yearLevelHash(curr->stud.info));
            printf("%-10s", ((curr->stud.info) & 16) == 16 ? "FEMALE" : "MALE");
            printf("%-15s", ((curr->stud.info) & 32) == 32 ? "IRREGULAR" : "REGULAR");
            printf("%-15s", ((curr->stud.info) & 64) == 64 ? "FOREIGNER" : "FILIPINO");
            printf("%-10s\n", ((curr->stud.info) & 128) == 128 ? "ACTIVE" : "INACTIVE");
        }
    }
}

//-----------------------------------------------------------------------------------------
// initDCISMDict(). The function will initialize the given  dcismDict to be empty
//-----------------------------------------------------------------------------------------
void initDCISMDict(dcismDict D)
{
     //Write your code here
     int x, y;
     for (x = 0; x < NUMPROGRAMS; x++) {
        for (y = 0; y < YEARLEVELS; y++) {
            D[x].programStuds[y] = NULL;
        }
        D[x].studCtr = 0;
     }

}


//-----------------------------------------------------------------------------------------
// convertToDCISMDict(). The function will go through list of students and insert them to their proper place in the dcismDict.
//-----------------------------------------------------------------------------------------
void convertToDCISMDict(dcismDict D, arrListStud SL)
{
     //Write your code here
    int x, yearLevel, program, check;
    for (x = 0; x < SL.numStuds; x++) {
        yearLevel = yearLevelHash(SL.studs[x].info) - 1;
        program = programHash(SL.studs[x].info);
        check = insertStudLL(&D[program].programStuds[yearLevel], SL.studs[x]);
        if (check == 1) {
            D[program].studCtr++;
        } else {
            printf("Student %s already exists\n", SL.studs[x].idNum);
        }
    }
}



//-----------------------------------------------------------------------------------------
// displayDCISMDict(). The function will display all the students in the dcismDict by program and year level.
//-----------------------------------------------------------------------------------------
void displayDCISMDict(dcismDict D)
{
    int i, j;
    for(i = 0; i < NUMPROGRAMS && D[i].programStuds[i] != NULL; i++){
        printf("\n---------------------------------------------------------------------------------------------------------------\n%s %d Students\n", getProgram(D[i].programStuds[i]->stud.info) ,D[i].studCtr);  //Complete code and uncomment
        for(j = 0 ; j < YEARLEVELS && D[i].programStuds[j] != NULL; j++ ){
                displayStudLL(D[i].programStuds[j]);
        } 
    }
}

/*****************************************************************************************
 *  Functions for Problem # 3                                                            *
 *****************************************************************************************/      
//-----------------------------------------------------------------------------------------
// initStudSet(). The functions initialize an empty array of studSets that can accommodate the total number of programs.
//-----------------------------------------------------------------------------------------
studSet* initStudSet(void)
{
     //Write your code here
     studSet* studentSet = (studSet*)malloc(sizeof(studSet) * NUMPROGRAMS);
     int x;
     for (x = 0; x < NUMPROGRAMS; x++) {
        studentSet[x] = (studSet)malloc(sizeof(sNode));
        studentSet[x]->count = 0;
     }
    return studentSet;
}


//-----------------------------------------------------------------------------------------
// insertStudSet(). The function will insert the studRec into the studSet. Student will be inserted at the end of the set.
//-----------------------------------------------------------------------------------------
void insertStudSet(studSet S, studRec sRecord)
{
    //Write your code here
    if (S->count < MAXSTUDS) {
        S->studs[S->count] = sRecord;
        S->count++;
    }   
}


//-----------------------------------------------------------------------------------------
// removeInactiveStudents(). The function will delete all student records that have the status "inactive".
// Deleted records will be stored in an array of studSets, such that each deleted student will be stored
// in its proper index in the array of studSets based on their program. Return the array of studSets to the calling function.
//-----------------------------------------------------------------------------------------
studSet* removeInactiveStudents(dcismDict D)
{
     //Write your code here
    studSet* inactiveStud = initStudSet();
    int x, y;
    studLL *trav, temp;
    for (x = 0; x < NUMPROGRAMS; x++) {
        for (y = 0; y < YEARLEVELS; y++) {
            for (trav = &D[x].programStuds[y]; *trav != NULL;) {
                if (((*trav)->stud.info & 128) != 128) {
                    temp = *trav;
                    *trav = (*trav)->next;
                    studRec insertRec;
                    strcpy(insertRec.studID, temp->stud.idNum);
                    insertRec.sName = temp->stud.name;
                    insertStudSet(inactiveStud[programHash(temp->stud.info)], insertRec);
                    free(temp);
                    D[x].studCtr--;
                } else {
                    trav = &(*trav)->next;
                }
            }
        }
    }
    return inactiveStud;
}



 
 
/**********************************************************************************
 *  Displays the ID, Firstname and Lastname of inactive students for each program. *
 **********************************************************************************/
void displayStudSets(studSet* S)
{
     //Write your code
     int x, y;
     char programDisplay[8];
     printf("\nInactive Students");
     for (x = 0; x < NUMPROGRAMS; x++) {
        switch (x) {
            case 0:
                strcpy(programDisplay, "BSCS");
                break;
            case 1:
                strcpy(programDisplay, "BSIT");
                break;
            case 2:
                strcpy(programDisplay, "BSIS");
                break;
            case 3:
                strcpy(programDisplay, "BSMATH");
                break;
        }
        printf("\n%s %d students\n", programDisplay, S[x]->count);
        printf("%-10s %-10s %-10s\n", "Id Number", "fName", "lName");
        for (y = 0; y < S[x]->count; y++) {
            printf("%-10s", S[x]->studs[y].studID);
            printf("%-10s", S[x]->studs[y].sName.fName);
            printf("%-10s\n", S[x]->studs[y].sName.lName);
        }
     }

    
}

void displayPersonalInfo(personalInfo I) {
    personalInfo numBits = sizeof(char) * 8;
    personalInfo mask = 1 << (numBits - 1);
    for (; mask != 0; mask >>= 1) {
        printf("%d", (I & mask) ? 1 : 0);
    }
}

studSet* removeActiveStudents(dcismDict D) {
    studSet* activeStuds = initStudSet();
    studLL* trav, temp;
    int x, y;
    personalInfo mask = 1 << 7;
    for (x = 0; x < NUMPROGRAMS; x++) {
        for (y = 0; y < YEARLEVELS; y++) {
            for (trav = &D[x].programStuds[y]; *trav != NULL;) {
                if (((*trav)->stud.info & 128) == 128) {
                    temp = *trav;
                    *trav = (*trav)->next;
                    studRec insertActive;
                    strcpy(insertActive.studID, temp->stud.idNum);
                    insertActive.sName = temp->stud.name;
                    insertStudSet(activeStuds[programHash(temp->stud.info)], insertActive);
                    free(temp);
                    D[x].studCtr--;
                } else {
                    trav = &(*trav)->next;
                }
            }
        }
    }
    return activeStuds;
}


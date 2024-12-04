/*
Always remember to open then close:
Make a file pointer
    File *fp = fopen("[file name/path]", "[access mode]");
or
    File *fp;
    fp = fopen("[file name/path]", "[access mode]");

Access modes:
r - read: Just reads the file
w - write: Will overwrite the file
a - appends: Adds on at the end of the file

    + - having a plus gives it permissions of the other
    b - makes it binary

Close file if you want to change modes
    fclose([File*]);

Binary files
Important to use these functions
fwrite([structure*], [bytes], [multiple of bytes],[File*]);
fread([structure*], [bytes], [multiple of bytes],[File*]);

Difference being in fwrite we put IN the file 
While fread is FROM the file and in the structure

fread returns a integer every time it takes from the file, 0 if no more data
So taking advantage of that
    fread(&struct, sizeof(struct_arr[0]), 1, fp);
        Breaking this down it means that you can count how many structs are in it
        So 
        Struct node struct, struct_arr[5];
        while(fread(&struct, sizeof(struct_arr[0]), 1, fp)){
            struct_arr[count++] = struct;
        }
        

If you want to set the file pointer(basically the thing that determines where you are in the file) 
to a specific location you can use:
    rewind([File*]);
    Puts the pointer at the start of the file.
or
    fseeek([File*], [offset by bytes], [position]);
    positions are:
        SEEK_SET - At the start. Best to use, if you want to skip through then 
        sizeof(structure) * [int]
        SEEK_CUR - Where the pointer is currently at
        SEEK_END - At the end, usually used to append
*/
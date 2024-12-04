#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int songID;
    char songName[50];
    char genre[26];
    char artist[26];
    int duration;
}Song;

typedef struct {
    Song songArray[50];
    int songCount;
}Playlist;

typedef struct node {
    Song songQ;
    struct node* link;
}SongNode, *SongList;

typedef struct {
    SongList front, rear;
}SongQueue;

typedef enum {TRUE, FALSE} Boolean;

void initPlaylist(Playlist* P);
void insertSong(Playlist* P, Song insSong);
void displayPlaylist(Playlist P);
void populatePlaylist(Playlist* P, Song songs[], int count);
void initSongQueue(SongQueue* Q);
void queueSong(SongQueue* Q, Song pickedSong);
void displayQueue(SongQueue Q);
void playQueue(SongQueue Q);


int main () {
    Playlist likedSongs;
    Song song1 = {1, "3 Boys", "R&B", "Omar Apollo", 129};
    Song songArr[] = {{2, "Die Trying", "Rap", "Key Glock", 167}, {3, "Rich Baby Daddy", "Pop", "Drake", 456}};
    SongQueue queue;
    initSongQueue(&queue);
    queueSong(&queue, song1);
    queueSong(&queue, songArr[0]);
    displayQueue(queue);
    playQueue(queue);
    // initPlaylist(&likedSongs);
    // insertSong(&likedSongs, song1);
    // populatePlaylist(&likedSongs, songArr, 2);
    // displayPlaylist(likedSongs);
}

void initPlaylist(Playlist* P) {
    P->songCount = 0;
}

void insertSong(Playlist* P, Song insSong) {
    P->songArray[P->songCount] = insSong;
    P->songCount++;
}

void displayPlaylist(Playlist P) {
    int x;
    printf("%-10s", "songID");
    printf("%-20s", "songName");
    printf("%-10s", "genre");
    printf("%-20s", "artist");
    printf("%-10s\n", "duration");
    for (x = 0; x < P.songCount; x++) {
        printf("%-10d", P.songArray[x].songID);
        printf("%-20s", P.songArray[x].songName);
        printf("%-10s", P.songArray[x].genre);
        printf("%-20s", P.songArray[x].artist);
        printf("%d:%02d\n", P.songArray[x].duration / 60, P.songArray[x].duration % 60);
    }
}

void initSongQueue(SongQueue* Q) {
    Q->front = NULL;
    Q->rear = NULL;
}

void populatePlaylist(Playlist* P, Song songs[], int count) {
    int x;
    for (x = 0; x < count; x++) {
        P->songArray[P->songCount] = songs[x];
        P->songCount++;
    }
}

void queueSong(SongQueue* Q, Song pickedSong) {
    SongList temp = (SongList)malloc(sizeof(SongNode));
    if (temp != NULL) {
        temp->songQ = pickedSong;
        temp->link = NULL;
        Q->front == NULL ? (Q->front = temp) : (Q->rear->link = temp);
        Q->rear = temp;
    }
}

void displayQueue(SongQueue Q) {
    SongList trav;
    for (trav = Q.front; trav != NULL; trav = trav->link) {
        printf("Song ID: %d\n", trav->songQ.songID);
    }
}

void playQueue(SongQueue Q) {
    printf("\nNOW PLAYING: %s", Q.front->songQ.songName);
}
/* Welcome to Jio's Playlist Creator project
   (I thought of this while driving lol)  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 10

typedef char String[100];
typedef struct{
    String name;
    String artist;
} Song;

typedef struct{
    String name;
    Song playlist[MAX];
    int count;
} Playlist;

typedef struct{
    Playlist listPlaylist[MAX];
    int count;
} Collection;

Playlist createPlaylist(){
    Playlist newPlaylist;
    newPlaylist.count=0;

    printf("Enter name of playlist: ");
    scanf("%s", newPlaylist.name);
    getchar();
    
    return newPlaylist;
}

Song createSong(){
    Song newSong;
    getchar();
    printf("Enter song name: ");
    gets(newSong.name);
    printf("Enter artist: ");
    gets(newSong.artist);

    return newSong;
}

void addSong(Playlist* PL, Song newSong){
    if (PL->count<MAX){
        PL->playlist[PL->count++]=newSong;
        system("clear");
        printf("%s by %s has been successfully added to %s!\n", newSong.name, newSong.artist, PL->name);
    }
}

void dispPlaylist(Playlist PL){
    system("clear");
    printf("%s\n", PL.name);
    for (int i=0;i<PL.count;++i){
        printf("%d. %s - %s\n", i+1, PL.playlist[i].name, PL.playlist[i].artist);
    }
}

void dispAllPlaylists(Collection collection){
    printf("Available Playlists: \n");
    for (int i=0;i<collection.count;++i){
        printf("%d.) %s [%d/%d]\n", i+1, collection.listPlaylist[i].name, collection.listPlaylist[i].count, MAX);
    }
}

void editSong(Song* S){
    printf("\nYou have selected: %s - %s.\n", S->name, S->artist);
    printf("Enter a new name for this song: ");
    getchar();
    gets(S->name);
    printf("Enter the new artist: ");
    gets(S->artist);

    printf("\nSong edited successfully!\n");
}

void delSong(Playlist* PL, int indexToDel){
    if (PL->count>0){
        for (int i=indexToDel;i<PL->count;++i){
            PL->playlist[i]=PL->playlist[i+1];
        }
        --(PL->count);
        printf("Song deleted successfully!\n");
    }
}

void dispMenu(){
    printf("Welcome to the Playlist Maker!\n");
    printf("1.) Create a new Playlist\n"); // Done
    printf("2.) Add song\n"); // Done
    printf("3.) Modify song\n"); // Done
    printf("4.) Delete song\n");
    printf("5.) Display a playlist\n\n"); // Done
    printf("6.) Exit\n"); // Done
}

void main(){
    Collection collection;
    collection.count=0;
    
    int choice;
    do{
        dispMenu();
        printf("Enter choice: ");
        scanf("%d", &choice);
    
        int indexPlaylist, indexSong;
        
        switch (choice){
            case 1:
                collection.listPlaylist[collection.count++]=createPlaylist();
                system("clear");
                printf("%s has been created successfully!\n", collection.listPlaylist[collection.count-1].name);
                break;
            case 2:
                system("clear");
                dispAllPlaylists(collection);
                printf("\nWhich playlist would you like to add a song to?: ");
                scanf("%d", &indexPlaylist);
                --indexPlaylist;

                addSong(&(collection.listPlaylist[indexPlaylist]), createSong());
                break;
            case 3:
                system("clear");
                dispAllPlaylists(collection);
                printf("\nChoose a Playlist: ");
                scanf("%d", &indexPlaylist);
                --indexPlaylist;

                dispPlaylist(collection.listPlaylist[indexPlaylist]);
                printf("\nWhich song would you like to edit?: ");
                scanf("%d", &indexSong);
                --indexSong;
                
                editSong(&(collection.listPlaylist[indexPlaylist].playlist[indexSong]));
                break;
            case 4:
                system("clear");
                dispAllPlaylists(collection);
                printf("\nChoose a Playlist: ");
                scanf("%d", &indexPlaylist);
                --indexPlaylist;

                dispPlaylist(collection.listPlaylist[indexPlaylist]);
                printf("\nWhich song would you like to delete?: ");
                scanf("%d", &indexSong);
                --indexSong;

                delSong(&(collection.listPlaylist[indexPlaylist]), indexSong);
                break;
            case 5:
                system("clear");
                dispAllPlaylists(collection);
                printf("\nWhich playlist would you like to see?: ");
                scanf("%d", &indexPlaylist);
                --indexPlaylist;

                dispPlaylist(collection.listPlaylist[indexPlaylist]);
                break;
            case 6:
                printf("\nProgram exiting...\n");
                break;
        }
        printf("\n");
    } while (choice != 6);
}
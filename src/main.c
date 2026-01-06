#include <stdio.h>
#include <string.h>
#include "downloader.h"
#include "utils.h"

#define MAX_INPUT 512
#define MAX_PATH_LEN 260

static void show_menu(void) {
    printf("\n==== YOUTUBE DOWNLOADER ====\n");
    printf("1. Download Video (MP4)\n");
    printf("2. Download Audio (MP3)\n");
    printf("0. Exit\n");
}

int main(void) {
    char url[MAX_INPUT];
    char filename[MAX_INPUT];
    char downloads[MAX_PATH_LEN];
    int choice;

    if (!get_downloads_folder(downloads, sizeof(downloads))) {
        printf("Failed to locate Downloads folder.\n");
        return 1;
    }

    while (1) {
        show_menu();
        printf("\nChoice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        if (choice == 0) break;

        printf("YouTube URL: ");
        fgets(url, sizeof(url), stdin);
        url[strcspn(url, "\n")] = 0;

        printf("Filename (no extension): ");
        fgets(filename, sizeof(filename), stdin);
        filename[strcspn(filename, "\n")] = 0;

        int result = -1;

        if (choice == 1) {
            result = download_youtube_video(url, filename, downloads);
        } else if (choice == 2) {
            result = download_youtube_audio(url, filename, downloads);
        } else {
            printf("Invalid option.\n");
            continue;
        }

        if (result == 0)
            printf("\n✅ Download completed successfully.\n");
        else
            printf("\n❌ Download failed.\n");
    }

    return 0;
}

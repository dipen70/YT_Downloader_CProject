#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int get_downloads_folder(char *path, size_t size) {
    const char *userprofile = getenv("USERPROFILE");
    if (!userprofile) return 0;

    snprintf(path, size, "%s\\Downloads", userprofile);
    return 1;
}

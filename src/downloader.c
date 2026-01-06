#include <windows.h>
#include <stdio.h>
#include <string.h>
#include "downloader.h"

#define CMD_SIZE 4096

#define YTDLP_PATH "yt-dlp"

static int run_command(const char *command) {
    STARTUPINFOA si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    ZeroMemory(&pi, sizeof(pi));

    si.cb = sizeof(si);

    char cmdline[CMD_SIZE];
    
    // We use cmd.exe /S /C to execute the command. 
    // The extra quotes around %s are crucial for handling paths with spaces.
    snprintf(cmdline, CMD_SIZE, "cmd.exe /S /C \"%s\"", command);

    printf("\n[DEBUG] Executing: %s\n", cmdline);

    if (!CreateProcessA(
            NULL,
            cmdline,
            NULL,
            NULL,
            FALSE,
            0,
            NULL,
            NULL,
            &si,
            &pi)) {
        printf("Failed to start process. Error Code: %lu\n", GetLastError());
        return -1;
    }

    WaitForSingleObject(pi.hProcess, INFINITE);

    DWORD exit_code = 1;
    GetExitCodeProcess(pi.hProcess, &exit_code);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return (exit_code == 0) ? 0 : -1;
}

static void build_output(char *out, size_t size, const char *dir, const char *name) {
    snprintf(out, size, "%s\\%s.%%(ext)s", dir, name);
}

int download_youtube_video(const char *url, const char *filename, const char *out_dir) {
    char cmd[CMD_SIZE];
    char output[MAX_PATH];

    build_output(output, sizeof(output), out_dir, filename);

    // Using "yt-dlp" directly (quoted to be safe against spaces, though mostly safe here)
    snprintf(cmd, CMD_SIZE,
        "\"%s\" -f \"bv*+ba/best\" --merge-output-format mp4 "
        "-o \"%s\" \"%s\"",
        YTDLP_PATH, output, url
    );

    return run_command(cmd);
}

int download_youtube_audio(const char *url, const char *filename, const char *out_dir) {
    char cmd[CMD_SIZE];
    char output[MAX_PATH];

    build_output(output, sizeof(output), out_dir, filename);

    snprintf(cmd, CMD_SIZE,
        "\"%s\" -x --audio-format mp3 "
        "-o \"%s\" \"%s\"",
        YTDLP_PATH, output, url
    );

    return run_command(cmd);
}
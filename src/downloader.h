#ifndef DOWNLOADER_H
#define DOWNLOADER_H

int download_youtube_video(const char *url, const char *filename, const char *out_dir);
int download_youtube_audio(const char *url, const char *filename, const char *out_dir);

#endif

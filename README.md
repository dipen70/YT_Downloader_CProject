# YouTube Downloader

A simple, user-friendly command-line application to download YouTube videos and audio files written in C for Windows.

## Features

- 📹 Download YouTube videos in MP4 format (best quality)
- 🎵 Extract audio from YouTube videos as MP3
- 💾 Automatic saving to Windows Downloads folder
- 🖥️ Simple menu-driven interface
- ⚡ Fast and lightweight

## Prerequisites

Before you can use this application, you need to install the following:

### 1. C Compiler (MinGW-w64)

**Download and Installation:**

1. Visit [MinGW-w64 Downloads](https://www.mingw-w64.org/downloads/)
2. Download the installer (recommended: MSYS2)
3. Install MSYS2 to `C:\msys64`
4. Open MSYS2 terminal and run:
   ```bash
   pacman -S mingw-w64-x86_64-gcc
   ```
5. Add MinGW to your PATH:
   - Open "Edit System Environment Variables"
   - Click "Environment Variables"
   - Under "System Variables", find "Path"
   - Add: `C:\msys64\mingw64\bin`

**Verify Installation:**
```bash
gcc --version
```

### 2. Python (Required for yt-dlp)

**Download and Installation:**

1. Visit [Python Official Website](https://www.python.org/downloads/)
2. Download Python 3.8 or later
3. Run the installer
4. **Important:** Check "Add Python to PATH" during installation
5. Complete the installation

**Verify Installation:**
```bash
python --version
```

### 3. yt-dlp (YouTube Downloader Tool)

**Installation via pip:**

Open Command Prompt or PowerShell and run:
```bash
pip install yt-dlp
```

**Alternative Installation (Standalone):**

1. Download `yt-dlp.exe` from [yt-dlp releases](https://github.com/yt-dlp/yt-dlp/releases)
2. Place it in a folder included in your PATH (or add its location to PATH)

**Verify Installation:**
```bash
yt-dlp --version
```

### 4. FFmpeg (Required for Audio Conversion)

**Installation:**

1. Visit [FFmpeg Official Website](https://ffmpeg.org/download.html)
2. Download Windows build (recommended: from [gyan.dev](https://www.gyan.dev/ffmpeg/builds/))
3. Extract the downloaded archive (e.g., `ffmpeg-release-essentials.zip`)
4. Copy the extracted folder to `C:\ffmpeg`
5. Add to PATH:
   - Open "Edit System Environment Variables"
   - Click "Environment Variables"
   - Under "System Variables", find "Path"
   - Add: `C:\ffmpeg\bin`

**Verify Installation:**
```bash
ffmpeg -version
```

## Installation

### Option 1: Download Pre-compiled Executable

1. Download `youtube_downloader.exe` from the releases page
2. Place it in any folder
3. Double-click to run

### Option 2: Compile from Source

1. **Download the Source Code:**
   ```bash
   # If using Git
   git clone <repository-url>
   cd youtube-downloader
   
   # Or download and extract the ZIP file
   ```

2. **Compile the Program:**
   
   Open Command Prompt in the project directory and run:
   ```bash
   gcc -o youtube_downloader.exe main.c downloader.c utils.c
   ```

3. **Verify Compilation:**
   
   You should see `youtube_downloader.exe` in your directory.

## Usage

### Running the Application

1. Open Command Prompt or PowerShell
2. Navigate to the folder containing `youtube_downloader.exe`
3. Run:
   ```bash
   youtube_downloader.exe
   ```

### Step-by-Step Guide

1. **Choose Option:**
   ```
   ==== YOUTUBE DOWNLOADER ====
   1. Download Video (MP4)
   2. Download Audio (MP3)
   0. Exit
   
   Choice: 
   ```
   - Enter `1` for video download
   - Enter `2` for audio download
   - Enter `0` to exit

2. **Enter YouTube URL:**
   ```
   YouTube URL: https://www.youtube.com/watch?v=dQw4w9WgXcQ
   ```
   - Paste the complete YouTube video URL
   - Press Enter

3. **Enter Filename:**
   ```
   Filename (no extension): my_video
   ```
   - Enter desired filename (without extension)
   - Extension will be added automatically (.mp4 or .mp3)
   - Press Enter

4. **Wait for Download:**
   - The application will display progress
   - Download completes automatically

5. **Check Result:**
   ```
   ✅ Download completed successfully.
   ```
   - Files are saved to your Downloads folder
   - Path: `C:\Users\<YourUsername>\Downloads\`

### Example Session

```
==== YOUTUBE DOWNLOADER ====
1. Download Video (MP4)
2. Download Audio (MP3)
0. Exit

Choice: 1
YouTube URL: https://www.youtube.com/watch?v=dQw4w9WgXcQ
Filename (no extension): rickroll

[DEBUG] Executing: cmd.exe /S /C "yt-dlp" -f "bv*+ba/best" --merge-output-format mp4 -o "C:\Users\John\Downloads\rickroll.%(ext)s" "https://www.youtube.com/watch?v=dQw4w9WgXcQ"

[download] Downloading video...
[download] 100% of 3.5MB

✅ Download completed successfully.
```

## File Structure

```
youtube-downloader/
├── main.c              # Main program entry point
├── downloader.c        # Download functionality
├── downloader.h        # Download function headers
├── utils.c             # Utility functions
├── utils.h             # Utility function headers
├── README.md           # This file
└── youtube_downloader.exe  # Compiled executable (after compilation)
```

## Troubleshooting

### Common Issues

#### 1. "yt-dlp is not recognized as an internal or external command"

**Solution:**
- Verify yt-dlp is installed: `pip install yt-dlp`
- Check if Python's Scripts folder is in PATH
- Restart your terminal after installation

#### 2. "Download failed" Error

**Possible Causes:**
- Invalid YouTube URL
- Video is private or region-restricted
- Network connection issues
- yt-dlp needs updating

**Solutions:**
- Verify the URL works in a browser
- Update yt-dlp: `pip install --upgrade yt-dlp`
- Check your internet connection
- Try a different video

#### 3. Audio Download Fails but Video Works

**Cause:** FFmpeg is not installed or not in PATH

**Solution:**
- Install FFmpeg (see Prerequisites)
- Verify with: `ffmpeg -version`
- Restart your terminal

#### 4. Compilation Errors

**Error: `gcc is not recognized`**
- Solution: Install MinGW and add to PATH

**Error: Cannot find header files**
- Solution: Ensure all `.c` and `.h` files are in the same directory

#### 5. Files Not Saving to Downloads Folder

**Cause:** USERPROFILE environment variable not set

**Solution:**
- Check: `echo %USERPROFILE%` in Command Prompt
- Should show: `C:\Users\<YourUsername>`
- Manually set if missing (Control Panel → System → Advanced)

### Debug Mode

The application shows debug output by default. You'll see:
```
[DEBUG] Executing: cmd.exe /S /C "yt-dlp" ...
```

This helps diagnose issues. If you encounter problems, check this output for error messages.

## Supported Formats

### Video Download
- **Output Format:** MP4
- **Quality:** Best available (combines best video + best audio)
- **Fallback:** Single best format if merging not possible

### Audio Download
- **Output Format:** MP3
- **Quality:** Best available audio
- **Conversion:** Automatic via FFmpeg

## Configuration

### Changing Download Location

Currently, files are saved to Windows Downloads folder automatically. To change this:

**Method 1: Modify Source Code**

Edit `main.c` and replace the `get_downloads_folder()` call:
```c
// Instead of:
if (!get_downloads_folder(downloads, sizeof(downloads))) {
    // ...
}

// Use:
strcpy(downloads, "C:\\MyCustomFolder");
```

**Method 2: Add Command-Line Argument** (requires code modification)

You can extend the program to accept a custom output directory as a command-line argument.

### Changing Video Quality

Edit `downloader.c` and modify the format string in `download_youtube_video()`:

```c
// For 720p maximum:
"-f \"bv*[height<=720]+ba/best[height<=720]\" --merge-output-format mp4 "

// For 1080p maximum:
"-f \"bv*[height<=1080]+ba/best[height<=1080]\" --merge-output-format mp4 "
```

### Changing Audio Bitrate

Edit `downloader.c` and modify the audio download command:

```c
// For high quality (320kbps):
"\"%s\" -x --audio-format mp3 --audio-quality 0 -o \"%s\" \"%s\""

// For smaller files (128kbps):
"\"%s\" -x --audio-format mp3 --audio-quality 5 -o \"%s\" \"%s\""
```

## Limitations

- **Windows Only:** Currently designed for Windows operating system
- **No Progress Bar:** Shows yt-dlp's native progress output
- **No Resume:** Failed downloads must be restarted
- **No Playlist Support:** Downloads single videos only
- **Basic Error Handling:** Limited error messages for troubleshooting

## Future Enhancements

- [ ] Cross-platform support (Linux, macOS)
- [ ] Playlist download support
- [ ] Custom quality selection
- [ ] Resume interrupted downloads
- [ ] GUI version
- [ ] Batch download from file
- [ ] Download history tracking
- [ ] Multiple concurrent downloads

## FAQ

**Q: Is this legal?**  
A: Downloading copyrighted content without permission may violate YouTube's Terms of Service and copyright laws. Use this tool only for content you own or have permission to download.

**Q: Can I download age-restricted videos?**  
A: yt-dlp supports age-restricted videos, but you may need to provide authentication in some cases.

**Q: Why does it take so long to start downloading?**  
A: yt-dlp needs to analyze the video and select the best format. This typically takes a few seconds.

**Q: Can I download 4K videos?**  
A: Yes, if the video is available in 4K, it will be downloaded in the highest quality.

**Q: Does this work with other websites?**  
A: The application is designed for YouTube, but yt-dlp supports many other sites. The code could be modified to support them.

## Contributing

Contributions are welcome! To contribute:

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Test thoroughly
5. Submit a pull request

## License

This project is provided as-is for educational purposes. Please respect YouTube's Terms of Service and copyright laws.

## Credits

- **yt-dlp:** [https://github.com/yt-dlp/yt-dlp](https://github.com/yt-dlp/yt-dlp)
- **FFmpeg:** [https://ffmpeg.org/](https://ffmpeg.org/)

## Support

If you encounter issues:

1. Check the Troubleshooting section
2. Verify all prerequisites are installed
3. Update yt-dlp: `pip install --upgrade yt-dlp`
4. Check yt-dlp's GitHub for known issues

## Contact

For questions or support, please open an issue on the project repository.

---

**Note:** This tool is for educational purposes. Always respect copyright laws and YouTube's Terms of Service when downloading content.
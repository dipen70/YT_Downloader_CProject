import os

base_dir = os.getcwd()

# Define folders
folders = [
    "src",
    "build"
]

# Define files
files = [
    "src/main.c",
    "src/menu.c",
    "src/menu.h",
    "src/downloader.c",
    "src/downloader.h",
    "src/utils.c",
    "src/utils.h",
    "compile_run.bat"
]

# Create folders
for folder in folders:
    os.makedirs(os.path.join(base_dir, folder), exist_ok=True)

# Create files
for file in files:
    file_path = os.path.join(base_dir, file)
    open(file_path, "a").close()

print("Project structure created successfully.")

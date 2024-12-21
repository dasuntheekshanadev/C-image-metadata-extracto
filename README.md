# Image Metadata Extractor

A simple C application to extract EXIF metadata from an image file.

## Requirements

- Fedora (or any Linux-based OS)
- libexif library

## Installation

1. Install dependencies:

   ```bash
   sudo dnf install libexif libexif-devel
2. Compile the application:
     ```bash
     gcc -o extract_metadata extract_metadata.c -lexif
3.Run the program:
    ```bash
    ./extract_metadata path_to_image.jpg


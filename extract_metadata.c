#include <stdio.h>
#include <stdlib.h>
#include <libexif/exif-data.h>

void display_exif_entry(ExifEntry *entry) {
    char value[1024];
    if (entry) {
        exif_entry_get_value(entry, value, sizeof(value));
        if (*value) {
            printf("%s: %s\n", exif_tag_get_name(entry->tag), value);
        }
    }
}

void display_exif_data(const char *filename) {
    ExifData *ed = exif_data_new_from_file(filename);
    if (!ed) {
        fprintf(stderr, "No EXIF data found in file: %s\n", filename);
        return;
    }

    for (int i = 0; i < EXIF_IFD_COUNT; i++) {
        ExifContent *content = ed->ifd[i];
        if (content) {
            for (unsigned int j = 0; j < content->count; j++) {
                display_exif_entry(content->entries[j]);
            }
        }
    }

    exif_data_unref(ed);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image-file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    display_exif_data(filename);

    return EXIT_SUCCESS;
}

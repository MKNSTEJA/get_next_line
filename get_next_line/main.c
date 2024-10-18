#include "get_next_line.h"  // Include your header file

// Function prototypes
void test_large_line(const char *filename);
void test_no_newline_at_end(const char *filename);
void test_binary_file(const char *filename);
void test_empty_file(const char *filename);
void test_file_with_only_newlines(const char *filename);
void test_file_with_mixed_content(const char *filename);
void test_unicode_file(const char *filename);
void test_long_and_short_lines(const char *filename);
void test_consecutive_newlines(const char *filename);
void test_non_printable_chars(const char *filename);
void test_stdin(void);

// Test reading from a normal file with multiple lines
void test_file(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    char *line;
    printf("\n--- Reading from file: %s ---\n", filename);
    while ((line = get_next_line(fd)) != NULL) {
        printf("Line: %s", line); // Line includes the '\n'
        free(line);
    }
    close(fd);
    printf("--- Finished reading file: %s ---\n", filename);
}

// Test with a file containing a single large line
void test_large_line(const char *filename) {
    test_file(filename);
}

// Test with a file that has no newline at the end
void test_no_newline_at_end(const char *filename) {
    test_file(filename);
}

// Test with a binary file (undefined behavior)
void test_binary_file(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        printf("Error opening binary file: %s\n", filename);
        return;
    }

    char *line;
    printf("\n--- Reading from binary file: %s ---\n", filename);
    while ((line = get_next_line(fd)) != NULL) {
        printf("Binary data: %s\n", line);  // May print garbage or behave unexpectedly
        free(line);
    }
    close(fd);
}

// Test with an empty file
void test_empty_file(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        printf("Error opening empty file: %s\n", filename);
        return;
    }

    char *line = get_next_line(fd);
    if (line == NULL) {
        printf("Test passed for empty file: No lines to read\n");
    } else {
        printf("Test failed for empty file\n");
        free(line);
    }
    close(fd);
}

// Test with a file containing only newlines
void test_file_with_only_newlines(const char *filename) {
    test_file(filename);
}

// Test with a file containing mixed content (text and binary-like data)
void test_file_with_mixed_content(const char *filename) {
    test_file(filename);
}

// Test with a file containing Unicode characters
void test_unicode_file(const char *filename) {
    test_file(filename);
}

// Test with a file containing both long and short lines
void test_long_and_short_lines(const char *filename) {
    test_file(filename);
}

// Test with a file containing consecutive newlines (blank lines)
void test_consecutive_newlines(const char *filename) {
    test_file(filename);
}

// Test with a file containing non-printable ASCII characters
void test_non_printable_chars(const char *filename) {
    test_file(filename);
}

// Test reading from standard input
void test_stdin() {
    printf("\n--- Test standard input (Ctrl+D to end): ---\n");
    char *line;
    while ((line = get_next_line(0)) != NULL) {
        printf("Line: %s", line);
        free(line);
    }
}

int main(void) {
    // Normal test cases
    test_file("file1.txt");                      // Normal file with multiple lines
    test_empty_file("empty.txt");                // Empty file test
    test_large_line("large_line.txt");           // Single large line test
    test_no_newline_at_end("no_newline.txt");    // File without a newline at the end
    test_binary_file("binary_file.bin");         // Binary file test (undefined behavior)

    // Additional test cases
    test_file_with_only_newlines("file_with_only_newlines.txt");     // File with only newlines
    test_file_with_mixed_content("file_with_mixed_content.txt");     // File with mixed content
    test_unicode_file("file_with_unicode_characters.txt");           // File with Unicode characters
    test_long_and_short_lines("file_with_long_lines_and_short_lines.txt"); // Long and short lines
    test_consecutive_newlines("file_with_consecutive_newlines.txt"); // File with consecutive newlines
    test_non_printable_chars("file_with_non_printable_characters.txt"); // Non-printable characters

    test_stdin();  // Standard input test

    return 0;
}

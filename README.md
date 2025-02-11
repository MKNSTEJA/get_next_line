# get_next_line

*Custom implementation of the `get_next_line` function for reading lines from a file descriptor.*

---

## Table of Contents

1. [Introduction](#introduction)
2. [Features](#features)
3. [Installation](#installation)
4. [Usage](#usage)
5. [Function Overview](#function-overview)
6. [Contributing](#contributing)
7. [License](#license)
8. [Acknowledgments](#acknowledgments)

---

## Introduction

**get_next_line** is a function designed to read a line from a file descriptor, handling multiple file descriptors simultaneously. This project is part of the 42 School curriculum and focuses on dynamic memory allocation, file handling, and efficient buffer management.

---

## Features

- **Reads from any file descriptor**: Supports standard input, files, and sockets.
- **Handles multiple file descriptors**: Can manage multiple open files simultaneously.
- **Dynamic buffer allocation**: Reads efficiently without unnecessary memory usage.
- **Works with different buffer sizes**: Behavior is adaptable based on `BUFFER_SIZE`.

---

## Installation

To use **get_next_line** in your project, follow these steps:

1. Clone the repository:
   ```sh
   git clone https://github.com/MKNSTEJA/get_next_line.git
   ```

2. Navigate to the project directory:
   ```sh
   cd get_next_line
   ```

3. Compile the library:
   ```sh
   make
   ```

4. Include `get_next_line.h` in your project and link the compiled library:
   ```c
   #include "get_next_line.h"
   ```

5. Compile and link against `get_next_line.a`:
   ```sh
   gcc main.c get_next_line.a -o program
   ```

---

## Usage

Once compiled, `get_next_line` can be used as follows:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd = open("file.txt", O_RDONLY);
    char *line;
    
    while ((line = get_next_line(fd))) {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

Run the compiled program:
```sh
./program
```

---

## Function Overview

```c
char *get_next_line(int fd);
```

- **Input:** A file descriptor `fd`.
- **Output:** The next line read from the file, including the newline character.
- **Returns:**
  - A pointer to the next line read.
  - `NULL` when the end of file is reached or an error occurs.

---

## Contributing

Contributions are welcome! Follow these steps to contribute:

1. Fork the repository.
2. Create a new branch:
   ```sh
   git checkout -b feature/your-feature-name
   ```
3. Commit your changes:
   ```sh
   git commit -m "Add feature or fix bug"
   ```
4. Push your changes:
   ```sh
   git push origin feature/your-feature-name
   ```
5. Open a pull request on GitHub.

---

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

## Acknowledgments

- **42 School:** For providing the challenge to build this project.
- **Community:** For inspiration and support in improving the implementation.

---

## Author

**MKNSTEJA**

- GitHub: [MKNSTEJA](https://github.com/MKNSTEJA)
- Email: chessmaniacs123@gmail.com

Feel free to contribute, report issues, or suggest improvements!


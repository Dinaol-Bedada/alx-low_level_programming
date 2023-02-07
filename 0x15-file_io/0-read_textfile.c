#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

ssize_t read_textfile(const char *filename, size_t letters) {
    int fd;
    ssize_t read_bytes, written_bytes;
    char *buf;

    if (!filename)
        return 0;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return 0;

    buf = (char *)malloc(sizeof(char) * letters);
    if (!buf) {
        close(fd);
        return 0;
    }

    read_bytes = read(fd, buf, letters);
    if (read_bytes == -1) {
        close(fd);
        free(buf);
        return 0;
    }

    written_bytes = write(STDOUT_FILENO, buf, read_bytes);
    if (written_bytes == -1 || written_bytes != read_bytes) {
        close(fd);
        free(buf);
        return 0;
    }

    close(fd);
    free(buf);
    return written_bytes;
}

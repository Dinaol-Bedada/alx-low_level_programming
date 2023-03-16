#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * read_textfile - reads a text file and prints it to the standard output
 * @filename: name of the file to be read
 * @letters: number of letters to read and print
 * Return: the number of letters printed, or 0 if it failed
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    int file_descriptor;
    ssize_t read_count, write_count;
    char *buffer;

    if (!filename)
    {
        return (0);
    }

    file_descriptor = open(filename, O_RDONLY);
    if (file_descriptor == -1)
    {
        return (0);
    }

    buffer = malloc(sizeof(char) * letters);
    if (!buffer)
    {
        close(file_descriptor);
        return (0);
    }

    read_count = read(file_descriptor, buffer, letters);
    if (read_count == -1)
    {
        close(file_descriptor);
        free(buffer);
        return (0);
    }

    write_count = write(STDOUT_FILENO, buffer, read_count);
    if (write_count == -1 || write_count != read_count)
    {
        close(file_descriptor);
        free(buffer);
        return (0);
    }

    close(file_descriptor);
    free(buffer);
    return (write_count);
}

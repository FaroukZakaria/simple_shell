#include "shell.h"
/**
 * _lread - s
 * @path: s
 * Return: s
 */
char *_lread(char *path)
{
	char buf[1024];
	ssize_t nread;
	char *target;
	int fd = open(path, O_RDONLY);

	if (fd < 0)
		return (NULL);
	nread = read(fd, buf, sizeof(buf));
	if (nread < 0)
		return (NULL);
	target = malloc(nread + 1);
	if (target == NULL)
		return (NULL);
	_memcpy(target, buf, nread);
	target[nread] = '\0';
	close(fd);
	return (target);
}

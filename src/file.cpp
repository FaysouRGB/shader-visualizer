#include <iostream>
#include <cstdio>

char *read_file(const char *file)
{
    FILE *fp = fopen(file, "rb");
    if (!fp)
    {
        std::cerr << "read_file: error opening file '" << file << "'" << std::endl;
        return nullptr;
    }

    fseek(fp, 0L, SEEK_END);
    long size = ftell(fp) + 1L;
    rewind(fp);
    char *content = (char *)malloc(size);
    fread(content, 1, size - 1, fp);
    content[size - 1] = '\0';
    fclose(fp);
    return content;
}
#include <stdio.h>

FILE *fopen(const char *__restrict__ _Filename, const char *__restrict__ _Mode);
int fclose(FILE *_File);

int fputc(int _Ch, FILE *_File);
int fgetc(FILE *_File);

int putc(int _Ch, FILE *_File);
int getc(FILE *_File);

char *fgets(char *__restrict__ _Buf, int _MaxCount, FILE *__restrict__ _File);
int fputs(const char *__restrict__ _Str, FILE *__restrict__ _File);

inline int fprintf(FILE *__stream, const char *__format, ...);
inline int fscanf(FILE *__stream, const char *__format, ...);

size_t fwrite(const void *__restrict__ _Str, size_t _Size, size_t _Count, FILE *__restrict__ _File);
int fseek(FILE *_File, long _Offset, int _Origin);
long ftell(FILE *_File);
void rewind(FILE *_File);
int feof(FILE *_File);
int ferror(FILE *_File);
void clearerr(FILE *_File);
void perror(const char *_ErrMsg);
int rename(const char *_OldFilename, const char *_NewFilename);
int remove(const char *_Filename);

int main(int argc, char *argv[]) { return 0; }
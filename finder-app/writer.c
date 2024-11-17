#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/syslog.h>
#include <sys/file.h>
#include <stdbool.h>
bool FileExists(const char* FileName) {
    struct stat buffer;
    return stat(FileName, &buffer) == 0 ? true : false;
}
int OpenFile(const char *GivenFileName, const char* GivenWriteContent) {
    int fd;
    fd = open(GivenFileName, O_RDWR);
    if (FileExists(GivenFileName) == true) {
    write(fd, GivenWriteContent, strlen (GivenWriteContent));
    syslog(LOG_USER, "FIle was created succesfully");
    return 0; } else {
        return 1;
    }
}
int main(int argc, char *argv[]) {
    if (argc > 2 ) { // proper checking before executing
        syslog(LOG_USER, "More paramers were passed then needed, ignoring."); 
    } if (argc  < 2) { 
        syslog(LOG_USER, "Not enough parameters were passed! Aborting.");
        return 1;
    } 
    char *FileName; 
    char *WriteContent;
    FileName = argv[1];
    WriteContent = argv[2];

    int succesbfr = OpenFile(FileName, WriteContent);
    switch (succesbfr) {
    case 1:
    syslog(LOG_USER, "Process exited with error status. Please check if the file passed exists and isn't used by another process");
    return succesbfr;
    break;
    case 0:
    syslog(LOG_USER, "Process executed successfully.");
    return succesbfr;
    break;
    default:
    syslog(LOG_USER, "unknown exit status.");
    return 1;
    break;
    }
}
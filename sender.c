 #include <stdio.h>
 #include <sys/ipc.h>
 #include <sys/msg.h>
 #include <string.h>

struct message {
    long type;
    char text[100];
};

int main() {
    key_t key = ftok(".", 'a');
    int msgid = msgget(key, 0666 | IPC_CREAT);
    struct message msg;
    
    msg.type = 1;
    strcpy(msg.text, "Hello Sangeeth");
    
    msgsnd(msgid, &msg, sizeof(msg.text), 0);
    printf("Sent: %s\n", msg.text);
    
    return 0;
}


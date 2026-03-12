 #include <stdio.h>
 #include <sys/ipc.h>
 #include <sys/msg.h>

struct message {
    long type;
    char text[100];
};

int main() {
    key_t key = ftok(".", 'a');
    int msgid = msgget(key, 0666 | IPC_CREAT);
    struct message msg;
    
    printf("Waiting for message...\n");
    msgrcv(msgid, &msg, sizeof(msg.text), 1, 0);
    printf("Received: %s\n", msg.text);
    
    return 0;
}

#include <stdio.h>
#include <string.h>

int main(void){
    FILE *fp;
    FILE *f;
    fp = fopen("ping_data.txt","a");
    f = fopen("ping_summary.txt", "a");

    printf("DATE(dd/mm/yy): ");
    
    fprintf(fp, "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
    fprintf(f, "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");

    char date[101];

    scanf("%[^\n]", date); getchar();

    fprintf(fp, "Date: %s ", date);
    fprintf(f, "Date: %s ", date);

    char time[101];
    printf("Time: ");

    scanf("%[^\n]", time); getchar();

    fprintf(fp, "Time: %s ", time);
    fprintf(f, "Time: %s ", time);

    char place[101];

    printf("Location: ");

    scanf("%[^\n]", place); getchar();

    fprintf(fp, "Location: %s\n", place);
    fprintf(f, "Location: %s\n", place);

    printf("Input data: (type \"DONE\" when done inputting)\n");


    double total_ping = 0;

    char catch[101];
    
    scanf("%s", catch);


    char server[101];
    int seq;
    int ttl;
    double ping;

    double min_ping = 100000000;
    double max_ping = 0;
    int loss_count = 0;

    char done[101] = "DONE";
    char request[101] = "Request";
    while (strcmp(catch, done) != 0){
        
        if (strcmp(catch, request) == 0){
            loss_count++;
            scanf(" timeout for icmp_seq %d", &seq);
            fprintf(fp,"Request timeout for icmp_seq %d\n", seq);
            getchar();
        }
        else{
            scanf(" bytes from %[^:]: icmp_seq=%d ttl=%d time=%lf ms", server, &seq, &ttl, &ping); getchar();

            if (ping < min_ping)
                min_ping = ping;
            
            if (ping > max_ping)
                max_ping = ping;
            total_ping += ping;

            fprintf(fp, "%s bytes from %s: icmp_seq=%d ttl=%d time=%.3lf ms\n", catch, server, seq, ttl, ping);
        }
        
        scanf("%s", catch); 
    }

    double loss = 1.0 * loss_count / seq * 100;

    double avg_ping = total_ping / (seq - loss_count);
    fprintf(fp, "--- %s ping statistics ---\n%d packets recived, %d packets received, %.1lf%% packet loss\nround-trip min/avg/max = %.3lf/%.3lf/%.3lf ms\n", server, seq, seq - loss_count, loss, min_ping, avg_ping, max_ping);
    if (loss <= 5){
        fprintf(fp, "LOSS: Good (<=5)\n");
        printf("LOSS: Good (<=5)\n");
    }
    else if (loss <= 10){
        fprintf(fp, "LOSS: Decent (<=10)\n");
        printf("LOSS: Decent (<=10)\n");
    }
    else{
        fprintf(fp, "LOSS: Bad (>10)\n");
        printf("LOSS: Bad (>10)\n");
    }

    if (avg_ping <= 60){
        fprintf(fp, "PING: Good (<=60)\n");
        printf("PING: Good (<=60)\n\n");
    }
    else if (avg_ping <= 120){
        fprintf(fp, "PING: Decent (<=120)\n");
        printf("PING: Decent\n (<=120)\n");
    }
    else{
        fprintf(fp, "PING: Bad\n");
        printf("PING: Bad\n");
    }

    fprintf(f, "--- %s ping statistics ---\n%d packets recived, %d packets received, %.1lf%% packet loss\nround-trip min/avg/max = %.3lf/%.3lf/%.3lf ms\n", server, seq, seq - loss_count, loss, min_ping, avg_ping, max_ping);
    if (loss <= 5){
        fprintf(f, "LOSS: Good (<=5)\n");
    }
    else if (loss <= 10){
        fprintf(f, "LOSS: Decent (<=10)\n");
    }
    else{
        fprintf(f, "LOSS: Bad (>10)\n");
    }

    if (avg_ping <= 60){
        fprintf(f, "PING: Good(<=60)\n");
    }
    else if (avg_ping <= 120){
        fprintf(f, "PING: Decent(<=120)\n");
    }
    else{
        fprintf(f, "PING: Bad(>120)\n");
    }
}
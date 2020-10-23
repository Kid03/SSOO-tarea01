#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<time.h>

int flag=0;
// Maneja las señales
void sig_handler(int signo)
{
    //Prepara la salida cuando toma SIGUSR1
    struct tm tm = *localtime(&(time_t){ time(NULL) });
    char str[50];
    asctime_r(&tm, str);
    int cltAux=0,i=0;

    if (signo == SIGUSR1){
        while(cltAux<2){
            if(str[i]==58){
                cltAux++;
            }
            i++;
        }
        str[i+2]='\0';
        str[i+3]='\0';
        printf("Señal SIGUSR1 recibida: %s CLT %d\n", str,tm.tm_year+1900);
        i=0;
        flag=0;
    }
    //Controla "^C", usa una variable global para mantener registro de las veces que se a presionado.
    else if (signo == SIGINT){
        flag++;
        printf("\n");
    }
    if(flag==2){
        flag=0;
        exit(EXIT_SUCCESS);
    }
}

int main(void)
{
    printf("Programa hora ejecutandose. PID=%d.\n",getpid());
    //Señales a recivir
    signal(SIGINT, sig_handler);
    signal(SIGUSR1, sig_handler);
    printf("Listo para recivir las señal SIGUSR1.\n");

    while(1)
        sleep(1);
    return 0;
}

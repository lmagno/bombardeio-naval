#ifndef libstatus_h__
#define libstatus_h__

typedef struct Status_Tag Status;
Status* sucesso();
Status* erro(int valor, char *mensagem);
void libera_status(Status *sts);
int trata_status(Status *sts);

#endif

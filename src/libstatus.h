#ifndef libstatus_h__
#define libstatus_h__

typedef struct Status_Tag Status;
Status* sucesso();
Status* erro(int valor, char *mensagem);
int trata_status(Status *sts);

#endif

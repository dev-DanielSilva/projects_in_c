#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARQUIVO_ENTRADA "master.txt"
#define ARQUIVO_SAIDA "final.txt"

typedef struct {
    int numero_conta;
    char nome[31];
    double saldo;
} Cliente;

Cliente *cadastro = NULL;
int total_clientes = 0;
int resultado;

int le_menu_opcao (void) {
    char txt[10];
    fgets(txt, sizeof(txt), stdin);
    return atoi(txt);
}

int le_arquivo (char *nome) {
    FILE *arq = fopen(nome, "r");
    if (arq == NULL) {
        return -1;
    }
    char buffer[100];

    if (fgets(buffer, sizeof(buffer), arq) != NULL){
        total_clientes = atoi(buffer);
    }
    if (total_clientes <= 0) {
        fclose(arq);
        return -1;
    }

    cadastro = calloc(total_clientes, sizeof(Cliente));
    if (cadastro == NULL) {
        fclose(arq);
        return -1;
    }
    for (int i = 0; i < total_clientes; i++) {
        fgets(buffer, sizeof(buffer), arq);
        cadastro[i].numero_conta = atoi(buffer);

        fgets(cadastro[i].nome, sizeof(cadastro[i].nome), arq);
        cadastro[i].nome[strcspn(cadastro[i].nome, "\r\n")] = '\0';

        fgets(buffer, sizeof(buffer), arq);
        cadastro[i].saldo = atof(buffer);
    }

    fclose(arq);
    return total_clientes;
}

int procura_conta (int conta) {
    for (int i = 0; i < total_clientes; i++) {
        if (cadastro[i].numero_conta == conta){
            return i;
        }
    }
    return -1;
}

void exibe_saldo_conta (int conta) {
    int indice = procura_conta(conta);

    if (indice == -1){
        printf("ERRO CONTA\n");
    }
    else {
        printf("%06d\n", cadastro[indice].numero_conta);
        printf("%s\n", cadastro[indice].nome);
        printf("%.2f\n", cadastro[indice].saldo);
    }
}

void exibe_contas (void) {
    printf("CONTAS %d\n", total_clientes);

    for (int i = 0; i < total_clientes; i++) {
        printf("%06d\n", cadastro[i].numero_conta);
        printf("%s\n", cadastro[i].nome);
        printf("%.2f\n", cadastro[i].saldo);
    }
}

double deposito (int ncliente, double valor) {
    cadastro[ncliente].saldo += valor;
    return cadastro[ncliente].saldo;
}

double saque (int ncliente, double valor) {
    if (valor > cadastro[ncliente].saldo) {
        printf("ERRO SALDO\n");
        return cadastro[ncliente].saldo;
    }
    cadastro[ncliente].saldo -= valor;
    return cadastro[ncliente].saldo;
}

void transfere (double *saldo_destino, double *saldo_origem) {

    double valor_transferencia = *saldo_origem;

    if (valor_transferencia <= 0) {
        printf("ERRO SALDO\n");
    }
    else {
        *saldo_origem -= valor_transferencia;
        *saldo_destino += valor_transferencia;
        printf("TRANSF OK\n");
    }
}

int grava_arquivo (char *nome, int nclientes) {
    FILE *arq = fopen(nome, "w");
    if (arq == NULL) {
        return -1;
    }

    fprintf(arq, "%d\n", nclientes);
    for (int i = 0; i < nclientes; i++) {
        fprintf(arq, "%06d\n", cadastro[i].numero_conta);
        fprintf(arq, "%s\n", cadastro[i].nome);
        fprintf(arq, "%.2f\n", cadastro[i].saldo);
    }

    fclose(arq);
    return nclientes;
}

int main()
{
    int opcao;

    do {
        opcao = le_menu_opcao();

        switch (opcao) {
            case 1: {
                resultado = le_arquivo(ARQUIVO_ENTRADA);
                if (resultado == -1) {
                    printf("ERRO ARQUIVO\n");
                } else {
                    printf("LIDOS %d\n", resultado);
                }
                break;
            }

            case 2: {
                char buffer_conta[20];
                char buffer_valor[20];
                int conta_procurada;
                int indice_encontrado;
                double valor_deposito;
                double saldo_atualizado;

                fgets(buffer_conta, sizeof(buffer_conta), stdin);
                conta_procurada = atoi(buffer_conta);

                indice_encontrado = procura_conta(conta_procurada);

                if (indice_encontrado == -1) {
                    printf("ERRO CONTA\n");
                } else {
                    fgets(buffer_valor, sizeof(buffer_valor), stdin);
                    valor_deposito = atof(buffer_valor);

                    saldo_atualizado = deposito(indice_encontrado, valor_deposito);
                    printf("SALDO %.2f\n", saldo_atualizado);
                }
                break;
            }

            case 3: {
                char buffer_conta[20];
                char buffer_valor[20];
                int conta_procurada;
                int indice_encontrado;
                double valor_saque;
                double saldo_atualizado;

                fgets(buffer_conta, sizeof(buffer_conta), stdin);
                conta_procurada = atoi(buffer_conta);

                indice_encontrado = procura_conta(conta_procurada);

                if (indice_encontrado == -1) {
                    printf("ERRO CONTA\n");
                } else {
                    fgets(buffer_valor, sizeof(buffer_valor), stdin);
                    valor_saque = atof(buffer_valor);

                    double saldo_anterior = cadastro[indice_encontrado].saldo;
                    saldo_atualizado = saque(indice_encontrado, valor_saque);

                    if (saldo_atualizado != saldo_anterior) {
                        printf("SALDO %.2f\n", saldo_atualizado);
                    }
                }
                break;
            }

            case 4: {
                char buffer_conta[20];
                int conta_origem, conta_destino;
                int ind_origem, ind_destino;

                fgets(buffer_conta, sizeof(buffer_conta), stdin);
                conta_destino = atoi(buffer_conta);
                ind_destino = procura_conta(conta_destino);

                fgets(buffer_conta, sizeof(buffer_conta), stdin);
                conta_origem = atoi(buffer_conta);
                ind_origem = procura_conta(conta_origem);

                if (ind_origem == -1 || ind_destino == -1) {
                    printf("ERRO CONTA\n");
                }
                else {
                    transfere(&cadastro[ind_destino].saldo, &cadastro[ind_origem].saldo);
                }
                break;
            }

            case 5: {
                char buffer_conta[20];
                int conta_procurada;

                fgets(buffer_conta, sizeof(buffer_conta), stdin);
                conta_procurada = atoi(buffer_conta);

                exibe_saldo_conta(conta_procurada);
                break;
            }

            case 6: {
                exibe_contas();
                break;
            }

            case 7: {
                resultado = grava_arquivo(ARQUIVO_SAIDA, total_clientes);
                if (resultado == -1) {
                    printf("ERRO ARQUIVO\n");
                } else {
                    printf("GRAVADOS %d\n", resultado);
                }
                break;
            }
        }
    } while (opcao != 0);

    if (cadastro != NULL) {
        free(cadastro);
    }

    return 0;
}

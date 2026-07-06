#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Estrutura que representa cada conta no sistema
typedef struct {
    char id[80];       // 80 caracteres tamanho fixo
    char senha[30];    // 30 caracteres tamanho fixo
    char descricao[100];// 100 caracteres tamanho fixo
    char status;       // 'A' para Ativo, 'I' para Inativo
} Conta;

// Protótipos das sub-rotinas
void criptografarSenha(char *senha, const char *senhaMestra);
void descriptografarSenha(char *senhaCripto, const char *senhaMestra);
void leArquivo(Conta **cadastro, int *total_ativos);
void escreverArquivo(Conta *cadastro, int total_ativos);
void definirSenhaMestra(char *senhaMestra, int *definida);
void exportarTexto(Conta *cadastro, int total_ativos, const char *senhaMestra);
void importarTexto(Conta **cadastro, int *total_ativos, const char *senhaMestra);
void liberarCadastro(Conta *cadastro);
void inserirManual(Conta **cadastro, int *total_ativos, const char *senhaMestra);
void consultaPorID(Conta *cadastro, int total_ativos, const char *senhaMestra);
void alterarSenha(Conta *cadastro, int total_ativos, const char *senhaMestra);
void consultaPorDados(Conta *cadastro, int total_ativos, const char *senhaMestra);
void remocaoLogica(Conta *cadastro, int total_ativos);

// Função auxiliar para converter string para minúsculo (Busca Case-Insensitive)
void paraMinusculo(const char *origem, char *destino) {
    int len = strlen(origem);
    for (int i = 0; i < len; i++) {
        destino[i] = tolower((unsigned char)origem[i]);
    }
    destino[len] = '\0';
}

// OPC1: Lê o arquivo binário "senhas-salvas.bin"
void leArquivo(Conta **cadastro, int *total_ativos) {
    FILE *arq = fopen("senhas-salvas.bin", "rb");
    if (arq == NULL) {
        printf("ERRO ARQ\n");
        return;
    }

    int qtdRegistros = 0;
    if (fread(&qtdRegistros, sizeof(int), 1, arq) != 1) {
        printf("ERRO ARQ\n");
        fclose(arq);
        return;
    }

    if (*cadastro != NULL) {
        free(*cadastro);
        *cadastro = NULL;
    }

    int capacidade_total = qtdRegistros + 30;
    *cadastro = (Conta *) calloc(capacidade_total, sizeof(Conta));

    if (*cadastro == NULL) {
        fclose(arq);
        return;
    }

    fread(*cadastro, sizeof(Conta), qtdRegistros, arq);
    *total_ativos = qtdRegistros;

    fclose(arq);
}

// OPC2: Salva o estado atual no arquivo binário "senhas.bin"
void escreverArquivo(Conta *cadastro, int total_ativos) {
    int ativos_reais = 0;
    for (int i = 0; i < total_ativos; i++) {
        if (cadastro[i].status == 'A') ativos_reais++;
    }

    FILE *arq = fopen("senhas.bin", "wb");
    if (arq == NULL) {
        printf("ERRO ARQ\n");
        return;
    }

    fwrite(&ativos_reais, sizeof(int), 1, arq);
    for (int i = 0; i < total_ativos; i++) {
        if (cadastro[i].status == 'A') {
            fwrite(&cadastro[i], sizeof(Conta), 1, arq);
        }
    }

    fclose(arq);
}

// OPC0: Define a senha mestra limitando a 10 caracteres
void definirSenhaMestra(char *senhaMestra, int *definida) {
    char buffer[200];
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        buffer[strcspn(buffer, "\r\n")] = '\0';
        strncpy(senhaMestra, buffer, 10);
        senhaMestra[10] = '\0';
        *definida = 1;
    }
}

// OPC3: Exporta para "senhas-bkp.txt" (Com o cabeçalho do total de ativos)
void exportarTexto(Conta *cadastro, int total_ativos, const char *senhaMestra) {
    int ativos_reais = 0;
    for (int i = 0; i < total_ativos; i++) {
        if (cadastro[i].status == 'A') ativos_reais++;
    }

    FILE *arq = fopen("senhas-bkp.txt", "w");
    if (arq == NULL) {
        printf("ERRO ARQ\n");
        return;
    }

    fprintf(arq, "%d\n", ativos_reais);

    for (int i = 0; i < total_ativos; i++) {
        if (cadastro[i].status == 'A') {
            char senhaAberta[31];
            strncpy(senhaAberta, cadastro[i].senha, 30);
            senhaAberta[30] = '\0';

            descriptografarSenha(senhaAberta, senhaMestra);

            fprintf(arq, "%s\n", cadastro[i].id);
            fprintf(arq, "%s\n", senhaAberta);
            fprintf(arq, "%s\n", cadastro[i].descricao);
        }
    }
    fclose(arq);
}

// OPC4: Importa de "senhas-bkp.txt" (Lendo o cabeçalho)
void importarTexto(Conta **cadastro, int *total_ativos, const char *senhaMestra) {
    FILE *arq = fopen("senhas-bkp.txt", "r");
    if (arq == NULL) {
        printf("ERRO ARQ\n");
        return;
    }

    char bufferQtd[50];
    if (fgets(bufferQtd, sizeof(bufferQtd), arq) == NULL) {
        printf("ERRO ARQ\n");
        fclose(arq);
        return;
    }
    int qtdRegistros = atoi(bufferQtd);

    if (*cadastro != NULL) {
        free(*cadastro);
        *cadastro = NULL;
    }

    int capacidade_total = qtdRegistros + 30;
    *cadastro = (Conta *) calloc(capacidade_total, sizeof(Conta));
    if (*cadastro == NULL) {
        fclose(arq);
        return;
    }

    char bufferID[200], bufferSenha[200], bufferDesc[200];
    Conta *vetor = *cadastro;
    *total_ativos = 0;

    while (*total_ativos < qtdRegistros) {
        if (fgets(bufferID, sizeof(bufferID), arq) == NULL) break;
        bufferID[strcspn(bufferID, "\r\n")] = '\0';

        if (fgets(bufferSenha, sizeof(bufferSenha), arq) == NULL) break;
        bufferSenha[strcspn(bufferSenha, "\r\n")] = '\0';

        if (fgets(bufferDesc, sizeof(bufferDesc), arq) == NULL) break;
        bufferDesc[strcspn(bufferDesc, "\r\n")] = '\0';

        int i = *total_ativos;
        strncpy(vetor[i].id, bufferID, 79);
        vetor[i].id[79] = '\0';

        strncpy(vetor[i].senha, bufferSenha, 29);
        vetor[i].senha[29] = '\0';
        criptografarSenha(vetor[i].senha, senhaMestra);

        strncpy(vetor[i].descricao, bufferDesc, 99);
        vetor[i].descricao[99] = '\0';

        vetor[i].status = 'A';
        (*total_ativos)++;
    }
    fclose(arq);
}

void liberarCadastro(Conta *cadastro) {
    if (cadastro != NULL) {
        free(cadastro);
    }
}

// Criptografia baseada em deslocamento cíclico pelos caracteres numéricos
void criptografarSenha(char *senha, const char *senhaMestra) {
    int tamSenha = strlen(senha);
    int tamMestra = strlen(senhaMestra);
    if (tamMestra == 0) return;

    for (int i = 0; i < tamSenha; i++) {
        int deslocamento = senhaMestra[i % tamMestra] - '0';
        senha[i] = senha[i] + deslocamento;
    }
}

void descriptografarSenha(char *senhaCripto, const char *senhaMestra) {
    int tamSenha = strlen(senhaCripto);
    int tamMestra = strlen(senhaMestra);
    if (tamMestra == 0) return;

    for (int i = 0; i < tamSenha; i++) {
        int deslocamento = senhaMestra[i % tamMestra] - '0';
        senhaCripto[i] = senhaCripto[i] - deslocamento;
    }
}

// OPC5: Inserção Manual via teclado expansível
void inserirManual(Conta **cadastro, int *total_ativos, const char *senhaMestra) {
    char buffer[200];
    int max_permitido = *total_ativos + 30;

    if (*cadastro == NULL) {
        *cadastro = (Conta *) calloc(30, sizeof(Conta));
        if (*cadastro == NULL) return;
        max_permitido = 30;
    }

    while (*total_ativos < max_permitido) {
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) break;
        buffer[strcspn(buffer, "\r\n")] = '\0';

        if (buffer[0] == '#') break;

        int i = *total_ativos;
        strncpy((*cadastro)[i].id, buffer, 79);
        (*cadastro)[i].id[79] = '\0';

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) break;
        buffer[strcspn(buffer, "\r\n")] = '\0';
        strncpy((*cadastro)[i].senha, buffer, 29);
        (*cadastro)[i].senha[29] = '\0';
        criptografarSenha((*cadastro)[i].senha, senhaMestra);

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) break;
        buffer[strcspn(buffer, "\r\n")] = '\0';
        strncpy((*cadastro)[i].descricao, buffer, 99);
        (*cadastro)[i].descricao[99] = '\0';

        (*cadastro)[i].status = 'A';
        (*total_ativos)++;
    }
}

// OPC6: Consulta por Substring Inicial do ID
void consultaPorID(Conta *cadastro, int total_ativos, const char *senhaMestra) {
    char termo[200];
    if (fgets(termo, sizeof(termo), stdin) == NULL) return;
    termo[strcspn(termo, "\r\n")] = '\0';

    char termoMinusculo[200];
    paraMinusculo(termo, termoMinusculo);

    for (int i = 0; i < total_ativos; i++) {
        if (cadastro[i].status == 'A') {
            char idMinusculo[80];
            paraMinusculo(cadastro[i].id, idMinusculo);

            // Verifica se o ID começa ou contém o termo pesquisado
            if (strstr(idMinusculo, termoMinusculo) != NULL) {
                char senhaAberta[31];
                strncpy(senhaAberta, cadastro[i].senha, 30);
                senhaAberta[30] = '\0';

                descriptografarSenha(senhaAberta, senhaMestra);

                printf("%s\n", cadastro[i].id);
                printf("%s\n", senhaAberta);
                printf("%s\n", cadastro[i].descricao);
            }
        }
    }
}

// OPC7: Altera senha por casamento EXATO de ID
void alterarSenha(Conta *cadastro, int total_ativos, const char *senhaMestra) {
    char termo[200], novaSenha[200];
    int achou = 0;

    if (fgets(termo, sizeof(termo), stdin) == NULL) return;
    termo[strcspn(termo, "\r\n")] = '\0';

    for (int i = 0; i < total_ativos; i++) {
        if (cadastro[i].status == 'A') {
            if (strcmp(cadastro[i].id, termo) == 0) {
                achou = 1;
                if (fgets(novaSenha, sizeof(novaSenha), stdin) == NULL) return;
                novaSenha[strcspn(novaSenha, "\r\n")] = '\0';

                strncpy(cadastro[i].senha, novaSenha, 29);
                cadastro[i].senha[29] = '\0';
                criptografarSenha(cadastro[i].senha, senhaMestra);

                printf("EXEC NEWPWD\n");
                break;
            }
        }
    }
    if (!achou) printf("EXEC FAILPWD\n");
}

// OPC8: Consulta Avançada por ID ou por Descrição/Informações do bloco
void consultaPorDados(Conta *cadastro, int total_ativos, const char *senhaMestra) {
    char termo[200];
    if (fgets(termo, sizeof(termo), stdin) == NULL) return;
    termo[strcspn(termo, "\r\n")] = '\0';

    char termoMinusculo[200];
    paraMinusculo(termo, termoMinusculo);

    for (int i = 0; i < total_ativos; i++) {
        if (cadastro[i].status == 'A') {
            char idMinusculo[80];
            char descMinuscula[100];
            paraMinusculo(cadastro[i].id, idMinusculo);
            paraMinusculo(cadastro[i].descricao, descMinuscula);

            // Busca tanto no ID quanto na Descrição
            if (strstr(idMinusculo, termoMinusculo) != NULL || strstr(descMinuscula, termoMinusculo) != NULL) {
                char senhaAberta[31];
                strncpy(senhaAberta, cadastro[i].senha, 30);
                senhaAberta[30] = '\0';

                descriptografarSenha(senhaAberta, senhaMestra);

                printf("%s\n", cadastro[i].id);
                printf("%s\n", senhaAberta);
                printf("%s\n", cadastro[i].descricao);
            }
        }
    }
}

// OPC9: Remoção lógica por ID exato
void remocaoLogica(Conta *cadastro, int total_ativos) {
    char termo[200];
    int achou = 0;

    if (fgets(termo, sizeof(termo), stdin) == NULL) return;
    termo[strcspn(termo, "\r\n")] = '\0';

    for (int i = 0; i < total_ativos; i++) {
        if (cadastro[i].status == 'A') {
            if (strcmp(cadastro[i].id, termo) == 0) {
                cadastro[i].status = 'I';
                achou = 1;
                printf("EXEC DEL\n"); // Mensagem Exigida pelo PDF
                break;
            }
        }
    }
    if (!achou) printf("EXEC ERRDEL\n"); // Mensagem Exigida pelo PDF
}

int main() {
    Conta *cadastro = NULL;
    int total_ativos = 0;
    char senhaMestra[31];
    int senhaDefinida = 0;
    char buffer[200];
    int opcao;

    printf("EXEC MAIN\n");

    for (;;) {
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) break;
        buffer[strcspn(buffer, "\r\n")] = '\0';
        opcao = atoi(buffer);

        if (opcao == -1) {
            liberarCadastro(cadastro);
            printf("EXEC FIM\n");
            break;
        }

        // Se tentar usar qualquer opção sem definir a senha mestra antes
        if (opcao != 0 && senhaDefinida == 0) {
            printf("ZERO ERRO\n");
            if (cadastro != NULL) liberarCadastro(cadastro);
            return 0;
        }

        switch (opcao) {
            case 0:
                printf("EXEC OPC0\n");
                definirSenhaMestra(senhaMestra, &senhaDefinida);
                break;
            case 1:
                printf("EXEC OPC1\n");
                leArquivo(&cadastro, &total_ativos);
                break;
            case 2:
                printf("EXEC OPC2\n");
                escreverArquivo(cadastro, total_ativos);
                break;
            case 3:
                printf("EXEC OPC3\n");
                exportarTexto(cadastro, total_ativos, senhaMestra);
                break;
            case 4:
                printf("EXEC OPC4\n");
                importarTexto(&cadastro, &total_ativos, senhaMestra);
                break;
            case 5:
                printf("EXEC OPC5\n");
                inserirManual(&cadastro, &total_ativos, senhaMestra);
                break;
            case 6:
                printf("EXEC OPC6\n");
                consultaPorID(cadastro, total_ativos, senhaMestra);
                break;
            case 7:
                printf("EXEC OPC7\n");
                alterarSenha(cadastro, total_ativos, senhaMestra);
                break;
            case 8:
                printf("EXEC OPC8\n");
                consultaPorDados(cadastro, total_ativos, senhaMestra);
                break;
            case 9:
                printf("EXEC OPC9\n");
                remocaoLogica(cadastro, total_ativos);
                break;
            default:
                printf("EXEC ERRO\n");
                break;
        }
    }
    return 0;
}

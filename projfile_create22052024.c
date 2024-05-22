#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "alunos.txt"

typedef struct {
    char nome[50];
    int idade;
    float nota;
} Aluno;

void adicionarAluno() {
    FILE *file = fopen(FILE_NAME, "a"); // Abre o arquivo para escrita no modo append
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Aluno aluno;
    printf("Digite o nome do aluno: ");
    scanf("%s", aluno.nome);
    printf("Digite a idade do aluno: ");
    scanf("%d", &aluno.idade);
    printf("Digite a nota do aluno: ");
    scanf("%f", &aluno.nota);

    // Escreve os dados do aluno no arquivo com o separador ;
    fprintf(file, "%s;%d;%.2f\n", aluno.nome, aluno.idade, aluno.nota);

    fclose(file);
    printf("Aluno adicionado com sucesso!\n");
}

void listarAlunos() {
    FILE *file = fopen(FILE_NAME, "r"); // Abre o arquivo para leitura
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Aluno aluno;
    printf("Lista de alunos:\n");
    // Lê os dados do arquivo utilizando o separador ;
    while (fscanf(file, "%49[^;];%d;%f\n", aluno.nome, &aluno.idade, &aluno.nota) != EOF) {
        printf("Nome: %s, Idade: %d, Nota: %.2f\n", aluno.nome, aluno.idade, aluno.nota);
    }

    fclose(file);
}

int main() {
    int opcao;
    do {
        printf("Menu:\n");
        printf("1. Adicionar Aluno\n");
        printf("2. Listar Alunos\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarAluno();
                break;
            case 2:
                listarAlunos();
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}
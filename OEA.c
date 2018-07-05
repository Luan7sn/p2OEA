#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
    char linha[2048];
    char UF[5];
    char procuraUF[5];
    char SIAFI[10];
    char procuraSIAFI[10];
    char NomeM[100];
    char procuraNomeM[100];
    char CodF[5];
    char CodSubF[10];
    char CodProg[10];
    char CodA[10];
    char Nis[15];
    char procuraNis[15];
    char NomeFav[100];
    char procuraNomeFav[100];
    char FonFin[100];
    char ValPar[15];
    char MesCo[20];
    int printar = 0;
    int escolha = 0;
    int coluna = 0;
    long posicao;
    char* campo;
    FILE *f = fopen("bolsa.csv", "r");

    printf("Digite o numero a esquerda do tipo de consulta desejada:\n\n");
    printf("1. Consulta por UF\n");
    printf("2. Consulta por SIAFI\n");
    printf("3. Consulta por Nome do Municipio\n");
    printf("4. Consulta por Nis\n");
    printf("5. Consulta por Nome do Favorecido\n");
    scanf("%d", &escolha);

    if(escolha == 1){
        printf("Digite a UF: \n");
        scanf("%s", procuraUF);
    }
    if(escolha == 2){
        printf("Digite o SIAFI utilizando um dos seguintes formatos [XXXX] ou [0XXX] substituindo os X pelo SIAFI e desconsiderando os colchetes: \n");
        scanf("%s", procuraSIAFI);
    }
    if(escolha == 3){
        printf("Digite o nome do municipio: \n");
        scanf(" %[^\n]s", procuraNomeM);
    }
    if(escolha == 4){
        printf("Digite o Nis utilizando o seguinte formato [000XXXXXXXXXXXX] substituindo os X pelo Nis e desconsiderando os colchetes: \n ");
        scanf("%s", procuraNis);
    }
    if(escolha == 5){
        printf("Digite o Nome do Favorecido: \n");
        scanf(" %[^\n]s", procuraNomeFav);
        printf("%s", procuraNomeFav);
    }

    fgets(linha, 2048, f);
    posicao = ftell(f);
    fgets(linha, 2048, f);
    while(!feof(f))
    {
        coluna = 0;
        campo = strtok(linha,"\t");
        while(campo)
        {
            if(coluna == 0)
            {
                strcpy(UF, campo);
            }
            if(coluna == 1)
            {
                strcpy(SIAFI, campo);
            }
            if(coluna == 2)
            {
                strcpy(NomeM, campo);
            }
            if(coluna == 3)
            {
                strcpy(CodF, campo);
            }
            if(coluna == 4)
            {
                strcpy(CodSubF, campo);
            }
            if(coluna == 5)
            {
                strcpy(CodProg, campo);
            }
            if(coluna == 6)
            {
                strcpy(CodA, campo);
            }
            if(coluna == 7)
            {
                strcpy(Nis, campo);
            }
            if(coluna == 8)
            {
                strcpy(NomeFav, campo);
            }
            if(coluna == 9)
            {
                strcpy(FonFin, campo);
            }
            if(coluna == 10)
            {
                strcpy(ValPar, campo);
            }
            if(coluna == 11)
            {
                strcpy(MesCo, campo);
            }
            coluna++;
            campo = strtok(NULL,"\t");
        }
        if(escolha == 1 && strcmp(procuraUF, UF) == 0){
            printar = 1;
        }
        if(escolha == 2 && strcmp(procuraSIAFI, SIAFI) == 0){
            printar = 1;
        }
        if(escolha == 3 && strcmp(procuraNomeM, NomeM) == 0){
            printar = 1;
        }
        if(escolha == 4 && strcmp(procuraNis, Nis) == 0){
            printf("UF: %s\n", UF);
            printf("SIAFI: %s\n", SIAFI);
            printf("Nome do municipio: %s\n", NomeM);
            printf("Codigo Funcao: %s\n", CodF);
            printf("Codigo Subfuncao: %s\n", CodSubF);
            printf("Codigo Programa: %s\n", CodProg);
            printf("Codigo Acao: %s\n", CodA);
            printf("NIS: %s\n", Nis);
            printf("Nome do favorecido: %s\n", NomeFav);
            printf("Fonte-Finalidade: %s\n", FonFin);
            printf("Valor da parcela: %s\n", ValPar);
            printf("Mes competencia: %s\n", MesCo);
            printf("---------------------------------------\n");
            break;
        }
        if(escolha == 5 && strcmp(procuraNomeFav, NomeFav) == 0){
            printar = 1;
        }

        if(printar == 1){
            printf("UF: %s\n", UF);
            printf("SIAFI: %s\n", SIAFI);
            printf("Nome do municipio: %s\n", NomeM);
            printf("Codigo Funcao: %s\n", CodF);
            printf("Codigo Subfuncao: %s\n", CodSubF);
            printf("Codigo Programa: %s\n", CodProg);
            printf("Codigo Acao: %s\n", CodA);
            printf("NIS: %s\n", Nis);
            printf("Nome do favorecido: %s\n", NomeFav);
            printf("Fonte-Finalidade: %s\n", FonFin);
            printf("Valor da parcela: %s\n", ValPar);
            printf("Mes competencia: %s\n", MesCo);
            printf("---------------------------------------\n");
            printar = 0;
        }
        posicao = ftell(f);
        fgets(linha, 2048, f);
    }
    fclose(f);
    return 0;
}

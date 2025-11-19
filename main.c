#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "clinica.h"

int op;
char buffer;

int ValidarLogin(char *usuario, char *senha){

    if (strcmp(usuario,logincerto)==0 && strcmp(senha,senhacerta)==0){
        printf("\n-----Login bem sucedido!-----\n");
        return 1;
    }else{
        printf("\nSenha ou login INVALIDOS!\n");
        printf("Digite 1 para tentar novamente: ");
        scanf ("%s", &op);
        system("cls");
        return 0;

    }

}

void CadastrarMedico(){

    system("cls");

   Medico novoMedico;

    printf("\n-----Cadastrar Médico-----\n\n");
    printf("Nome: ");
    scanf("%c", &buffer);

    fgets(novoMedico.nome, 50, stdin);

    printf("Especialidade: ");
    fgets(novoMedico.especialidade, 50, stdin);

    listaMedicos[NumeroMedicos] = novoMedico;
    NumeroMedicos++;

     printf("\n-----Médico cadastrado: -----\n\n");

    printf("- Nome: %s", listaMedicos[NumeroMedicos-1].nome);
    printf("- Especialidade: %s", listaMedicos[NumeroMedicos-1].especialidade);

    printf("\n\nDigite 1 para voltar ao menu: ");
    scanf("%d", &op);


}

int MarcarConsulta(){

    system("cls");

    Consulta novaConsulta;
    int naoEncontrado = 1;

    printf("\n-----Médicos-----\n\n");

    if(NumeroMedicos == 0) {
         printf("Não há médicos cadastrados\n");
         printf("Digite 1 para voltar ao menu principal: ");
         scanf("%d", &op);

         return 0;

    }

    for(int i = 0; i < NumeroMedicos; i++){
        printf("%d - %s  %s\n", i+1, listaMedicos[i], listaMedicos[i].especialidade);
    }


    printf("\n-----Marcar colsulta!-----\n\n");
    printf("Nome do paciente: ");
    scanf("%c", & buffer);
    fgets(novaConsulta.paciente.nome, 50, stdin);

    printf("Idade do paciente: ");
    scanf("%d",&novaConsulta.paciente.idade);

    printf("Genero do paciente - F M N : ");
    scanf(" %c",&novaConsulta.paciente.genero);

    printf ("Dia:  ");
    scanf("%d", &novaConsulta.dia);

    printf ("Mês:  ");
    scanf("%d", &novaConsulta.mes);




    do{
        printf ("Número do médico: ");
        scanf("%c", &buffer);
        scanf("%d", &op);

        if(op <= NumeroMedicos && op >  0 ){

            novaConsulta.NomeMedico = listaMedicos[op-1].nome;

            listaConsultas[NumeroConsultas] = novaConsulta;
            NumeroConsultas++;

            printf("\n-----CONSULTA MARCADA!-----\n\n");

            printf("- Paciente: %s", listaConsultas[NumeroConsultas-1].paciente.nome);
            printf("- Data: %d/%d\n", listaConsultas[NumeroConsultas-1].dia,  listaConsultas[NumeroConsultas-1].mes );
            printf("- Médico: %s", listaConsultas[NumeroConsultas-1].NomeMedico);



            printf("\nDigite 1 para voltar ao menu principal: ");
            scanf("%d", &op);

             return 0;

        }

        printf("**NUMERO INVÁLIDO**\n");
    }while(naoEncontrado);







}

void listarconsulta (){

    int i;
    system ("cls");

    printf("\n-----Consultas-----\n\n");

    if (NumeroConsultas == 0){
        printf("Não há consultas marcadas!\n");
    }

    else{
        for (int i = 0;i < NumeroConsultas;i++){
            printf("Consulta: %d\n",i++);
            printf("Paciente: %s\n", listaConsultas[i].paciente.nome);
            printf("Idade: %d\n",listaConsultas[i].paciente.idade);
            printf("Gênero: %c\n",listaConsultas[i].paciente.genero);
            printf("Data: %d/%d\n",listaConsultas[i].dia,listaConsultas[i].mes);
            printf("Médico(a): %s\n",listaMedicos[i].nome);
        }
    }
     printf("\nDigite 1 para voltar ao menu principal: ");
            scanf("%d", &op);
}



int confirmarconsulta(){

    if (NumeroConsultas == 0){
        printf("Não há consultas para confirmar!\n");
        printf("\nDigite 1 para voltar ao menu principal: ");
            scanf("%d", &op);
    return 0;
    }

    else {
        printf("\n-----Confirmar Consulta-----\n\n");

 for (int i = 0; i < NumeroConsultas; i++) {
        printf("%d - %s  (%d/%d)\nMédico: %s\n",i++,listaConsultas[i].paciente.nome,listaConsultas[i].dia,listaConsultas[i].mes, listaConsultas[i].NomeMedico);

}
        printf("Selecione  a consulta que deseja confirmar:");
        scanf("%d",&op);
}

}
int main()
{
    setlocale(LC_ALL,"portuguese");

    char usuario[50];
    char senha[50];

    do{

         printf("-----LOGIN-----\n");


        printf("Insira seu usuário:");
        scanf("%s", usuario);

        printf("Insira sua senha:");
        scanf("%s", senha);

    }while(!ValidarLogin(usuario, senha));



    do{

    system("cls");

    printf("-----MENU PRINCIPAL-----"); //desenvolver cada opção
    printf("\n1 - Cadastrar médico\n");
    printf("2 - Marcar consulta\n");
    printf("3 - Listar consulta\n");
    printf("4 - Confirmar consulta\n");
    printf("5 - Finalizar\n");
    printf("------------------------\n");
    printf("Escolha uma opção:");
    scanf("%d",&op);


    switch(op){  //um monte de array,pra consulta e etc
        case 1:
            CadastrarMedico();
            break;  //struct medico
        case 2:
            MarcarConsulta();
            break;
        case 3:
            listarconsulta();
            break;
        case 4:
            confirmarconsulta();
            break;
        case 5:
            printf("Você escolheu: Finalizar\n");
            break;
        default:
            printf("Opção inválida!");
        }
    }while (op !=5);


        return 0;
}

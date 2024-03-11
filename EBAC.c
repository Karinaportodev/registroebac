#include <stdio.h> //biblioteca de comunica��o com o usu�rio 
#include <stdlib.h>//biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>//biblioteca de aloca��es de texto por regi�o
#include <string.h>// biblioteca de cria��o de strings

int registro()//fun��o responsavel por cadastrar ususario
{
	char arquivo[40];//inicio da cria��o de variaveis
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];// fim da cria��o de variaveis
	
	printf("Digite o cpf a ser cadastrado: ");//coletando informa��o do usuario
	scanf("%s", cpf);//salvando na variavel(%S � usado para string)
	
	strcpy(arquivo, cpf);//responsavel por copiar os valores da strings
	
	FILE *file;//criar arquivo
	file = fopen(arquivo, "w");//cria arquivo w(novo nome)
	fprintf(file,cpf);//salvo o valor da variavel
	fclose(file);//fecho o arquivo
	
	file = fopen(arquivo, "a");//acrescentar espa�o,linhas, a(editar)
	fprintf(file,",");//o que quero acrescentar no arquivo
	fclose(file);//fecho o arquivo
	
	printf("Digite o nome a ser cadastrado: ");//coletando informa��o do usuario
	scanf("%s",nome);//salvando na variavel
	
	file = fopen(arquivo, "a");//abrindo o arquivo a(para editar)
	fprintf(file,nome);//salvo valor da variavel
	fclose(file);//fecho o arquivo
	
	file = fopen(arquivo, "a");//abrindo o arquivo a(para editar)
	fprintf(file,",");//salvo valor da variavel
	fclose(file);//fecho o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");//coletando informa��o do usuario
	scanf("%s", sobrenome);//salvando na variavel
	
	file = fopen(arquivo, "a");//abrindo o arquivo a(para editar)
	fprintf(file,sobrenome);//salvo valor da variavel
	fclose(file);//fecho o arquivo
	
	file = fopen(arquivo,"a");//abrindo o arquivo a(para editar)
	fprintf(file,",");//salvo valor da variavel
	fclose(file);//fecho o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//coletando informa��o do usuario
	scanf("%s", cargo);//salvo valor da variavel
	
	file = fopen(arquivo, "a");//abrindo o arquivo a(para editar)
	fprintf(file,cargo);//salvo valor da variavel
	fclose(file);//fecho o arquivo
	
	system("pause");//pausa para ler
}
int consulta()//fun��o responsavel por culsultar

{
	setlocale(LC_ALL, "portuguese");//definindo a linguagem
	
	char cpf[40];//inicio da cria��o de variaveis
	char conteudo[200];// fim da cria��o de variaveis
	
	printf("\nDigite o CPF a ser consultado: ");//coletado informa��o do usuario
	scanf("%s",cpf);//salvando na variavel
	
	FILE *file;//criar arquivo
	file = fopen(cpf, "r");//abrindo arquivo r(para ler)
	
	if(file == NULL)//fazendo a valida��o
	{
		printf("\nCpf n�o localizado\nVerifique se o usuario j� foi cadastrado\n");//informa��o para o cliente
	}
	
	while(fgets(conteudo, 200, file) != NULL)//fazendo a avalia��o
	{
		printf("\nDados do usuario:\nCPF,Nome,Sobrenome,Cargo\n");//informa��o para o cliente
		printf("%s", conteudo);//salvando na variavel
		printf("\n\n");//pulando linha
    }

	system("pause");//pausa
}
int deletar()//fun��o responsavel por de letar

{
	char cpf[40];//cria��o de variedade
	
	printf("\nDigite o cpf do usuario a ser deletado: ");//coletando informa��o do usuario
	scanf("%s",cpf);//salvando na variavel
	
	remove(cpf);//deletando cpf
	
	FILE *file;//criando arquivo
	file = fopen(cpf, "r");// abrir arquivo r(ler)
	
	if(file == NULL)//fazendo a valida��o caso seja nulo
	{
		printf("\nUsuario n�o se encontra no sistema!\n\n");//informa��o para o cliente
		system("pause");
	}
	while(fgets(cpf, 200, file) != NULL)//fazendo a valida��o caso tenh o arquivo
	{
		printf("\nUsuario deletado com sucesso.\n\n");//informa��o para o cliente
		printf("%s", cpf);//salvando na variavel
		system("pause");//pausa
	}
}

int main()//fun��o principal
{
	int opcao=0;//definindo vari�veis
	int laco=1;
	  
	for(laco=1;laco=1;)//la�o de repti��o
	{
    	system("cls");//apagando informa�oes na tela
	
        setlocale(LC_ALL, "portuguese");// definindo a linguagem
    
    	printf("\t### Cart�rio da EBAC ###\n\n");// inicio do menu
    	printf("Escolha a op��o desejada do menu: \n\n");
    	printf("\t1 - Incluir nomes \n");
    	printf("\t2 - Consultar nomes \n");
    	printf("\t3 - Deletar nomes \n\n\n");
    	printf("escolha a op��o desejada:");//fim do menu
	
    	scanf("%d" , &opcao);//armazenando a escolha do usuario
 	
    	system("cls");
	
    	switch(opcao)
    	{
	        case 1://inicio da escolha
	        registro();
	        break;
            
			case 2:
        	consulta();
        	break;
        	
			case 3:
        	deletar();
        	break;
        	
			default:
        	printf ("Esta op��o n�o esta disponivel!\n\n\n");
        	system("pause");
        	break;
        	//fim da escolha
       }
  }
	}

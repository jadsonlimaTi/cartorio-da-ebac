
#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h>//biblioteca respos�vel por cuidar dos strng

int registro()//Fun��o responsavel por cadastrar os usuarios no sistema
{
	//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/string(string s�o conjunto de variaveis)
	
	printf("Digite o CPF  ser cadastrado:" );//coletando informa��o do usu�rio
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf);//respons�vel por copiar os valores das string
	
	FILE *file;//cria o arquivo e o "w" significa escrever
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf);
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}
 
 
 int consulta()
{
	setlocale(LC_ALL, "portuguese");//definindo as linguagen
	
	char cpf[40];
	char conteudo [200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file =fopen(cpf,"r");
	
	if(file == NULL);
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
		
	}
	
}

int main()
		{
		int opcao=0;// Definindo vari�veis
		int laco=1;
		
		for(laco=1;laco=1;)
	{
	
	
	
		system("cls");
	
		setlocale(LC_ALL, "portuguese");//definindo as linguagens
		printf("\t### Cartorio da EBAC ###\n\n");//In�cio do men�
		printf("\tEscolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema!\n");
		printf("Op��o:");//Fim do men�
		
		
		scanf("%d" , &opcao);//Armazenando a escolha dos usu�rios
		
		system("cls");//respons�vel por limpar a tela
			
		
		switch(opcao)//inicio da sele��o do Menu
		{
		
			case 1:
			registro();//chamada de fun��es
			break;
			
			case 2:
			consulta();//chamada de fun��es
			break;
			
			case 3:
			deletar();//chamada de fun��es
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n"); 
			return 0; 
			break; 
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
		} //fim da sele��o
		
	}
		
}

#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloa��o de espa�o em mem�ria
#include <locale.h>  //biblioteca de aloca��oes de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro()  //Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//inicio cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final cria��o de variaveis/string
	
	printf("Digite o cpf a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s" , cpf);  //% refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo, "w" significa write(escrever)
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo, "a" significa atualizar
	fprintf(file,","); 
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",nome); //% refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo, "a" significa atualizar
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",sobrenome); //% refere-se a string
	
	file = fopen(arquivo, "a"); 
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",cargo); //% refere-se a string
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);	
	
    system("pause"); //pausa na tela atual
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem

	//inicio cria��o de variaveis/string
	char cpf[40];
	char conteudo[200];
	//final cria��o de variaveis/string
	
	
	printf("Digite o CPF a ser consultado:"); //pedindo informa��es para o usu�rio
	scanf("%s",cpf);
	
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //cria o arquivo, "r" significa read(ler)
	
	
	if(file == NULL)  //fa�a algo caso requisitos forem compridos
    {
      printf("\nN�o foi possivel abrir o arquivo, n�o localizado\n\n");
      system("pause");
      return 0;
	}
	
	printf("CPF\nNome\nSobrenome\nCargo\n");
	
	while(fgets(conteudo,200,file) != NULL) //salva em conteudo os 200 que est�o em File e para quando for diferente de NULL(nulo)
	{
		printf("\n\t%s",conteudo); //mostra para o usu�rio as informa��es que foram salvas em while, \t significa centralizar 
		printf("\n\n"); // \n significa pular linha
	}
	system("pause"); //pausa na tela atual

	
}

int deletar()
{
	char cpf[40]; //cria��o da string
	
	printf("Digite o CPF do usu�rio a ser deletado:"); //pedindo informa��es para o usu�rio
	scanf("%s",cpf); //% refere-se a string
	
	if (remove(cpf) == 0)
    {
        printf("\nUsu�rio deletado com sucesso!\n\n"); // mostrando informa��es ao usu�rio
        system("pause");
    }
    else
    {
        printf("\nN�o foi poss�vel deletar. Usu�rio n�o se encontra no sistema\n\n"); // mostrando informa��es ao usu�rio
        system("pause");
    }
	
}

int main()
{ 
        setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
    
    int opcao=0; //definindo variaveis
    int x=1;
        
	do
	{
		
		
		system("cls"); //responsavel por limpar a tela

        
    
	    printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
	    printf("Escolha a op��o desejada do menu: \n\n");
     	printf("\t1 - Registrar nomes \n");
        printf("\t2 - Consultar nomes \n");
        printf("\t3 - Deletar nomes \n\n"); 
		printf("\t4 - Sair do sistema \n"); 
    	printf("Op��o: ");  //fim do menu
    
        scanf("%d", &opcao);  //armazenando a escolha do usu�rio
    
        system("cls"); //responsavel por limpar a tela
        
        
        switch(opcao)
        {
        	case 1:
            registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;	
			
			case 4:
			printf("Obrigado por utilizar o sistema! \n");
			return 0;
			break;	
			
			default:
			printf("Essa op��o n�o est� disponivel \n");
			system("pause");
			break;	
		}
  
        
	
	
	} while(x==1);
    
    
    
    
                                                                    

}

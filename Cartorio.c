#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de aloação de espaço em memória
#include <locale.h>  //biblioteca de alocaçãoes de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro()  //Função responsavel por cadastrar os usuários no sistema
{
	//inicio criação de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criação de variaveis/string
	
	printf("Digite o cpf a ser cadastrado: "); //coletando informação do usuário
	scanf("%s" , cpf);  //% refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo, "w" significa write(escrever)
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo, "a" significa atualizar
	fprintf(file,","); 
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",nome); //% refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo, "a" significa atualizar
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",sobrenome); //% refere-se a string
	
	file = fopen(arquivo, "a"); 
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informação do usuário
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

	//inicio criação de variaveis/string
	char cpf[40];
	char conteudo[200];
	//final criação de variaveis/string
	
	
	printf("Digite o CPF a ser consultado:"); //pedindo informações para o usuário
	scanf("%s",cpf);
	
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //cria o arquivo, "r" significa read(ler)
	
	
	if(file == NULL)  //faça algo caso requisitos forem compridos
    {
      printf("\nNão foi possivel abrir o arquivo, não localizado\n\n");
      system("pause");
      return 0;
	}
	
	printf("CPF\nNome\nSobrenome\nCargo\n");
	
	while(fgets(conteudo,200,file) != NULL) //salva em conteudo os 200 que estão em File e para quando for diferente de NULL(nulo)
	{
		printf("\n\t%s",conteudo); //mostra para o usuário as informações que foram salvas em while, \t significa centralizar 
		printf("\n\n"); // \n significa pular linha
	}
	system("pause"); //pausa na tela atual

	
}

int deletar()
{
	char cpf[40]; //criação da string
	
	printf("Digite o CPF do usuário a ser deletado:"); //pedindo informações para o usuário
	scanf("%s",cpf); //% refere-se a string
	
	if (remove(cpf) == 0)
    {
        printf("\nUsuário deletado com sucesso!\n\n"); // mostrando informações ao usuário
        system("pause");
    }
    else
    {
        printf("\nNão foi possível deletar. Usuário não se encontra no sistema\n\n"); // mostrando informações ao usuário
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

        
    
	    printf("### Cartório da EBAC ###\n\n"); //inicio do menu
	    printf("Escolha a opção desejada do menu: \n\n");
     	printf("\t1 - Registrar nomes \n");
        printf("\t2 - Consultar nomes \n");
        printf("\t3 - Deletar nomes \n\n"); 
		printf("\t4 - Sair do sistema \n"); 
    	printf("Opção: ");  //fim do menu
    
        scanf("%d", &opcao);  //armazenando a escolha do usuário
    
        system("cls"); //responsavel por limpar a tela
        
        
        switch(opcao)
        {
        	case 1:
            registro(); //chamada de funções
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
			printf("Essa opção não está disponivel \n");
			system("pause");
			break;	
		}
  
        
	
	
	} while(x==1);
    
    
    
    
                                                                    

}

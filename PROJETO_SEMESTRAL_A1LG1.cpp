#include <iostream>
#include <locale.h>
#include <string.h>

//Programa de Identificação de Sistema Representacional. Existem 4 tipos, são eles: A (Auditivo) // D (Digital) // C (Cinestésico) // V (Visual).

int main(int argc, char** argv) {
	setlocale(LC_ALL,"");
	int cont, a2, b2, c2, d2, x, y, z, w, a[5], b[5], c[5], d[5], i, len, len2, len3, retorno, controle;
	char perfil[20], nome[200], anderline = '_', prontuario[200], identificacao[200], identificacaoarq[200], opcao = 'v', ler[100], resultado[200]="Resultado_";
	i = 5;
	cont = 1;
	controle = 1;
	FILE* referencial_teorico;
	referencial_teorico = fopen("referencial_teorico.txt","w");
	fprintf(referencial_teorico,"REFERENCIAL TEÓRICO\n\n=========================\n\nSegundo Albert Merabian, em seu livro “Silent Messages”, o poder de influência das palavras não passa de 7%, enquanto a forma como as palavras são ditas e a fisiologia representam 38%% e 55\%% deste poder, respectivamente.\n\nPara Merabian 55%% do impacto da comunicação é não-verbal. Corresponde à postura, gestos e contato visual da pessoa enquanto se comunica.\n\nO tom da voz representa 38%% do impacto da comunicação.\n\nPor fim, as palavras propriamente ditas detêm 7%% do impacto da comunicação.\n\nAssim sendo, conclui Merabian, não é o que dizemos, mas como dizemos que faz a diferença na comunicação.\n\nAs portas da percepção são os nossos sentidos, nossos olhos, nariz, ouvidos, boca e pele, nossos únicos pontos de contato com o mundo exterior. Da mesma forma que utilizamos os sentidos para filtrarmos as experiências, utilizamos os sentidos para estruturar nosso pensamento e nossa comunicação.\n\nDe acordo com a Programação Neurolinguística existem os seguintes sistemas representacionais.\n\n- Auditivo \n- Digital \n- Cinestésico \n- Visual \n\nAlgumas pessoas captam melhor as mensagens do mundo exterior através da audição, são as pessoas chamadas auditivas. Outras pessoas sentem necessidade de perguntar muito, necessitam de muitas informações e fatos. Estas são as digitais. As cinestésicas aprendem melhor por meio das sensações táteis, como o tato, a temperatura, a umidade, as sensações internas e as emoções. Já as pessoas visuais aprendem melhor quando se valendo da visão.\n\nCada pessoa tem um sistema representacional predominante e adequar a comunicação ao sistema representacional dominante dela é fundamental para diálogos eficientes.\n\n");
	fclose(referencial_teorico);
	
	struct Teste_Sistema{
		int nrofrase, cinestesico, auditivo, visual, digital;
		char frase[100], opcaoA[100], opcaoB[100], opcaoC[100], opcaoD[100];
	};
	
	struct Teste_Sistema teste[5];
	
	FILE *SR;
	SR = fopen("TESTE_SISTEMA_REPRESENTACIONAL.dat","rb");
	fclose(SR);
	
	FILE *questionario;
	
	if(SR == NULL){
	
	teste[0].nrofrase = 1;
	teste[1].nrofrase = 2;
	teste[2].nrofrase = 3;
	teste[3].nrofrase = 4;
	teste[4].nrofrase = 5;
	
	strcpy(teste[0].frase, "Eu tomo decisões importantes baseado em:");
	strcpy(teste[0].opcaoA, "Intuição.");
	strcpy(teste[0].opcaoB, "O que me soa melhor.");
	strcpy(teste[0].opcaoC, "O que me parece melhor.");
	strcpy(teste[0].opcaoD, "Um estudo precioso e minucioso do assunto.");
	
	strcpy(teste[1].frase, "Durante uma discussão eu sou mais influenciado por:");
	strcpy(teste[1].opcaoA, "Se eu entro em contato ou não com os sentimentos reais do outro.");
	strcpy(teste[1].opcaoB, "O tom de voz da outra pessoa.");
	strcpy(teste[1].opcaoC, "Se eu posso ou não ver o argumento da outra pessoa.");
	strcpy(teste[1].opcaoD, "A lógica do argumento da outra pessoa.");
	
	strcpy(teste[2].frase, "Eu comunico mais facilmente o que se passa comigo:");
	strcpy(teste[2].opcaoA, "Pelos sentimentos que compartilho.");
	strcpy(teste[2].opcaoB, "Pelo tom da minha voz.");
	strcpy(teste[2].opcaoC, "Do modo como me visto e aparento.");
	strcpy(teste[2].opcaoD, "Pelas palavras que escolho.");
	
	strcpy(teste[3].frase, "É muito fácil para mim:");
	strcpy(teste[3].opcaoA, "Escolher os móveis mais confortáveis.");
	strcpy(teste[3].opcaoB, "Achar o volume e a sintonia ideais num sistema de som.");
	strcpy(teste[3].opcaoC, "Escolher as combinações de cores mais ricas e atraentes.");
	strcpy(teste[3].opcaoD, "Selecionar o ponto mais relevante relativo a um assunto interessante.");
	
	strcpy(teste[4].frase, "Eu me percebo assim:");
	strcpy(teste[4].opcaoA, "Eu sou muito sensível à maneira como a roupa veste o meu corpo.");
	strcpy(teste[4].opcaoB, "Se estou muito em sintonia com os sons do ambiente.");
	strcpy(teste[4].opcaoC, "Eu respondo fortemente às cores e à aparência de uma sala.");
	strcpy(teste[4].opcaoD, "Se sou muito capaz de raciocinar com fatos e dados novos.");
	
	SR = fopen("TESTE_SISTEMA_REPRESENTACIONAL.dat","wb");
	fwrite(&teste,sizeof(Teste_Sistema),5,SR);
	fclose(SR);
	
	questionario = fopen("QUESTIONARIO_1.txt","w");
	fprintf(questionario,"NroFrase                          Frase						C item_1								A item_2							V item_3									D item_4\n\n============================================================================================================================================================================================================================================================================================================================");
	fclose(questionario);
	
	i = 0;
	SR = fopen("TESTE_SISTEMA_REPRESENTACIONAL.dat","rb");
	while(fread(&teste,sizeof(Teste_Sistema),5,SR)){
		questionario = fopen("QUESTIONARIO_1.txt","a");
		fprintf(questionario,"\n%d	%s				%s								%s					%s						%s\n",teste[0].nrofrase,teste[0].frase,teste[0].opcaoA,teste[0].opcaoB,teste[0].opcaoC,teste[0].opcaoD);
		fprintf(questionario,"\n%d	%s			%s		%s				%s			%s\n",teste[1].nrofrase,teste[1].frase,teste[1].opcaoA,teste[1].opcaoB,teste[1].opcaoC,teste[1].opcaoD);	
		fprintf(questionario,"\n%d	%s			%s					%s					%s					%s\n",teste[2].nrofrase,teste[2].frase,teste[2].opcaoA,teste[2].opcaoB,teste[2].opcaoC,teste[2].opcaoD);	
		fprintf(questionario,"\n%d	%s						%s				%s		%s		%s\n",teste[3].nrofrase,teste[3].frase,teste[3].opcaoA,teste[3].opcaoB,teste[3].opcaoC,teste[3].opcaoD);	
		fprintf(questionario,"\n%d	%s						%s	%s		%s		%s\n============================================================================================================================================================================================================================================================================================================================",teste[4].nrofrase,teste[4].frase,teste[4].opcaoA,teste[4].opcaoB,teste[4].opcaoC,teste[4].opcaoD);				
		fclose(questionario);
	}
	
	fclose(SR);
}
	
	i = 0;
	fflush(stdin);
    printf("DIGITE SEU NOME \t:");
    fgets(nome, 100, stdin);
    len = strlen(nome);
    for (i = 0; i < len; i++) {
        if (nome[i] == ' ') nome[i] = anderline;
    }

    fflush(stdin);
	printf("DIGITE SEU PRONTUÁRIO \t:");
	fgets(prontuario, 100, stdin);
	
	len = strlen(nome) - 1;
	len2 = strlen(prontuario) - 1;
	
	i = 0;
	for(i=0;i<=len;i++) identificacao[i] = nome[i];
	
	identificacao[len] = anderline;
	
	len2 = strlen(identificacao) + strlen(prontuario);

	strncat(identificacao,prontuario,len2);	
	
	len2 = strlen(identificacao) - 1;
	
	i = 0;
	for(i=0;i<len2;i++) identificacaoarq[i] = identificacao[i];
		
	strcat(identificacaoarq,".txt");
	
	len3 = strlen(identificacaoarq) + strlen(resultado);
	
	strncat(resultado,identificacaoarq,len3);

	FILE* perfil_representacional;
	perfil_representacional = fopen(resultado,"w");
	fclose(perfil_representacional);
	
	while(controle==1){	
	retorno = strncmp(nome,"MASTER",6);
	opcao = 'v';
	
	if(retorno == 0){
	
		while (opcao != 'F' && opcao != 'f'){
			printf("\n===============================================\n\tTESTE DOS SISTEMAS REPRESENTACIONAIS\n===============================================\n\t1. Cadastrar questionário\n\t2. Visualizar questionário\n\t3. Realizar Teste\n\t4. Sobre o Teste\n\tF. Fim\n===============================================\n\tEscolha ->");
			fflush(stdin);
			opcao = getchar();
			switch (opcao){
			case '1':
				i = 0;
				for(i=0;i<=4;i++){
					system("cls");
					printf("Informe número da frase: \t");
					fflush(stdin);
					scanf("%d",&teste[i].nrofrase);
					printf("\nInforme o conteudo da frase: \t");
					fflush(stdin);
					gets(teste[i].frase);
					printf("\nInforme a primeira opção de resposta: \t");
					fflush(stdin);
					gets(teste[i].opcaoA);
					printf("\nInforme a segunda opção de resposta: \t");
					fflush(stdin);
					gets(teste[i].opcaoB);
					printf("\nInforme a terceira opção de resposta: \t");
					fflush(stdin);
					gets(teste[i].opcaoC);
					printf("\nInforme a quarta opção de resposta: \t");
					fflush(stdin);
					gets(teste[i].opcaoD);
				}
				
				SR = fopen("TESTE_SISTEMA_REPRESENTACIONAL.dat","w");
				fwrite(&teste,sizeof(Teste_Sistema),5,SR);
				fclose(SR);
				
				questionario = fopen("QUESTIONARIO_1.txt","w");
				fprintf(questionario,"NroFrase\tFrase\t\tC item_1\tA item_2\tV item_3\tD item_4\n\n==========================================================================================");
				fclose(questionario);
				
				i = 0;
				SR = fopen("TESTE_SISTEMA_REPRESENTACIONAL.dat","r");
				while(fread(&teste,sizeof(Teste_Sistema),5,SR)){
					questionario = fopen("QUESTIONARIO_1.txt","a");
					for(i=0;i<=4;i++){
					fprintf(questionario,"\n%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s",teste[i].nrofrase,teste[i].frase,teste[i].opcaoA,teste[i].opcaoB,teste[i].opcaoC,teste[i].opcaoD);
					}}
					fprintf(questionario,"\n==========================================================================================");
					fclose(questionario);
				fclose(SR);
				break;
				
			case '2':
				system("cls");
				questionario = fopen("QUESTIONARIO_1.txt","r");
				while(fgets(ler, 100, questionario) != NULL){
				printf("%s",ler);
				}
				fclose(questionario);
				break;
			
			case '3':
				opcao = 'f';
				continue;
	
			case '4':
				system("cls");
				FILE *rtopen;
				rtopen = fopen("referencial_teorico.txt","rt");
				while(fgets(ler, 100, rtopen) != NULL){
				printf("%s",ler);
				}
				fclose(referencial_teorico);
				break;
				
			case 'f':
				exit(0);
			
			case 'F':
				exit(0);
				
			default:
				system("cls");
				printf("\n===============================================\nERRO AO ESCOLHER!\n===============================================\n");
				break;
			}
		}
	}
	
	SR = fopen("TESTE_SISTEMA_REPRESENTACIONAL.dat","rt");
	while(fread(&teste,sizeof(Teste_Sistema),5,SR)){
	i=0;
	for(i=0;i<=4;i++){
	cont = 1;
	while(cont == 1){
	system("cls");
	printf("Nas frases a seguir, pontue com: \n4 - A que melhor descreve você;\n3 - A próxima melhor descrição; \n2 - A próxima melhor; \n1 - Aquela que menos descreve você.\n\n");
	printf("%d %s \na) %s \nb) %s \nc) %s \nd) %s\n",teste[i].nrofrase,teste[i].frase,teste[i].opcaoA,teste[i].opcaoB,teste[i].opcaoC,teste[i].opcaoD);
	printf("[a] -> ");
	scanf("%d",&teste[i].cinestesico);
	if ((teste[i].cinestesico >= 1) && (teste[i].cinestesico <=4)) {
		printf("[b] -> ");
		scanf("%d",&teste[i].auditivo); }
	else{
	system("cls");
	printf("Número inválido, tente novamente.\n\n");
	continue;}
		if ((teste[i].auditivo >= 1) && (teste[i].auditivo <=4) && (teste[i].auditivo != teste[i].cinestesico) ){
			printf("[c] -> ");
			scanf("%d",&teste[i].visual); }
		else{
		system("cls");
		printf("Número inválido, tente novamente.\n\n");
		continue;}
			if((teste[i].visual >= 1) && (teste[i].visual <=4) && (teste[i].visual != teste[i].auditivo) && (teste[i].visual != teste[i].cinestesico)) {
				printf("[d] -> ");
				scanf("%d",&teste[i].digital); }
			else{
			system("cls");
			printf("Número inválido, tente novamente.\n\n");
			continue;}
				if((teste[i].digital >= 1) && (teste[i].digital <=4) && (teste[i].digital != teste[i].auditivo) && (teste[i].digital != teste[i].cinestesico) && (teste[i].digital != teste[i].visual))
				cont = 0;
				else{
				system("cls");
				printf("Número inválido, tente novamente.\n\n");
				continue;}
}}}
	fclose(SR);
	system("cls");
	
	i= 0;
	int totalCinestesico = 0;
	int totalAuditivo = 0;
	int totalVisual = 0;
	int totalDigital = 0;
	
	for(i = 0; i<=4; i++){
		totalCinestesico = totalCinestesico + teste[i].cinestesico;
		totalAuditivo = totalAuditivo + teste[i].auditivo;
		totalVisual = totalVisual + teste[i].visual;
		totalDigital = totalDigital + teste[i].digital;
	}
	totalCinestesico = totalCinestesico*2;
	totalAuditivo = totalAuditivo*2;
	totalVisual = totalVisual*2;
	totalDigital = totalDigital*2;
	
	//A = Cinestesico, B = Auditivo, C = Visual, D = Digital

	if ((totalCinestesico >= totalAuditivo) && (totalCinestesico >= totalVisual) && (totalCinestesico >= totalDigital)){
		perfil_representacional = fopen(resultado,"w");
		fprintf(perfil_representacional,"======================================================== PERFIL REPRESENTACIONAL DE MASTER =======================================================\n%d%% Visual\t%d%% Auditivo\t%d%% Cinestesico\t%d%% Digital\n===================================================================================================================================================\n\nO indivíduo cinestésico é aquele que não se satisfaz apenas ouvindo ou vendo. \nEle precisa tocar, experimentar, sentir e cheirar para compreender melhor o que está diante dele. \nO termo é um adjetivo relacionado com a cinestesia, que é um conjunto de sensações que nos permite perceber os nossos movimentos musculares. \nFazendo uma analogia, podemos dizer que o cinestésico é o conjunto dos sentidos que nos possibilita ter uma noção mais prática das coisas.\n\n===================================================================================================================================================\nSEU PERFIL É: CINESTÉSICO.\n===================================================================================================================================================\n",totalVisual,totalAuditivo,totalCinestesico,totalDigital);
		fclose(perfil_representacional);
		FILE *rfopen;
		rfopen = fopen(resultado,"rt");
		while(fgets(ler, 100, rfopen) != NULL){
			printf("%s",ler);
			}
		fclose(perfil_representacional);
		system("pause");
	}
	if ((totalAuditivo >= totalCinestesico) && (totalAuditivo >= totalVisual) && (totalAuditivo >= totalDigital)){
		perfil_representacional = fopen(resultado,"w");
		fprintf(perfil_representacional,"======================================================== PERFIL REPRESENTACIONAL DE MASTER =======================================================\n%d%% Visual\t%d%% Auditivo\t%d%% Cinestesico\t%d%% Digital\n===================================================================================================================================================\n\nVocê é aquele que ouve. \nUma pessoa auditiva gosta de ouvir as outras pessoas, apresenta um amplo vocabulário, se expressam com objetividade e gesticulam muito. \nEssas pessoas aprendem a partir da escuta e gostam de desfrutar do silêncio.\n\n===================================================================================================================================================\nSEU PERFIL É: AUDITIVO.\n===================================================================================================================================================\n",totalVisual,totalAuditivo,totalCinestesico,totalDigital);
		fclose(perfil_representacional);
		FILE *rfopen;
		rfopen = fopen(resultado,"rt");
		while(fgets(ler, 100, rfopen) != NULL){
			printf("%s",ler);
			}
		fclose(perfil_representacional);
		system("pause");
	}	

	if ((totalVisual >= totalCinestesico) && (totalVisual >= totalAuditivo) && (totalVisual >= totalDigital)){
		perfil_representacional = fopen(resultado,"w");
		fprintf(perfil_representacional,"======================================================== PERFIL REPRESENTACIONAL DE MASTER =======================================================\n%d%% Visual\t%d%% Auditivo\t%d%% Cinestesico\t%d%% Digital\n===================================================================================================================================================\n\nVocê é aquele que vê. \nUma pessoa visual usa a visão como maneira de conseguir informações, identificando as coisas por meio de imagens. \nEssas pessoas têm memória fotográfica e geralmente demoram a repetir instruções orais/faladas. \nEm geral, preferem ler sozinhos a perguntar ou depender de outra pessoa.\n\n===================================================================================================================================================\nSEU PERFIL É: VISUAL\n===================================================================================================================================================\n",totalVisual,totalAuditivo,totalCinestesico,totalDigital);
		fclose(perfil_representacional);
		FILE *rfopen;
		rfopen = fopen(resultado,"rt");
		while(fgets(ler, 100, rfopen) != NULL){
			printf("%s",ler);
			}
		fclose(perfil_representacional);
		system("pause");
	}

	if ((totalDigital >= totalCinestesico) && (totalDigital >= totalAuditivo) && (totalDigital >= totalVisual)){
		perfil_representacional = fopen(resultado,"w");
		fprintf(perfil_representacional,"======================================================== PERFIL REPRESENTACIONAL DE MASTER =======================================================\n%d%% Visual\t%d%% Auditivo\t%d%% Cinestesico\t%d%% Digital\n===================================================================================================================================================\n\nVocê é uma pessoa que ouve e entende.\nFaz muitas perguntas e precisa de muita informação.\nPessoas com essas características estudam as ideias para descobrir se elas fazem sentido e estão sempre dialogando internamente.\nPossuem dificuldade para se concentrar e, por isso, a leitura é um ponto fraco.\n\n===================================================================================================================================================\nSEU PERFIL É: DIGITAL.\n===================================================================================================================================================\n",totalVisual,totalAuditivo,totalCinestesico,totalDigital);
		fclose(perfil_representacional);
		FILE *rfopen;
		rfopen = fopen(resultado,"rt");
		while(fgets(ler, 100, rfopen) != NULL){
			printf("%s",ler);
			}
		fclose(perfil_representacional);
		system("pause");
	}
	
	retorno = strncmp(nome,"MASTER",6);
	if(retorno != 0){
		controle = 0;
	} 
		
}
	return 0;
		}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define LOGIN_MAX	64
#define SENHA_MAX	32

struct usuario_t {
	char login[64];
	char senha[32];
};

void cadastrar()
{
	FILE *fp;
	struct usuario_t usuario;
	memset(&usuario, 0, sizeof(struct usuario_t));

	printf("Cadastro de usu�rio: \n");
	printf("login> ");
	scanf("%s", &usuario.login);
	printf("senha> ");
	scanf("%s", &usuario.senha);

	fp = fopen("login", "a");
	if (!fp) {
		printf("N�o foi poss�vel criar o arquivo de login");
		return;
	}
	fwrite(&usuario, sizeof(struct usuario_t), 1, fp);
	fclose(fp);
}

int login()
{
    FILE *fp;
	struct usuario_t usuario;
	fp = fopen("login", "r");
	if (!fp) {
		cadastrar();
		fp = fopen("login", "r");
		if (!fp) {
		    printf("N�o foi possivel encontrar o arquivo de login\n");
		    return 0;
		}
	}
	memset(&usuario, 0, sizeof(struct usuario_t));

	fread(&usuario, sizeof(struct usuario_t), 1, fp);
	fclose(fp);
	if (!strcmp("", usuario.login)) {
		printf("Nenhum usu�rio encontrado, abrindo cadastro!\n");
		cadastrar();
	} else {
	    int tentativas = 0;
		do {
			char login[LOGIN_MAX];
			char senha[SENHA_MAX];
			printf("Login: ");
			scanf("%s", &login);
			printf("Senha: ");
			scanf("%s", &senha);
			if (!strcmp(login, usuario.login) && !strcmp(senha, usuario.senha)) {
				system("cls");
				printf("\nBem vindo %s\n", usuario.login);
				printf("\nPressione qualquer tecla para continuar!");
				getch();
				/*return 1;*/
				system("Admin.exe");
			} else {
				printf("Usu�rio ou senha invalidos!\n");
				tentativas++;
			}
		} while (tentativas < 2);
		printf("Numero maximo de tentativas alcan�ado!\n");
		exit(0);
        return 0;
	}
	return 0;
}

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "");
	login();
	return 0;
}

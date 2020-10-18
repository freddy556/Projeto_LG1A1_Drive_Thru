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

	printf("Cadastro de usuário: \n");
	printf("login> ");
	scanf("%s", &usuario.login);
	printf("senha> ");
	scanf("%s", &usuario.senha);

	fp = fopen("login", "a");
	if (!fp) {
		printf("Não foi possível criar o arquivo de login");
		return;
	}
	fwrite(&usuario, sizeof(struct usuario_t), 1, fp);
	fclose(fp);
}

int main(int argc, char *argv[])
{
	cadastrar();
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "tela.h"

void Salvar();
void Excluir();
void Opcoes();

int main() {
    Tela tela = CriarTela(200, 400);
    Botao botao1 = CriarBotao("Salvar", 12, "FFF", CLICK, Salvar);
    Botao botao2 = CriarBotao("Excluir", 18, "000", CLICK, Excluir);
    Botao botao3 = CriarBotao("Opcoes", 10, "FF0000", LONGO_CLICK, Opcoes);

    RegistraBotaoTela(&tela, botao1);
    RegistraBotaoTela(&tela, botao2);
    RegistraBotaoTela(&tela, botao3);
    DesenhaTela(tela);
    OuvidorEventosTela(tela);

    return 0;
}

void Salvar() {
    printf("- Botao de SALVAR dados ativado!\n");
}

void Excluir() {
    printf("- Botao de EXCLUIR dados ativado!\n");
}

void Opcoes() {
    printf("- Botao de OPCOES ativado!\n");
}

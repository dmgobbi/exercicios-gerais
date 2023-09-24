#include <stdio.h>
#include "eleicao.h"

tEleicao InicializaEleicao() {
    tEleicao eleicao;
   
    eleicao.totalPresidentes = 0;  
    eleicao.votosNulosPresidente = 0; 
    eleicao.votosBrancosPresidente = 0;
    eleicao.totalGovernadores = 0; 
    eleicao.votosNulosGovernador = 0;
    eleicao.votosBrancosGovernador = 0;
    eleicao.totalEleitores = 0;

    int qtdCandidatos;
    scanf("%d", &qtdCandidatos);

    for (int i = 0; i < qtdCandidatos; i++) {
        tCandidato candidato = LeCandidato();

        if (ObtemCargo(candidato) == 'P') {
            eleicao.presidentes[eleicao.totalPresidentes++] = candidato;
        } else if (ObtemCargo(candidato) == 'G') {
            eleicao.governadores[eleicao.totalGovernadores++] = candidato;
        } 
    }

    return eleicao;
}

tEleicao RealizaEleicao(tEleicao eleicao) {  
    scanf("%d", &eleicao.totalEleitores);
    
    for (int i = 0; i < eleicao.totalEleitores; i++) {
        eleicao.eleitores[i] = LeEleitor();

        int votoPresidente = ObtemVotoPresidente(eleicao.eleitores[i]);
        int votoGovernador = ObtemVotoGovernador(eleicao.eleitores[i]);
 
        if (!votoPresidente) {
            eleicao.votosBrancosPresidente++;
        } else {
            int votoValido = 0;
            for (int p = 0; p < eleicao.totalPresidentes; p++) {
                if (VerificaIdCandidato(eleicao.presidentes[p], votoPresidente)) {
                    eleicao.presidentes[p] = IncrementaVotoCandidato(eleicao.presidentes[p]);
                    votoValido = 1;
                    break;
                } 
            }
            if (!votoValido) {
                eleicao.votosNulosPresidente++;
            }
        }

        if (!votoGovernador) {
            eleicao.votosBrancosGovernador++;
        } else {
            int votoValido = 0;
            for (int g = 0; g < eleicao.totalGovernadores; g++) {
                if (VerificaIdCandidato(eleicao.governadores[g], votoGovernador)) {
                    eleicao.governadores[g] = IncrementaVotoCandidato(eleicao.governadores[g]);
                    votoValido = 1;
                    break;
                } 
            }
            if (!votoValido) {
                eleicao.votosNulosGovernador++;
            }
        }
    }

    return eleicao;
}

void ImprimeResultadoEleicao(tEleicao eleicao) {
    int anulada = 0;
    int empateP = 0, empateG = 0;
    int vencedorP = 0, vencedorG = 0;
    int iVencedorP = 0, iVencedorG = 0;

    for (int i = 0; i < eleicao.totalEleitores - 1; i++) {
        for (int j = i + 1; j < eleicao.totalEleitores; j++) {
            if (EhMesmoEleitor(eleicao.eleitores[i], eleicao.eleitores[j])) {
                anulada = 1;
                break;
            }
        }
        if (anulada) {
            break;
        }
    }

    if (eleicao.totalEleitores > 10 || eleicao.totalPresidentes > 3 || eleicao.totalGovernadores > 3) {
        anulada = 1;
    }

    if (anulada) {
        printf("ELEICAO ANULADA\n");
        return;
    }

    for (int i = 0; i < eleicao.totalPresidentes; i++) {
        if (ObtemVotos(eleicao.presidentes[i]) > vencedorP) {
            vencedorP = ObtemVotos(eleicao.presidentes[i]);
            iVencedorP = i;
        }
    }

    for (int i = 0; i < eleicao.totalPresidentes; i++) {
        if (ObtemVotos(eleicao.presidentes[i]) == vencedorP && 
            !EhMesmoCandidato(eleicao.presidentes[i], eleicao.presidentes[iVencedorP])) {
            empateP = 1;
        }
    }

    for (int i = 0; i < eleicao.totalGovernadores; i++) {
        if (ObtemVotos(eleicao.governadores[i]) > vencedorG) {
            vencedorG = ObtemVotos(eleicao.governadores[i]);
            iVencedorG = i;
        }
    }

    for (int i = 0; i < eleicao.totalGovernadores; i++) {
        if (ObtemVotos(eleicao.governadores[i]) == vencedorG && 
            !EhMesmoCandidato(eleicao.governadores[i], eleicao.governadores[iVencedorG])) {
            empateG = 1;
        }
    }

    float percentualVotosP = CalculaPercentualVotos(eleicao.presidentes[iVencedorP], eleicao.totalEleitores);
    float percentualVotosG = CalculaPercentualVotos(eleicao.governadores[iVencedorG], eleicao.totalEleitores);
    int votosNulosBrancosP = eleicao.votosNulosPresidente + eleicao.votosBrancosPresidente;
    int votosNulosBrancosG = eleicao.votosNulosGovernador + eleicao.votosBrancosGovernador;
    int votosPresidenteVencedor = ObtemVotos(eleicao.presidentes[iVencedorP]);
    int votosGovernadorVencedor = ObtemVotos(eleicao.governadores[iVencedorG]);

    printf("- PRESIDENTE ELEITO: ");
    if (empateP) {
        printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
    } else if (votosNulosBrancosP > votosPresidenteVencedor) {
        printf("SEM DECISAO\n");
    } else {
        ImprimeCandidato(eleicao.presidentes[iVencedorP], percentualVotosP);
    }
    
    printf("- GOVERNADOR ELEITO: ");
    if (empateG) {
        printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
    } else if (votosNulosBrancosG > votosGovernadorVencedor) {
        printf("SEM DECISAO\n");
    } else {
        ImprimeCandidato(eleicao.governadores[iVencedorG], percentualVotosG);
    }

    int totalVotosNulos = eleicao.votosNulosPresidente + eleicao.votosNulosGovernador;
    int totalVotosBrancos = eleicao.votosBrancosPresidente + eleicao.votosBrancosGovernador;

    printf("- NULOS E BRANCOS: %d, %d", totalVotosNulos, totalVotosBrancos);
}
